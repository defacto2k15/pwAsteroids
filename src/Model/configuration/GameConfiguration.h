//
// Created by defacto on 27.11.15.
//

#ifndef PWASTEROIDS_ACTORSCONFIGURATION_H
#define PWASTEROIDS_ACTORSCONFIGURATION_H


#include <Model/PrimitiveTypes/Rect.h>
#include <Model/PrimitiveTypes/Rotation.h>
#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>

class GameConfiguration {

public:
	virtual Point getInitialPosition() const;

	virtual Rotation getInitialRotation() const;

	virtual double getRocketAccelerationRate() const;

	virtual double getRocketTurnRate() const;

	virtual ScaleToScreen getRocketScaleToScreen() const;

	virtual float getDistanceBetweenRocketAndTail();

	virtual ScaleToScreen getBox2dToAllegroScale()const;

	virtual ScaleToScreen getAllegroToBox2dScale() const;

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

	unsigned int getInitialRocketLife();

	unsigned int getTimesRocketImageIsFlickering();

	unsigned long getTimeofOneFlicker();

	Point getInitialHeartPosition();

	unsigned int getMaxRocketLifes();

	Point getScoreTextPosition();

	unsigned int getScoreByDestroyingAsteroid();

	unsigned long getMinTimeBetweenSecondPlayerShoots();

	double getSecondPlayerAsteroidVelocityMultiplayer();

	double getSecondPlayerAsteroidSizeDivider();

	double getMinSecondPlayerAsteroidSize();

	double getMaxSecondPlayerAsteroidSize();

};


#endif //PWASTEROIDS_ACTORSCONFIGURATION_H
