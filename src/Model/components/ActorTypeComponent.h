//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_ACTORTYPECOMPONENT_H
#define PWASTEROIDS_ACTORTYPECOMPONENT_H

#include <Model/python/PythonClassVisibilityModule.h>
#include <Model/Actors/ActorType.h>
#include "Component.h"

class ActorTypeComponent : public Component {
    PythonClassVisibilityModule<ActorTypeComponent, std::shared_ptr<PythonModule>>  classVisibility_;
    ActorType type_;

public:
    ActorTypeComponent(ActorType type, std::shared_ptr<PythonModule> pythonModule )
            : classVisibility_(pythonModule), type_(type){
    }

    virtual void OnStart( IActor &actor){
        classVisibility_.registerActorMethod("getActorType", &ActorTypeComponent::getActorType );
    }

    std::string getActorType(){
        return getActorTypeString(type_);
    }

};


#endif //PWASTEROIDS_ACTORTYPECOMPONENT_H
