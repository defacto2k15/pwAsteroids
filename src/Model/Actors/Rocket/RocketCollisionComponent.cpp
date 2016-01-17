//
// Created by defacto on 2015.12.29..
//

#include "RocketCollisionComponent.h"

RocketCollisionComponent::RocketCollisionComponent(ContactComponentsContainer &contactContainer, RocketLife &rocketLife_,
                                                   GameConfiguration &gameConfiguration_, std::shared_ptr<GameTimeProvider> timeProvider_,
                                                   std::shared_ptr<MusicManager> musicManager)
        : Box2dCollisionsComponent(contactContainer), rocketLife_(rocketLife_),
          gameConfiguration_(gameConfiguration_), timeProvider_(timeProvider_), musicManager_(musicManager) {
}

void RocketCollisionComponent::OnStart(IActor &actor) {
    Box2dCollisionsComponent::OnStart(actor);
    drawingComponent_ = actor.getOnlyComponent<DrawingComponent>();
    positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
}

void RocketCollisionComponent::OnUpdate() {
    Box2dCollisionsComponent::OnUpdate();
    if( isRocketReseting_ ){
        int timesImageIsFlickering = gameConfiguration_.getTimesRocketImageIsFlickering();
        unsigned int timeOfOneFlicker = gameConfiguration_.getTimeofOneFlicker();
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

bool RocketCollisionComponent::manageCollision(CollisionData &data ) {
    if( data.collisionGroup == CollisionGroup_Powerup ){
        return false;
    }
    double impulseValue = data.impulseValue;
    if( impulseValue < 0.004){
        return false;
    }

    if( isRocketReseting_ ){
        return false;
    }

    isRocketReseting_ = true;
    musicManager_->addMusicElement(MusicElements::RocketDestructionSound, 0.6);
    rocketLife_.decreaseLife();
    positionSettingComponent_->setPosition(
            gameConfiguration_.getInitialPosition().getX(), gameConfiguration_.getInitialPosition().getY());
    lastTimeOfReset_ = timeProvider_->getMilisecondsSinceGameStart();
    return false;
}