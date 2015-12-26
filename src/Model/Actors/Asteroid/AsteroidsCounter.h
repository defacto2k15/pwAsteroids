//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_ASTEROIDSCOUNTER_H
#define PWASTEROIDS_ASTEROIDSCOUNTER_H


class AsteroidsCounter {
    int value=0;
public:
    void Increment(){
        ++value;
    }

    void Decrement(){
        --value;
    }

    int getValue(){
        return value;
    }
};


#endif //PWASTEROIDS_ASTEROIDSCOUNTER_H
