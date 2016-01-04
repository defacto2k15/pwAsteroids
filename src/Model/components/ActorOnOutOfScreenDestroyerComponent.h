//
// Created by defacto on 2015.12.27..
//

#ifndef PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H
#define PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H


#include <Model/configuration/GameConfiguration.h>
#include <Model/Services/ActorsContainer.h>
#include "Component.h"
#include "PositionComponent.h"

class ActorOnOutOfScreenDestroyerComponent : public Component {
    GameConfiguration &configuration_;
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorId actorId_;
    std::shared_ptr<PositionComponent> positionComponent_;
public:

    ActorOnOutOfScreenDestroyerComponent(GameConfiguration &configuration_,
                                         std::shared_ptr<ActorsContainer> &actorsContainer_);

    void OnStart(IActor &actor );

    void OnUpdate();
};


#endif //PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H
