//
// Created by defacto on 2015.12.29..
//

#include "RocketLife.h"

RocketLife::RocketLife(ActorsConfiguration &actorsConfiguration)
        : life_(actorsConfiguration.getInitialRocketLife()), actorsConfiguration_(actorsConfiguration) {
}

void RocketLife::decreaseLife() {
    if( life_ == 0){
        throw std::runtime_error("There is arleady 0 life_ left");
    }
    --life_;
}

void RocketLife::increaseLife() {
    life_;
}

void RocketLife::resetLife() {
    life_ = actorsConfiguration_.getInitialRocketLife();
}

unsigned int RocketLife::getLife() {
    return life_;
}