//
// Created by defacto on 2015.12.28..
//

#include "ProjectilesGenerator.h"
#include "ProjectileCollisionComponent.h"

ProjectilesGenerator::ProjectilesGenerator(std::shared_ptr<ActorsContainer> actorsContainer,
                                           ActorIdGenerator &idGenerator,
                                           std::shared_ptr<PythonModule> pythonModule,
                                           DrawingSystem &drawingSystem,
                                           ActorsConfiguration &actorsConfiguration,
                                           std::shared_ptr<Box2DService> boxService,
                                           Box2dObjectsContainer &container,
                                           ImageScalesContainer &imageScalesContainer,
                                           ContactComponentsContainer &contactComponentsContainer,
                                                ScoreCount &scoreCount) :
        ActorsGenerator(actorsContainer, idGenerator, pythonModule, drawingSystem,
                        actorsConfiguration, boxService, container, imageScalesContainer, contactComponentsContainer),
                scoreCount_(scoreCount){
}

void ProjectilesGenerator::generateProjectile(Point position, Rotation rotation, Point speedVector, double rotationSpeed) {
        std::vector<std::shared_ptr<Component>> componentsForAsteroid;
        componentsForAsteroid.push_back(std::make_shared<Box2dComponent>(boxService_, actorsConfiguration_, container_.getProjectileObject()));
        componentsForAsteroid.push_back(std::make_shared<PositionComponent>(pythonModule_));
        componentsForAsteroid.push_back(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Projectile, imageScalesContainer_.getProjectileImageScale()));
        componentsForAsteroid.push_back( std::make_shared<PythonActorComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorTypeComponent>(ActorType_Asteroid, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<Box2dPositionSettingComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorOnOutOfScreenDestroyerComponent>(actorsConfiguration_, actorsContainer_));
        componentsForAsteroid.push_back( std::make_shared<ProjectileCollisionComponent>(contactComponentsContainer_, actorsContainer_, scoreCount_, actorsConfiguration_));

        generateActor(componentsForAsteroid, position, rotation, speedVector, rotationSpeed);
}