//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_ROCKETTAILPOSITIONCOMPONENT_H
#define PWASTEROIDS_ROCKETTAILPOSITIONCOMPONENT_H


#include <Model/components/Component.h>
#include <Model/components/PositionComponent.h>
#include <cmath>
#include <Model/help/DegreesCalculations.h>
#include <Model/help/myMath.h>
#include <Model/configuration/ActorsConfiguration.h>

class RocketTailPositionComponent : public Component {
	std::shared_ptr<IActor> rocketActor_;
	ActorsConfiguration &configurableValues_;
	std::shared_ptr<PositionComponent> tailPositionComponent_;
	std::shared_ptr<PositionComponent> rocketPositionComponent_;
public:
	RocketTailPositionComponent( std::shared_ptr<IActor> rocketActor, ActorsConfiguration &values )
			: rocketActor_( rocketActor ), configurableValues_(values){
	}

	virtual void OnStart(IActor &actor);

	virtual void OnUpdate();

	virtual void OnStop(){

	}

};


#endif //PWASTEROIDS_ROCKETTAILPOSITIONCOMPONENT_H
