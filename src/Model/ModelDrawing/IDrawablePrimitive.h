//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_IDRAWABLEPRIMITIVE_H
#define PWASTEROIDS_IDRAWABLEPRIMITIVE_H

#include <Model/PrimitiveTypes/AliasedTypes.h>
#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include "Model/PrimitiveTypes/Point.h"

class IDrawablePrimitive{
public:
	virtual Point getPosition() const =0;
	virtual Rotation getRotation() const =0;
	virtual ScaleToScreen getScale() const = 0;
	virtual ~IDrawablePrimitive(){};
};
#endif //PWASTEROIDS_IDRAWABLEPRIMITIVE_H
