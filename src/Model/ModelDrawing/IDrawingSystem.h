//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_IDRAWINGSYSTEM_H
#define PWASTEROIDS_IDRAWINGSYSTEM_H

#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/Rotation.h>
#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include "ImagePrimitiveType.h"

class IDrawingSystem{
public:
    virtual void drawImage(ImagePrimitiveType type, Point position,
                           Rotation rotation, ScaleToScreen scale, ActorId actorId) = 0;
    virtual void drawText( std::string textValue, Point position, ActorId actorId) = 0;
};
#endif //PWASTEROIDS_IDRAWINGSYSTEM_H
