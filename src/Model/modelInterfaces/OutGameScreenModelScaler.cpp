//
// Created by defacto on 01.12.15.
//

#include "OutGameScreenModelScaler.h"


std::vector<ImagePrimitive>  OutGameScreenModelScaler::getImagePrimitives() {
	return originalOutGameScreenModel_->getImagePrimitives();
}

std::vector<TextPrimitive> OutGameScreenModelScaler::getTextPrimitives() {
	return originalOutGameScreenModel_->getTextPrimitives();
}

void  OutGameScreenModelScaler::OnUpdate() {
	originalOutGameScreenModel_->OnUpdate();
}

void OutGameScreenModelScaler::AddPrimitive(std::shared_ptr<IDrawablePrimitive> primitive) {
	Point newPosition = calculateNewPosition(primitive->getPosition());
	primitive->setPosition(newPosition);
	originalOutGameScreenModel_->AddPrimitive(primitive);
}

Point OutGameScreenModelScaler::calculateNewPosition(Point oldPosition) {
	ScaleToScreen scale = configuration_.getBox2dToAllegroScale();
	Point newPos( oldPosition.getX() * scale.getX(), oldPosition.getY() * scale.getY());
	return newPos;
}

std::vector<ActorId> OutGameScreenModelScaler::getRemovedActorsIds() {
	return originalOutGameScreenModel_->getRemovedActorsIds();
}

void OutGameScreenModelScaler::AddRemovedPrimitiveId(ActorId id) {
	originalOutGameScreenModel_->AddRemovedPrimitiveId(id);
}
