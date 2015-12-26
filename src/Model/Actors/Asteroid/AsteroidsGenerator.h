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
#include <Model/Actors/Rocket/RocketBox2dComponent.h>
#include <Model/components/DrawingComponent.h>
#include <Model/Actors/Rocket/RocketMovingComponent.h>
#include <Model/components/ActorTypeComponent.h>
#include <Model/box2d/Box2dPositionSettingComponent.h>
#include <Model/configuration/ActorsConfiguration.h>
#include "AsteroidsCountingComponent.h"

class AsteroidsGenerator {
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorIdGenerator &idGenerator_;
    std::shared_ptr<PythonModule> pythonModule_;
    std::shared_ptr<DrawingSystem> drawingSystem_;
    std::shared_ptr<ActorsConfiguration> actorsConfiguration_;
    std::shared_ptr<Box2DService> boxService_;
    std::shared_ptr<AsteroidsCounter> asteroidsCounter_;

public:
    void generateAsteroid( Point position, Rotation rotation, double size, Point speedVector, double rotationSpeed){
//        auto newAsteroid = std::make_shared<Actor>(idGenerator_.getActorId());
//        newAsteroid->addComponent(std::make_shared<RocketBox2dComponent>(boxService_, actorsConfiguration_));
//        newAsteroid->addComponent(std::make_shared<PositionComponent>(pythonModule_));
//        newAsteroid->addComponent(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Asteroid, ScaleToScreen(0.053, 0.1)*size)); // todo set scale!!!
//        newAsteroid->addComponent( std::make_shared<PythonActorComponent>(pythonModule_));
//        newAsteroid->addComponent( std::make_shared<ActorTypeComponent>(ActorType_Asteroid, pythonModule_));
//        newAsteroid->addComponent( std::make_shared<Box2dPositionSettingComponent>(pythonModule_));
//        newAsteroid->addComponent( std::make_shared<AsteroidsCountingComponent>(asteroidsCounter_));
    }
};


#endif //PWASTEROIDS_ASTEROIDSGENERATOR_H
