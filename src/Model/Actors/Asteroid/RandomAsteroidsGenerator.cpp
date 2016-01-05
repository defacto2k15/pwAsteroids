//
// Created by defacto on 2015.12.26..
//

#include "RandomAsteroidsGenerator.h"

RandomAsteroidsGenerator::RandomAsteroidsGenerator(AsteroidsGenerator &asteroidsGenerator_,
                                                   AsteroidsCounter &asteroidsCounter_,
                                                   GameConfiguration &configuration_,
                                                   std::shared_ptr<GameTimeProvider> &timeProvider_,
                                                   RandomNumbersProvider &provider_)
        : asteroidsGenerator_(asteroidsGenerator_), asteroidsCounter_(asteroidsCounter_),
          configuration_(configuration_), timeProvider_(timeProvider_), provider_(provider_) {

}

void RandomAsteroidsGenerator::OnUpdate() {
    if( timeProvider_->getMilisecondsSinceGameStart() - timeOfLastAsteroidCreation_
        > configuration_.GetMinTimeBetweenAsteroidsCreation()) {
        if (provider_.getRandomBool(configuration_.getAsteroidCreationPropabilityRatio())) {
            if( asteroidsCounter_.getValue() < configuration_.GetMaxAsteroidsCount() ) {
                timeOfLastAsteroidCreation_ = timeProvider_->getMilisecondsSinceGameStart();
                createAsteroid();
            }
        }
    }
}

void RandomAsteroidsGenerator::createAsteroid() {
    Point asteroidsGenerationScreenSize(
            configuration_.getBox2dScreenDimensions().getX() + (configuration_.GetAsteroidsGenerationBoundariesSize().getX()*2),
            configuration_.getBox2dScreenDimensions().getY() + (configuration_.GetAsteroidsGenerationBoundariesSize().getY()*2));
    Rect borderCircuit ( Point(
                                 -configuration_.GetAsteroidsGenerationBoundariesSize().getX(),
                                 -configuration_.GetAsteroidsGenerationBoundariesSize().getY()),
                         Point(asteroidsGenerationScreenSize.getX(), asteroidsGenerationScreenSize.getY()));
    double circuitLength = borderCircuit.getLength();
    double x = provider_.getRandomDouble(0,circuitLength);
    Point creationPosition = borderCircuit.getPointByLength(x);

    double targetLength = fmod (provider_.getRandomDouble( 0.25*circuitLength, 0.75*circuitLength) + x, circuitLength);
    Point targetPointOfAcceleration = borderCircuit.getPointByLength(targetLength);

    Point accelerationNormalVector = targetPointOfAcceleration - creationPosition;
    accelerationNormalVector.normalize();

    auto accelerationVector  = accelerationNormalVector *= provider_.getRandomDouble(
            configuration_.GetAsteroidMinInitialImpulse(), configuration_.GetAsteroidMaxInitialImpulse());
    Rotation newRotation = DegreesCalculations::degreesToRadians(provider_.getRandom(360) );

    double size = provider_.getRandomDouble(configuration_.GetAsteroidMinSize(), configuration_.GetAsteroidMaxSize());
    double rotationSpeed = provider_.getRandomDouble(0, configuration_.GetAsteroidMaxRotationSpeed());
    // todo - size is not used for now!
    asteroidsGenerator_.generateAsteroid(creationPosition, newRotation, 1, accelerationVector, rotationSpeed  );
}

