//
// Created by defacto on 2016.01.01..
//

#ifndef PWASTEROIDS_SECONDPLAYERTARGETCOMPONENT_H
#define PWASTEROIDS_SECONDPLAYERTARGETCOMPONENT_H


#include <Model/components/PositionComponent.h>
#include "IBorderIndicatorPositionProvider.h"
#include <memory>
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/components/IPositionSettingComponent.h>
#include <Model/modelInterfaces/IInputStateProvider.h>
#include <Model/Services/GameTimeProvider.h>
#include <algorithm>
#include <Model/Actors/Asteroid/AsteroidsGenerator.h>

class SecondPlayerTargetComponent : public Component {
    std::shared_ptr<IBorderIndicatorPositionProvider> indicatorPositionProvider_;
    std::shared_ptr<GameTimeProvider> gameTimeProvider_;
    std::shared_ptr<IInputStateProvider> inputStateProvider_;
    std::shared_ptr<AsteroidsGenerator> asteroidGenerator_;

    ActorsConfiguration &configuration_;

    std::shared_ptr<IPositionSettingComponent> positionSettingComponent_;
    unsigned long timeOfLastShoot_ = 0;
public:

    SecondPlayerTargetComponent(std::shared_ptr<IBorderIndicatorPositionProvider> indicatorPositionProvider_,
                                std::shared_ptr<GameTimeProvider> gameTimeProvider_,
                                std::shared_ptr<IInputStateProvider> inputStateProvider_,
                                std::shared_ptr<AsteroidsGenerator> asteroidGenerator_,
                                ActorsConfiguration &configuration_);

    virtual void OnStart(IActor &actor);

    virtual void OnUpdate();

private:
    Point calculateVelocityVector();

    double calculateAsteroidSize(Point velocityVector );

    double calculateDistanceBetweenPoints(Point p1, Point p2);

};


#endif //PWASTEROIDS_SECONDPLAYERTARGETCOMPONENT_H
