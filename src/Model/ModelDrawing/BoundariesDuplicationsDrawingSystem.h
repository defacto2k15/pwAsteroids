//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_BOUNDARIESDUPLICATIONSDRAWINGSYSTEM_H
#define PWASTEROIDS_BOUNDARIESDUPLICATIONSDRAWINGSYSTEM_H


#include "IDrawingSystem.h"
#include <memory>
#include <Model/configuration/ActorsConfiguration.h>

class BoundariesDuplicationsDrawingSystem : public IDrawingSystem{
     std::shared_ptr<IDrawingSystem> normalDrawingSystem_;
     ActorsConfiguration &configuration_;
public:
    BoundariesDuplicationsDrawingSystem(std::shared_ptr<IDrawingSystem> normalDrawingSystem,
                                        ActorsConfiguration &configuration);

    virtual void drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale,
                           ActorId actorId);

    virtual void drawText( std::string textValue, Point position, ActorId actorId){
        normalDrawingSystem_->drawText(textValue, position, actorId);
    }
};


#endif //PWASTEROIDS_BOUNDARIESDUPLICATIONSDRAWINGSYSTEM_H
