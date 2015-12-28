//
// Created by defacto on 2015.12.27..
//

#ifndef PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H
#define PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H


#include <Model/configuration/ActorsConfiguration.h>
#include <Model/Services/ActorsContainer.h>
#include "Component.h"
#include "PositionComponent.h"

class ActorOnOutOfScreenDestroyerComponent : public Component {
    ActorsConfiguration &configuration_;
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorId actorId_;
    std::shared_ptr<PositionComponent> positionComponent_;
public:

    ActorOnOutOfScreenDestroyerComponent(ActorsConfiguration &configuration_,
                                         std::shared_ptr<ActorsContainer> &actorsContainer_);

    void OnStart(IActor &actor );

    void OnUpdate();
};


#endif //PWASTEROIDS_ACTORONOUTOFSCREENDESTROYERCOMPONENT_H
