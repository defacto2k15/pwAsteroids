//
// Created by defacto on 2015.12.22..
//

//#include "Box2dPositionSettingComponent.h"
//
//Box2dPositionSettingComponent::Box2dPositionSettingComponent(PythonModule &python )
//        : visibilityModule_(python) {
//}
//
//void Box2dPositionSettingComponent::OnStart(IActor &actor) {
//    box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
//    visibilityModule_.registerActorMethod("setPosition", &Box2dPositionSettingComponent::setPosition);
//    visibilityModule_.registerActorMethod("setRotation", &Box2dPositionSettingComponent::setRotation);
//}
//
//void Box2dPositionSettingComponent::setPosition(double x, double y) {
//    box2dComponent_->setPosition(x,y);
//}
//
//void Box2dPositionSettingComponent::setRotation(double rotation) {
//    box2dComponent_->setRotation(rotation);
//}