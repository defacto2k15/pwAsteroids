//
// Created by defacto on 2016.01.01..
//

#include "ScallingMousePositionGetter.h"


ScallingMousePositionGetter::ScallingMousePositionGetter(const std::shared_ptr<IInputStateGetter> &rootStateGetter_,
                                                         ActorsConfiguration &configuration_)
        : rootStateGetter_(rootStateGetter_),
          configuration_(configuration_) { }

void ScallingMousePositionGetter::gameKeyIsPressed(Keys key) {
    rootStateGetter_->gameKeyIsPressed(key);
}

void ScallingMousePositionGetter::setMousePosition(double x, double y) {
    Point inPoint(x,y);
    Point newPoint = configuration_.getAllegroToBox2dScale().scalePoint(inPoint);
    rootStateGetter_->setMousePosition(newPoint.getX(), newPoint.getY());
}