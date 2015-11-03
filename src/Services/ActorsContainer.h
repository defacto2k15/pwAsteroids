//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_ACTORSCONTAINER_H
#define PWASTEROIDS_ACTORSCONTAINER_H


#include "ServiceContainer.h"
#include <memory>
#include <algorithm>
#include <exceptions/RemovingNotAddedActorException.h>
#include <Actors/IActor.h>

class ActorsContainer  : public ServiceContainer {
	std::vector<std::shared_ptr<IActor>> actorsVec_;
public:
	void addActor(std::shared_ptr<IActor> newActor){
		actorsVec_.push_back(newActor);
	}

	void removeActor(std::shared_ptr<IActor> newActor){
		auto foundIt = std::find(begin(actorsVec_), end(actorsVec_), newActor);
		if(foundIt == actorsVec_.end()){
			throw RemovingNotAddedActorException();
		}
		actorsVec_.erase(foundIt);
	}
protected:
	virtual std::vector<std::shared_ptr<IService>> getServices();
};


#endif //PWASTEROIDS_ACTORSCONTAINER_H
