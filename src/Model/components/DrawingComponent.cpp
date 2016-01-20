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
	ImagePrimitiveType  type;
	if( isVisible_ ) {
		scale = scaleToScreen_;
		type = imageType_;
	} else {
		scale = ScaleToScreen(0, 0);
		type = ImagePrimitiveType::NotVisibleElement;
	}
    scale *= size_;
    // todo zrob cos z opacity

	drawingSystem_.drawImage(type, positionComponent_->getPosition(), positionComponent_->getRotation(),
		                          scale, actorId_);
}

void DrawingComponent::setVisibility(bool visibility ) {
	isVisible_ = visibility;
}
