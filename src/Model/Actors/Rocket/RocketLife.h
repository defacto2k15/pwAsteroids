//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_ROCKETLIFECOMPONENT_H
#define PWASTEROIDS_ROCKETLIFECOMPONENT_H

#include <memory>
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/modelInterfaces/IOutGameScreenModel.h>
#include <stdexcept>

class RocketLife {
    unsigned int life_;
    ActorsConfiguration &actorsConfiguration_;
public:
    RocketLife(ActorsConfiguration &actorsConfiguration);

    void decreaseLife();

    void increaseLife();

    void resetLife();

    unsigned int getLife();
};


#endif //PWASTEROIDS_ROCKETLIFECOMPONENT_H
