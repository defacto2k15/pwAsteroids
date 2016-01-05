//
// Created by defacto on 2015.12.19..
//

#include "PythonActorComponent.h"

#include "PythonClassVisibilityModule.h"

void PythonActorComponent::OnStart(IActor &actor) {
    actor_ = &actor;
    module_->registerClass();

    // python_.registerClass<PythonActorComponent>() not needed, is in main
}

PythonActorComponent::PythonActorComponent(PythonModule &python) : python_(python){
    module_ = new PythonClassVisibilityModule<PythonActorComponent, PythonModule&>(python_);
   // module_->registerActorMethod("getActorId", &PythonActorComponent::getActorId);
}

PythonActorComponent &PythonActorComponent::operator=(const PythonActorComponent &other) {
    this->actor_ = other.actor_;
    this->python_ = other.python_;
    this->module_ = other.module_;
}

IActor *PythonActorComponent::getActor() {
    return actor_;
}

bool PythonActorComponent::operator==(const PythonActorComponent &other) {
    return actor_ == other.actor_;
}

int PythonActorComponent::getActorId() {
    return actor_->getActorId();
}