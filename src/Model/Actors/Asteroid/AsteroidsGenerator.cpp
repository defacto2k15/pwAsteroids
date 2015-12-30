//
// Created by defacto on 2015.12.26..
//

#include "AsteroidsGenerator.h"

AsteroidsGenerator::AsteroidsGenerator(std::shared_ptr<ActorsContainer> actorsContainer,
                                       ActorIdGenerator &idGenerator,
                                       std::shared_ptr<PythonModule> pythonModule,
                                       std::shared_ptr<DrawingSystem> drawingSystem,
                                       ActorsConfiguration &actorsConfiguration,
                                       std::shared_ptr<Box2DService> boxService,
                                       Box2dObjectsContainer &container,
                                       ImageScalesContainer &imageScalesContainer,
                                       ContactComponentsContainer &contactComponentsContainer,
                                       std::shared_ptr<AsteroidsCounter> asteroidsCounter)
        : ActorsGenerator(actorsContainer, idGenerator, pythonModule, drawingSystem,
                          actorsConfiguration, boxService, container, imageScalesContainer, contactComponentsContainer),
          asteroidsCounter_( asteroidsCounter) {
}

void AsteroidsGenerator::generateAsteroid(Point position, Rotation rotation, double size, Point speedVector, double rotationSpeed) {
        std::vector<std::shared_ptr<Component>> componentsForAsteroid;
        componentsForAsteroid.push_back(std::make_shared<Box2dComponent>(boxService_, actorsConfiguration_, container_.getAsteriodObject(size)));
        componentsForAsteroid.push_back(std::make_shared<PositionComponent>(pythonModule_));
        componentsForAsteroid.push_back(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Asteroid, imageScalesContainer_.getBasicAsteroidImageScale() * size));
        componentsForAsteroid.push_back( std::make_shared<PythonActorComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorTypeComponent>(ActorType_Asteroid, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<Box2dPositionSettingComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<AsteroidsCountingComponent>(asteroidsCounter_));
        componentsForAsteroid.push_back( std::make_shared<ActorOnOutOfScreenDestroyerComponent>(actorsConfiguration_, actorsContainer_));
        componentsForAsteroid.push_back( std::make_shared<AsteroidCollisionComponent>(
                contactComponentsContainer_, actorsContainer_, *this));
        componentsForAsteroid.push_back( std::make_shared<AsteroidSizeComponent>(size));

        generateActor(componentsForAsteroid, position, rotation, speedVector, rotationSpeed);
}