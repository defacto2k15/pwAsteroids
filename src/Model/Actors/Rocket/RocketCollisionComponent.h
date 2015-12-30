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
    ActorsConfiguration &actorsConfiguration_;
    RocketLife &rocketLife_;
    unsigned long lastTimeOfReset_ = 0;
    bool isRocketReseting_ = false;

    std::shared_ptr<DrawingComponent> drawingComponent_;
    std::shared_ptr<IPositionSettingComponent> positionSettingComponent_;
public:

    RocketCollisionComponent(ContactComponentsContainer &contactContainer, RocketLife &rocketLife_,
                             ActorsConfiguration &actorsConfiguration_,
                             std::shared_ptr<GameTimeProvider> timeProvider_)
            : Box2dCollisionsComponent( contactContainer), rocketLife_(rocketLife_),
              actorsConfiguration_(actorsConfiguration_), timeProvider_(timeProvider_) {
    }

    void OnStart( IActor &actor) override{
        Box2dCollisionsComponent::OnStart(actor);
        drawingComponent_ = actor.getOnlyComponent<DrawingComponent>();
        positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
    }

    void OnUpdate() override {
        Box2dCollisionsComponent::OnUpdate();
        if( isRocketReseting_ ){
            int timesImageIsFlickering = actorsConfiguration_.getTimesRocketImageIsFlickering();
            unsigned int timeOfOneFlicker = actorsConfiguration_.getTimeofOneFlicker();
            unsigned int currentTime = timeProvider_->getMilisecondsSinceGameStart() - lastTimeOfReset_;
            if( currentTime > timesImageIsFlickering * 2 * timeOfOneFlicker){
                isRocketReseting_ = false;
                return;
            }
            bool shouldRocketBeVisible = ((currentTime / timeOfOneFlicker)  % 2) == 1;
            drawingComponent_->setVisibility(shouldRocketBeVisible);
        } else {
            drawingComponent_->setVisibility(true);
        }
    }

private:
    bool manageCollision( double impulseValue ) override{
        if( impulseValue < 0.2){
            return false;
        }

        if( isRocketReseting_ ){
            return false;
        }

        isRocketReseting_ = true;
        rocketLife_.decreaseLife();
        positionSettingComponent_->setPosition(
                actorsConfiguration_.getInitialPosition().getX(), actorsConfiguration_.getInitialPosition().getY());
        lastTimeOfReset_ = timeProvider_->getMilisecondsSinceGameStart();
        return false;
    }

};


#endif //PWASTEROIDS_ROCKETCOLLISIONCOMPONENT_H
