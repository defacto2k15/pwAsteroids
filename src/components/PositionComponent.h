//
// Created by defacto on 24.10.15.
//

#include <Component.h>
#include <PrimitiveTypes/Point.h>
#include <PrimitiveTypes/AliasedTypes.h>

#ifndef PWASTEROIDS_POSITIONCOMPONENT_H
#define PWASTEROIDS_POSITIONCOMPONENT_H

class PositionComponent : public Component{
	Point position_;
	Rotation rotation_;

public:
	PositionComponent();

	Point getPosition() const;

	Rotation getRotation() const;

	void setPosition( Point newPos);

	void setX( double newX);

	void setY(double newY );

	void moveBy( Point moveVector );

	void setRotation( Rotation newRotation );

	void rotateBy( double toRotate );

};


#endif //PWASTEROIDS_POSITIONCOMPONENT_H
