//
// Created by defacto on 02.12.15.
//
#include <iostream>
#include "OutGameScreenModelImageCentering.h"

std::vector<ImagePrimitive>  OutGameScreenModelImageCentering::getImagePrimitives() {
	return originalOutGameScreenModel_->getImagePrimitives();
}

void  OutGameScreenModelImageCentering::OnUpdate() {
	originalOutGameScreenModel_->OnUpdate();
}


void OutGameScreenModelImageCentering::AddPrimitive(std::shared_ptr<IDrawablePrimitive> primitive) {
	Point imageSize =primitive->getScale().scalePoint( configuration_.getBox2dScreenDimensions());
	Point newPos(
			primitive->getPosition().getX() + (0.5f)*imageSize.getY() * myMath::sinDeg( primitive->getRotation() ),
			primitive->getPosition().getY() - (0.5)*imageSize.getY() * myMath::cosDeg(primitive->getRotation())
	);
	Point newPos2(
			newPos.getX() - (0.5f)*imageSize.getX() * myMath::cosDeg( primitive->getRotation() ),
			newPos.getY() - (0.5f)*imageSize.getX() * myMath::sinDeg( primitive->getRotation() )
	);
	primitive->setPosition(newPos2);
	originalOutGameScreenModel_->AddPrimitive(primitive);
}

std::vector<TextPrimitive> OutGameScreenModelImageCentering::getTextPrimitives() {
	return originalOutGameScreenModel_->getTextPrimitives();
}

std::vector<ActorId> OutGameScreenModelImageCentering::getRemovedActorsIds() {
	return originalOutGameScreenModel_->getRemovedActorsIds();
}

void OutGameScreenModelImageCentering::AddRemovedPrimitiveId(ActorId id) {
	originalOutGameScreenModel_->AddRemovedPrimitiveId(id);
}
