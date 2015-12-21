//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_DRAWINGSYSTEM_H
#define PWASTEROIDS_DRAWINGSYSTEM_H


#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include "ImagePrimitiveType.h"
#include "IPrimitivesToDrawContainer.h"
#include <memory>

class DrawingSystem {
	std::shared_ptr<IPrimitivesToDrawContainer> primitivesContainer_;
public:
	DrawingSystem( std::shared_ptr<IPrimitivesToDrawContainer> primitivesContainer);

	void drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale, ActorId actorId);

};


#endif //PWASTEROIDS_DRAWINGSYSTEM_H
