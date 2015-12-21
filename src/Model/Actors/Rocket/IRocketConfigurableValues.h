//
// Created by defacto on 27.11.15.
//

#ifndef PWASTEROIDS_IROCKETCONFIGURABLEVALUES_H
#define PWASTEROIDS_IROCKETCONFIGURABLEVALUES_H

#include <Model/PrimitiveTypes/AliasedTypes.h>
#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/ScaleToScreen.h>

class IRocketConfigurableValues {
public:
	virtual Point getInitialPosition() const = 0;
	virtual Rotation getInitialRotation() const = 0;
	virtual int getRocketAccelerationRate() const = 0;
	virtual int getRocketTurnRate() const = 0;
	virtual ScaleToScreen getRocketScaleToScreen() const = 0;
};
#endif //PWASTEROIDS_IROCKETCONFIGURABLEVALUES_H
