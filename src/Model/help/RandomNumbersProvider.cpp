//
// Created by defacto on 2015.12.26..
//

#include "RandomNumbersProvider.h"

unsigned int RandomNumbersProvider::getRandom(unsigned int min, unsigned int max) {
    return min + ( rand() % (max-min));
}

unsigned int RandomNumbersProvider::getRandom(unsigned int max) {
    return getRandom(0, max);
}

double RandomNumbersProvider::getRandomDouble(double min, double max ) {
    double f = (double)rand() / RAND_MAX;
    return min + f*( max - min);
}

bool RandomNumbersProvider::getRandomBool(unsigned int propabilityRatio ) {
    return getRandom(0, propabilityRatio) == 0;
}

bool RandomNumbersProvider::getRandomBool() {
    return getRandomBool(1);
}