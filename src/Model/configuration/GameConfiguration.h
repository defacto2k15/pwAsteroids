//
// Created by defacto on 27.11.15.
//

#ifndef PWASTEROIDS_ACTORSCONFIGURATION_H
#define PWASTEROIDS_ACTORSCONFIGURATION_H


#include <Model/PrimitiveTypes/Rect.h>
#include <Model/PrimitiveTypes/Rotation.h>
#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include <Model/python/PythonModule.h>
#include <Model/python/PythonClassVisibilityModule.h>

class GameConfiguration;
GameConfiguration & configurationGettingFunction();


class GameConfiguration {

	Point  InitialPosition = Point( 0,0);
	Rotation  InitialRotation = 90;
	double  RocketAccelerationRate = -3;
	double  RocketTurnRate = 0.8f;
	ScaleToScreen  RocketScaleToScreen = ScaleToScreen(0.05f, 0.05f);
	float  DistanceBetweenRocketAndTail = 0.5f;
	ScaleToScreen  Box2dToAllegroScale = ScaleToScreen( 100.0f, 100.0f);
	ScaleToScreen  AllegroToBox2dScale = ScaleToScreen(0.01f,0.01f);
	Point  Box2dScreenDimensions = Point( 10.24f, 6.00f);
	Point  DuplicationBoundariesSize = Point(1.0f, 1.0f);
	ActorId  BoundariesDuplicateActorIdOffset = 10000;
	unsigned  AsteroidCreationPropabilityRatio = 2;
	unsigned  MinTimeBetweenAsteroidsCreation = 4000;
	unsigned  MaxAsteroidsCount = 12;
	Point  AsteroidsGenerationBoundariesSize = Point(0.001, 0.001);
	double  AsteroidMaxInitialImpulse = 0.15f;
	double  AsteroidMinInitialImpulse = 0.05f;
	double  AsteroidMinSize = 0.1f;
	double  AsteroidMaxSize = 0.4f;
	double  AsteroidMaxRotationSpeed = 0.08f;
	Rect  ActorsDestroyRectangle = Rect( -Point(2,2), Point(10.24, 6.00f));
	unsigned long MinTimeBetweenShots = 200; //
	double  DistanceBetweenRocketAndProjectile = 0.2f;
	double  ProjectileSpeed = 1.8f;
	unsigned  InitialRocketLife = 3;
	unsigned  TimesRocketImageIsFlickering = 4;
	unsigned long TimeofOneFlicker = 400;  //
	Point  InitialHeartPosition = Point(1,1);
	unsigned  MaxRocketLifes = 5;
	Point  ScoreTextPosition = Point(8,5);
	unsigned  ScoreByDestroyingAsteroid = 10;
	unsigned long MinTimeBetweenSecondPlayerShoots = 300;  //
	double  SecondPlayerAsteroidVelocityMultiplayer = 0.4f;
	double  SecondPlayerAsteroidSizeDivider = 3.0f;
	double  MinSecondPlayerAsteroidSize = 0.15f;
	double  MaxSecondPlayerAsteroidSize = 3.5f;
	std::string OnStartPythonScriptPath = "../res/OnStart.py";
	std::string OnUpdatePythonScriptPath = "../res/OnUpdate.py";

	PythonClassVisibilityModule<GameConfiguration> visibility_;
	PythonModule &python_;
public:
	static GameConfiguration* onlyInstancePointer;

	GameConfiguration(PythonModule &python) : python_(python), visibility_(python){
		onlyInstancePointer = this;

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

		using gameRef = GameConfiguration&;
		std::function< GameConfiguration&() > func = configurationGettingFunction;
		python_.addRootFunctionX("getConfiguration", func);
	}



	Point getInitialPosition() const {
		return InitialPosition;
	}

	void setInitialPosition(Point InitialPosition) {
		GameConfiguration::InitialPosition = InitialPosition;
	}

	Rotation getInitialRotation() const {
		return InitialRotation;
	}

	void setInitialRotation(Rotation InitialRotation) {
		GameConfiguration::InitialRotation = InitialRotation;
	}

	double getRocketAccelerationRate() const {
		return RocketAccelerationRate;
	}

	void setRocketAccelerationRate(double RocketAccelerationRate) {
		GameConfiguration::RocketAccelerationRate = RocketAccelerationRate;
	}

	double getRocketTurnRate() const {
		return RocketTurnRate;
	}

	void setRocketTurnRate(double RocketTurnRate) {
		GameConfiguration::RocketTurnRate = RocketTurnRate;
	}

	ScaleToScreen getRocketScaleToScreen() const {
		return RocketScaleToScreen;
	}

	void setRocketScaleToScreen(ScaleToScreen RocketScaleToScreen) {
		GameConfiguration::RocketScaleToScreen = RocketScaleToScreen;
	}

	float getDistanceBetweenRocketAndTail() const {
		return DistanceBetweenRocketAndTail;
	}

