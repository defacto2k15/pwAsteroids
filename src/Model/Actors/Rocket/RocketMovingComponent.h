//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
#define PWASTEROIDS_ROCKETMOVINGCOMPONENT_H

#include <Model/components/PositionComponent.h>
#include <Model/modelInterfaces/IKeyboardStateProvider.h>
#include <Model/Services/IPhysicsService.h>

class RocketMovingComponent : public Component {

public:
	RocketMovingComponent( IPhysicsService &physicsService, IKeyboardStateProvider &provider )
			: physicsService_(physicsService), keyboardStateProvider_(provider){
	}

	virtual void OnStart(IActor &actor) override{
		positionComponent_ = actor.getOnlyComponent<PositionComponent>();
	//	physicsService.registerObject(masa i takie inne) //TODO kontynuuj here
	}

	virtual void OnUpdate() override{

	}

	virtual void OnStop() override{};
private:

	std::shared_ptr<PositionComponent> positionComponent_;
	IPhysicsService &physicsService_;
	IKeyboardStateProvider &keyboardStateProvider_;
};
#endif //PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
