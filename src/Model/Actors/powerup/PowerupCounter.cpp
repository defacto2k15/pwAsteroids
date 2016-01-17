//
// Created by defacto on 2016.01.16..
//

#include "PowerupCounter.h"

void PowerupCounter::increase() {
    countOfPowerups_++;
}

void PowerupCounter::decrease() {
    countOfPowerups_--;
}

unsigned  int PowerupCounter::getCount() {
    return countOfPowerups_;
}