//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
#define PWASTEROIDS_ROCKETMOVINGCOMPONENT_H

#include <Model/components/PositionComponent.h>
#include <Model/modelInterfaces/IKeyboardStateProvider.h>
#include <Model/Services/IPhysicsService.h>
#include <Model/box2d/Box2DService.h>
#include "RocketBox2dComponent.h"
#include "Model/modelInterfaces/Keys.h"

class RocketMovingComponent : public Component {
	std::shared_ptr<RocketBox2dComponent> box2dComponent_;
	std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider_;
public:
	RocketMovingComponent( std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider )
			: keyboardStateProvider_(keyboardStateProvider){
	}

	virtual void OnStart(IActor &actor) override{
		box2dComponent_ = actor.getOnlyComponent<RocketBox2dComponent>();
	}

	virtual void OnUpdate() override{
		if(keyboardStateProvider_->isPressed(Keys::Player1AccelerateKey)){
			box2dComponent_->accelerate();
		} else if (keyboardStateProvider_->isPressed(Keys::Player1LeftKey)){
			box2dComponent_->turnLeft();
		} else if (keyboardStateProvider_->isPressed(Keys::Player1RightKey)){
			box2dComponent_->turnRight();
		}
	}

	virtual void OnStop() override{};
private:

};
#endif //PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
