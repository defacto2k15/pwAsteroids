//
// Created by defacto on 2016.01.16..
//
#include <stdlib.h>
#include <assert.h>
#include "PowerupType.h"

PowerupType generateRandomPowerup() {
    return PowerupType( rand() % int(PowerupType::EndPowerup) );
}
