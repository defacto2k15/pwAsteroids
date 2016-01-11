//
// Created by defacto on 2015.12.26..
//

#include "BoundariesDuplicationsDrawingSystem.h"

BoundariesDuplicationsDrawingSystem::BoundariesDuplicationsDrawingSystem(IDrawingSystem &normalDrawingSystem,
                                                                         GameConfiguration &configuration)
        : normalDrawingSystem_(normalDrawingSystem), configuration_(configuration) {
}

void BoundariesDuplicationsDrawingSystem::drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale,
                                                            ActorId actorId) {
    auto screenSize = configuration_.getBox2dScreenDimensions();
    std::cout << "ss is " << screenSize.toString() << std::endl;
    normalDrawingSystem_.drawImage(type, position, rotation, scale, actorId);
    Point delta;
    if( position.getX() < configuration_.getDuplicationBoundariesSize().getX()){
        delta = delta + Point(screenSize.getX()+ position.getX(), 0);
    } else if( position.getX() > screenSize.getX() -configuration_.getDuplicationBoundariesSize().getX() ){
        delta = delta + Point( -screenSize.getX() ,0);
    }


    if( position.getY() < configuration_.getDuplicationBoundariesSize().getY()){
        delta = delta + Point(0, screenSize.getY()+ position.getY());
    } else if( position.getY() > screenSize.getY() -configuration_.getDuplicationBoundariesSize().getY() ){
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
