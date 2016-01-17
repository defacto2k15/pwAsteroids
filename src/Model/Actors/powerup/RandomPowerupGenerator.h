//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_RANDOMPOWERUPGENERATOR_H
#define PWASTEROIDS_RANDOMPOWERUPGENERATOR_H


#include <Model/Services/IService.h>
#include <Model/Actors/IActor.h>
#include <Model/configuration/GameConfiguration.h>
#include <Model/Services/GameTimeProvider.h>
#include <Model/help/RandomNumbersProvider.h>
#include "PowerupGenerator.h"
#include "PowerupCounter.h"

class RandomPowerupGenerator : public IService {
    std::shared_ptr<IActor> rocketActor_;
    GameConfiguration &configuration_;
    std::shared_ptr<GameTimeProvider> timeProvider_;
    PowerupGenerator &generator_;
    PowerupCounter &counter_;
    RandomNumbersProvider &randomNumbers_;

    long timeOfLastCreation_ = 0;

public:


    RandomPowerupGenerator(std::shared_ptr<IActor> rocketActor_, GameConfiguration &configuration_,
                           std::shared_ptr<GameTimeProvider> timeProvider_, PowerupGenerator &generator,
                           PowerupCounter &counter_, RandomNumbersProvider &randomNumbers_);

    void OnUpdate();

};


#endif //PWASTEROIDS_RANDOMPOWERUPGENERATOR_H
