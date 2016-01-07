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
    ActorTypeEnumInPythonVisualisator(PythonModule &module );

    virtual void OnStart();
};

#endif //PWASTEROIDS_ACTORTYPEENUMINPYTHONVISUALISATOR_H
