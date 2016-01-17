//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_POWERUPCOUNTER_H
#define PWASTEROIDS_POWERUPCOUNTER_H


class PowerupCounter {
    unsigned int countOfPowerups_;
public:
    void increase();

    void decrease();

    unsigned  int getCount();
};


#endif //PWASTEROIDS_POWERUPCOUNTER_H
