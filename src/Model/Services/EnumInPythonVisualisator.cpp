//
// Created by defacto on 2015.12.22..
//

#include <Model/Actors/powerup/PowerupType.h>
#include "EnumInPythonVisualisator.h"

EnumInPythonVisualisator::EnumInPythonVisualisator(PythonModule &module )
        : actorTypeVisibilityModule_(module), powerupTypeVisibilityModule_(module) {
}

void  EnumInPythonVisualisator::OnStart() {
        actorTypeVisibilityModule_.registerClass("ActorType");
        powerupTypeVisibilityModule_.registerClass("PowerupType");

        actorTypeVisibilityModule_.addEnumValue("Invalid", ActorType_Invalid);
        actorTypeVisibilityModule_.addEnumValue("Rocket", ActorType_Rocket);
        actorTypeVisibilityModule_.addEnumValue("RocketTail", ActorType_RocketTail);
        actorTypeVisibilityModule_.addEnumValue("Projectile", ActorType_Projectile);
        actorTypeVisibilityModule_.addEnumValue("Asteroid", ActorType_Asteroid);
        actorTypeVisibilityModule_.addEnumValue("Other", ActorType_Other);


        powerupTypeVisibilityModule_.addEnumValue("TripleShoot", PowerupType::TripleShoot);
        powerupTypeVisibilityModule_.addEnumValue("Health", PowerupType::Health);
}