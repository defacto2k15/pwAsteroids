//
// Created by defacto on 14.10.15.
//

#ifndef PWASTEROIDS_COMPONENT_H
#define PWASTEROIDS_COMPONENT_H
#include "Model/Actors/IActor.h"
class IActor;

class Component {
public:
	virtual void OnStart(IActor &actor);
	virtual void OnUpdate();
	virtual void OnStop();
	virtual ~Component();
};

#endif //PWASTEROIDS_COMPONENT_H
