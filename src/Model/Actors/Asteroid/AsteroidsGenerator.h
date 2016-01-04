//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_ASTEROIDSGENERATOR_H
#define PWASTEROIDS_ASTEROIDSGENERATOR_H


#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/Rotation.h>
#include <Model/Services/ActorsContainer.h>
#include <Model/Actors/ActorIdGenerator.h>
#include <Model/Actors/Actor.h>

#include <Model/components/DrawingComponent.h>
#include <Model/Actors/Rocket/RocketMovingComponent.h>
#include <Model/components/ActorTypeComponent.h>
#include <Model/box2d/Box2dPositionSettingComponent.h>
#include <Model/configuration/GameConfiguration.h>
#include <Model/box2d/Box2dObjectsContainer.h>
#include <Model/components/OnStartLambdaComponent.h>
#include <Model/components/ActorOnOutOfScreenDestroyerComponent.h>
#include <Model/Actors/ActorsGenerator.h>
#include <Model/collisions/Box2dCollisionsComponent.h>
#include "AsteroidsCountingComponent.h"
#include "AsteroidCollisionComponent.h"

class AsteroidsGenerator : public ActorsGenerator{
    AsteroidsCounter &asteroidsCounter_;
    std::shared_ptr<PythonModule> python_;

public:

    AsteroidsGenerator(std::shared_ptr<ActorsContainer> actorsContainer,
                       ActorIdGenerator &idGenerator,
                       std::shared_ptr<PythonModule> pythonModule,
                       DrawingSystem &drawingSystem,
                       GameConfiguration &gameConfiguration,
                       std::shared_ptr<Box2DService> boxService,
                       Box2dObjectsContainer &container,
                       ImageScalesContainer &imageScalesContainer,
                       ContactComponentsContainer &contactComponentsContainer,
                       AsteroidsCounter &asteroidsCounter);

    void generateAsteroid(Point position, Rotation rotation, double size, Point speedVector, double rotationSpeed);
};


#endif //PWASTEROIDS_ASTEROIDSGENERATOR_H
