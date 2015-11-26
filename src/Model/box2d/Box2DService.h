//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_BOX2DSERVICE_H
#define PWASTEROIDS_BOX2DSERVICE_H


#include <Model/Services/IService.h>
#include <Box2D/Dynamics/b2World.h>
#include <Model/Actors/Actor.h>
#include <Model/PrimitiveTypes/Point.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include "Box2dObject.h"

class Box2DService : public IService {
	b2World world_;
public:
	std::vector< std::shared_ptr<Box2dObject> > objectsToCreate_;

	Box2DService() : world_(b2Vec2(0.0f, 0.0f)) {
	}

	void addObject( std::shared_ptr<Box2dObject> object ){
		auto body = world_.CreateBody( object->getDef() );
		object->setBodyAndCreateFixtures(body);
	}

	void removeObject( std::shared_ptr<Box2dObject> object ){
		// dont expect it to work, but who knows....
		 world_.DestroyBody(object->getBody());
	}


	virtual void OnUpdate(){
		float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
		int32 velocityIterations = 8;   //how strongly to correct velocity
		int32 positionIterations = 3;   //how strongly to correct position


		world_.Step( timeStep, velocityIterations, positionIterations);

	}

};


#endif //PWASTEROIDS_BOX2DSERVICE_H
