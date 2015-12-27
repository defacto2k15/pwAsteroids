//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_RANDOMNUMBERSPROVIDER_H
#define PWASTEROIDS_RANDOMNUMBERSPROVIDER_H

#include <cstdlib>

class RandomNumbersProvider {

public:
    unsigned int getRandom(unsigned int min, unsigned int max){
        return min + ( rand() % (max-min));
    }

    unsigned int getRandom( unsigned int max){
        return getRandom(0, max);
    }

    double getRandomDouble( double min, double max ){
        double f = (double)rand() / RAND_MAX;
        return min + f*( max - min);
    }

    bool getRandomBool( unsigned int propabilityRatio ){
        return getRandom(0, propabilityRatio) == 0;
    }

    bool getRandomBool(){
        return getRandomBool(1);
    }
};


#endif //PWASTEROIDS_RANDOMNUMBERSPROVIDER_H
