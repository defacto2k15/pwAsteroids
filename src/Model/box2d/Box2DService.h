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
#include <Model/collisions/MyContactListener.h>
#include "Box2dObject.h"

class Box2DService : public IService {
	b2World world_;
	bool isOn_ = true;
public:

	Box2DService( MyContactListener *contactListener) : world_(b2Vec2(0.0f, 0.0f)) {
		world_.SetContactListener( contactListener );
	}

	void addObject( std::shared_ptr<Box2dObject> object );

	void removeObject( std::shared_ptr<Box2dObject> object );


	virtual void OnUpdate();

	void turnOffSimulation(){
		isOn_ = false;
	}

	void turnOnSimulation(){
		isOn_ = true;
	}

};


#endif //PWASTEROIDS_BOX2DSERVICE_H
