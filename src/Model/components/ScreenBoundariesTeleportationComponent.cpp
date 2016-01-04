//
// Created by defacto on 2015.12.24..
//

#include "ScreenBoundariesTeleportationComponent.h"

ScreenBoundariesTeleportationComponent::ScreenBoundariesTeleportationComponent(GameConfiguration & configuration )
        : configuration_(configuration ) {
}

void ScreenBoundariesTeleportationComponent::OnStart(IActor &actor) {
    positionComponent_ = actor.getOnlyComponent<PositionComponent>();
    positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
}

void ScreenBoundariesTeleportationComponent::OnUpdate() {
    Point position  = positionComponent_->getPosition();
    if( position.getX() < 0  || position.getY( ) < 0 ||
        position.getX() >   configuration_.getBox2dScreenDimensions().getX() ||
        position.getY() >   configuration_.getBox2dScreenDimensions().getY( )){
        position = Point( fmod(position.getX() + configuration_.getBox2dScreenDimensions().getX(),  configuration_.getBox2dScreenDimensions().getX()),
                          fmod(position.getY() + configuration_.getBox2dScreenDimensions().getY(),  configuration_.getBox2dScreenDimensions().getY()));
        positionSettingComponent_->setPosition( position.getX(), position.getY());
    }
}