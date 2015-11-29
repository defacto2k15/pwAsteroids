//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_ROCKETBOX2DCOMPONENT_H
#define PWASTEROIDS_ROCKETBOX2DCOMPONENT_H


#include <Model/components/Component.h>
#include <Model/box2d/Box2DService.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Model/components/PositionComponent.h>
#include "IRocketConfigurableValues.h"
#include <cmath>
#include <Model/help/DegreesCalculations.h>

class RocketBox2dComponent : public Component{
	std::shared_ptr<Box2DService> box2dService_;
	std::shared_ptr<Box2dObject> rocketBox2dObject_;
	std::shared_ptr<PositionComponent> rocketPositionComponent_;
	std::shared_ptr<IRocketConfigurableValues> configurableValues_;
	b2PolygonShape polygonShape_;

public:
	RocketBox2dComponent( std::shared_ptr<Box2DService> box2dService , std::shared_ptr<IRocketConfigurableValues> configurableValues) :
			box2dService_(box2dService), configurableValues_(configurableValues){

		polygonShape_.SetAsBox(2,2);

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set( configurableValues->getInitialPosition().getX(), configurableValues->getInitialPosition().getY() );
		bodyDef.angle = DegreesCalculations::degreesToRadians( configurableValues->getInitialRotation() );

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &polygonShape_;
		fixtureDef.density = 1;

		std::vector<b2FixtureDef> fixturesVec{fixtureDef};
		rocketBox2dObject_ = std::make_shared<Box2dObject>(bodyDef, fixturesVec);
	}

	virtual void OnStart(IActor &actor){
		rocketPositionComponent_ = actor.getOnlyComponent<PositionComponent>();
		box2dService_->addObject(rocketBox2dObject_);

		rocketPositionComponent_->setPosition(configurableValues_->getInitialPosition());
		rocketPositionComponent_->setRotation(configurableValues_->getInitialRotation());

	}

	virtual void OnUpdate(){
		auto rocketPositionInVec2d = rocketBox2dObject_->getBody()->GetPosition();
		auto rocketRotationInRadians = rocketBox2dObject_->getBody()->GetAngle();

		rocketPositionComponent_->setPosition( Point(rocketPositionInVec2d.x, rocketPositionInVec2d.y));
		rocketPositionComponent_->setRotation( DegreesCalculations::radiansToDegrees(rocketRotationInRadians));
	}

	virtual void OnStop(){
		box2dService_->removeObject(rocketBox2dObject_);
	}

	void accelerate(){ // LOL allways force to the same angle!
		b2Vec2 accVec =  b2Vec2(configurableValues_->getRocketAccelerationRate() * sin( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation())),
		                        configurableValues_->getRocketAccelerationRate() * cos( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation())));
		std::cout<< "Acc vector is x " << accVec.x << " and y is " << accVec.y << std::endl;
		rocketBox2dObject_->getBody()->ApplyForce(accVec,
		                                           rocketBox2dObject_->getBody()->GetWorldCenter(), true);
	}

	void turnLeft(){
		// Moze wygaszajmy obroty jak nikt nic nie klika?
		//std::cout << "AV: "<<rocketBox2dObject_->getBody()->GetAngularVelocity() << std::endl;
		rocketBox2dObject_->getBody()->ApplyTorque(-configurableValues_->getRocketTurnRate(), true);
	}

	void turnRight(){
		rocketBox2dObject_->getBody()->ApplyTorque(configurableValues_->getRocketTurnRate(), true);
	}
private:

};


#endif //PWASTEROIDS_ROCKETBOX2DCOMPONENT_H
