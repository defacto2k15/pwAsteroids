//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_POWERUPCOUNTER_H
#define PWASTEROIDS_POWERUPCOUNTER_H


class PowerupCounter {
    unsigned int countOfPowerups_;
public:
    void increase(){
        countOfPowerups_++;
    }

    void decrease(){
        countOfPowerups_--;
    }

    unsigned  int getCount(){
        return countOfPowerups_;
    }
};


#endif //PWASTEROIDS_POWERUPCOUNTER_H
