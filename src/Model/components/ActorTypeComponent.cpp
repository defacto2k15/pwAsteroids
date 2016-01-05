//
// Created by defacto on 2015.12.22..
//

#include "ActorTypeComponent.h"

ActorTypeComponent::ActorTypeComponent(ActorType type, PythonModule &pythonModule )
        : classVisibility_(pythonModule), type_(type) {
}

void ActorTypeComponent::OnStart(IActor &actor) {
    classVisibility_.registerActorMethod("getActorType", &ActorTypeComponent::getActorType );
}

std::string ActorTypeComponent::getActorType() {
    return getActorTypeString(type_);
}