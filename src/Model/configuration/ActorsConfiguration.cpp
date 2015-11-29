//
// Created by defacto on 27.11.15.
//

#include "ActorsConfiguration.h"

Point ActorsConfiguration::getInitialPosition() const {
	return Point(100.0f, 100.0f);
}

Rotation ActorsConfiguration::getInitialRotation() const {
	return 180;
}

int ActorsConfiguration::getRocketAccelerationRate() const {
	return -200;
}

int ActorsConfiguration::getRocketTurnRate() const {
	return 10;
}

ScaleToScreen ActorsConfiguration::getRocketScaleToScreen() const {
	return ScaleToScreen(0.05f, 0.05f);
}

int ActorsConfiguration::getDistanceBetweenRocketAndTail() {
	return 20;
}
