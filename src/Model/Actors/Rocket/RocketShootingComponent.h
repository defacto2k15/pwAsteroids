//
// Created by defacto on 2015.12.28..
//

#ifndef PWASTEROIDS_ROCKETSHOOTINGCOMPONENT_H
#define PWASTEROIDS_ROCKETSHOOTINGCOMPONENT_H


#include <Model/components/Component.h>
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/components/PositionComponent.h>
#include <Model/Actors/Projectile/ProjectilesGenerator.h>
#include <Model/Services/GameTimeProvider.h>

class RocketShootingComponent : public Component {
    std::shared_ptr<PositionComponent> positionComponent_;
    std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider_;
    std::shared_ptr<GameTimeProvider> timeProvider_;
    std::shared_ptr<Box2dComponent> box2dComponent_;
    ActorsConfiguration &configuration_;
    std::shared_ptr<ProjectilesGenerator> projectilesGenerator_;

    unsigned long timeOfLastShot_ = 0;
public:
    RocketShootingComponent(ActorsConfiguration &configuration, std::shared_ptr<ProjectilesGenerator> projectilesGenerator,
            std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider, std::shared_ptr<GameTimeProvider> timeProvider ) :
            configuration_(configuration), projectilesGenerator_(projectilesGenerator),
            keyboardStateProvider_(keyboardStateProvider), timeProvider_(timeProvider) {
        int todoDelete = 44;
    }

    void OnStart(IActor &actor) override{
        positionComponent_ = actor.getOnlyComponent<PositionComponent>();
        box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
    }

    void OnUpdate() override {
        if( keyboardStateProvider_->wasClicked(Keys::Player1AttackKey) ){
            if( timeProvider_->getMilisecondsSinceGameStart() - timeOfLastShot_ > configuration_.getMinTimeBetweenShots()){
                timeOfLastShot_ = timeProvider_->getMilisecondsSinceGameStart();
                shootProjectile();
            }
        }
    }

private:
    void shootProjectile(){
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
};


#endif //PWASTEROIDS_ROCKETSHOOTINGCOMPONENT_H
