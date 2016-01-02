//
// Created by defacto on 2015.12.26..
//

#include "BoundariesDuplicationsDrawingSystem.h"

BoundariesDuplicationsDrawingSystem::BoundariesDuplicationsDrawingSystem(IDrawingSystem &normalDrawingSystem,
                                                                         ActorsConfiguration &configuration)
        : normalDrawingSystem_(normalDrawingSystem), configuration_(configuration) {
}

void BoundariesDuplicationsDrawingSystem::drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale,
                                                            ActorId actorId) {
    auto screenSize = configuration_.getBox2dScreenDimensions();
    normalDrawingSystem_.drawImage(type, position, rotation, scale, actorId);
    Point delta;
    if( position.getX() < configuration_.GetDuplicationBoundariesSize().getX()){
        delta = delta + Point(screenSize.getX()+ position.getX(), 0);
    } else if( position.getX() > screenSize.getX() -configuration_.GetDuplicationBoundariesSize().getX() ){
        delta = delta + Point( -screenSize.getX() ,0);
    }


    if( position.getY() < configuration_.GetDuplicationBoundariesSize().getY()){
        delta = delta + Point(0, screenSize.getY()+ position.getY());
    } else if( position.getY() > screenSize.getY() -configuration_.GetDuplicationBoundariesSize().getY() ){
        delta = delta + Point(0, -screenSize.getY());
    }

    if( delta != Point() ){
        normalDrawingSystem_.drawImage(type, position+delta, rotation, scale,
                                        actorId+configuration_.getBoundariesDuplicateActorIdOffset());
    }

}

void BoundariesDuplicationsDrawingSystem::addRemovedActorId(ActorId id) {
    normalDrawingSystem_.addRemovedActorId(id);
}
