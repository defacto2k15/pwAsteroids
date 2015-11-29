//
// Created by defacto on 28.11.15.
//

#include "DegreesCalculations.h"

Rotation DegreesCalculations::radiansToDegrees( float32 rad) {
	return rad * 57.295779513082320876f; // ugly but works!
}

float DegreesCalculations::degreesToRadians( Rotation degrees ) {
	return degrees *0.0174532925199432957f;
}