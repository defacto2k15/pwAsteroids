//
// Created by defacto on 27.11.15.
//

#include <Model/configuration/GameConfiguration.h>

Point GameConfiguration::getInitialPosition() const {
	return Point( getBox2dScreenDimensions().getX()/2, getBox2dScreenDimensions().getY()/2);
}

Rotation GameConfiguration::getInitialRotation() const {
	return 90;
}

double GameConfiguration::getRocketAccelerationRate() const {
	return -3;
}

double GameConfiguration::getRocketTurnRate() const {
	return 0.2;
}

ScaleToScreen GameConfiguration::getRocketScaleToScreen() const {
	return ScaleToScreen(0.05f, 0.05f);
}

float GameConfiguration::getDistanceBetweenRocketAndTail() {
	return 0.5f;
}

ScaleToScreen GameConfiguration::getBox2dToAllegroScale() const {
	return ScaleToScreen( 100.0f, 100.0f);
}

ScaleToScreen GameConfiguration::getAllegroToBox2dScale() const {
	return ScaleToScreen(0.01f,0.01f);
}

Point GameConfiguration::getBox2dScreenDimensions() const {
	return Point( 10.24f, 6.00f);
}

Point GameConfiguration::GetDuplicationBoundariesSize() const {
	return Point(1.0f, 1.0f);
}

ActorId GameConfiguration::getBoundariesDuplicateActorIdOffset() const {
	return 10000;
}

unsigned int GameConfiguration::getAsteroidCreationPropabilityRatio() const {
	return 2;
}

unsigned int GameConfiguration::GetMinTimeBetweenAsteroidsCreation() const {
	return 4000;
}

unsigned int GameConfiguration::GetMaxAsteroidsCount() const {
	return 12;
}

Point GameConfiguration::GetAsteroidsGenerationBoundariesSize() const {
	return Point(0.001, 0.001);
}

double GameConfiguration::GetAsteroidMaxInitialImpulse() {
	return 0.15;
}

double GameConfiguration::GetAsteroidMinInitialImpulse() {
	return 0.05;
}

double GameConfiguration::GetAsteroidMinSize() {
	return 0.1;
}

double GameConfiguration::GetAsteroidMaxSize() {
	return 0.4;
}

double GameConfiguration::GetAsteroidMaxRotationSpeed() {
	return 0.08;
}

Rect GameConfiguration::getActorsDestroyRectangle() {
	Point destroyBoundaries(2,2);
	return Rect(-destroyBoundaries, getBox2dScreenDimensions() + (destroyBoundaries * 2));
}

unsigned long GameConfiguration::getMinTimeBetweenShots() {
	return 200;
}

double GameConfiguration::getDistanceBetweenRocketAndProjectile() {
	return 0.2f;
}

double GameConfiguration::getProjectileSpeed() {
	return 1.8f;
}

unsigned int GameConfiguration::getInitialRocketLife() {
	return 3;
}

unsigned int GameConfiguration::getTimesRocketImageIsFlickering() {
	return 4;
}

unsigned long GameConfiguration::getTimeofOneFlicker() {
	return 400;
}

Point GameConfiguration::getInitialHeartPosition() {
	return Point(1,1);
}

unsigned int GameConfiguration::getMaxRocketLifes() {
	return 5;
}

unsigned int GameConfiguration::getScoreByDestroyingAsteroid() {
	return 10;
}

unsigned long GameConfiguration::getMinTimeBetweenSecondPlayerShoots() {
	return 300;
}

double GameConfiguration::getSecondPlayerAsteroidVelocityMultiplayer() {
	return 0.4f;
}

double GameConfiguration::getSecondPlayerAsteroidSizeDivider() {
	return 3.0f;
}

double GameConfiguration::getMinSecondPlayerAsteroidSize() {
	return 0.15f;
}

double GameConfiguration::getMaxSecondPlayerAsteroidSize() {
	return 3.5f;
}

Point GameConfiguration::getScoreTextPosition() {
	return Point(8, 5);
}