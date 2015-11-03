//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_COMPONENTTYPECHECKER_H
#define PWASTEROIDS_COMPONENTTYPECHECKER_H

#include <assert.h>

class Component;

class ComponentTypeChecker{
	template<typename ComponentType>
	static bool checker( Component * ptr){ return dynamic_cast<ComponentType*>(ptr)!= NULL;}

	std::function<bool(Component*)> checker_;

public:
	template<typename ComponentType>
	ComponentTypeChecker( ComponentType *ptr) : checker_(&checker<ComponentType>){};

	template<typename ComponentType>
	static ComponentTypeChecker create(){
		ComponentType *ptr = nullptr;
		assert(ptr== nullptr);
		return ComponentTypeChecker(ptr);
	}

	bool wasCastSuccesfull( Component *componentWeAreChecking ){
		return checker_(componentWeAreChecking);
	}

};
#endif //PWASTEROIDS_COMPONENTTYPECHECKER_H
