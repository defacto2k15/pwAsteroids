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
                             RandomNumbersProvider &provider_);

    void OnUpdate();

private:
    void createAsteroid();

    Point generateRandomPositionOnRectangularEdgeWithBoundaries();

    Point generateRandomPointInRectangularWithBoundaries();

    Point generateAccelerationNormalVector(Point startPoint);

};


#endif //PWASTEROIDS_RANDOMASTEROIDSGENERATOR_H
