//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_BORDERINDICATOR_H
#define PWASTEROIDS_BORDERINDICATOR_H


#include <Model/components/Component.h>
#include <Model/configuration/GameConfiguration.h>
#include <Model/modelInterfaces/IOutGameScreenModel.h>
#include <Model/ModelDrawing/ImageScalesContainer.h>
#include <Model/modelInterfaces/IInputStateGetter.h>
#include <Model/modelInterfaces/IInputStateProvider.h>
#include <Model/components/PositionComponent.h>
#include <Model/components/IPositionSettingComponent.h>
#include "IBorderIndicatorPositionProvider.h"

class BorderIndicatorComponent : public Component, public IBorderIndicatorPositionProvider{
    GameConfiguration &configuration_;
    std::shared_ptr<IInputStateProvider> inputStateProvider_;
    std::shared_ptr<IPositionSettingComponent> positionSettingComponent_;
    Rect indicatorMovingCircuitRect_;

    double lastIndicatorPosition_ = 0;
public:
    virtual Point getBorderIndicatorPosition() override;

    BorderIndicatorComponent(GameConfiguration &configuration,
                             std::shared_ptr<IInputStateProvider> inputStateProvider);

    void OnStart(IActor &actor);

    void OnUpdate();

private:
    Point calculatePositionOfIndicator( );


};


#endif //PWASTEROIDS_BORDERINDICATOR_H
