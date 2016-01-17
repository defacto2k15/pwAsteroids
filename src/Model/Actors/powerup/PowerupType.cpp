//
// Created by defacto on 2016.01.16..
//
#include <stdlib.h>
#include <assert.h>
#include "PowerupType.h"

PowerupType generateRandomPowerup() {
    int optionsCount = 1;
    if( ( rand() % optionsCount) == 0 ){
        return PowerupType::TripleShoot;
    }
    assert(false);
}
