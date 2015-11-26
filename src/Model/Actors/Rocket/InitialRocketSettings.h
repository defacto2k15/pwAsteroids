//
// Created by defacto on 25.11.15.
//

#ifndef PWASTEROIDS_INITIALROCKETSETTINGS_H
#define PWASTEROIDS_INITIALROCKETSETTINGS_H


#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>

class InitialRocketSettings {
public:
	static  Point initialPosition();

	static  Rotation initialRotation();
};


#endif //PWASTEROIDS_INITIALROCKETSETTINGS_H
