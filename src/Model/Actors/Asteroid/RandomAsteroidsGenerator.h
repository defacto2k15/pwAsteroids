//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_RANDOMASTEROIDSGENERATOR_H
#define PWASTEROIDS_RANDOMASTEROIDSGENERATOR_H


#include <Model/help/RandomNumbersProvider.h>
#include <Model/Services/GameTimeProvider.h>
#include "AsteroidsGenerator.h"
#include <iostream>

class RandomAsteroidsGenerator : public IService{
    std::shared_ptr<AsteroidsGenerator> asteroidsGenerator_;
    std::shared_ptr<AsteroidsCounter> asteroidsCounter_;
    ActorsConfiguration &configuration_;
    std::shared_ptr<GameTimeProvider> timeProvider_;
    RandomNumbersProvider &provider_;
    unsigned int timeOfLastAsteroidCreation_ = 0;
public:
    RandomAsteroidsGenerator(std::shared_ptr<AsteroidsGenerator> &asteroidsGenerator_,
                             std::shared_ptr<AsteroidsCounter> &asteroidsCounter_,
                             ActorsConfiguration &configuration_,
                             std::shared_ptr<GameTimeProvider> &timeProvider_,
                             RandomNumbersProvider &provider_)
            : asteroidsGenerator_(asteroidsGenerator_), asteroidsCounter_(asteroidsCounter_),
              configuration_(configuration_), timeProvider_(timeProvider_), provider_(provider_) {

    }

    void OnUpdate(){
        if( timeProvider_->getMilisecondsSinceGameStart() - timeOfLastAsteroidCreation_
                > configuration_.GetMinTimeBetweenAsteroidsCreation()) {
            if (provider_.getRandomBool(configuration_.getAsteroidCreationPropabilityRatio())) {
                if( asteroidsCounter_->getValue() < configuration_.GetMaxAsteroidsCount() ) {
                    timeOfLastAsteroidCreation_ = timeProvider_->getMilisecondsSinceGameStart();
                    createAsteroid();
                }
            }
        }
    }

private:
    void createAsteroid(){
        Point position = generateRandomPositionOnRectangularEdgeWithBoundaries(); // have to odjac size boudaries!!asdas
        Point accelerationNormalVector = generateAccelerationNormalVector( position );
        auto accelerationVector  = accelerationNormalVector *= provider_.getRandomDouble(
                configuration_.GetAsteroidMinInitialImpulse(), configuration_.GetAsteroidMaxInitialImpulse());
        Rotation newRotation = DegreesCalculations::degreesToRadians(provider_.getRandom(360) );

        position = position - Point( configuration_.GetAsteroidsGenerationBoundariesSize().getX(),
                                     configuration_.GetAsteroidsGenerationBoundariesSize().getY());
        double size = provider_.getRandomDouble(configuration_.GetAsteroidMinSize(), configuration_.GetAsteroidMaxSize());
        double rotationSpeed = provider_.getRandomDouble(0, configuration_.GetAsteroidMaxRotationSpeed());
        asteroidsGenerator_->generateAsteroid(position, newRotation, size, accelerationVector, rotationSpeed  );
       // std::cout << "Created in pos "<<position.toString() <<" accelvec  " << accelerationVector.toString() << std::endl;
    }

    Point  generateRandomPositionOnRectangularEdgeWithBoundaries(){
        bool generateOnLongerSide = provider_.getRandomBool();
        Point creationPoint;
        Point asteroidsGenerationScreenSize(
                configuration_.getBox2dScreenDimensions().getX() + (configuration_.GetAsteroidsGenerationBoundariesSize().getX()*2),
                configuration_.getBox2dScreenDimensions().getY() + (configuration_.GetAsteroidsGenerationBoundariesSize().getY()*2));

        double x = provider_.getRandomDouble(0,1) * ( 2* asteroidsGenerationScreenSize.getX() + 2*asteroidsGenerationScreenSize.getY());
        if( x < asteroidsGenerationScreenSize.getX( )){
            return Point(x, 0);
        }
        x -= asteroidsGenerationScreenSize.getX();
        if( x < asteroidsGenerationScreenSize.getY( )){
            return Point( asteroidsGenerationScreenSize.getX(), x);
        }
        x -= asteroidsGenerationScreenSize.getY();
        if( x < asteroidsGenerationScreenSize.getX()){
            return Point( x, asteroidsGenerationScreenSize.getY());
        } else {
            return Point(0, x - asteroidsGenerationScreenSize.getX());
        }
    }

    Point generateRandomPointInRectangularWithBoundaries(){
        Point asteroidsGenerationScreenSize(
                configuration_.getBox2dScreenDimensions().getX() + (configuration_.GetAsteroidsGenerationBoundariesSize().getX()*2),
                configuration_.getBox2dScreenDimensions().getY() + (configuration_.GetAsteroidsGenerationBoundariesSize().getY()*2));
        return Point(provider_.getRandomDouble(0, asteroidsGenerationScreenSize.getX()),
                     provider_.getRandomDouble(0, asteroidsGenerationScreenSize.getY()));
    }

    Point generateAccelerationNormalVector(Point startPoint){
        Point randomPointOnRectangular = generateRandomPointInRectangularWithBoundaries();
        Point vectorBeforeNormalization = randomPointOnRectangular - startPoint;
        vectorBeforeNormalization.normalize();

       // std::cout << "Rp in rect " << randomPointOnRectangular.toString() << " vec bef norm " << vectorBeforeNormalization.toString() << "  ";
        return vectorBeforeNormalization;
    }

};


#endif //PWASTEROIDS_RANDOMASTEROIDSGENERATOR_H
