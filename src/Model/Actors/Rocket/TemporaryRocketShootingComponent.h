//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_TEMPORARYROCKETSHOOTINGCOMPONENT_H
#define PWASTEROIDS_TEMPORARYROCKETSHOOTINGCOMPONENT_H


#include "RocketShootingComponent.h"

class TemporaryRocketShootingComponent : public RocketShootingComponent  {
    std::shared_ptr<GameTimeProvider> timeProvider_;
    GameConfiguration &gameConfiguration_;
    IActor *rocketActor_;
    long creationTime_;

public:
    TemporaryRocketShootingComponent(GameConfiguration &configuration, ProjectilesGenerator &projectilesGenerator,
                                     const std::shared_ptr<IInputStateProvider> &inputStateProvider,
                                     const std::shared_ptr<GameTimeProvider> &timeProvider,
                                     const std::shared_ptr<MusicManager> &musicManager, const Rotation &angleOfShoot);


    virtual void OnStart(IActor &actor);

    virtual void OnUpdate();
};


#endif //PWASTEROIDS_TEMPORARYROCKETSHOOTINGCOMPONENT_H
