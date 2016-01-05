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
    ActorTypeEnumInPythonVisualisator( PythonModule &module ):visibilityModule_(module){
    }

    virtual void OnStart() override {
        visibilityModule_.registerClass();
        visibilityModule_.addEnumValue("Invalid", ActorType_Invalid);
        visibilityModule_.addEnumValue("Rocket", ActorType_Rocket);
        visibilityModule_.addEnumValue("RocketTail", ActorType_RocketTail);
        visibilityModule_.addEnumValue("Projectile", ActorType_Projectile);
        visibilityModule_.addEnumValue("Asteroid", ActorType_Asteroid);
        visibilityModule_.addEnumValue("Other", ActorType_Other);
    }
};

#endif //PWASTEROIDS_ACTORTYPEENUMINPYTHONVISUALISATOR_H
