//
// Created by defacto on 2015.12.27..
//

#ifndef PWASTEROIDS_IMAGESCALESCONTAINER_H
#define PWASTEROIDS_IMAGESCALESCONTAINER_H


#include <Model/PrimitiveTypes/ScaleToScreen.h>

class ImageScalesContainer {
public:
    Point getScreenSize(){
        return Point(1024, 600);
    }

    ScaleToScreen getRocketImageScale(){
        return ScaleToScreen(0.053, 0.1);
    }

    ScaleToScreen getRocketTailImageScale(){
        return ScaleToScreen(0.053, 0.1);
    }

    ScaleToScreen getBasicAsteroidImageScale(){
        return ScaleToScreen(0.053, 0.1);
    }

    ScaleToScreen getSecondPlayerTargetImageScale(){
        return ScaleToScreen(0.053, 0.1);
    }

    ScaleToScreen getProjectileImageScale(){
        return ScaleToScreen(15.0f / getScreenSize().getX(), 15.0f / getScreenSize().getY());
    }

    ScaleToScreen getBorderIndicatorImageScale(){
        return getProjectileImageScale();
    }

    ScaleToScreen getHeartImageScale(){
        return getProjectileImageScale();
    }
};


#endif //PWASTEROIDS_IMAGESCALESCONTAINER_H
