//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_DEGREESCALCULATIONS_H
#define PWASTEROIDS_DEGREESCALCULATIONS_H


#include <Model/PrimitiveTypes/Rotation.h>
#include <Box2D/Common/b2Settings.h>

class DegreesCalculations {
public:
	static Rotation radiansToDegrees( double rad);

	static double degreesToRadians( Rotation degrees );
};


#endif //PWASTEROIDS_DEGREESCALCULATIONS_H
