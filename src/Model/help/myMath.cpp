//
// Created by defacto on 02.12.15.
//

#include <iostream>
#include "myMath.h"

double  myMath::sinDeg( Rotation rot ) {
	return sin( DegreesCalculations::degreesToRadians(rot)) ;
}

double  myMath::cosDeg( Rotation rot ) {
	return cos( DegreesCalculations::degreesToRadians(rot)) ;
}