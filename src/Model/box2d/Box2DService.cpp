//
// Created by defacto on 09.11.15.
//

#include "Box2DService.h"

void Box2DService::addObject( std::shared_ptr<Box2dObject> object ) {

	auto body = world_.CreateBody( object->getDef() );
	object->setBodyAndCreateFixtures(body);
}

void Box2DService::removeObject( std::shared_ptr<Box2dObject> object ) {
	// dont expect it to work, but who knows....
	world_.DestroyBody(object->getBody());
}

void Box2DService::OnUpdate() {
	float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	int32 velocityIterations = 8;   //how strongly to correct velocity
	int32 positionIterations = 3;   //how strongly to correct position

	if( isOn_ ) {
		world_.Step(timeStep, velocityIterations, positionIterations);
	}

}