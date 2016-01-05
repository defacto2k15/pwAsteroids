//
// Created by defacto on 2016.01.04..
//

#include "PositionSettingComponent.h"

void PositionSettingComponent::OnStart(IActor &actor) {
    if( isObjectFromBox2d_ ){
        box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
    } else {
        normalPositionComponent_ = actor.getOnlyComponent<PositionComponent>();
    }
}

void PositionSettingComponent::setPosition(double x, double y) {
    if( isObjectFromBox2d_ ){
        box2dComponent_->setPosition(x,y);
    } else {
        normalPositionComponent_->setPosition( Point(x,y) );
    }
}

void PositionSettingComponent::setRotation(double rotation) {
    if( isObjectFromBox2d_ ){
        box2dComponent_->setRotation(rotation);
    } else {
        normalPositionComponent_->setRotation(rotation);
    }
}
