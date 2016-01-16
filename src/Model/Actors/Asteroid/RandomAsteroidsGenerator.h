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
    AsteroidsGenerator &asteroidsGenerator_;
    AsteroidsCounter &asteroidsCounter_;
    GameConfiguration &configuration_;
    std::shared_ptr<GameTimeProvider> timeProvider_;
    RandomNumbersProvider &provider_;
    PythonModule &python_;
    unsigned int timeOfLastAsteroidCreation_ = 0;
    bool generatorEnabled = true;
public:
    RandomAsteroidsGenerator(AsteroidsGenerator &asteroidsGenerator_, AsteroidsCounter &asteroidsCounter_,
                                 GameConfiguration &configuration_, std::shared_ptr<GameTimeProvider> &timeProvider_,
                                 RandomNumbersProvider &provider_, PythonModule &python);

    void OnUpdate();

    void OnStart();

    void enableAsteroidsGeneration();

    void disableAsteroidsGeneration();

private:
    void createAsteroid();

};


#endif //PWASTEROIDS_RANDOMASTEROIDSGENERATOR_H
