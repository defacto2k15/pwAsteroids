//
// Created by defacto on 2015.12.27..
//

#include "ActorOnOutOfScreenDestroyerComponent.h"

ActorOnOutOfScreenDestroyerComponent::ActorOnOutOfScreenDestroyerComponent(GameConfiguration &configuration_,
                                                                           std::shared_ptr<ActorsContainer> &actorsContainer_)
        : configuration_(
        configuration_), actorsContainer_(actorsContainer_) {
}

void ActorOnOutOfScreenDestroyerComponent::OnStart(IActor &actor ) {
    actorId_ = actor.getActorId();
    positionComponent_ = actor.getOnlyComponent<PositionComponent>();
}

void ActorOnOutOfScreenDestroyerComponent::OnUpdate() {
    Point position = positionComponent_->getPosition();
    if( configuration_.getActorsDestroyRectangle().isPointInRectangle(position) == false){
        actorsContainer_->removeActorById(actorId_);
    }
}