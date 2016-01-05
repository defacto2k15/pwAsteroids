//
// Created by defacto on 2015.12.28..
//

#ifndef PWASTEROIDS_ACTORSGENERATOR_H
#define PWASTEROIDS_ACTORSGENERATOR_H


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

class ActorsGenerator {
protected:
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorIdGenerator &idGenerator_;
    PythonModule &pythonModule_;
    DrawingSystem &drawingSystem_;
    GameConfiguration &gameConfiguration_;
    std::shared_ptr<Box2DService> boxService_;
    Box2dObjectsContainer &container_;
    ImageScalesContainer &imageScalesContainer_;
    ContactComponentsContainer &contactComponentsContainer_;

    ActorsGenerator(std::shared_ptr<ActorsContainer> actorsContainer_,
        ActorIdGenerator &idGenerator_,
        PythonModule &pythonModule_,
        DrawingSystem &drawingSystem_,
        GameConfiguration &gameConfiguration_,
        std::shared_ptr<Box2DService> boxService_,
        Box2dObjectsContainer &container_,
        ImageScalesContainer &imageScalesContainer,
        ContactComponentsContainer &contactComponentsContainer)
    : actorsContainer_(actorsContainer_), idGenerator_(idGenerator_), pythonModule_(pythonModule_),
        drawingSystem_(drawingSystem_), gameConfiguration_(gameConfiguration_), boxService_(boxService_),
        container_(container_), imageScalesContainer_(imageScalesContainer),
      contactComponentsContainer_(contactComponentsContainer) {
    }

    void generateActor( std::vector<std::shared_ptr<Component>> componentsVector,
                        Point position, Rotation rotation, Point speedVector, double rotationSpeed){
        auto newAsteroid = std::make_shared<Actor>(idGenerator_.getActorId());
        for( auto oneComponent : componentsVector){
            newAsteroid->addComponent(oneComponent);
        }

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


#endif //PWASTEROIDS_ACTORSGENERATOR_H
