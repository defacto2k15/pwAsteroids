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
#include <Model/python/PythonActorComponent.h>
#include <Model/help/boostHelp.h>

class ActorsContainer  : public ServiceContainer {
	std::vector<std::shared_ptr<IActor>> actorsVec_;
	std::shared_ptr< PythonModule >python_;
public:
	ActorsContainer(std::shared_ptr< PythonModule > python) : python_(python){

	}

	virtual void OnStart() override {
		std::function<std::vector<PythonActorComponent>(void) > func =  [this](){ return getAllActors();};
		python_->addRootFunction("getAllActors", func);
		ServiceContainer::OnStart();
	}

	std::vector<PythonActorComponent> getAllActors(){
		std::vector<PythonActorComponent> outVec;
		for( auto &oneActor : actorsVec_ ){
			if( oneActor->isComponentPresent<PythonActorComponent>() ) {
				auto comp = oneActor->getOnlyComponent<PythonActorComponent>();
				outVec.push_back(*comp);
			}
		}
		return outVec;
	}

	void addActor(std::shared_ptr<IActor> newActor);

	void removeActor(std::shared_ptr<IActor> newActor);
protected:
	virtual std::vector<std::shared_ptr<IService>> getServices();
};


#endif //PWASTEROIDS_ACTORSCONTAINER_H
