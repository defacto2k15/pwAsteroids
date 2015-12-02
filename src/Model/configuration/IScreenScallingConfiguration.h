//
// Created by defacto on 01.12.15.
//

#ifndef PWASTEROIDS_ISCREENSCALLINGCONFIGURATION_H
#define PWASTEROIDS_ISCREENSCALLINGCONFIGURATION_H

#include <Model/PrimitiveTypes/ScaleToScreen.h>

class IScreenScalingConfiguration{
public:
	virtual ScaleToScreen getBox2dToAllegroScale() const = 0;
};

#endif //PWASTEROIDS_ISCREENSCALLINGCONFIGURATION_H
