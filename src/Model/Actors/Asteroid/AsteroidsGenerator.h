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
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/box2d/Box2dObjectsContainer.h>
#include <Model/components/OnStartLambdaComponent.h>
#include <Model/components/ActorOnOutOfScreenDestroyerComponent.h>
#include "AsteroidsCountingComponent.h"

class AsteroidsGenerator {
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorIdGenerator &idGenerator_;
    std::shared_ptr<PythonModule> pythonModule_;
    std::shared_ptr<DrawingSystem> drawingSystem_;
    std::shared_ptr<ActorsConfiguration> actorsConfiguration_;
    std::shared_ptr<Box2DService> boxService_;
    std::shared_ptr<AsteroidsCounter> asteroidsCounter_;
    Box2dObjectsContainer &container_;
    ImageScalesContainer &imageScalesContainer_;
public:

    AsteroidsGenerator(std::shared_ptr<ActorsContainer> &actorsContainer_,
                       ActorIdGenerator &idGenerator_,
                       std::shared_ptr<PythonModule> &pythonModule_,
                       std::shared_ptr<DrawingSystem> &drawingSystem_,
                       std::shared_ptr<ActorsConfiguration> &actorsConfiguration_,
                       std::shared_ptr<Box2DService> &boxService_,
                       std::shared_ptr<AsteroidsCounter> &asteroidsCounter_,
                       Box2dObjectsContainer &container_,
                        ImageScalesContainer &imageScalesContainer)
            : actorsContainer_(actorsContainer_), idGenerator_(idGenerator_), pythonModule_(pythonModule_),
              drawingSystem_(drawingSystem_), actorsConfiguration_(actorsConfiguration_), boxService_(boxService_),
              asteroidsCounter_(asteroidsCounter_), container_(container_), imageScalesContainer_(imageScalesContainer) {

    }

    void generateAsteroid( Point position, Rotation rotation, double size, Point speedVector, double rotationSpeed){
        auto newAsteroid = std::make_shared<Actor>(idGenerator_.getActorId());
        newAsteroid->addComponent(std::make_shared<Box2dComponent>(boxService_, actorsConfiguration_, container_.getAsteriodObject(size)));
        newAsteroid->addComponent(std::make_shared<PositionComponent>(pythonModule_));
        newAsteroid->addComponent(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Asteroid, imageScalesContainer_.getBasicAsteroidImageScale() * size));
        newAsteroid->addComponent( std::make_shared<PythonActorComponent>(pythonModule_));
        newAsteroid->addComponent( std::make_shared<ActorTypeComponent>(ActorType_Asteroid, pythonModule_));
        newAsteroid->addComponent( std::make_shared<Box2dPositionSettingComponent>(pythonModule_));
        newAsteroid->addComponent( std::make_shared<AsteroidsCountingComponent>(asteroidsCounter_));
        newAsteroid->addComponent( std::make_shared<ActorOnOutOfScreenDestroyerComponent>(actorsConfiguration_, actorsContainer_));

        newAsteroid->addComponent( std::make_shared<OnStartLambdaComponent>(
                [position, rotation, speedVector, rotationSpeed](IActor &actor){
            auto positionCopy = position;
            auto rotationCopy = rotation;
            auto speedVectorCopy = speedVector;
            auto rotationSpeedCopy = rotationSpeed;

            auto box2dComponent = actor.getOnlyComponent<Box2dComponent>();
            box2dComponent->setPosition(positionCopy.getX(), positionCopy.getY());
            box2dComponent->setRotation(rotationCopy);
            box2dComponent->SetLineralVelocity(speedVectorCopy);
            box2dComponent->SetAngularVelocity(rotationSpeedCopy);

        }));
        actorsContainer_->addActorDuringRuntime(newAsteroid);
    }
};


#endif //PWASTEROIDS_ASTEROIDSGENERATOR_H
