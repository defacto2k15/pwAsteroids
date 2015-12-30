//
// Created by defacto on 27.11.15.
//

#include "ActorsConfiguration.h"

Point ActorsConfiguration::getInitialPosition() const {
	return Point( getBox2dScreenDimensions().getX()/2, getBox2dScreenDimensions().getY()/2);
}

Rotation ActorsConfiguration::getInitialRotation() const {
	return 90;
}

double ActorsConfiguration::getRocketAccelerationRate() const {
	return -3;
}

double ActorsConfiguration::getRocketTurnRate() const {
	return 0.2;
}

ScaleToScreen ActorsConfiguration::getRocketScaleToScreen() const {
	return ScaleToScreen(0.05f, 0.05f);
}

float ActorsConfiguration::getDistanceBetweenRocketAndTail() {
	return 0.5f;
}

ScaleToScreen ActorsConfiguration::getBox2dToAllegroScale() const {
	return ScaleToScreen( 100.0f, 100.0f);
}

Point ActorsConfiguration::getBox2dScreenDimensions() const {
	return Point( 10.24f, 6.00f);
}

Point ActorsConfiguration::GetDuplicationBoundariesSize() const {
	return Point(1.0f, 1.0f);
}

ActorId ActorsConfiguration::getBoundariesDuplicateActorIdOffset() const {
	return 10000;
}

unsigned int ActorsConfiguration::getAsteroidCreationPropabilityRatio() const {
	return 2;
}

unsigned int ActorsConfiguration::GetMinTimeBetweenAsteroidsCreation() const {
	return 4000;
}

unsigned int ActorsConfiguration::GetMaxAsteroidsCount() const {
	return 12;
}

Point ActorsConfiguration::GetAsteroidsGenerationBoundariesSize() const {
	return Point(0.001, 0.001);
}

double ActorsConfiguration::GetAsteroidMaxInitialImpulse() {
	return 0.15;
}

double ActorsConfiguration::GetAsteroidMinInitialImpulse() {
	return 0.05;
}

double ActorsConfiguration::GetAsteroidMinSize() {
	return 0.1;
}

double ActorsConfiguration::GetAsteroidMaxSize() {
	return 0.4;
}

double ActorsConfiguration::GetAsteroidMaxRotationSpeed() {
	return 0.08;
}

Rect ActorsConfiguration::getActorsDestroyRectangle() {
	Point destroyBoundaries(2,2);
	return Rect(-destroyBoundaries, getBox2dScreenDimensions() + (destroyBoundaries * 2));
}

unsigned long ActorsConfiguration::getMinTimeBetweenShots() {
	return 200;
}

double ActorsConfiguration::getDistanceBetweenRocketAndProjectile() {
	return 0.2f;
}

double ActorsConfiguration::getProjectileSpeed() {
	return 1.8f;
}

unsigned int ActorsConfiguration::getInitialRocketLife() {
	return 3;
}

unsigned int ActorsConfiguration::getTimesRocketImageIsFlickering() {
	return 4;
}

unsigned long ActorsConfiguration::getTimeofOneFlicker() {
	return 400;
}

Point ActorsConfiguration::getInitialHeartPosition() {
	return Point(1,1);
}

unsigned int ActorsConfiguration::getMaxRocketLifes() {
	return 5;
}