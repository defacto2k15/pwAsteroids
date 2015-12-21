//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_BOX2DOBJECT_H
#define PWASTEROIDS_BOX2DOBJECT_H


#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <vector>
#include <iostream>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2World.h>

class Box2dObject {
	b2Body *body_;
	b2BodyDef bodyDef_;
	std::vector<b2FixtureDef> fixtureDefVec_;
	std::vector<b2Fixture*> createdFixtures_;
public:
	Box2dObject(b2BodyDef def, std::vector<b2FixtureDef> fixtureDefVec) : bodyDef_(def), fixtureDefVec_(fixtureDefVec){
	}

	const b2BodyDef * getDef();

	void setBodyAndCreateFixtures( b2Body *body);

	b2Body * getBody();

	std::vector<b2Fixture*> getFixtures();

};


#endif //PWASTEROIDS_BOX2DOBJECT_H
