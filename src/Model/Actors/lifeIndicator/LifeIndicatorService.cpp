//
// Created by defacto on 2015.12.30..
//

#include "LifeIndicatorService.h"
#include <iostream>

LifeIndicatorService::LifeIndicatorService(std::shared_ptr<ActorsContainer> actorsContainer,
                                           PythonModule &pythonModule_,
                                           IDrawingSystem &drawingSystem,
                                           ImageScalesContainer &imageScalesContainer, ActorIdGenerator &idGenerator,
                                           GameConfiguration &configuration, RocketLife &life)
        : actorsContainer_(actorsContainer), pythonModule_(pythonModule_), drawingSystem_(drawingSystem),
          imageScalesContainer_(imageScalesContainer), idGenerator_(idGenerator), configuration_(configuration),
          life_(life) {
}

void LifeIndicatorService::OnStart() {
    createHearts();
}

void LifeIndicatorService::OnUpdate() {
    unsigned int activeHearts = life_.getLife();
    for( int i = 0; i < configuration_.getMaxRocketLifes(); i++){
        bool visibility = false;
        if( i < activeHearts ){
            visibility = true;
        }
        heartsActors[i]->getOnlyComponent<DrawingComponent>()->setVisibility(visibility);
    }
}

void LifeIndicatorService::OnStop() {
    heartsActors.clear();
}

void LifeIndicatorService::createHearts() {
    heartsActors.clear();
    for( int i = 0; i < configuration_.getMaxRocketLifes(); i++ ){
        Point position = configuration_.getInitialHeartPosition();
        position += Point(1, 0) * i;
        auto newActor = std::make_shared<Actor>(idGenerator_.getActorId());
        auto positionComponent = std::make_shared<PositionComponent>(pythonModule_);
        newActor->addComponent( positionComponent );
        positionComponent ->setX(position.getX());
        positionComponent ->setY(position.getY());
        newActor->addComponent( std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Heart, imageScalesContainer_.getImageScale(ImagePrimitiveType::Heart)) );
        actorsContainer_->addActorDuringRuntime(newActor );
        heartsActors.push_back(newActor);
    }
}
