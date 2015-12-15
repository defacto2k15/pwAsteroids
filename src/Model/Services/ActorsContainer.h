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
#include <Model/python/PythonActorHandle.h>

class ActorsContainer  : public ServiceContainer {
	std::vector<std::shared_ptr<IActor>> actorsVec_;
public:
	ActorsContainer(){
		//python->addOnlyObject(this, "ActorsContainer").addMethod( &ActorsContainer::getAllActors, "ActorsContainer").build();
	}

	std::vector<PythonActorHandle> getAllActors(){
		std::vector<PythonActorHandle> outVec;
		for( auto &oneActor : actorsVec_ ){
			outVec.push_back(PythonActorHandle(oneActor));
		}
		return outVec;
	}

	void addActor(std::shared_ptr<IActor> newActor);

	void removeActor(std::shared_ptr<IActor> newActor);
protected:
	virtual std::vector<std::shared_ptr<IService>> getServices();
};


#endif //PWASTEROIDS_ACTORSCONTAINER_H
