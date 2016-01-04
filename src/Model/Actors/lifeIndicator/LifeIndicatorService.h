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
    GameConfiguration &configuration_;
    ActorIdGenerator &idGenerator_;
    ImageScalesContainer &imageScalesContainer_;
    std::shared_ptr<ActorsContainer> actorsContainer_;
    IDrawingSystem &drawingSystem_;
    std::shared_ptr<PythonModule>  pythonModule_;

    std::vector<std::shared_ptr<IActor>> heartsActors;

public:
    LifeIndicatorService(std::shared_ptr<ActorsContainer> actorsContainer,
                         std::shared_ptr<PythonModule> pythonModule_,
                         IDrawingSystem &drawingSystem,
                         ImageScalesContainer &imageScalesContainer, ActorIdGenerator &idGenerator,
                         GameConfiguration &configuration, RocketLife &life);

    void OnStart();

    void OnUpdate();

    void OnStop();
};


#endif //PWASTEROIDS_LIFEINDICATORSERVICE_H
