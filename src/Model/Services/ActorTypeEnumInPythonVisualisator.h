//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_ACTORTYPEENUMINPYTHONVISUALISATOR_H
#define PWASTEROIDS_ACTORTYPEENUMINPYTHONVISUALISATOR_H

#include <Model/python/PythonEnumVisibilityModule.h>
#include <Model/Actors/ActorType.h>
#include "IService.h"

class ActorTypeEnumInPythonVisualisator : public IService{
    PythonEnumVisibilityModule<ActorType> visibilityModule_;

public:
    ActorTypeEnumInPythonVisualisator( std::shared_ptr<PythonModule> module ):visibilityModule_(module){
    }

    virtual void OnStart() override {
        visibilityModule_.registerClass();
        visibilityModule_.addEnumValue("Invalid", ActorType_Invalid);
        visibilityModule_.addEnumValue("Rocket", ActorType_Rocket);
        visibilityModule_.addEnumValue("RocketTail", ActorType_RocketTail);
    }
};

#endif //PWASTEROIDS_ACTORTYPEENUMINPYTHONVISUALISATOR_H
