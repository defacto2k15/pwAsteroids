//
// Created by defacto on 2015.12.29..
//
#include <iostream>
#include "AsteroidCollisionComponent.h"

#include <Model/Actors/Asteroid/AsteroidsGenerator.h>

AsteroidCollisionComponent::AsteroidCollisionComponent(ContactComponentsContainer &contactContainer,
                                                       std::shared_ptr<ActorsContainer> actorsContainer, AsteroidsGenerator &asteroidsGenerator,
                                                       std::shared_ptr<MusicManager> musicManager, ExplosionCloudGenerator &cloudGenerator)
        : Box2dCollisionsComponent(contactContainer), actorsContainer_(actorsContainer),
          asteroidsGenerator_( asteroidsGenerator), musicManager_(musicManager), cloudGenerator_(cloudGenerator) {
}

void AsteroidCollisionComponent::OnStart(IActor &actor ) {
    Box2dCollisionsComponent::OnStart(actor);
    positionComponent_ = actor.getOnlyComponent<PositionComponent>();
    box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
    id_ = actor.getActorId();
    size_ = actor.getOnlyComponent<AsteroidSizeComponent>()->getSize();
}

bool AsteroidCollisionComponent::manageCollision(CollisionData &data ) {
    double minCollisionImpulseValueToManage = 1.2;
    double destructionMassFactor = 0.20f;
    double asteroidMass = box2dComponent_->getMass();

    double impulseValue = data.impulseValue;

    if( impulseValue < destructionMassFactor * asteroidMass*0.51){
        return false;
    }

    if( (box2dComponent_->getBody()->GetMass() > data.otherContacterFixture->GetBody()->GetMass()) ||
        (( box2dComponent_->getBody()->GetMass() == data.otherContacterFixture->GetBody()->GetMass() ) &&
                (box2dComponent_->getBody()->GetPosition().x >= data.otherContacterFixture->GetBody()->GetPosition().x))){
        auto ourPos = box2dComponent_->getBody()->GetPosition();
        auto theirPos = data.otherContacterFixture->GetBody()->GetPosition();
        Point cloudPos( (ourPos.x + theirPos.x)/2, (ourPos.y + theirPos.y) / 2);
        cloudGenerator_.generateExplosionCloud(cloudPos,  box2dComponent_->getBoxSize().getX()*6);
    }

    musicManager_->addMusicElement(MusicElements::AsteroidCollisionSound, sqrt(asteroidMass / 40) );
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
    double distanceBetweenAsteroids = 0.02f;
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