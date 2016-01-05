//
// Created by defacto on 24.10.15.
//

#include <Model/python/PythonModule.h>
#include "PositionComponent.h"

PositionComponent::PositionComponent( PythonModule &python)
		: position_(0.0, 0.0), rotation_(0.0), visibility_(python) {
}

Point PositionComponent::getPosition()  {
	return position_;
}

Rotation PositionComponent::getRotation()  {
	return rotation_;
}

void PositionComponent::setPosition( Point newPos) {
	position_ = newPos;
}

void PositionComponent::setX( double newX) {
	position_ = Point( newX, position_.getY() );
}

void PositionComponent::setY(double newY ) {
	position_ = Point(position_.getX(), newY );
}

void PositionComponent::moveBy( Point moveVector ) {
	position_.move(moveVector.getX(), moveVector.getY());
}

void PositionComponent::setRotation( Rotation newRotation ) {
	rotation_ = newRotation;
}

void PositionComponent::rotateBy( double toRotate ) {
	rotation_+=toRotate;
}

