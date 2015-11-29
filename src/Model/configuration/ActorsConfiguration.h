//
// Created by defacto on 27.11.15.
//

#ifndef PWASTEROIDS_ACTORSCONFIGURATION_H
#define PWASTEROIDS_ACTORSCONFIGURATION_H


#include <Model/Actors/Rocket/IRocketConfigurableValues.h>
#include <Model/Actors/RocketTail/IRocketTailConfigurableValues.h>

class ActorsConfiguration : public IRocketConfigurableValues, public IRocketTailConfigurableValues {

public:
	virtual Point getInitialPosition() const;

	virtual Rotation getInitialRotation() const;

	virtual int getRocketAccelerationRate() const;

	virtual int getRocketTurnRate() const;

	virtual ScaleToScreen getRocketScaleToScreen() const;


	virtual int getDistanceBetweenRocketAndTail();
};


#endif //PWASTEROIDS_ACTORSCONFIGURATION_H
