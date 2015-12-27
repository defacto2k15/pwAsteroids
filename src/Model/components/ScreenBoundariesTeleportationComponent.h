//
// Created by defacto on 2015.12.24..
//

#ifndef PWASTEROIDS_SCREENBOUNDARIESTELEPORTATIONCOMPONENT_H
#define PWASTEROIDS_SCREENBOUNDARIESTELEPORTATIONCOMPONENT_H


#include <Model/configuration/ActorsConfiguration.h>
#include "Component.h"
#include "PositionComponent.h"
#include "IPositionSettingComponent.h"

class ScreenBoundariesTeleportationComponent : public Component {
    std::shared_ptr<PositionComponent> positionComponent_;
    std::shared_ptr<IPositionSettingComponent> positionSettingComponent_;
    ActorsConfiguration &configuration_;
public:
    ScreenBoundariesTeleportationComponent( ActorsConfiguration & configuration ) : configuration_(configuration ){
    }

    void OnStart( IActor &actor) override {
        positionComponent_ = actor.getOnlyComponent<PositionComponent>();
        positionSettingComponent_ = actor.getOnlyComponent<IPositionSettingComponent>();
    }

    void OnUpdate() override{
        Point position  = positionComponent_->getPosition();
        if( position.getX() < 0  || position.getY( ) < 0 ||
                position.getX() >   configuration_.getBox2dScreenDimensions().getX() ||
                position.getY() >   configuration_.getBox2dScreenDimensions().getY( )){
            position = Point( fmod(position.getX() + configuration_.getBox2dScreenDimensions().getX(),  configuration_.getBox2dScreenDimensions().getX()),
                              fmod(position.getY() + configuration_.getBox2dScreenDimensions().getY(),  configuration_.getBox2dScreenDimensions().getY()));
            positionSettingComponent_->setPosition( position.getX(), position.getY());
        }
    }
};


#endif //PWASTEROIDS_SCREENBOUNDARIESTELEPORTATIONCOMPONENT_H
