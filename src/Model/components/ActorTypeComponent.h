//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_ACTORTYPECOMPONENT_H
#define PWASTEROIDS_ACTORTYPECOMPONENT_H

#include <Model/python/PythonClassVisibilityModule.h>
#include <Model/Actors/ActorType.h>
#include "Component.h"

class ActorTypeComponent : public Component {
    PythonClassVisibilityModule<ActorTypeComponent, PythonModule &>  classVisibility_;
    ActorType type_;

public:
    ActorTypeComponent(ActorType type, PythonModule &pythonModule );

    virtual void OnStart(IActor &actor);

    std::string getActorType();

};


#endif //PWASTEROIDS_ACTORTYPECOMPONENT_H
