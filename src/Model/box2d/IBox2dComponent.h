//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_BOX2DCOMPONENT_H
#define PWASTEROIDS_BOX2DCOMPONENT_H

#include <Model/components/Component.h>

class IBox2dComponent : public Component{
public:
    virtual void setPosition( double x, double y )=0;
    virtual void setRotation( double rotation )=0;
};

#endif //PWASTEROIDS_BOX2DCOMPONENT_H
