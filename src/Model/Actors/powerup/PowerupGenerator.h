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

class PowerupGenerator : public ActorsGenerator {
    PythonModule &python_;
    std::shared_ptr<IActor> rocketActor_;
    ProjectilesGenerator &projectilesGenerator_;
    std::shared_ptr<IInputStateProvider> inputStateProvider_;
    std::shared_ptr<GameTimeProvider> timeProvider_;
    std::shared_ptr<MusicManager> musicManager_;
    PowerupCounter &counter_;

public:


    PowerupGenerator(const std::shared_ptr<ActorsContainer> &actorsContainer_, ActorIdGenerator &idGenerator_,
                     PythonModule &pythonModule_, DrawingSystem &drawingSystem_, GameConfiguration &gameConfiguration_,
                     const std::shared_ptr<Box2DService> &boxService_, Box2dObjectsContainer &container_,
                     ImageScalesContainer &imageScalesContainer, ContactComponentsContainer &contactComponentsContainer,
                     std::shared_ptr<IActor> rocketActor_, ProjectilesGenerator &projectilesGenerator_,
                     const std::shared_ptr<IInputStateProvider> &inputStateProvider_,
                     const std::shared_ptr<GameTimeProvider> &timeProvider_,
                     const std::shared_ptr<MusicManager> &musicManager_,
                     PowerupCounter &counter) : ActorsGenerator(actorsContainer_,
                                                               idGenerator_, pythonModule_,
                                                               drawingSystem_,
                                                               gameConfiguration_,
                                                               boxService_, container_,
                                                               imageScalesContainer,
                                                               contactComponentsContainer),
                                               python_(pythonModule_), rocketActor_(rocketActor_),
                                               projectilesGenerator_(projectilesGenerator_),
                                               inputStateProvider_(inputStateProvider_),
                                               timeProvider_(timeProvider_),
                                               musicManager_(musicManager_), counter_(counter) { }

    void generatePowerup(Point position, PowerupType type){
        std::vector<std::shared_ptr<Component>> componentsForAsteroid;
        componentsForAsteroid.push_back(std::make_shared<Box2dComponent>(boxService_, gameConfiguration_, container_.getPowerupObject()));
        componentsForAsteroid.push_back(std::make_shared<PositionComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<PythonActorComponent>(pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<PositionSettingComponent >(true, pythonModule_));
        componentsForAsteroid.push_back( std::make_shared<PowerupCounterComponent>(counter_));

        if( type == PowerupType::TripleShoot ) {
            componentsForAsteroid.push_back(std::make_shared<ActorTypeComponent>(ActorType_TripleShootPowerup, pythonModule_));
            componentsForAsteroid.push_back(std::make_shared<TripleShootPowerupCollisionComponent>(
                    contactComponentsContainer_, actorsContainer_, rocketActor_, gameConfiguration_, projectilesGenerator_, inputStateProvider_, musicManager_, timeProvider_));
            componentsForAsteroid.push_back(
                    std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::TripleShootPowerup,
                                                       imageScalesContainer_.getImageScale(
                                                               ImagePrimitiveType::TripleShootPowerup)));
        } else {
            assert(false);
        }
        generateActor(componentsForAsteroid, position, Rotation(0), Point(0, 0), 0.0f);
    }
};


#endif //PWASTEROIDS_POWERUPGENERATOR_H
