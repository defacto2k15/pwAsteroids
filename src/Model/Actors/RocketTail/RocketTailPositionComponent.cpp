//
// Created by defacto on 28.11.15.
//

#include "RocketTailPositionComponent.h"

void  RocketTailPositionComponent::OnStart(IActor &actor) {
	tailPositionComponent_ = actor.getOnlyComponent<PositionComponent>();
	rocketPositionComponent_ = rocketActor_->getOnlyComponent<PositionComponent>();
}

void  RocketTailPositionComponent::OnUpdate() {
	Point newPos(
			rocketPositionComponent_->getPosition().getX()
			- configurableValues_.getDistanceBetweenRocketAndTail()*myMath::sinDeg(rocketPositionComponent_->getRotation()),
			rocketPositionComponent_->getPosition().getY()
			+ configurableValues_.getDistanceBetweenRocketAndTail()*myMath::cosDeg(rocketPositionComponent_->getRotation()));
	std::cout << " RocketPos " << rocketPositionComponent_->getPosition().toString() << " new pos " << newPos.toString() << std::endl;
	tailPositionComponent_->setPosition(newPos);
	tailPositionComponent_->setRotation(rocketPositionComponent_->getRotation());
}