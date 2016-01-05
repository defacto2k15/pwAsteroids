//
// Created by defacto on 2016.01.04..
//

#ifndef PWASTEROIDS_POSITIONSETTINGCOMPONENT_H
#define PWASTEROIDS_POSITIONSETTINGCOMPONENT_H


#include "PositionComponent.h"
#include "IPositionSettingComponent.h"
#include <Model/Actors/Rocket/Box2dComponent.h>

class PositionSettingComponent : public IPositionSettingComponent {
    std::shared_ptr<Box2dComponent> box2dComponent_;
    std::shared_ptr<PositionComponent> normalPositionComponent_;
    PythonClassVisibilityModule<PositionSettingComponent> visibilityModule_;
    bool isObjectFromBox2d_;
public:
    PositionSettingComponent( bool isObjectFromBox2d, PythonModule &python)
            : visibilityModule_(python), isObjectFromBox2d_(isObjectFromBox2d){
        visibilityModule_.registerActorMethod("setPosition", &PositionSettingComponent::setPosition);
        visibilityModule_.registerActorMethod("setRotation", &PositionSettingComponent::setRotation);
    }

    virtual void OnStart(IActor &actor) override;

    virtual void setPosition(double x, double y) override;

    virtual void setRotation(double rotation) override;
};


#endif //PWASTEROIDS_POSITIONSETTINGCOMPONENT_H
