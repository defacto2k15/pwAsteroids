//
// Created by defacto on 27.11.15.
//

#include "ActorsConfiguration.h"

Point ActorsConfiguration::getInitialPosition() const {
	return Point( getBox2dScreenDimensions().getX()/2, getBox2dScreenDimensions().getY()/2);
}

Rotation ActorsConfiguration::getInitialRotation() const {
	return 0;
}

int ActorsConfiguration::getRocketAccelerationRate() const {
	return -3;
}

int ActorsConfiguration::getRocketTurnRate() const {
	return 3;
}

ScaleToScreen ActorsConfiguration::getRocketScaleToScreen() const {
	return ScaleToScreen(0.05f, 0.05f);
}

float ActorsConfiguration::getDistanceBetweenRocketAndTail() {
	return 0.5f;
}

ScaleToScreen ActorsConfiguration::getBox2dToAllegroScale() const {
	return ScaleToScreen( 100.0f, 100.0f);
}

Point ActorsConfiguration::getBox2dScreenDimensions() const {
	return Point( 10.24f, 6.00f);
}
