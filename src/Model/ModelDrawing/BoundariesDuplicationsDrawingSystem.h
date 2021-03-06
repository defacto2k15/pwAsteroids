//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_BOUNDARIESDUPLICATIONSDRAWINGSYSTEM_H
#define PWASTEROIDS_BOUNDARIESDUPLICATIONSDRAWINGSYSTEM_H


#include "IDrawingSystem.h"
#include <memory>
#include <Model/configuration/GameConfiguration.h>

class BoundariesDuplicationsDrawingSystem : public IDrawingSystem{
     IDrawingSystem &normalDrawingSystem_;
     GameConfiguration &configuration_;
public:
    BoundariesDuplicationsDrawingSystem(IDrawingSystem &normalDrawingSystem,
                                        GameConfiguration &configuration);

    virtual void drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale,
                           ActorId actorId);

    virtual void drawText( std::string textValue, Point position, ActorId actorId){
        normalDrawingSystem_.drawText(textValue, position, actorId);
    }

    virtual void addRemovedActorId(ActorId id) override;
};


#endif //PWASTEROIDS_BOUNDARIESDUPLICATIONSDRAWINGSYSTEM_H
