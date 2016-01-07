//
// Created by defacto on 2015.12.22..
//

#include "ActorTypeEnumInPythonVisualisator.h"

ActorTypeEnumInPythonVisualisator::ActorTypeEnumInPythonVisualisator(PythonModule &module )
        : visibilityModule_(module) {
}

void  ActorTypeEnumInPythonVisualisator::OnStart() {
        visibilityModule_.registerClass();
        visibilityModule_.addEnumValue("Invalid", ActorType_Invalid);
        visibilityModule_.addEnumValue("Rocket", ActorType_Rocket);
        visibilityModule_.addEnumValue("RocketTail", ActorType_RocketTail);
        visibilityModule_.addEnumValue("Projectile", ActorType_Projectile);
        visibilityModule_.addEnumValue("Asteroid", ActorType_Asteroid);
        visibilityModule_.addEnumValue("Other", ActorType_Other);
}