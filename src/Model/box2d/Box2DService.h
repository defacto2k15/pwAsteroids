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

	Box2DService() : world_(b2Vec2(0.0f, 0.0f)) {
	}

	void addObject( std::shared_ptr<Box2dObject> object );

	void removeObject( std::shared_ptr<Box2dObject> object );


	virtual void OnUpdate();

};


#endif //PWASTEROIDS_BOX2DSERVICE_H
