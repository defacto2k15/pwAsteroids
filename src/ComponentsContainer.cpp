//
// Created by defacto on 14.10.15.
//

#include "ComponentsContainer.h"
#include "Component.h"

void ComponentsContainer::addComponent(std::shared_ptr<Component> newComponent) {
	componentsVector_.push_back(newComponent);
}

std::vector<std::shared_ptr<Component>> ComponentsContainer::getAllComponents() {
	return componentsVector_;
}
