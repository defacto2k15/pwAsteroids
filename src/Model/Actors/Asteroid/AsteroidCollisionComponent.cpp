//
// Created by defacto on 2015.12.29..
//
#include <iostream>
#include "AsteroidCollisionComponent.h"

#include <Model/Actors/Asteroid/AsteroidsGenerator.h>

AsteroidCollisionComponent::AsteroidCollisionComponent(ContactComponentsContainer &contactContainer, std::shared_ptr<ActorsContainer> actorsContainer,
                                                       AsteroidsGenerator &asteroidsGenerator)
        : Box2dCollisionsComponent(contactContainer), actorsContainer_(actorsContainer),
          asteroidsGenerator_( asteroidsGenerator) {
}

void AsteroidCollisionComponent::OnStart(IActor &actor ) {
    Box2dCollisionsComponent::OnStart(actor);
    positionComponent_ = actor.getOnlyComponent<PositionComponent>();
    id_ = actor.getActorId();
    size_ = actor.getOnlyComponent<AsteroidSizeComponent>()->getSize();
}

bool AsteroidCollisionComponent::manageCollision(double impulseValue ) {
    double minCollisionImpulseValueToManage = 0.4;
    double destructionMassFactor = 0.50f;
    double asteroidMass = box2dComponent_->getMass();


    if( impulseValue < minCollisionImpulseValueToManage){
        return false;
    }

    if( impulseValue > destructionMassFactor*asteroidMass){
        actorsContainer_->removeActorById(id_);
        return true;
    }


    createAsteroidAtAngleRelativeToCurrentAsteroid( impulseValue, 90, 2);
    createAsteroidAtAngleRelativeToCurrentAsteroid( impulseValue, 270, 2);
    actorsContainer_->removeActorById(id_);
    return true;
}

void AsteroidCollisionComponent::createAsteroidAtAngleRelativeToCurrentAsteroid(double impulseValue, Rotation angle,
            int partsOfAsteroid) {
    double distanceBetweenAsteroids = 0.1f;
    double massDissappearanceFactor = 0.9f;
    double impulseToSpeedRatio = 0.5f;

    double sizeOfNewAsteroids = sqrt( (size_*massDissappearanceFactor)/partsOfAsteroid );
    double asteroidMass = box2dComponent_->getMass();
    Point originalBoxDimensions = box2dComponent_->getBoxSize();

    Point firstAsteroidPosition = positionComponent_->getPosition();
    Point oldSpeedVector = box2dComponent_->getLineralVelocity();
    Rotation firstAsteroidAngle =  atan2( oldSpeedVector.getY(), oldSpeedVector.getX() )  + angle;

    Point newAsteroidVector( cos(DegreesCalculations::degreesToRadians(firstAsteroidAngle)),
                             -sin(DegreesCalculations::degreesToRadians(firstAsteroidAngle)));
    newAsteroidVector.normalize();

    firstAsteroidPosition += newAsteroidVector * distanceBetweenAsteroids;
    firstAsteroidPosition += newAsteroidVector * (originalBoxDimensions.getY() / 2);

    Point newAsteroidSpeedVector = box2dComponent_->getLineralVelocity();
    newAsteroidSpeedVector += newAsteroidVector * ((impulseValue * impulseToSpeedRatio ) / asteroidMass );


    asteroidsGenerator_.generateAsteroid(firstAsteroidPosition, positionComponent_->getRotation(),
                                         sizeOfNewAsteroids, newAsteroidSpeedVector, 0);
}