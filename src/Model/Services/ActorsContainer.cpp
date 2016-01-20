//
// Created by defacto on 24.10.15.
//

#include "ActorsContainer.h"

void ActorsContainer::addActor(std::shared_ptr<IActor> newActor) {
	assert(!weHaveStarted);
	actorsVec_.push_back(newActor);
}

void ActorsContainer::addActorDuringRuntime(std::shared_ptr<IActor> newActor) {
	newActor->OnStart();
	actorsVec_.push_back(newActor);
}

void ActorsContainer::removeActor(std::shared_ptr<IActor> newActor) {
	auto foundIt = std::find(begin(actorsVec_), end(actorsVec_), newActor);
	if(foundIt == actorsVec_.end()){
		throw RemovingNotAddedActorException();
	}
	(*foundIt)->OnStop();
	actorsVec_.erase(foundIt);
}

std::vector<std::shared_ptr<IService>> ActorsContainer::getServices() {
	std::vector<std::shared_ptr<IService>> outVec(actorsVec_.size());
	std::copy(begin(actorsVec_), end(actorsVec_), begin(outVec));
	return outVec;
}

void  ActorsContainer::OnStart() {
	std::function<std::vector<PythonActorComponent>(void) > func =  [this](){ return getAllActors();};
	python_.addRootFunction("getAllActors", func);
	std::function<void(PythonActorComponent &)> removeFunc
			= [this](PythonActorComponent comp){ removeActor(comp);};
	python_.addRootFunction("removeActor", removeFunc);
	ServiceContainer::OnStart();
	weHaveStarted = true;
}

std::vector<PythonActorComponent> ActorsContainer::getAllActors() {
	std::vector<PythonActorComponent> outVec;
	for( auto &oneActor : actorsVec_ ){
		if( oneActor->isComponentPresent<PythonActorComponent>() ) {
			auto comp = oneActor->getOnlyComponent<PythonActorComponent>();
			outVec.push_back(*comp);
		}
	}
	return outVec;
}

ActorsContainer::ActorsContainer(PythonModule &python) : python_(python) {

}

void ActorsContainer::removeActor(PythonActorComponent &pythonActorComponent) {
	removeActorById(pythonActorComponent.getActorId());
}

void ActorsContainer::removeActorById(ActorId id ) {
	auto iterator = std::find_if( begin(actorsVec_), end(actorsVec_), [id](std::shared_ptr<IActor> actor){
		return actor->getActorId() == id;
	});
	if( iterator == actorsVec_.end() ){
		throw RemovingNotAddedActorException();
	}
	removeActor( *iterator );
}

void ActorsContainer::resetAndRemoveAllActors() {
    for( auto oneActor : actorsVec_){
        oneActor->OnStop();
    }
    actorsVec_.clear();
    weHaveStarted = false;
}
