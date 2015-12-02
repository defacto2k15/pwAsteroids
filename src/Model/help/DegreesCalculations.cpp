//
// Created by defacto on 28.11.15.
//

#include "DegreesCalculations.h"

Rotation DegreesCalculations::radiansToDegrees( double rad) {
	return rad * 57.295779513082320876f; // ugly but works!
}

double DegreesCalculations::degreesToRadians( Rotation degrees ) {
	double newDegrees =  degrees *0.0174532925199432957f;
	return newDegrees;
}