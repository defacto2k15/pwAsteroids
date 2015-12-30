//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_STATICPOSITIONSETTINGCOMPONENT_H
#define PWASTEROIDS_STATICPOSITIONSETTINGCOMPONENT_H


#include "IPositionSettingComponent.h"
#include "PositionComponent.h"

class StaticPositionSettingComponent : public IPositionSettingComponent {
    std::shared_ptr<PositionComponent> positionComponent_;
public:
    void OnStart(IActor &actor){
        positionComponent_ = actor.getOnlyComponent<PositionComponent>();
    }

    virtual void setPosition( double x, double y) override {
        positionComponent_->setPosition(Point(x,y));
    }
    virtual void setRotation( double rotation ) override{
        positionComponent_->setRotation( rotation );
    }

};


#endif //PWASTEROIDS_STATICPOSITIONSETTINGCOMPONENT_H
