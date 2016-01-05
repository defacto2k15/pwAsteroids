//
// Created by defacto on 2015.12.28..
//

#include <Model/components/PositionSettingComponent.h>
#include "ProjectilesGenerator.h"
#include "ProjectileCollisionComponent.h"

ProjectilesGenerator::ProjectilesGenerator(std::shared_ptr<ActorsContainer> actorsContainer,
                                           ActorIdGenerator &idGenerator,
                                           PythonModule &pythonModule,
                                           DrawingSystem &drawingSystem,
                                           GameConfiguration &gameConfiguration,
                                           std::shared_ptr<Box2DService> boxService,
                                           Box2dObjectsContainer &container,
                                           ImageScalesContainer &imageScalesContainer,
                                           ContactComponentsContainer &contactComponentsContainer,
                                                ScoreCount &scoreCount) :
        ActorsGenerator(actorsContainer, idGenerator, pythonModule, drawingSystem,
                        gameConfiguration, boxService, container, imageScalesContainer, contactComponentsContainer),
                scoreCount_(scoreCount){
        std::function<void (Point position, Rotation rotation, Point speedVector, double rotationSpeed)> func =
                [this](Point position, Rotation rotation, Point speedVector, double rotationSpeed){ generateProjectile(position, rotation, speedVector, rotationSpeed);};
        pythonModule_.addRootFunction("generateProjectile", func);
}

void ProjectilesGenerator::generateProjectile(Point position, Rotation rotation, Point speedVector, double rotationSpeed) {
        std::vector<std::shared_ptr<Component>> componentsForAsteroid;
        componentsForAsteroid.push_back(std::make_shared<Box2dComponent>(boxService_, gameConfiguration_, container_.getProjectileObject()));
        componentsForAsteroid.push_back(std::make_shared<PositionComponent>(pythonModule_));
        componentsForAsteroid.push_back(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Projectile, imageScalesContainer_.getProjectileImageScale()));
        componentsForAsteroid.push_back( std::make_shared<PythonActorComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorTypeComponent>(ActorType_Projectile, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<PositionSettingComponent >(true, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorOnOutOfScreenDestroyerComponent>(gameConfiguration_, actorsContainer_));
        componentsForAsteroid.push_back( std::make_shared<ProjectileCollisionComponent>(contactComponentsContainer_, actorsContainer_, scoreCount_, gameConfiguration_));

        generateActor(componentsForAsteroid, position, rotation, speedVector, rotationSpeed);
}