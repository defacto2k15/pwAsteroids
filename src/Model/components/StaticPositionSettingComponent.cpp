//
// Created by defacto on 2015.12.29..
//

#include "StaticPositionSettingComponent.h"

void StaticPositionSettingComponent::OnStart(IActor &actor) {
    positionComponent_ = actor.getOnlyComponent<PositionComponent>();
}

void StaticPositionSettingComponent::setPosition(double x, double y) {
    positionComponent_->setPosition(Point(x,y));
}

void StaticPositionSettingComponent::setRotation(double rotation ) {
    positionComponent_->setRotation( rotation );
}