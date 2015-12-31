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
                            std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider, std::shared_ptr<GameTimeProvider> timeProvider );

    void OnStart(IActor &actor);

    void OnUpdate();

private:
    void shootProjectile();
};


#endif //PWASTEROIDS_ROCKETSHOOTINGCOMPONENT_H