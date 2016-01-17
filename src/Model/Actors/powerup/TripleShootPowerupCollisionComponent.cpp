//
// Created by defacto on 2016.01.16..
//

#include "TripleShootPowerupCollisionComponent.h"

TripleShootPowerupCollisionComponent::TripleShootPowerupCollisionComponent(ContactComponentsContainer &contactContainer,
                                                                           std::shared_ptr<ActorsContainer> &actorsContainer_,
                                                                           std::shared_ptr<IActor> rocketActor_,
                                                                           GameConfiguration &configuration,
                                                                           ProjectilesGenerator &projectilesGenerator,
                                                                           std::shared_ptr<IInputStateProvider> &inputStateProvider_,
                                                                           std::shared_ptr<MusicManager> &musicManager_,
                                                                           std::shared_ptr<GameTimeProvider> &timeProvider_)
        : Box2dCollisionsComponent(
        contactContainer), actorsContainer_(actorsContainer_), rocketActor_(rocketActor_), configuration(
        configuration), projectilesGenerator(projectilesGenerator), inputStateProvider_(inputStateProvider_),
          musicManager_(
                  musicManager_),
          timeProvider_(
                  timeProvider_) {
}

void TripleShootPowerupCollisionComponent::OnStart(IActor &actor) {
    id = actor.getActorId();
    Box2dCollisionsComponent::OnStart(actor);
}

bool TripleShootPowerupCollisionComponent::manageCollision(CollisionData &data ) {
    if( rocketActor_->isComponentPresent<TemporaryRocketShootingComponent>() == false) {
        rocketActor_->addComponent(createTemporaryRocketShootingComponent(-30));
        rocketActor_->addComponent(createTemporaryRocketShootingComponent(30));
    }
    musicManager_->addMusicElement(MusicElements::PowerupGainSound, 0.5);
    actorsContainer_->removeActorById(id);
    return true;
}

std::shared_ptr<Component> TripleShootPowerupCollisionComponent::createTemporaryRocketShootingComponent(double angle) {
    auto tempComponent = std::make_shared<TemporaryRocketShootingComponent>(
            configuration, projectilesGenerator, inputStateProvider_, timeProvider_, musicManager_,  Rotation(angle) );
    return  tempComponent;
}