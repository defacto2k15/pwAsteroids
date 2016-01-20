//
// Created by root on 2016.01.20..
//

#ifndef PWASTEROIDS_EXPLOSIONCLOUDGENERATOR_H
#define PWASTEROIDS_EXPLOSIONCLOUDGENERATOR_H


#include <Model/Actors/ActorsGenerator.h>
#include <Model/components/PositionSettingComponent.h>
#include "ExplisionCloudImageManipulatingComponent.h"

class ExplosionCloudGenerator {
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorIdGenerator &idGenerator_;
    PythonModule &pythonModule_;
    DrawingSystem &drawingSystem_;
    GameConfiguration &gameConfiguration_;
    ImageScalesContainer &imageScalesContainer_;
    std::shared_ptr<GameTimeProvider> gameTimeProvider_;
public:
    ExplosionCloudGenerator(const std::shared_ptr<ActorsContainer> &actorsContainer, ActorIdGenerator &idGenerator,
                            PythonModule &pythonModule, DrawingSystem &drawingSystem,
                            GameConfiguration &gameConfiguration, ImageScalesContainer &imageScalesContainer,
                            std::shared_ptr<GameTimeProvider> gameTimeProvider);

    void generateExplosionCloud(Point position, double size);
};


#endif //PWASTEROIDS_EXPLOSIONCLOUDGENERATOR_H
