//
// Created by defacto on 2015.12.28..
//

#include "RocketShootingComponent.h"

RocketShootingComponent::RocketShootingComponent(GameConfiguration &configuration, ProjectilesGenerator &projectilesGenerator,
                                                 std::shared_ptr<IInputStateProvider> inputStateProvider,
                                                 std::shared_ptr<GameTimeProvider> timeProvider, std::shared_ptr<MusicManager> musicManager)
        : configuration_(configuration), projectilesGenerator_(projectilesGenerator),
          inputStateProvider_(inputStateProvider), timeProvider_(timeProvider), musicManager_(musicManager) {
}

void RocketShootingComponent::OnStart(IActor &actor) {
    positionComponent_ = actor.getOnlyComponent<PositionComponent>();
    box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
}

void RocketShootingComponent::OnUpdate() {
    if( inputStateProvider_->wasClicked(Keys::Player1AttackKey) ){
        if( timeProvider_->getMilisecondsSinceGameStart() - timeOfLastShot_ > configuration_.getMinTimeBetweenShots()){
            timeOfLastShot_ = timeProvider_->getMilisecondsSinceGameStart();
            shootProjectile();
            musicManager_->addMusicElement(MusicElements::ShootSound, 0.7);
        }
    }
}

void RocketShootingComponent::shootProjectile() {
    auto rocketPosition = positionComponent_->getPosition();
    auto rocketRotation = positionComponent_->getRotation();

    auto distanceBetweenRocketAndProjectile = configuration_.getDistanceBetweenRocketAndProjectile();
    Point projectileAndRocketDelta = Point(
            distanceBetweenRocketAndProjectile * sin(DegreesCalculations::degreesToRadians(rocketRotation)),
            - distanceBetweenRocketAndProjectile * cos(DegreesCalculations::degreesToRadians(rocketRotation)));
    Point speedVector = projectileAndRocketDelta;
    speedVector.normalize();
    speedVector *= configuration_.getProjectileSpeed();
    //speedVector += box2dComponent_->getLineralVelocity();

    projectilesGenerator_.generateProjectile(rocketPosition + projectileAndRocketDelta,
                                              rocketRotation, speedVector, 0);
}