//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_BOX2DPOSITIONSETTINGCOMPONENT_H
#define PWASTEROIDS_BOX2DPOSITIONSETTINGCOMPONENT_H


#include <Model/python/PythonModule.h>
#include <Model/python/PythonClassVisibilityModule.h>
#include "Model/components/IPositionSettingComponent.h"
#include "IBox2dComponent.h"


class Box2dPositionSettingComponent : public IPositionSettingComponent{
    PythonClassVisibilityModule<Box2dPositionSettingComponent, std::shared_ptr<PythonModule>> visibilityModule_;
    std::shared_ptr<IBox2dComponent> box2dComponent_;
public:
    Box2dPositionSettingComponent( std::shared_ptr<PythonModule> python ) : visibilityModule_(python){
    }

    virtual void OnStart(IActor &actor){
        box2dComponent_ = actor.getOnlyComponent<IBox2dComponent>();
        visibilityModule_.registerActorMethod("setPosition", &Box2dPositionSettingComponent::setPosition);
        visibilityModule_.registerActorMethod("setRotation", &Box2dPositionSettingComponent::setRotation);
    }

    virtual void setPosition(double x, double y) override{
        box2dComponent_->setPosition(x,y);
    }

    virtual void setRotation(double rotation) override{
        box2dComponent_->setRotation(rotation);
    }
};


#endif //PWASTEROIDS_BOX2DPOSITIONSETTINGCOMPONENT_H
