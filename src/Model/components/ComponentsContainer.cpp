//
// Created by defacto on 14.10.15.
//

#include <Model/exceptions/ThereIsNotOneComponentOfGivenType.h>
#include "ComponentsContainer.h"

void ComponentsContainer::addComponent(std::shared_ptr<Component> newComponent) {
	componentsVector_.push_back(newComponent);
}

std::vector<std::shared_ptr<Component>> ComponentsContainer::getAllComponents() {
	return componentsVector_;
}

std::vector<std::shared_ptr<Component>> ComponentsContainer::getComponents( ComponentTypeChecker checker ) {
	std::vector<std::shared_ptr<Component>> componentsCopy(componentsVector_);

	componentsCopy.erase(
			std::remove_if( begin(componentsCopy), end(componentsCopy),
			             [&checker]( std::shared_ptr<Component> oneComponent ){
				             return !checker.wasCastSuccesfull(oneComponent.get());
			             }), componentsCopy.end() );
	return componentsCopy;
}

std::shared_ptr<Component> ComponentsContainer::getOnlyComponent(ComponentTypeChecker checker) {
	auto retrivedComponents = getComponents(checker);
	if( retrivedComponents.size() != 1){
		throw ThereIsNotOneComponentOfGivenType(retrivedComponents.size());
	}
	return retrivedComponents[0];
}

bool ComponentsContainer::isComponentPresent(ComponentTypeChecker checker) {
	return getComponents(checker).size() != 0;
}

void ComponentsContainer::removeComponent(Component *component) {
	auto iter = std::find_if( begin( componentsVector_), end( componentsVector_),
							  [component]( std::shared_ptr<Component> oneComponent ){
								  return oneComponent.get() == component;
							  });
	if( iter == componentsVector_.end() ){
		assert(false);
	}

	iter =	std::remove_if( begin( componentsVector_), end( componentsVector_),
							[component]( std::shared_ptr<Component> oneComponent ){
								return oneComponent.get() == component;
							});

	componentsVector_.erase( iter, componentsVector_.end());
}
