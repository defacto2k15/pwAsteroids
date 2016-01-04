//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_ROCKETCOLLISIONCOMPONENT_H
#define PWASTEROIDS_ROCKETCOLLISIONCOMPONENT_H

#include <iostream>
#include <Model/components/Component.h>
#include <Model/collisions/Box2dCollisionsComponent.h>
#include <Model/Services/GameTimeProvider.h>
#include <Model/components/DrawingComponent.h>
#include "RocketLife.h"

class RocketCollisionComponent : public Box2dCollisionsComponent {
    std::shared_ptr<GameTimeProvider> timeProvider_;
    GameConfiguration &gameConfiguration_;
    RocketLife &rocketLife_;
    unsigned long lastTimeOfReset_ = 0;
    bool isRocketReseting_ = false;

    std::shared_ptr<DrawingComponent> drawingComponent_;
    std::shared_ptr<IPositionSettingComponent> positionSettingComponent_;
public:

    RocketCollisionComponent(ContactComponentsContainer &contactContainer, RocketLife &rocketLife_,
                             GameConfiguration &gameConfiguration_,
                             std::shared_ptr<GameTimeProvider> timeProvider_);

    void OnStart(IActor &actor);

    void OnUpdate();

private:
    bool manageCollision(double impulseValue );

};


#endif //PWASTEROIDS_ROCKETCOLLISIONCOMPONENT_H
