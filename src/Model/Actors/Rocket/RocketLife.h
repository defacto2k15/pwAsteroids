//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_ROCKETLIFECOMPONENT_H
#define PWASTEROIDS_ROCKETLIFECOMPONENT_H

#include <memory>
#include <Model/configuration/GameConfiguration.h>
#include <Model/modelInterfaces/IOutGameScreenModel.h>
#include <stdexcept>

class RocketLife {
    unsigned int life_;
    GameConfiguration &gameConfiguration_;
    PythonModule &python_;
public:
    RocketLife(GameConfiguration &gameConfiguration, PythonModule &python);

    void decreaseLife();

    void increaseLife();

    void resetLife();

    unsigned int getLife();
};


#endif //PWASTEROIDS_ROCKETLIFECOMPONENT_H
