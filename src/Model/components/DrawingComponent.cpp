//

#include "DrawingComponent.h"

//
// Created by defacto on 28.11.15.
DrawingComponent::DrawingComponent(IDrawingSystem &drawingSystem, ImagePrimitiveType imageType, ScaleToScreen scaleToScreen)
		: drawingSystem_(drawingSystem), imageType_(imageType), scaleToScreen_(scaleToScreen) {}

void  DrawingComponent::OnStart(IActor &actor) {
	positionComponent_ = actor.getOnlyComponent<PositionComponent>();
	actorId_ = actor.getActorId();
}

void  DrawingComponent::OnUpdate() {
	ScaleToScreen scale;
	if( isVisible_ ) {
		scale = scaleToScreen_;
	} else {
		scale = ScaleToScreen(0, 0);
	}

	drawingSystem_.drawImage(imageType_, positionComponent_->getPosition(), positionComponent_->getRotation(),
		                          scale, actorId_);
}

void DrawingComponent::setVisibility(bool visibility ) {
	isVisible_ = visibility;
}
