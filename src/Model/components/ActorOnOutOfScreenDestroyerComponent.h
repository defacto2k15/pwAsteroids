//
// Created by defacto on 2015.12.27..
//

#ifndef PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H
#define PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H


#include <Model/configuration/ActorsConfiguration.h>
#include <Model/Services/ActorsContainer.h>
#include "Component.h"
#include "PositionComponent.h"

class ActorOnOutOfScreenDestroyerComponent : public Component {
    ActorsConfiguration &configuration_;
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorId actorId_;
    std::shared_ptr<PositionComponent> positionComponent_;
public:

    ActorOnOutOfScreenDestroyerComponent(ActorsConfiguration &configuration_,
                                         std::shared_ptr<ActorsContainer> &actorsContainer_) : configuration_(
            configuration_), actorsContainer_(actorsContainer_) {
    }

    void OnStart( IActor &actor )override {
        actorId_ = actor.getActorId();
        positionComponent_ = actor.getOnlyComponent<PositionComponent>();
    }

    void OnUpdate() override {
        Point position = positionComponent_->getPosition();
        if( configuration_.getActorsDestroyRectangle().isPointInRectangle(position) == false){
            actorsContainer_->removeActorById(actorId_);
        }
    }
};


#endif //PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H
