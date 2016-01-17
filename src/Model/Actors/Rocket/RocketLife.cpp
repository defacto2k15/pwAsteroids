//
// Created by defacto on 2015.12.29..
//

#include "RocketLife.h"

RocketLife::RocketLife(GameConfiguration &gameConfiguration, PythonModule &python)
        : life_(gameConfiguration.getInitialRocketLife()), gameConfiguration_(gameConfiguration),
            python_(python){
    std::function< int() > getLifeFunc = [this](){ return life_;};
    python.addRootFunction("getLife", getLifeFunc);

    std::function< void(int) > setLifeFunc = [this](int newLife){ life_ = newLife;};
    python.addRootFunction("setLife", setLifeFunc);
}

void RocketLife::decreaseLife() {
    if( life_ == 0){
        throw std::runtime_error("There is arleady 0 life_ left");
    }
    --life_;
}

void RocketLife::increaseLife() {
    if( life_ <  gameConfiguration_.getMaxRocketLifes() ) {
        ++life_;
    }
}

void RocketLife::resetLife() {
    life_ = gameConfiguration_.getInitialRocketLife();
}

unsigned int RocketLife::getLife() {
    return life_;
}