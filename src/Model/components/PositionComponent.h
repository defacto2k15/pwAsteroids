//
// Created by defacto on 24.10.15.
//

#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include <Model/python/PythonClassVisibilityModule.h>
#include "Component.h"

#ifndef PWASTEROIDS_POSITIONCOMPONENT_H
#define PWASTEROIDS_POSITIONCOMPONENT_H

class PositionComponent : public Component{
	Point position_;
	Rotation rotation_;
	PythonClassVisibilityModule<PositionComponent> visibility_;

public:
	PositionComponent( PythonModule &python);

	Point getPosition() ;

	Rotation getRotation() ;

	void setPosition( Point newPos);

	void setX( double newX);

	void setY(double newY );

	void moveBy( Point moveVector );

	void setRotation( Rotation newRotation );

	void rotateBy( double toRotate );

	void OnStart( IActor &actor) override{
		visibility_.registerClass();
		visibility_.registerActorMethod("getPosition", &PositionComponent::getPosition);
		visibility_.registerActorMethod("getRotation", &PositionComponent::getRotation);
	}

};


#endif //PWASTEROIDS_POSITIONCOMPONENT_H
