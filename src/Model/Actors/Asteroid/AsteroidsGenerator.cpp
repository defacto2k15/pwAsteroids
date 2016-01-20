//
// Created by defacto on 2015.12.26..
//

#include <Model/components/PositionSettingComponent.h>
#include "AsteroidsGenerator.h"

AsteroidsGenerator::AsteroidsGenerator(std::shared_ptr<ActorsContainer> actorsContainer, ActorIdGenerator &idGenerator,
                                       PythonModule &pythonModule, DrawingSystem &drawingSystem, GameConfiguration &gameConfiguration,
                                       std::shared_ptr<Box2DService> boxService, Box2dObjectsContainer &container,
                                       ImageScalesContainer &imageScalesContainer,
                                       ContactComponentsContainer &contactComponentsContainer, AsteroidsCounter &asteroidsCounter,
                                       std::shared_ptr<MusicManager> musicManager, ExplosionCloudGenerator &cloudGenerator)
        : ActorsGenerator(actorsContainer, idGenerator, pythonModule, drawingSystem,
                          gameConfiguration, boxService, container, imageScalesContainer, contactComponentsContainer),
          asteroidsCounter_( asteroidsCounter), python_( pythonModule ), musicManager_(musicManager), cloudGenerator_(cloudGenerator) {

        std::function< void (Point position, Rotation rotation, double size, Point speedVector, double rotationSpeed)>
                func =  [this](Point position, Rotation rotation, double size, Point speedVector, double rotationSpeed){ generateAsteroid(position, rotation, size, speedVector, rotationSpeed);};
        python_.addRootFunction("generateAsteroid", func );
}

void AsteroidsGenerator::generateAsteroid(Point position, Rotation rotation, double size, Point speedVector, double rotationSpeed) {
        std::vector<std::shared_ptr<Component>> componentsForAsteroid;
        componentsForAsteroid.push_back(std::make_shared<Box2dComponent>(boxService_, gameConfiguration_, container_.getAsteriodObject(size)));
        componentsForAsteroid.push_back(std::make_shared<PositionComponent>(pythonModule_));
        componentsForAsteroid.push_back(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Asteroid, imageScalesContainer_.getImageScale(ImagePrimitiveType::Asteroid) * size));
        componentsForAsteroid.push_back( std::make_shared<PythonActorComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorTypeComponent>(ActorType_Asteroid, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<PositionSettingComponent >(true, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<AsteroidsCountingComponent>(asteroidsCounter_));
        componentsForAsteroid.push_back( std::make_shared<ActorOnOutOfScreenDestroyerComponent>(gameConfiguration_, actorsContainer_));
        componentsForAsteroid.push_back( std::make_shared<AsteroidCollisionComponent>(
                contactComponentsContainer_, actorsContainer_, *this, musicManager_, cloudGenerator_));
        componentsForAsteroid.push_back( std::make_shared<AsteroidSizeComponent>(size));

        generateActor(componentsForAsteroid, position, rotation, speedVector, rotationSpeed);
}