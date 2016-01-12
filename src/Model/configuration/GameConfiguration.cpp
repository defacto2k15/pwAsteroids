//
// Created by defacto on 27.11.15.
//

#include <Model/configuration/GameConfiguration.h>



GameConfiguration* GameConfiguration::onlyInstancePointer;

GameConfiguration & configurationGettingFunction(){
   return *GameConfiguration::onlyInstancePointer;
}

GameConfiguration::GameConfiguration(PythonModule &python,  Point AllegroScreenDimensions) :
		python_(python), visibility_(python) {
	onlyInstancePointer = this;

	setScreenSizeInPixels(AllegroScreenDimensions);
	setBox2dScreenDimensions(AllegroToBox2dScale.scalePoint(AllegroScreenDimensions));
	setActorsDestroyRectangle( Rect( -Point(2,2), Box2dScreenDimensions) );

	InitialPosition = Point( getBox2dScreenDimensions().getX()/2, getBox2dScreenDimensions().getY()/2 );
	Point destroyBoundaries(2,2);
	ActorsDestroyRectangle =  Rect(-destroyBoundaries, getBox2dScreenDimensions() + (destroyBoundaries * 2));

	visibility_.registerClass("GameConfiguration");
	visibility_.registerProperty("InitialPosition", &GameConfiguration::getInitialPosition, &GameConfiguration::setInitialPosition);
	visibility_.registerProperty("MinTimeBetweenSecondPlayerShoots", &GameConfiguration::getMinTimeBetweenSecondPlayerShoots, &GameConfiguration::setMinTimeBetweenSecondPlayerShoots   );
	visibility_.registerProperty("TimeofOneFlicker", &GameConfiguration::getTimeofOneFlicker, &GameConfiguration::setTimeofOneFlicker   );
	visibility_.registerProperty("MinTimeBetweenShots", &GameConfiguration::getMinTimeBetweenShots, &GameConfiguration::setMinTimeBetweenShots   );
	visibility_.registerProperty("InitialRotation", &GameConfiguration::getInitialRotation, &GameConfiguration::setInitialRotation   );
	visibility_.registerProperty("RocketAccelerationRate", &GameConfiguration::getRocketAccelerationRate, &GameConfiguration::setRocketAccelerationRate   );
	visibility_.registerProperty("RocketTurnRate", &GameConfiguration::getRocketTurnRate, &GameConfiguration::setRocketTurnRate   );
	visibility_.registerProperty("RocketScaleToScreen", &GameConfiguration::getRocketScaleToScreen, &GameConfiguration::setRocketScaleToScreen   );
	visibility_.registerProperty("DistanceBetweenRocketAndTail", &GameConfiguration::getDistanceBetweenRocketAndTail, &GameConfiguration::setDistanceBetweenRocketAndTail   );
	visibility_.registerProperty("Box2dToAllegroScale", &GameConfiguration::getBox2dToAllegroScale, &GameConfiguration::setBox2dToAllegroScale   );
	visibility_.registerProperty("AllegroToBox2dScale", &GameConfiguration::getAllegroToBox2dScale, &GameConfiguration::setAllegroToBox2dScale   );
	visibility_.registerProperty("Box2dScreenDimensions", &GameConfiguration::getBox2dScreenDimensions, &GameConfiguration::setBox2dScreenDimensions   );
	visibility_.registerProperty("DuplicationBoundariesSize", &GameConfiguration::getDuplicationBoundariesSize, &GameConfiguration::setDuplicationBoundariesSize   );
	visibility_.registerProperty("BoundariesDuplicateActorIdOffset", &GameConfiguration::getBoundariesDuplicateActorIdOffset, &GameConfiguration::setBoundariesDuplicateActorIdOffset   );
	visibility_.registerProperty("AsteroidCreationPropabilityRatio", &GameConfiguration::getAsteroidCreationPropabilityRatio, &GameConfiguration::setAsteroidCreationPropabilityRatio   );
	visibility_.registerProperty("MinTimeBetweenAsteroidsCreation", &GameConfiguration::getMinTimeBetweenAsteroidsCreation, &GameConfiguration::setMinTimeBetweenAsteroidsCreation   );
	visibility_.registerProperty("MaxAsteroidsCount", &GameConfiguration::getMaxAsteroidsCount, &GameConfiguration::setMaxAsteroidsCount   );
	visibility_.registerProperty("AsteroidsGenerationBoundariesSize", &GameConfiguration::getAsteroidsGenerationBoundariesSize, &GameConfiguration::setAsteroidsGenerationBoundariesSize   );
	visibility_.registerProperty("AsteroidMaxInitialImpulse", &GameConfiguration::getAsteroidMaxInitialImpulse, &GameConfiguration::setAsteroidMaxInitialImpulse   );
	visibility_.registerProperty("AsteroidMinInitialImpulse", &GameConfiguration::getAsteroidMinInitialImpulse, &GameConfiguration::setAsteroidMinInitialImpulse   );
	visibility_.registerProperty("AsteroidMinSize", &GameConfiguration::getAsteroidMinSize, &GameConfiguration::setAsteroidMinSize   );
	visibility_.registerProperty("AsteroidMaxSize", &GameConfiguration::getAsteroidMaxSize, &GameConfiguration::setAsteroidMaxSize   );
	visibility_.registerProperty("AsteroidMaxRotationSpeed", &GameConfiguration::getAsteroidMaxRotationSpeed, &GameConfiguration::setAsteroidMaxRotationSpeed   );
	visibility_.registerProperty("ActorsDestroyRectangle", &GameConfiguration::getActorsDestroyRectangle, &GameConfiguration::setActorsDestroyRectangle   );
	visibility_.registerProperty("DistanceBetweenRocketAndProjectile", &GameConfiguration::getDistanceBetweenRocketAndProjectile, &GameConfiguration::setDistanceBetweenRocketAndProjectile   );
	visibility_.registerProperty("ProjectileSpeed", &GameConfiguration::getProjectileSpeed, &GameConfiguration::setProjectileSpeed   );
	visibility_.registerProperty("InitialRocketLife", &GameConfiguration::getInitialRocketLife, &GameConfiguration::setInitialRocketLife   );
	visibility_.registerProperty("TimesRocketImageIsFlickering", &GameConfiguration::getTimesRocketImageIsFlickering, &GameConfiguration::setTimesRocketImageIsFlickering   );
	visibility_.registerProperty("InitialHeartPosition", &GameConfiguration::getInitialHeartPosition, &GameConfiguration::setInitialHeartPosition   );
	visibility_.registerProperty("MaxRocketLifes", &GameConfiguration::getMaxRocketLifes, &GameConfiguration::setMaxRocketLifes   );
	visibility_.registerProperty("ScoreTextPosition", &GameConfiguration::getScoreTextPosition, &GameConfiguration::setScoreTextPosition   );
	visibility_.registerProperty("ScoreByDestroyingAsteroid", &GameConfiguration::getScoreByDestroyingAsteroid, &GameConfiguration::setScoreByDestroyingAsteroid   );
	visibility_.registerProperty("SecondPlayerAsteroidVelocityMultiplayer", &GameConfiguration::getSecondPlayerAsteroidVelocityMultiplayer, &GameConfiguration::setSecondPlayerAsteroidVelocityMultiplayer   );
	visibility_.registerProperty("SecondPlayerAsteroidSizeDivider", &GameConfiguration::getSecondPlayerAsteroidSizeDivider, &GameConfiguration::setSecondPlayerAsteroidSizeDivider   );
	visibility_.registerProperty("MinSecondPlayerAsteroidSize", &GameConfiguration::getMinSecondPlayerAsteroidSize, &GameConfiguration::setMinSecondPlayerAsteroidSize   );
	visibility_.registerProperty("MaxSecondPlayerAsteroidSize", &GameConfiguration::getMaxSecondPlayerAsteroidSize, &GameConfiguration::setMaxSecondPlayerAsteroidSize   );
	visibility_.registerProperty("OnStartPythonScriptPath", &GameConfiguration::getOnStartPythonScriptPath, &GameConfiguration::setOnStartPythonScriptPath);
	visibility_.registerProperty("OnUpdatePythonScriptPath", &GameConfiguration::getOnUpdatePythonScriptPath, &GameConfiguration::setOnUpdatePythonScriptPath);
	visibility_.registerProperty("ScreenSizeInPixels", &GameConfiguration::getScreenSizeInPixels, &GameConfiguration::setScreenSizeInPixels);

	using gameRef = GameConfiguration&;
	std::function< GameConfiguration&() > func = configurationGettingFunction;
	python_.addRootFunctionX("getConfiguration", func);
}