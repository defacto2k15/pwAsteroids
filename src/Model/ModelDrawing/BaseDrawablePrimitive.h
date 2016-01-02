//
// Created by defacto on 2016.01.02..
//

#ifndef PWASTEROIDS_BASEDRAWABLEPRIMITIVE_H
#define PWASTEROIDS_BASEDRAWABLEPRIMITIVE_H


#include <Model/PrimitiveTypes/Rotation.h>
#include "IDrawablePrimitive.h"

class BaseDrawablePrimitive : public IDrawablePrimitive {
    Point position_;
    Rotation rotation_;
    ScaleToScreen scale_;
	ActorId id_;
public:
	BaseDrawablePrimitive(const Point &position_, const Rotation &rotation_, const ScaleToScreen &scale_, const ActorId &id);

	virtual Point getPosition() const;;

	virtual void setPosition(Point newPosition);;

	virtual Rotation getRotation() const;;

	virtual void setRotation(Rotation rotation);;

	virtual ScaleToScreen getScale() const;;

	virtual ActorId getActorId() const;;
};


#endif //PWASTEROIDS_BASEDRAWABLEPRIMITIVE_H
