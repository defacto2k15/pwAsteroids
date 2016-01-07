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
                    ContactComponentsContainer &contactComponentsContainer);

    void generateActor(std::vector<std::shared_ptr<Component>> componentsVector,
                       Point position, Rotation rotation, Point speedVector, double rotationSpeed);
};


#endif //PWASTEROIDS_ACTORSGENERATOR_H
