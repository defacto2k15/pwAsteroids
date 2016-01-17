//
// Created by defacto on 14.10.15.
//

#ifndef PWASTEROIDS_IACTOR_H
#define PWASTEROIDS_IACTOR_H

#include <memory>
#include <Model/Services/IService.h>
#include <memory>
#include <assert.h>
#include <Model/components/ComponentTypeChecker.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>

class Component;

class IActor : public IService {
public:
	virtual void addComponent(std::shared_ptr<Component> component)=0;
	virtual void removeComponent( Component *componentToDelete)=0;

	template<typename ComponentType>
	std::shared_ptr<ComponentType> getOnlyComponent(){
		auto componentBeforeCast = getOnlyComponent(ComponentTypeChecker::create<ComponentType>());
		std::shared_ptr<ComponentType> afterCast;
		afterCast = std::dynamic_pointer_cast<ComponentType>(componentBeforeCast);
		assert(afterCast);
		return afterCast;
	}

	template<typename ComponentType>
	bool isComponentPresent(){
		return isComponentPresent(ComponentTypeChecker::create<ComponentType>());
	}

	virtual ActorId getActorId() const=0;

	virtual ~IActor(){};

protected:
	virtual std::shared_ptr<Component> getOnlyComponent(ComponentTypeChecker checker)=0;
	virtual bool isComponentPresent(ComponentTypeChecker checker)=0;

};
#endif //PWASTEROIDS_IACTOR_H
