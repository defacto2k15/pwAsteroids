//
// Created by defacto on 26.10.15.
//

#include "DrawingSystem.h"
#include "ImagePrimitive.h"

ScaleToScreen DrawingSystem::getScale(ImagePrimitiveType type) {
	if(type==ImagePrimitiveType::Rocket){ // TODO repair later
		return ScaleToScreen(0.1,0.1);
	} else {
		return ScaleToScreen(1,1);
	}
}

void DrawingSystem::drawImage(ImagePrimitiveType type, Point position, Rotation rotation) {
	primitivesContainer_.AddImage(ImagePrimitive(position, rotation, getScale(type), type));
}

DrawingSystem::DrawingSystem( IPrimitivesToDrawContainer &primitivesContainer)
		: primitivesContainer_(primitivesContainer) {}