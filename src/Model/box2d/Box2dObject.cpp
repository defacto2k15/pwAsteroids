//
// Created by defacto on 09.11.15.
//

#include "Box2dObject.h"
#include <iostream>

const b2BodyDef *Box2dObject::getDef() {
	return &bodyDef_;
}

void Box2dObject::setBodyAndCreateFixtures( b2Body *body) {
	body_ = body;
	for( auto& oneFixtureDef : fixtureDefVec_ ){
		auto fixture = body_->CreateFixture(&oneFixtureDef);
		createdFixtures_.push_back(fixture);
	}

}

b2Body *Box2dObject::getBody() {
	return body_;
}

std::vector<b2Fixture*> Box2dObject::getFixtures() {
	return createdFixtures_;
}

double Box2dObject::getMass() {
	return mass_;
}

Point Box2dObject::getBoxSize() {
	return boxSize_;
}