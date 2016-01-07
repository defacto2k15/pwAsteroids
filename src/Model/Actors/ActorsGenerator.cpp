//
// Created by defacto on 2015.12.28..
//

#include "ActorsGenerator.h"

ActorsGenerator::ActorsGenerator(std::shared_ptr<ActorsContainer> actorsContainer_,
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

void ActorsGenerator::generateActor(std::vector<std::shared_ptr<Component>> componentsVector,
                                    Point position, Rotation rotation, Point speedVector, double rotationSpeed) {
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