	void setDistanceBetweenRocketAndTail(float DistanceBetweenRocketAndTail) {
		GameConfiguration::DistanceBetweenRocketAndTail = DistanceBetweenRocketAndTail;
	}

	ScaleToScreen getBox2dToAllegroScale() const {
		return Box2dToAllegroScale;
	}

	void setBox2dToAllegroScale(ScaleToScreen Box2dToAllegroScale) {
		GameConfiguration::Box2dToAllegroScale = Box2dToAllegroScale;
	}

	ScaleToScreen getAllegroToBox2dScale() const {
		return AllegroToBox2dScale;
	}

	void setAllegroToBox2dScale(ScaleToScreen AllegroToBox2dScale) {
		GameConfiguration::AllegroToBox2dScale = AllegroToBox2dScale;
	}

	Point getBox2dScreenDimensions() const {
		return Box2dScreenDimensions;
	}

	void setBox2dScreenDimensions(Point Box2dScreenDimensions) {
		GameConfiguration::Box2dScreenDimensions = Box2dScreenDimensions;
	}

	Point getDuplicationBoundariesSize() const {
		return DuplicationBoundariesSize;
	}

	void setDuplicationBoundariesSize(Point DuplicationBoundariesSize) {
		GameConfiguration::DuplicationBoundariesSize = DuplicationBoundariesSize;
	}

	ActorId getBoundariesDuplicateActorIdOffset() const {
		return BoundariesDuplicateActorIdOffset;
	}

	void setBoundariesDuplicateActorIdOffset(ActorId BoundariesDuplicateActorIdOffset) {
		GameConfiguration::BoundariesDuplicateActorIdOffset = BoundariesDuplicateActorIdOffset;
	}

	unsigned int getAsteroidCreationPropabilityRatio() const {
		return AsteroidCreationPropabilityRatio;
	}

	void setAsteroidCreationPropabilityRatio(unsigned int AsteroidCreationPropabilityRatio) {
		GameConfiguration::AsteroidCreationPropabilityRatio = AsteroidCreationPropabilityRatio;
	}

	unsigned int getMinTimeBetweenAsteroidsCreation() const {
		return MinTimeBetweenAsteroidsCreation;
	}

	void setMinTimeBetweenAsteroidsCreation(unsigned int MinTimeBetweenAsteroidsCreation) {
		GameConfiguration::MinTimeBetweenAsteroidsCreation = MinTimeBetweenAsteroidsCreation;
	}

	unsigned int getMaxAsteroidsCount() const {
		return MaxAsteroidsCount;
	}

	void setMaxAsteroidsCount(unsigned int MaxAsteroidsCount) {
		GameConfiguration::MaxAsteroidsCount = MaxAsteroidsCount;
	}

	Point getAsteroidsGenerationBoundariesSize() const {
		return AsteroidsGenerationBoundariesSize;
	}

	void setAsteroidsGenerationBoundariesSize(Point AsteroidsGenerationBoundariesSize) {
		GameConfiguration::AsteroidsGenerationBoundariesSize = AsteroidsGenerationBoundariesSize;
	}

	double getAsteroidMaxInitialImpulse() const {
		return AsteroidMaxInitialImpulse;
	}

	void setAsteroidMaxInitialImpulse(double AsteroidMaxInitialImpulse) {
		GameConfiguration::AsteroidMaxInitialImpulse = AsteroidMaxInitialImpulse;
	}

	double getAsteroidMinInitialImpulse() const {
		return AsteroidMinInitialImpulse;
	}

	void setAsteroidMinInitialImpulse(double AsteroidMinInitialImpulse) {
		GameConfiguration::AsteroidMinInitialImpulse = AsteroidMinInitialImpulse;
	}

	double getAsteroidMinSize() const {
		return AsteroidMinSize;
	}

	void setAsteroidMinSize(double AsteroidMinSize) {
		GameConfiguration::AsteroidMinSize = AsteroidMinSize;
	}

	double getAsteroidMaxSize() const {
		return AsteroidMaxSize;
	}

	void setAsteroidMaxSize(double AsteroidMaxSize) {
		GameConfiguration::AsteroidMaxSize = AsteroidMaxSize;
	}

	double getAsteroidMaxRotationSpeed() const {
		return AsteroidMaxRotationSpeed;
	}

	void setAsteroidMaxRotationSpeed(double AsteroidMaxRotationSpeed) {
		GameConfiguration::AsteroidMaxRotationSpeed = AsteroidMaxRotationSpeed;
	}

	Rect getActorsDestroyRectangle() const {
		return ActorsDestroyRectangle;
	}

	void setActorsDestroyRectangle(Rect ActorsDestroyRectangle) {
		GameConfiguration::ActorsDestroyRectangle = ActorsDestroyRectangle;
	}

	unsigned long getMinTimeBetweenShots() const {
		return MinTimeBetweenShots;
	}

	void setMinTimeBetweenShots(unsigned long MinTimeBetweenShots) {
		GameConfiguration::MinTimeBetweenShots = MinTimeBetweenShots;
	}

