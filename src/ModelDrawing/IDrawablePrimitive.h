//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_IDRAWABLEPRIMITIVE_H
#define PWASTEROIDS_IDRAWABLEPRIMITIVE_H

#include <PrimitiveTypes/AliasedTypes.h>
#include <PrimitiveTypes/ScaleToScreen.h>
#include "src/PrimitiveTypes/Point.h"

class IDrawablePrimitive{
public:
	virtual Point getPosition() const =0;
	virtual Rotation getRotation() const =0;
	virtual ScaleToScreen getScale() const = 0;
};
#endif //PWASTEROIDS_IDRAWABLEPRIMITIVE_H
