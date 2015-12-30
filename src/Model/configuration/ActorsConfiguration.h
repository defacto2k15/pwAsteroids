//
// Created by defacto on 27.11.15.
//

#ifndef PWASTEROIDS_ACTORSCONFIGURATION_H
#define PWASTEROIDS_ACTORSCONFIGURATION_H


#include <Model/Actors/Rocket/IRocketConfigurableValues.h>
#include <Model/Actors/RocketTail/IRocketTailConfigurableValues.h>
#include <Model/PrimitiveTypes/Rect.h>
#include "IScreenScallingConfiguration.h"
#include "IImageCenteringConfiguration.h"

class ActorsConfiguration : public IRocketConfigurableValues,
                            public IRocketTailConfigurableValues,
                            public IScreenScalingConfiguration,
							public IImageCenteringConfiguration {

public:
	virtual Point getInitialPosition() const;

	virtual Rotation getInitialRotation() const;

	virtual double getRocketAccelerationRate() const;

	virtual double getRocketTurnRate() const;

	virtual ScaleToScreen getRocketScaleToScreen() const;


	virtual float getDistanceBetweenRocketAndTail();

	virtual ScaleToScreen getBox2dToAllegroScale()const override;

	virtual Point getBox2dScreenDimensions() const;

	virtual Point GetDuplicationBoundariesSize() const;

	virtual ActorId getBoundariesDuplicateActorIdOffset() const;

	unsigned int getAsteroidCreationPropabilityRatio() const;

	unsigned int GetMinTimeBetweenAsteroidsCreation() const;

	unsigned int GetMaxAsteroidsCount() const;

	Point GetAsteroidsGenerationBoundariesSize() const;

	double GetAsteroidMaxInitialImpulse();

	double GetAsteroidMinInitialImpulse();

	double GetAsteroidMinSize();

	double GetAsteroidMaxSize();

	double GetAsteroidMaxRotationSpeed();

	Rect getActorsDestroyRectangle();

	unsigned long getMinTimeBetweenShots();

	double getDistanceBetweenRocketAndProjectile();

	double getProjectileSpeed();

	unsigned int getInitialRocketLife(){
		return 3;
	}

	unsigned int getTimesRocketImageIsFlickering(){
		return 4;
	}

	unsigned long getTimeofOneFlicker(){
		return 400;
	}

	Point getInitialHeartPosition(){
		return Point(1,1);
	}

	unsigned int getMaxRocketLifes(){
		return 5;
	}

};


#endif //PWASTEROIDS_ACTORSCONFIGURATION_H
