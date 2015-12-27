//
// Created by defacto on 26.10.15.
//

#include <Model/python/PythonActorComponent.h>
#include "RocketMovingComponent.h"

void RocketMovingComponent::OnStart(IActor &actor) {
	rocketPositionComponent_ = actor.getOnlyComponent<PositionComponent>();
	box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
	visibilityModule_.registerClass();
	visibilityModule_.registerActorMethod("sf", &RocketMovingComponent::someStupidFunction );

	//actor.getOnlyComponent<PythonActorComponent>()->makeMethodVisible("someSt", &RocketMovingComponent::someStupidFunction);
}

void RocketMovingComponent::OnUpdate() {
	if( rocketTailDrawing_ == false){
		assert(false && "The rocket tail actor was not set! Shared ptr is null!") ;
	}

	if(keyboardStateProvider_->isPressed(Keys::Player1AccelerateKey)){ /* UGLY AS HELL, my eyes bleed but works*/
		accelerate();
		rocketTailDrawing_->setVisibility(true);
	}  else {
		rocketTailDrawing_->setVisibility(false);
	}
	if (keyboardStateProvider_->isPressed(Keys::Player1LeftKey)){
		box2dComponent_->applyTorque(-actorsConfiguration_->getRocketTurnRate());
	}
	if (keyboardStateProvider_->isPressed(Keys::Player1RightKey)){
		box2dComponent_->applyTorque(actorsConfiguration_->getRocketTurnRate());
	}
}

void RocketMovingComponent::setRocketTail( std::shared_ptr<IActor> tailActor) {
	rocketTailDrawing_ = tailActor->getOnlyComponent<DrawingComponent>();
}

void RocketMovingComponent::accelerate() {
	Point accVec = Point((-1)*(actorsConfiguration_->getRocketAccelerationRate() * sin( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation()))),
							actorsConfiguration_->getRocketAccelerationRate() * cos( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation())));
	box2dComponent_->applyForce(accVec);

}
