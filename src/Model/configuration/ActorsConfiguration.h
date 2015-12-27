//
// Created by defacto on 27.11.15.
//

#ifndef PWASTEROIDS_ACTORSCONFIGURATION_H
#define PWASTEROIDS_ACTORSCONFIGURATION_H


#include <Model/Actors/Rocket/IRocketConfigurableValues.h>
#include <Model/Actors/RocketTail/IRocketTailConfigurableValues.h>
#include <Model/PrimitiveTypes/Rectangle.h>
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

	/* Asteroids generation */
	unsigned int getAsteroidCreationPropabilityRatio() const{
		return 2;
	}

	unsigned int GetMinTimeBetweenAsteroidsCreation() const{
		return 4000;
	}

	unsigned int GetMaxAsteroidsCount() const{
		return 12;
	}

	Point GetAsteroidsGenerationBoundariesSize() const {
		return Point(0.001, 0.001);
	}

	double GetAsteroidMaxInitialImpulse(){
		return 0.15;
	}

	double GetAsteroidMinInitialImpulse(){
		return 0.05;
	}

	double GetAsteroidMinSize(){
		return 0.1;
	}

	double GetAsteroidMaxSize(){
		return 0.4;
	}

	double GetAsteroidMaxRotationSpeed(){
		return 0.08;
	}

	Rectangle getActorsDestroyRectangle(){
		Point destroyBoundaries(2,2);
		return Rectangle( -destroyBoundaries, getBox2dScreenDimensions() + (destroyBoundaries*2));
	}

};


#endif //PWASTEROIDS_ACTORSCONFIGURATION_H
