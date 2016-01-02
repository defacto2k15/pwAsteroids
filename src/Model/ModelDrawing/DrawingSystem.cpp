//
// Created by defacto on 26.10.15.
//

#include "DrawingSystem.h"

void DrawingSystem::drawImage(ImagePrimitiveType type, Point position, Rotation rotation, ScaleToScreen scale, ActorId actorId) {
	primitivesContainer_->AddPrimitive( std::make_shared<ImagePrimitive>(position, rotation, scale, actorId, type));
}

DrawingSystem::DrawingSystem( std::shared_ptr<IPrimitivesToDrawContainer> primitivesContainer)
		: primitivesContainer_(primitivesContainer) {}

void DrawingSystem::drawText(std::string textValue, Point position, ActorId actorId) {
	primitivesContainer_->AddPrimitive( std::make_shared<TextPrimitive>(position, 0, ScaleToScreen(0.2f, 0.2f), actorId, textValue));
}

void DrawingSystem::addRemovedActorId(ActorId id) {
	primitivesContainer_->AddRemovedPrimitiveId(id);
}
