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
                                ActorsConfiguration &configuration_) :
            indicatorPositionProvider_( indicatorPositionProvider_), gameTimeProvider_(gameTimeProvider_),
            inputStateProvider_(inputStateProvider_), asteroidGenerator_(asteroidGenerator_),
                                                                       configuration_(configuration_) {
    }

    virtual void OnStart(IActor &actor) override{
        positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
    }

    virtual void OnUpdate() override{
        Point mousePosition = inputStateProvider_->getMousePosition();
        std::cout << "Mouse position: " << mousePosition.toString() << std::endl;
        positionSettingComponent_->setPosition(mousePosition.getX(), mousePosition.getY());

        if( inputStateProvider_->isPressed( Keys::Player2AttackKey)) {
            if (gameTimeProvider_->getMilisecondsSinceGameStart()
                    > timeOfLastShoot_ + configuration_.getMinTimeBetweenSecondPlayerShoots()) {
                timeOfLastShoot_ = gameTimeProvider_->getMilisecondsSinceGameStart();
                Point newAsteroidVelocityVector = calculateVelocityVector();
                double asteroidSize = calculateAsteroidSize( newAsteroidVelocityVector);
                asteroidGenerator_->generateAsteroid( indicatorPositionProvider_->getBorderIndicatorPosition(),
                                                      0, asteroidSize, newAsteroidVelocityVector, 0);
            }
        }
    }

private:
    Point calculateVelocityVector(){
        Point firstPoint = indicatorPositionProvider_->getBorderIndicatorPosition();
        Point secondPoint = inputStateProvider_->getMousePosition();
        Point velocityVector = secondPoint - firstPoint;
        velocityVector.normalize();
        double distanceBetweenPoints = calculateDistanceBetweenPoints(firstPoint, secondPoint);
        velocityVector *= configuration_.getSecondPlayerAsteroidVelocityMultiplayer()*distanceBetweenPoints;
        return velocityVector;
    }

    double calculateAsteroidSize( Point velocityVector ){
        double distance = sqrt( pow(velocityVector.getX(),2) + pow(velocityVector.getY(),2));
        double size = configuration_.getSecondPlayerAsteroidSizeDivider()/distance;
        size = std::max(size , configuration_.getMinSecondPlayerAsteroidSize());
        size = std::min(size , configuration_.getMaxSecondPlayerAsteroidSize());
        return size;
    }

    double calculateDistanceBetweenPoints( Point p1, Point p2){
        double distanceBetweenPoints = sqrt( pow(p1.getX()-p2.getX(),2) + (p1.getY()-p2.getY(),2) );
        return distanceBetweenPoints;
    }

};


#endif //PWASTEROIDS_SECONDPLAYERTARGETCOMPONENT_H
