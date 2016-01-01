//
// Created by defacto on 2016.01.01..
//

#ifndef PWASTEROIDS_IBORDERINDICATORPOSITIONPROVIDER_H
#define PWASTEROIDS_IBORDERINDICATORPOSITIONPROVIDER_H

#include <Model/PrimitiveTypes/Point.h>

class IBorderIndicatorPositionProvider{
public:
    virtual Point getBorderIndicatorPosition()=0;
};
#endif //PWASTEROIDS_IBORDERINDICATORPOSITIONPROVIDER_H
