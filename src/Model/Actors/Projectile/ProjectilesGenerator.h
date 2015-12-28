//
// Created by defacto on 2015.12.28..
//

#ifndef PWASTEROIDS_PROJECTILESGENERATOR_H
#define PWASTEROIDS_PROJECTILESGENERATOR_H


#include <Model/Actors/ActorsGenerator.h>

class ProjectilesGenerator : public ActorsGenerator{
public:
    ProjectilesGenerator(std::shared_ptr<ActorsContainer> actorsContainer,
    ActorIdGenerator &idGenerator,
            std::shared_ptr<PythonModule> pythonModule,
    std::shared_ptr<DrawingSystem> drawingSystem,
            ActorsConfiguration &actorsConfiguration,
    std::shared_ptr<Box2DService> boxService,
            Box2dObjectsContainer &container,
    ImageScalesContainer &imageScalesContainer)
    : ActorsGenerator(actorsContainer,idGenerator, pythonModule, drawingSystem,
            actorsConfiguration, boxService, container, imageScalesContainer){
    }

    void generateProjectile( Point position, Rotation rotation, Point speedVector, double rotationSpeed){
        std::vector<std::shared_ptr<Component>> componentsForAsteroid;
        componentsForAsteroid.push_back(std::make_shared<Box2dComponent>(boxService_, actorsConfiguration_, container_.getProjectileObject()));
        componentsForAsteroid.push_back(std::make_shared<PositionComponent>(pythonModule_));
        componentsForAsteroid.push_back(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Projectile, imageScalesContainer_.getProjectileImageScale()));
        componentsForAsteroid.push_back( std::make_shared<PythonActorComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorTypeComponent>(ActorType_Asteroid, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<Box2dPositionSettingComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<ActorOnOutOfScreenDestroyerComponent>(actorsConfiguration_, actorsContainer_));

        generateActor(componentsForAsteroid, position, rotation, speedVector, rotationSpeed);
    }
};


#endif //PWASTEROIDS_PROJECTILESGENERATOR_H
