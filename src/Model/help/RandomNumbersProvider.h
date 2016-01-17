//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_RANDOMNUMBERSPROVIDER_H
#define PWASTEROIDS_RANDOMNUMBERSPROVIDER_H

#include <cstdlib>
#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/Rect.h>

class RandomNumbersProvider {

public:
    unsigned int getRandom(unsigned int min, unsigned int max);

    unsigned int getRandom(unsigned int max);

    double getRandomDouble(double min, double max );

    bool getRandomBool(unsigned int propabilityRatio );

    bool getRandomBool();

    Point generateRandomPointInRectangle(Rect rect);
};


#endif //PWASTEROIDS_RANDOMNUMBERSPROVIDER_H
