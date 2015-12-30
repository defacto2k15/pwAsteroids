//
// Created by defacto on 2015.12.29..
//

#include "BorderIndicatorComponent.h"
#include <iostream>

BorderIndicatorComponent::BorderIndicatorComponent(ActorsConfiguration &configuration,
                                                   std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider)
        : configuration_(configuration), keyboardStateProvider_(keyboardStateProvider),
          indicatorMovingCircuitRect_(Point(0,0), configuration.getBox2dScreenDimensions()) {
}

void BorderIndicatorComponent::OnStart(IActor &actor) {
    positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
}

void BorderIndicatorComponent::OnUpdate() {
    double indicatorMoveDelta = 0.05;
    if( keyboardStateProvider_->isPressed(Keys::Player2LeftKey)){
        lastIndicatorPosition_ -= indicatorMoveDelta;
    }
    if( keyboardStateProvider_->isPressed(Keys::Player2RightKey)){
        lastIndicatorPosition_ += indicatorMoveDelta;
    }
    lastIndicatorPosition_ += indicatorMovingCircuitRect_.getLength();
    lastIndicatorPosition_ = fmod(lastIndicatorPosition_, indicatorMovingCircuitRect_.getLength());
    auto positionOfIndicator = indicatorMovingCircuitRect_.getPointByLength(lastIndicatorPosition_);
    positionSettingComponent_->setPosition(positionOfIndicator.getX(), positionOfIndicator.getY());
}