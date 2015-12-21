//
// Created by defacto on 02.12.15.
//

#ifndef PWASTEROIDS_MYMATH_H
#define PWASTEROIDS_MYMATH_H


#include <Model/PrimitiveTypes/Rotation.h>
#include <cmath>
#include "DegreesCalculations.h"

class myMath {
public:
	static double sinDeg( Rotation rot );

	static double cosDeg( Rotation rot );
};


#endif //PWASTEROIDS_MYMATH_H
