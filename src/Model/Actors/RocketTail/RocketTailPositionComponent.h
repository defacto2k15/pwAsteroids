//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_ROCKETTAILPOSITIONCOMPONENT_H
#define PWASTEROIDS_ROCKETTAILPOSITIONCOMPONENT_H


#include <Model/components/Component.h>
#include <Model/components/PositionComponent.h>
#include "IRocketTailConfigurableValues.h"
#include <cmath>
#include <Model/help/DegreesCalculations.h>
#include <Model/help/myMath.h>

class RocketTailPositionComponent : public Component {
	std::shared_ptr<IActor> rocketActor_;
	std::shared_ptr<IRocketTailConfigurableValues> configurableValues_;
	std::shared_ptr<PositionComponent> tailPositionComponent_;
	std::shared_ptr<PositionComponent> rocketPositionComponent_;
public:
	RocketTailPositionComponent( std::shared_ptr<IActor> rocketActor, std::shared_ptr<IRocketTailConfigurableValues> values )
			: rocketActor_( rocketActor ), configurableValues_(values){
	}

	virtual void OnStart(IActor &actor){
		tailPositionComponent_ = actor.getOnlyComponent<PositionComponent>();
		rocketPositionComponent_ = rocketActor_->getOnlyComponent<PositionComponent>();
	}

	virtual void OnUpdate(){
		Point newPos(
				rocketPositionComponent_->getPosition().getX()
						- configurableValues_->getDistanceBetweenRocketAndTail()*myMath::sinDeg(rocketPositionComponent_->getRotation()),
				rocketPositionComponent_->getPosition().getY()
						+ configurableValues_->getDistanceBetweenRocketAndTail()*myMath::cosDeg(rocketPositionComponent_->getRotation()));
		tailPositionComponent_->setPosition(newPos);
		tailPositionComponent_->setRotation(rocketPositionComponent_->getRotation());
	}

	virtual void OnStop(){

	}

};


#endif //PWASTEROIDS_ROCKETTAILPOSITIONCOMPONENT_H
