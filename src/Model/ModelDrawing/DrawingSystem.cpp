//
// Created by defacto on 26.10.15.
//

#include "DrawingSystem.h"

void DrawingSystem::drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale, ActorId actorId) {
	primitivesContainer_->AddImage(ImagePrimitive(position, rotation, scale, actorId, type));
}

DrawingSystem::DrawingSystem( std::shared_ptr<IPrimitivesToDrawContainer> primitivesContainer)
		: primitivesContainer_(primitivesContainer) {}

void DrawingSystem::drawText(std::string textValue, Point position, ActorId actorId) {
	primitivesContainer_->AddText(TextPrimitive(textValue, position, actorId));
}
