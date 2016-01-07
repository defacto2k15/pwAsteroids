//
// Created by defacto on 2016.01.01..
//

#include "SecondPlayerTargetComponent.h"

SecondPlayerTargetComponent::SecondPlayerTargetComponent(std::shared_ptr<IBorderIndicatorPositionProvider> indicatorPositionProvider_,
                                                         std::shared_ptr<GameTimeProvider> gameTimeProvider_,
                                                         std::shared_ptr<IInputStateProvider> inputStateProvider_,
                                                         AsteroidsGenerator &asteroidGenerator_,
                                                         GameConfiguration &configuration_,
                                                         std::shared_ptr<MusicManager> musicManager)
        : indicatorPositionProvider_(indicatorPositionProvider_), gameTimeProvider_(gameTimeProvider_),
          inputStateProvider_(inputStateProvider_), asteroidGenerator_(asteroidGenerator_),
          configuration_(configuration_), musicManager_(musicManager) {
}

void SecondPlayerTargetComponent::OnStart(IActor &actor) {
    positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
}

void SecondPlayerTargetComponent::OnUpdate() {
    Point mousePosition = inputStateProvider_->getMousePosition();
    positionSettingComponent_->setPosition(mousePosition.getX(), mousePosition.getY());

    if( inputStateProvider_->isPressed( Keys::Player2AttackKey)) {
        if (gameTimeProvider_->getMilisecondsSinceGameStart()
            > timeOfLastShoot_ + configuration_.getMinTimeBetweenSecondPlayerShoots()) {
            timeOfLastShoot_ = gameTimeProvider_->getMilisecondsSinceGameStart();
            Point newAsteroidVelocityVector = calculateVelocityVector();
            double asteroidSize = calculateAsteroidSize( newAsteroidVelocityVector);
            asteroidGenerator_.generateAsteroid( indicatorPositionProvider_->getBorderIndicatorPosition(),
                                                  0, asteroidSize, newAsteroidVelocityVector, 0);
            musicManager_->addMusicElement(MusicElements::SecondPlayerAsteroidShoot, 0.8);
        }
    }
}

Point SecondPlayerTargetComponent::calculateVelocityVector() {
    Point firstPoint = indicatorPositionProvider_->getBorderIndicatorPosition();
    Point secondPoint = inputStateProvider_->getMousePosition();
    Point velocityVector = secondPoint - firstPoint;
    velocityVector.normalize();
    double distanceBetweenPoints = calculateDistanceBetweenPoints(firstPoint, secondPoint);
    velocityVector *= configuration_.getSecondPlayerAsteroidVelocityMultiplayer()*distanceBetweenPoints;
    return velocityVector;
}

double SecondPlayerTargetComponent::calculateAsteroidSize(Point velocityVector ) {
    double distance = sqrt( pow(velocityVector.getX(),2) + pow(velocityVector.getY(),2));
    double size = configuration_.getSecondPlayerAsteroidSizeDivider()/distance;
    size = std::max(size , configuration_.getMinSecondPlayerAsteroidSize());
    size = std::min(size , configuration_.getMaxSecondPlayerAsteroidSize());
    size = sqrt(size);
    return size;
}

double SecondPlayerTargetComponent::calculateDistanceBetweenPoints(Point p1, Point p2) {
    double distanceBetweenPoints = sqrt( pow(p1.getX()-p2.getX(),2) + (p1.getY()-p2.getY(),2) );
    return distanceBetweenPoints;
}