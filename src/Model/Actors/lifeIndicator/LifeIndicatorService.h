//
// Created by defacto on 2015.12.30..
//

#ifndef PWASTEROIDS_LIFEINDICATORSERVICE_H
#define PWASTEROIDS_LIFEINDICATORSERVICE_H

#include <vector>
#include <memory>
#include <Model/Services/IService.h>
#include <Model/Actors/Rocket/RocketLife.h>
#include <Model/Actors/IActor.h>
#include <Model/Services/ActorsContainer.h>
#include <Model/Actors/ActorIdGenerator.h>
#include <Model/Actors/Actor.h>
#include <Model/components/DrawingComponent.h>
#include <Model/ModelDrawing/ImageScalesContainer.h>
#include <iostream>

class LifeIndicatorService : public IService{
    RocketLife &life_;
    ActorsConfiguration &configuration_;
    ActorIdGenerator &idGenerator_;
    ImageScalesContainer &imageScalesContainer_;
    std::shared_ptr<ActorsContainer> actorsContainer_;
    std::shared_ptr<IDrawingSystem> drawingSystem_;
    std::shared_ptr<PythonModule>  pythonModule_;

    std::vector<std::shared_ptr<IActor>> heartsActors;

public:
    LifeIndicatorService(std::shared_ptr<ActorsContainer> actorsContainer,
                         std::shared_ptr<PythonModule> pythonModule_,
                         std::shared_ptr<IDrawingSystem> drawingSystem,
                         ImageScalesContainer &imageScalesContainer, ActorIdGenerator &idGenerator,
                         ActorsConfiguration &configuration, RocketLife &life) :
            actorsContainer_(actorsContainer), pythonModule_(pythonModule_), drawingSystem_(drawingSystem),
            imageScalesContainer_(imageScalesContainer), idGenerator_(idGenerator), configuration_(configuration),
            life_(life) {
    }

    void OnStart() override{
        for( int i = 0; i < configuration_.getMaxRocketLifes(); i++ ){
            Point position = configuration_.getInitialHeartPosition();
            position += Point(1, 0) * i;
            auto newActor = std::make_shared<Actor>(idGenerator_.getActorId());
            auto positionComponent = std::make_shared<PositionComponent>(pythonModule_);
            newActor->addComponent( positionComponent );
            positionComponent ->setX(position.getX());
            positionComponent ->setY(position.getY());
            newActor->addComponent( std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Heart, imageScalesContainer_.getHeartImageScale()) );
            std::cout << "Created component in " << position.toString() << std::endl;
            actorsContainer_->addActorDuringRuntime(newActor );
            heartsActors.push_back(newActor);
        }
    }

    void OnUpdate() override{
        unsigned int activeHearts = life_.getLife();
        for( int i = 0; i < configuration_.getMaxRocketLifes(); i++){
            bool visibility = false;
            std::cout << " There are " << activeHearts << " life" << std::endl;
            if( i < activeHearts ){
                visibility = true;
            }
            heartsActors[i]->getOnlyComponent<DrawingComponent>()->setVisibility(visibility);
        }
    }

    void OnStop() override{
        heartsActors.clear();
    }
};


#endif //PWASTEROIDS_LIFEINDICATORSERVICE_H
