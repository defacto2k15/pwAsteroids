//
// Created by defacto on 2015.12.24..
//

#ifndef PWASTEROIDS_SCREENBOUNDARIESTELEPORTATIONCOMPONENT_H
#define PWASTEROIDS_SCREENBOUNDARIESTELEPORTATIONCOMPONENT_H


#include <Model/configuration/ActorsConfiguration.h>
#include "Component.h"
#include "PositionComponent.h"
#include "IPositionSettingComponent.h"

class ScreenBoundariesTeleportationComponent : public Component {
    std::shared_ptr<PositionComponent> positionComponent_;
    std::shared_ptr<IPositionSettingComponent> positionSettingComponent_;
    ActorsConfiguration &configuration_;
public:
    ScreenBoundariesTeleportationComponent(ActorsConfiguration & configuration );

    void OnStart(IActor &actor);

    void OnUpdate();
};


#endif //PWASTEROIDS_SCREENBOUNDARIESTELEPORTATIONCOMPONENT_H
