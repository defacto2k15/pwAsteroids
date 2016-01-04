//
// Created by defacto on 2015.12.29..
//

#include "ProjectileCollisionComponent.h"

ProjectileCollisionComponent::ProjectileCollisionComponent(ContactComponentsContainer &contactContainer,
                                                           const std::shared_ptr<ActorsContainer> actorsContainer,
                                                            ScoreCount &scoreCount,
                                                            GameConfiguration &configuration)
        : Box2dCollisionsComponent(
        contactContainer), actorsContainer_(actorsContainer), scoreCount_(scoreCount), gameConfiguration_(configuration) {
}

void ProjectileCollisionComponent::OnStart(IActor &actor ) {
    Box2dCollisionsComponent::OnStart(actor);
    id_ = actor.getActorId();
}

bool ProjectileCollisionComponent::manageCollision(double impulseValue ) {
    actorsContainer_->removeActorById(id_);
    scoreCount_.addScore( gameConfiguration_.getScoreByDestroyingAsteroid());
    return true;
}