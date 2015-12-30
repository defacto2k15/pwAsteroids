//
// Created by defacto on 2015.12.28..
//

#include "RocketShootingComponent.h"

RocketShootingComponent::RocketShootingComponent(ActorsConfiguration &configuration, std::shared_ptr<ProjectilesGenerator> projectilesGenerator,
                                                 std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider, std::shared_ptr<GameTimeProvider> timeProvider )
        : configuration_(configuration), projectilesGenerator_(projectilesGenerator),
          keyboardStateProvider_(keyboardStateProvider), timeProvider_(timeProvider) {
    int todoDelete = 44;
}

void RocketShootingComponent::OnStart(IActor &actor) {
    positionComponent_ = actor.getOnlyComponent<PositionComponent>();
    box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
}

void RocketShootingComponent::OnUpdate() {
    if( keyboardStateProvider_->wasClicked(Keys::Player1AttackKey) ){
        if( timeProvider_->getMilisecondsSinceGameStart() - timeOfLastShot_ > configuration_.getMinTimeBetweenShots()){
            timeOfLastShot_ = timeProvider_->getMilisecondsSinceGameStart();
            shootProjectile();
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

    projectilesGenerator_->generateProjectile(rocketPosition + projectileAndRocketDelta,
                                              rocketRotation, speedVector, 0);
}