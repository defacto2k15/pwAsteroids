//
// Created by defacto on 2016.01.16..
//

#include "TemporaryRocketShootingComponent.h"

TemporaryRocketShootingComponent::TemporaryRocketShootingComponent(GameConfiguration &configuration, ProjectilesGenerator &projectilesGenerator,
                                                                   const std::shared_ptr<IInputStateProvider> &inputStateProvider,
                                                                   const std::shared_ptr<GameTimeProvider> &timeProvider,
                                                                   const std::shared_ptr<MusicManager> &musicManager, const Rotation &angleOfShoot)
        : RocketShootingComponent(configuration, projectilesGenerator, inputStateProvider, timeProvider,
                                  musicManager, angleOfShoot), timeProvider_(timeProvider), gameConfiguration_(configuration) {
}

void TemporaryRocketShootingComponent::OnStart(IActor &actor) {
    rocketActor_ = &actor;
    creationTime_ = timeProvider_->getMilisecondsSinceGameStart();
    RocketShootingComponent::OnStart(actor);
}

void TemporaryRocketShootingComponent::OnUpdate() {
    if( timeProvider_->getMilisecondsSinceGameStart() - creationTime_
        > gameConfiguration_.getTemporaryRocketShootingComponentLifeTime()){
        rocketActor_->removeComponent(this);
    } else {
        RocketShootingComponent::OnUpdate();
    }
}