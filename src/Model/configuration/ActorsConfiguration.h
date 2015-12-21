//
// Created by defacto on 27.11.15.
//

#ifndef PWASTEROIDS_ACTORSCONFIGURATION_H
#define PWASTEROIDS_ACTORSCONFIGURATION_H


#include <Model/Actors/Rocket/IRocketConfigurableValues.h>
#include <Model/Actors/RocketTail/IRocketTailConfigurableValues.h>
#include "IScreenScallingConfiguration.h"
#include "IImageCenteringConfiguration.h"

class ActorsConfiguration : public IRocketConfigurableValues,
                            public IRocketTailConfigurableValues,
                            public IScreenScalingConfiguration,
							public IImageCenteringConfiguration {

public:
	virtual Point getInitialPosition() const;

	virtual Rotation getInitialRotation() const;

	virtual int getRocketAccelerationRate() const;

	virtual int getRocketTurnRate() const;

	virtual ScaleToScreen getRocketScaleToScreen() const;


	virtual float getDistanceBetweenRocketAndTail();

	virtual ScaleToScreen getBox2dToAllegroScale()const override;

	virtual Point getBox2dScreenDimensions() const;
};


#endif //PWASTEROIDS_ACTORSCONFIGURATION_H
