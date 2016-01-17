//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_POWERUPGENERATOR_H
#define PWASTEROIDS_POWERUPGENERATOR_H


#include <Model/Actors/ActorsGenerator.h>
#include <Model/Actors/Asteroid/AsteroidCollisionComponent.h>
#include <Model/Actors/Asteroid/AsteroidsCountingComponent.h>
#include <Model/components/PositionSettingComponent.h>
#include <Model/Actors/Rocket/TemporaryRocketShootingComponent.h>
#include "PowerupType.h"
#include "PowerupCounterComponent.h"
#include "TripleShootPowerupCollisionComponent.h"
#include "HealthPowerupCollisionComponent.h"

class PowerupGenerator : public ActorsGenerator {
    PythonModule &python_;
    std::shared_ptr<IActor> rocketActor_;
    ProjectilesGenerator &projectilesGenerator_;
    std::shared_ptr<IInputStateProvider> inputStateProvider_;
    std::shared_ptr<GameTimeProvider> timeProvider_;
    std::shared_ptr<MusicManager> musicManager_;
    PowerupCounter &counter_;
    RocketLife &rocketLife_;

public:
    PowerupGenerator(const std::shared_ptr<ActorsContainer> &actorsContainer_, ActorIdGenerator &idGenerator_,
                     PythonModule &pythonModule_, DrawingSystem &drawingSystem_, GameConfiguration &gameConfiguration_,
                     const std::shared_ptr<Box2DService> &boxService_, Box2dObjectsContainer &container_,
                     ImageScalesContainer &imageScalesContainer, ContactComponentsContainer &contactComponentsContainer,
                     std::shared_ptr<IActor> rocketActor_, ProjectilesGenerator &projectilesGenerator_,
                     const std::shared_ptr<IInputStateProvider> &inputStateProvider_,
                     const std::shared_ptr<GameTimeProvider> &timeProvider_,
                     const std::shared_ptr<MusicManager> &musicManager_,
                     PowerupCounter &counter, RocketLife &rocketLife);

    void generatePowerup(Point position, PowerupType type);
};


#endif //PWASTEROIDS_POWERUPGENERATOR_H