	double getDistanceBetweenRocketAndProjectile() const {
		return DistanceBetweenRocketAndProjectile;
	}

	void setDistanceBetweenRocketAndProjectile(double DistanceBetweenRocketAndProjectile) {
		GameConfiguration::DistanceBetweenRocketAndProjectile = DistanceBetweenRocketAndProjectile;
	}

	double getProjectileSpeed() const {
		return ProjectileSpeed;
	}

	void setProjectileSpeed(double ProjectileSpeed) {
		GameConfiguration::ProjectileSpeed = ProjectileSpeed;
	}

	unsigned int getInitialRocketLife() const {
		return InitialRocketLife;
	}

	void setInitialRocketLife(unsigned int InitialRocketLife) {
		GameConfiguration::InitialRocketLife = InitialRocketLife;
	}

	unsigned int getTimesRocketImageIsFlickering() const {
		return TimesRocketImageIsFlickering;
	}

	void setTimesRocketImageIsFlickering(unsigned int TimesRocketImageIsFlickering) {
		GameConfiguration::TimesRocketImageIsFlickering = TimesRocketImageIsFlickering;
	}

	unsigned long getTimeofOneFlicker() const {
		return TimeofOneFlicker;
	}

	void setTimeofOneFlicker(unsigned long TimeofOneFlicker) {
		GameConfiguration::TimeofOneFlicker = TimeofOneFlicker;
	}

	Point getInitialHeartPosition() const {
		return InitialHeartPosition;
	}

	void setInitialHeartPosition(Point InitialHeartPosition) {
		GameConfiguration::InitialHeartPosition = InitialHeartPosition;
	}

	unsigned int getMaxRocketLifes() const {
		return MaxRocketLifes;
	}

	void setMaxRocketLifes(unsigned int MaxRocketLifes) {
		GameConfiguration::MaxRocketLifes = MaxRocketLifes;
	}

	Point getScoreTextPosition() const {
		return ScoreTextPosition;
	}

	void setScoreTextPosition(Point ScoreTextPosition) {
		GameConfiguration::ScoreTextPosition = ScoreTextPosition;
	}

	unsigned int getScoreByDestroyingAsteroid() const {
		return ScoreByDestroyingAsteroid;
	}

	void setScoreByDestroyingAsteroid(unsigned int ScoreByDestroyingAsteroid) {
		GameConfiguration::ScoreByDestroyingAsteroid = ScoreByDestroyingAsteroid;
	}

	unsigned long getMinTimeBetweenSecondPlayerShoots() const {
		return MinTimeBetweenSecondPlayerShoots;
	}

	void setMinTimeBetweenSecondPlayerShoots(unsigned long MinTimeBetweenSecondPlayerShoots) {
		GameConfiguration::MinTimeBetweenSecondPlayerShoots = MinTimeBetweenSecondPlayerShoots;
	}

	double getSecondPlayerAsteroidVelocityMultiplayer() const {
		return SecondPlayerAsteroidVelocityMultiplayer;
	}

	void setSecondPlayerAsteroidVelocityMultiplayer(double SecondPlayerAsteroidVelocityMultiplayer) {
		GameConfiguration::SecondPlayerAsteroidVelocityMultiplayer = SecondPlayerAsteroidVelocityMultiplayer;
	}

	double getSecondPlayerAsteroidSizeDivider() const {
		return SecondPlayerAsteroidSizeDivider;
	}

	void setSecondPlayerAsteroidSizeDivider(double SecondPlayerAsteroidSizeDivider) {
		GameConfiguration::SecondPlayerAsteroidSizeDivider = SecondPlayerAsteroidSizeDivider;
	}

	double getMinSecondPlayerAsteroidSize() const {
		return MinSecondPlayerAsteroidSize;
	}

	void setMinSecondPlayerAsteroidSize(double MinSecondPlayerAsteroidSize) {
		GameConfiguration::MinSecondPlayerAsteroidSize = MinSecondPlayerAsteroidSize;
	}

	double getMaxSecondPlayerAsteroidSize() const {
		return MaxSecondPlayerAsteroidSize;
	}

	void setMaxSecondPlayerAsteroidSize(double MaxSecondPlayerAsteroidSize) {
		GameConfiguration::MaxSecondPlayerAsteroidSize = MaxSecondPlayerAsteroidSize;
	}

	std::string getOnUpdatePythonScriptPath() const {
		return OnUpdatePythonScriptPath;
	}

	void setOnUpdatePythonScriptPath(std::string OnUpdatePythonScriptPath) {
		GameConfiguration::OnUpdatePythonScriptPath = OnUpdatePythonScriptPath;
	}

	std::string getOnStartPythonScriptPath() const {
		return OnStartPythonScriptPath;
	}

	void setOnStartPythonScriptPath(std::string OnStartPythonScriptPath) {
		GameConfiguration::OnStartPythonScriptPath = OnStartPythonScriptPath;
	}
};


#endif //PWASTEROIDS_ACTORSCONFIGURATION_H
