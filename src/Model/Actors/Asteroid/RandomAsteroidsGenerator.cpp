//
// Created by defacto on 2015.12.26..
//

#include "RandomAsteroidsGenerator.h"

RandomAsteroidsGenerator::RandomAsteroidsGenerator(AsteroidsGenerator &asteroidsGenerator_, AsteroidsCounter &asteroidsCounter_,
                                                   GameConfiguration &configuration_, std::shared_ptr<GameTimeProvider> &timeProvider_,
                                                   RandomNumbersProvider &provider_, PythonModule &python)
        : asteroidsGenerator_(asteroidsGenerator_), asteroidsCounter_(asteroidsCounter_),
          configuration_(configuration_), timeProvider_(timeProvider_), provider_(provider_), python_(python) {

}

void RandomAsteroidsGenerator::OnUpdate() {
    if( timeProvider_->getMilisecondsSinceGameStart() - timeOfLastAsteroidCreation_
        > configuration_.getMinTimeBetweenAsteroidsCreation()) {
        if (provider_.getRandomBool(configuration_.getAsteroidCreationPropabilityRatio())) {
            if( asteroidsCounter_.getValue() < configuration_.getMaxAsteroidsCount() ) {
                timeOfLastAsteroidCreation_ = timeProvider_->getMilisecondsSinceGameStart();
                createAsteroid();
            }
        }
    }
}

void RandomAsteroidsGenerator::createAsteroid() {
    Point asteroidsGenerationScreenSize(
            configuration_.getBox2dScreenDimensions().getX() + (configuration_.getAsteroidsGenerationBoundariesSize().getX()*2),
            configuration_.getBox2dScreenDimensions().getY() + (configuration_.getAsteroidsGenerationBoundariesSize().getY()*2));
    Rect borderCircuit ( Point(
                                 -configuration_.getAsteroidsGenerationBoundariesSize().getX(),
                                 -configuration_.getAsteroidsGenerationBoundariesSize().getY()),
                         Point(asteroidsGenerationScreenSize.getX(), asteroidsGenerationScreenSize.getY()));
    double circuitLength = borderCircuit.getLength();
    double x = provider_.getRandomDouble(0,circuitLength);
    Point creationPosition = borderCircuit.getPointByLength(x);

    double targetLength = fmod (provider_.getRandomDouble( 0.25*circuitLength, 0.75*circuitLength) + x, circuitLength);
    Point targetPointOfAcceleration = borderCircuit.getPointByLength(targetLength);

    Point accelerationNormalVector = targetPointOfAcceleration - creationPosition;
    accelerationNormalVector.normalize();

    auto accelerationVector  = accelerationNormalVector *= provider_.getRandomDouble(
            configuration_.getAsteroidMinInitialImpulse(), configuration_.getAsteroidMaxInitialImpulse());
    Rotation newRotation = DegreesCalculations::degreesToRadians(provider_.getRandom(360) );

    double size = provider_.getRandomDouble(configuration_.getAsteroidMinSize(), configuration_.getAsteroidMaxSize());
    double rotationSpeed = provider_.getRandomDouble(0, configuration_.getAsteroidMaxRotationSpeed());
    // todo - size is not used for now!
    if( generatorEnabled ) {
        asteroidsGenerator_.generateAsteroid(creationPosition, newRotation, 1, accelerationVector, rotationSpeed);
    }
}

void RandomAsteroidsGenerator::OnStart() {
    std::function<void(void) > enable =  [this](){ enableAsteroidsGeneration(); };
    python_.addRootFunction("enableAsteroidsGeneration", enable);
    std::function<void(void) > disable =  [this](){ disableAsteroidsGeneration(); };
    python_.addRootFunction("disableAsteroidsGeneration", disable);
}

void RandomAsteroidsGenerator::enableAsteroidsGeneration() {
    generatorEnabled = true;
}

void RandomAsteroidsGenerator::disableAsteroidsGeneration() {
    generatorEnabled = false;
}