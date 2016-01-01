//
// Created by defacto on 2016.01.01..
//

#ifndef PWASTEROIDS_SCALLINGDMOUSEPOSITIONGETTER_H
#define PWASTEROIDS_SCALLINGDMOUSEPOSITIONGETTER_H

#include <memory>
#include <Model/configuration/ActorsConfiguration.h>
#include "IInputStateGetter.h"

class ScallingMousePositionGetter : public IInputStateGetter {
    std::shared_ptr<IInputStateGetter> rootStateGetter_;
    ActorsConfiguration &configuration_;
public:
    ScallingMousePositionGetter(const std::shared_ptr<IInputStateGetter> &rootStateGetter_,
                                ActorsConfiguration &configuration_) : rootStateGetter_(rootStateGetter_),
                                                                       configuration_(configuration_) { }

    virtual void gameKeyIsPressed(Keys key){
        rootStateGetter_->gameKeyIsPressed(key);
    }

    virtual void setMousePosition(double x, double y){
        Point inPoint(x,y);
        Point newPoint = configuration_.getAllegroToBox2dScale().scalePoint(inPoint);
        rootStateGetter_->setMousePosition(newPoint.getX(), newPoint.getY());
    }
};


#endif //PWASTEROIDS_SCALLINGDMOUSEPOSITIONGETTER_H
