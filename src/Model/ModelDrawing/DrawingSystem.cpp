//
// Created by defacto on 26.10.15.
//

#include "DrawingSystem.h"
#include "ImagePrimitive.h"

void DrawingSystem::drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale) {
	primitivesContainer_->AddImage(ImagePrimitive(position, rotation, scale, type));
}

DrawingSystem::DrawingSystem( std::shared_ptr<IPrimitivesToDrawContainer> primitivesContainer)
		: primitivesContainer_(primitivesContainer) {}