//
// Created by defacto on 2015.12.29..
//

#include "RocketCollisionComponent.h"

RocketCollisionComponent::RocketCollisionComponent(ContactComponentsContainer &contactContainer, RocketLife &rocketLife_,
                                                   ActorsConfiguration &actorsConfiguration_,
                                                   std::shared_ptr<GameTimeProvider> timeProvider_)
        : Box2dCollisionsComponent(contactContainer), rocketLife_(rocketLife_),
          actorsConfiguration_(actorsConfiguration_), timeProvider_(timeProvider_) {
}

void RocketCollisionComponent::OnStart(IActor &actor) {
    Box2dCollisionsComponent::OnStart(actor);
    drawingComponent_ = actor.getOnlyComponent<DrawingComponent>();
    positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
}

void RocketCollisionComponent::OnUpdate() {
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

bool RocketCollisionComponent::manageCollision(double impulseValue ) {
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