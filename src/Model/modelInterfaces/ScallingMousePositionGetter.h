//
// Created by defacto on 2016.01.01..
//

#ifndef PWASTEROIDS_SCALLINGDMOUSEPOSITIONGETTER_H
#define PWASTEROIDS_SCALLINGDMOUSEPOSITIONGETTER_H

#include <memory>
#include <Model/configuration/GameConfiguration.h>
#include "IInputStateGetter.h"

class ScallingMousePositionGetter : public IInputStateGetter {
    std::shared_ptr<IInputStateGetter> rootStateGetter_;
    GameConfiguration &configuration_;
public:
    ScallingMousePositionGetter(const std::shared_ptr<IInputStateGetter> &rootStateGetter_,
                                GameConfiguration &configuration_);

    virtual void gameKeyIsPressed(Keys key);

    virtual void setMousePosition(double x, double y);
};


#endif //PWASTEROIDS_SCALLINGDMOUSEPOSITIONGETTER_H
