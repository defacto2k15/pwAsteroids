//
// Created by defacto on 14.10.15.
//

#include "Actor.h"

void Actor::addComponent(std::shared_ptr<Component> component) {
	container_.addComponent(component);
}

void Actor::OnStart() {
	for( auto &component : container_.getAllComponents() ){
		component->OnStart(*this);
	}
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
