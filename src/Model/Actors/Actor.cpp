//

#include <Model/help/StdContainers.h>
#include "Actor.h"

void Actor::addComponent(std::shared_ptr<Component> component) {
	container_.addComponent(component);
	if( hasActorStarted_ ){
		component->OnStart(*this);
	}
}

void Actor::OnStart() {
	for( auto &component : container_.getAllComponents() ){
		component->OnStart(*this);
	}
	hasActorStarted_ = true;
}

void Actor::OnUpdate() {
	for( auto &component : container_.getAllComponents() ){
		component->OnUpdate();
	}
}

void Actor::OnStop() {
	for( auto &component : container_.getAllComponents() ){
		component->OnStop();
	}
}

std::shared_ptr<Component> Actor::getOnlyComponent(ComponentTypeChecker checker) {
	return container_.getOnlyComponent(checker);
}

//
// Created by defacto on 14.10.15.
bool Actor::isComponentPresent(ComponentTypeChecker checker) {
	return container_.isComponentPresent(checker);
}

ActorId  Actor::getActorId() const {
	return actorId_;
}

void Actor::removeComponent(Component *component) {
	component->OnStop();
	container_.removeComponent( component );
}
