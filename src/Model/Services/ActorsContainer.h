//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_ACTORSCONTAINER_H
#define PWASTEROIDS_ACTORSCONTAINER_H


#include "ServiceContainer.h"
#include <memory>
#include <algorithm>
#include <Model/exceptions/RemovingNotAddedActorException.h>
#include <Model/Actors/IActor.h>
#include <Model/python/PythonModule.h>
#include <Model/python/PythonActorComponent.h>
#include <Model/help/boostHelp.h>

class ActorsContainer  : public ServiceContainer {
	std::vector<std::shared_ptr<IActor>> actorsVec_;
	PythonModule &python_;
	bool weHaveStarted = false;
public:
	ActorsContainer(PythonModule &python);

	virtual void OnStart();

	std::vector<PythonActorComponent> getAllActors();

	void addActor(std::shared_ptr<IActor> newActor);

	void addActorDuringRuntime(std::shared_ptr<IActor> newActor);

	void removeActor(std::shared_ptr<IActor> newActor);

	void removeActor(PythonActorComponent &pythonActorComponent);

	void removeActorById(ActorId id );
protected:
	virtual std::vector<std::shared_ptr<IService>> getServices();
};


#endif //PWASTEROIDS_ACTORSCONTAINER_H
