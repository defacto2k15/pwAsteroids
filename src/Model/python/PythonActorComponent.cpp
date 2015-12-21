//
// Created by defacto on 2015.12.19..
//

#include "PythonActorComponent.h"

#include "PythonClassVisibilityModule.h"

void PythonActorComponent::OnStart(IActor &actor) {
    actor_ = &actor;
    module_->registerClass();
    // python_->registerClass<PythonActorComponent>() not needed, is in main
}

PythonActorComponent::PythonActorComponent(std::shared_ptr<PythonModule> python) : python_(python){
    module_ = new PythonClassVisibilityModule<PythonActorComponent, std::shared_ptr<PythonModule>>(python_);
}