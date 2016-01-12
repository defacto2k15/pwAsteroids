//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_ALIASEDTYPES_H
#define PWASTEROIDS_ALIASEDTYPES_H

#include <string>

 //using Rotation = double; //WAS in past, but now is:
#include "Model/PrimitiveTypes/Rotation.h"
#include "Point.h"

using ImagePath = std::string;
using ActorId = unsigned int;
using Size = Point;
#endif //PWASTEROIDS_ALIASEDTYPES_H
