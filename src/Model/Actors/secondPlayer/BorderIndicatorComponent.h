//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_BORDERINDICATOR_H
#define PWASTEROIDS_BORDERINDICATOR_H


#include <Model/components/Component.h>
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/modelInterfaces/IOutGameScreenModel.h>
#include <Model/ModelDrawing/ImageScalesContainer.h>
#include <Model/modelInterfaces/IInKeyboardStateGetter.h>
#include <Model/modelInterfaces/IKeyboardStateProvider.h>
#include <Model/components/PositionComponent.h>
#include <Model/components/IPositionSettingComponent.h>

class BorderIndicatorComponent : public Component{
    ActorsConfiguration &configuration_;
    std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider_;
    std::shared_ptr<IPositionSettingComponent> positionSettingComponent_;
    Rect indicatorMovingCircuitRect_;

    double lastIndicatorPosition_ = 0;
public:
    BorderIndicatorComponent(ActorsConfiguration &configuration,
                             std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider);

    void OnStart(IActor &actor);

    void OnUpdate();
};


#endif //PWASTEROIDS_BORDERINDICATOR_H
