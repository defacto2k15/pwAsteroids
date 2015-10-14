//
// Created by defacto on 14.10.15.
//

#ifndef PWASTEROIDS_COMPONENTSCONTAINER_H
#define PWASTEROIDS_COMPONENTSCONTAINER_H


#include <memory>
#include "Component.h"
#include <vector>
#include <algorithm>
class Actor;

class ComponentsContainer {
private:
	std::vector<std::shared_ptr<Component>> componentsVector_;
public:
	void addComponent(std::shared_ptr<Component> newComponent);

	template< typename ComponentType >
	std::vector<std::shared_ptr<ComponentType>> getComponents(){
		std::vector<std::shared_ptr<ComponentType>> outVec;
		for( auto &basePtr : componentsVector_ ){
			auto castedPtr = std::dynamic_pointer_cast<ComponentType>(basePtr);
			if(castedPtr != nullptr){
				outVec.push_back(castedPtr);
			}
		}
		return outVec;
	}

	std::vector<std::shared_ptr<Component>> getAllComponents();
};


#endif //PWASTEROIDS_COMPONENTSCONTAINER_H
