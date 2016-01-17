//
// Created by defacto on 14.10.15.
//

#ifndef PWASTEROIDS_ACTOR_H
#define PWASTEROIDS_ACTOR_H


#include <Model/components/ComponentsContainer.h>
#include "IActor.h"
class ComponentsContainer;

class Actor : public IActor {
	ComponentsContainer container_;
	ActorId  actorId_;
	bool hasActorStarted_ = false;
public:


	virtual std::shared_ptr<Component> getOnlyComponent(ComponentTypeChecker checker);

	virtual bool isComponentPresent( ComponentTypeChecker checker );

	Actor(ActorId id) : actorId_(id){
		int h=7;
	}
	virtual void OnStart();

	virtual void OnUpdate();

	virtual void OnStop();

	virtual void removeComponent(Component *component) override;

	virtual void addComponent(std::shared_ptr<Component> component) override;

	virtual ActorId getActorId() const;
};


#endif //PWASTEROIDS_ACTOR_H
