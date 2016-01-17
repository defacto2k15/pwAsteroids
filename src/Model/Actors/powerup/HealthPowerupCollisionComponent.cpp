//
// Created by defacto on 2016.01.17..
//

#include "HealthPowerupCollisionComponent.h"

HealthPowerupCollisionComponent::HealthPowerupCollisionComponent(ContactComponentsContainer &contactContainer,
                                                                 std::shared_ptr<ActorsContainer> actorsContainer_,
                                                                 std::shared_ptr<MusicManager> musicManager_, RocketLife &rocketLife)
        : Box2dCollisionsComponent(contactContainer), actorsContainer_(actorsContainer_),
          musicManager_(musicManager_), rocketLife(rocketLife) {
}

void HealthPowerupCollisionComponent::OnStart(IActor &actor) {
    id_ = actor.getActorId();
    Box2dCollisionsComponent::OnStart(actor);
}

bool HealthPowerupCollisionComponent::manageCollision(CollisionData &data) {
    rocketLife.increaseLife();
    //musicManager_->addMusicElement(MusicElements::PowerupGainSound, 0.5f);
    actorsContainer_->removeActorById(id_);
}