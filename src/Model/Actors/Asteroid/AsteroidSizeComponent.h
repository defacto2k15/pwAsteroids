//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_ASTEROIDSIZECOMPONENT_H
#define PWASTEROIDS_ASTEROIDSIZECOMPONENT_H

#include <Model/components/Component.h>

class AsteroidSizeComponent : public Component {
    double size_;
public:
    AsteroidSizeComponent(double size );

    double getSize();
};


#endif //PWASTEROIDS_ASTEROIDSIZECOMPONENT_H
