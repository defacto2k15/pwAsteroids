//
// Created by defacto on 2016.01.12..
//

#ifndef PWASTEROIDS_GAMESCREENSIZE_H
#define PWASTEROIDS_GAMESCREENSIZE_H


#include <Model/PrimitiveTypes/AliasedTypes.h>

class ScreenSize {
    Size size_;
public:
    ScreenSize(Size size) : size_(size){
    }

    void setSize(Size size);

    Size getSize();
};


#endif //PWASTEROIDS_GAMESCREENSIZE_H
