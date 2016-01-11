//
// Created by defacto on 2015.12.29..
//

#include "BorderIndicatorComponent.h"
#include <iostream>

BorderIndicatorComponent::BorderIndicatorComponent(GameConfiguration &configuration,
                                                   std::shared_ptr<IInputStateProvider> inputStateProvider)
        : configuration_(configuration), inputStateProvider_(inputStateProvider){
}

void BorderIndicatorComponent::OnStart(IActor &actor) {
    positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
}

void BorderIndicatorComponent::OnUpdate() {
    indicatorMovingCircuitRect_ = Rect(Point(0,0), configuration_.getBox2dScreenDimensions() );

    double indicatorMoveDelta = 0.05;
    if( inputStateProvider_->isPressed(Keys::Player2LeftKey)){
        lastIndicatorPosition_ -= indicatorMoveDelta;
    }
    if( inputStateProvider_->isPressed(Keys::Player2RightKey)){
        lastIndicatorPosition_ += indicatorMoveDelta;
    }
    lastIndicatorPosition_ += indicatorMovingCircuitRect_.getLength();
    lastIndicatorPosition_ = fmod(lastIndicatorPosition_, indicatorMovingCircuitRect_.getLength());
    auto positionOfIndicator = calculatePositionOfIndicator();
    positionSettingComponent_->setPosition(positionOfIndicator.getX(), positionOfIndicator.getY());
}

Point BorderIndicatorComponent::getBorderIndicatorPosition() {
    return calculatePositionOfIndicator();
}

Point BorderIndicatorComponent::calculatePositionOfIndicator( ) {
    auto positionOfIndicator = indicatorMovingCircuitRect_.getPointByLength(lastIndicatorPosition_);
    return positionOfIndicator;
}