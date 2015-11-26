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
#include "InitialRocketSettings.h"

class RocketBox2dComponent : public Component{
	std::shared_ptr<Box2DService> box2dService_;
	std::shared_ptr<Box2dObject> rocketBox2dObject_;
	std::shared_ptr<PositionComponent> rocketPositionComponent_;
	b2PolygonShape polygonShape_;
public:
	RocketBox2dComponent( std::shared_ptr<Box2DService> box2dService ) : box2dService_(box2dService){

//		b2Vec2 vertices[6];
//		for (int i = 0; i < 6; i++) {
//			float angle = degreesToRadians(-i/6.0 * 360) ;
//			vertices[i].Set(sinf(angle), cosf(angle));
//		}
//		vertices[0].Set( 0, 4 ); //change one vertex to be pointy
//		polygonShape_.Set(vertices, 6);

		polygonShape_.SetAsBox(2,2);

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set( InitialRocketSettings::initialPosition().getX(), InitialRocketSettings::initialPosition().getY() );
		bodyDef.angle = InitialRocketSettings::initialRotation();

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &polygonShape_;
		fixtureDef.density = 1;

		std::vector<b2FixtureDef> fixturesVec{fixtureDef};
		rocketBox2dObject_ = std::make_shared<Box2dObject>(bodyDef, fixturesVec);
	}

	virtual void OnStart(IActor &actor){
		rocketPositionComponent_ = actor.getOnlyComponent<PositionComponent>();
		box2dService_->addObject(rocketBox2dObject_);

		rocketPositionComponent_->setPosition(InitialRocketSettings::initialPosition());
		rocketPositionComponent_->setRotation(InitialRocketSettings::initialRotation());

	}

	virtual void OnUpdate(){
		auto rocketPositionInVec2d = rocketBox2dObject_->getBody()->GetPosition();
		auto rocketRotationInRadians = rocketBox2dObject_->getBody()->GetAngle();

		rocketPositionComponent_->setPosition( Point(rocketPositionInVec2d.x, rocketPositionInVec2d.y));
		rocketPositionComponent_->setRotation( radiansToDegrees(rocketRotationInRadians));
	}

	virtual void OnStop(){
		box2dService_->removeObject(rocketBox2dObject_);
	}

	void accelerate(){ // LOL allways force to the same angle!
		rocketBox2dObject_->getBody()->ApplyForce( b2Vec2(200, 500), rocketBox2dObject_->getBody()->GetWorldCenter(), true);
	//	rocketBox2dObject_->getBody()->SetTransform( b2Vec2(4.3f, 2.2f), 0.99f);
	}

	void turnLeft(){
		rocketBox2dObject_->getBody()->ApplyTorque(-10, true);
	}

	void turnRight(){
		rocketBox2dObject_->getBody()->ApplyTorque(10, true);
	}
private:
	Rotation radiansToDegrees( float32 rad){
		return rad * 57.295779513082320876f; // ugly but works!
	}

	float degreesToRadians( Rotation degrees ){
		return degrees *0.0174532925199432957f;
	}
};


#endif //PWASTEROIDS_ROCKETBOX2DCOMPONENT_H
