//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_IPOSITIONSETTINGCOMPONENT_H
#define PWASTEROIDS_IPOSITIONSETTINGCOMPONENT_H

#include "Component.h"

class IPositionSettingComponent : public Component {
public:
    virtual void setPosition( double x, double y)=0;
    virtual void setRotation( double rotation )=0;
};

#endif //PWASTEROIDS_IPOSITIONSETTINGCOMPONENT_H
