//
// Created by defacto on 14.10.15.
//

#ifndef PWASTEROIDS_ACTOR_H
#define PWASTEROIDS_ACTOR_H


#include "IActor.h"
#include "ComponentsContainer.h"
class ComponentsContainer;

class Actor : public IActor {
	ComponentsContainer container_;
public:


	virtual std::shared_ptr<Component> getOnlyComponent(ComponentTypeChecker checker);

	Actor(){}
	virtual void OnStart();

	virtual void OnUpdate();

	virtual void OnStop();

	virtual void addComponent(std::shared_ptr<Component> component) override;
};


#endif //PWASTEROIDS_ACTOR_H
