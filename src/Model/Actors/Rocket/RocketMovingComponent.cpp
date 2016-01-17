//
// Created by defacto on 26.10.15.
//

#include <Model/python/PythonActorComponent.h>
#include "RocketMovingComponent.h"
#include <iostream>

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

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

	if(inputStateProvider_->isPressed(Keys::Player1AccelerateKey)){ /* UGLY AS HELL, my eyes bleed but works*/
		accelerate();
		rocketTailDrawing_->setVisibility(true);
	}  else {
		rocketTailDrawing_->setVisibility(false);
	}
	auto turnRate = (double(timeProvider_->getMilisecondsBetweenFrames()) / 1000) * -gameConfiguration_.getRocketTurnRate();

	if (inputStateProvider_->isPressed(Keys::Player1LeftKey)){
		box2dComponent_->applyTorque(turnRate);
	}
	if (inputStateProvider_->isPressed(Keys::Player1RightKey)){
		box2dComponent_->applyTorque(-turnRate);
	}
}

void RocketMovingComponent::setRocketTail( std::shared_ptr<IActor> tailActor) {
	rocketTailDrawing_ = tailActor->getOnlyComponent<DrawingComponent>();
}

void RocketMovingComponent::accelerate() {
	auto currentSpeed = box2dComponent_->getLineralVelocity();

	auto acceleration = (double(timeProvider_->getMilisecondsBetweenFrames()) / 1000) * -gameConfiguration_.getRocketAccelerationRate();
	Point accVec = Point((-1)*(acceleration * sin( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation()))),
						 acceleration * cos( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation())));
	//double xDelta =;
	accVec += Point( calculateAccelerationDelta(currentSpeed.getX(), accVec.getX() ),
					 calculateAccelerationDelta(currentSpeed.getY(), accVec.getY() ));

	//std::cout << "AFS " << adjustedSpeed.toString() << " and " <<  ()<< std::endl;
	box2dComponent_->applyForce(accVec);

}

RocketMovingComponent::RocketMovingComponent(std::shared_ptr<IInputStateProvider> inputStateProvider, PythonModule &pythonModule,
											 GameConfiguration &gameConfiguration, std::shared_ptr<GameTimeProvider> timeProvider)
		: inputStateProvider_(inputStateProvider), visibilityModule_(pythonModule),
		  gameConfiguration_(gameConfiguration), timeProvider_(timeProvider) {
}

double RocketMovingComponent::calculateAccelerationDelta(double velocity, double acceleration) {
	double xDelta =  fabs(velocity + acceleration ) - fabs(velocity );
	if(xDelta < 0){
		return sgn(velocity)*xDelta*2;
	} else {
		return 0;
	}
}
