//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
#define PWASTEROIDS_ROCKETMOVINGCOMPONENT_H

#include <Model/components/PositionComponent.h>
#include <Model/modelInterfaces/IKeyboardStateProvider.h>
#include <Model/Services/IPhysicsService.h>
#include <Model/box2d/Box2DService.h>
#include <Model/components/DrawingComponent.h>
#include "RocketBox2dComponent.h"
#include "Model/modelInterfaces/Keys.h"
#include "IRocketConfigurableValues.h"

class RocketMovingComponent : public Component {
	std::shared_ptr<RocketBox2dComponent> box2dComponent_;
	std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider_;
	std::shared_ptr<DrawingComponent> rocketTailDrawing_;

public:
	RocketMovingComponent( std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider)
			: keyboardStateProvider_(keyboardStateProvider){
	}

	virtual void OnStart(IActor &actor) override{
		box2dComponent_ = actor.getOnlyComponent<RocketBox2dComponent>();
	}

	virtual void OnUpdate() override{
		if( rocketTailDrawing_ == false){
			assert(false && "The rocket tail actor was not set! Shared ptr is null!") ;
		}

		if(keyboardStateProvider_->isPressed(Keys::Player1AccelerateKey)){ /* UGLY AS HELL, my eyes bleed but works*/
			box2dComponent_->accelerate();
			rocketTailDrawing_->setVisibility(true);
		}  else {
			rocketTailDrawing_->setVisibility(false);
		}
		if (keyboardStateProvider_->isPressed(Keys::Player1LeftKey)){
			box2dComponent_->turnLeft();
		}
		if (keyboardStateProvider_->isPressed(Keys::Player1RightKey)){
			box2dComponent_->turnRight();
		}
	}

	void setRocketTail( std::shared_ptr<IActor> tailActor){
		rocketTailDrawing_ = tailActor->getOnlyComponent<DrawingComponent>();
	}

	virtual void OnStop() override{};
private:

};
#endif //PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
