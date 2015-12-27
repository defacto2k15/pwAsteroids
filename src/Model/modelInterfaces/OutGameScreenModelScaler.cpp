//
// Created by defacto on 01.12.15.
//

#include "OutGameScreenModelScaler.h"

void  OutGameScreenModelScaler::AddImage(ImagePrimitive image) {
	originalOutGameScreenModel_->AddImage(image);
}

std::vector<ImagePrimitive>  OutGameScreenModelScaler::getImagePrimitives() {
	auto oldPrimitives = originalOutGameScreenModel_->getImagePrimitives();
	std::vector<ImagePrimitive> newPrimitives;
	ScaleToScreen scale = configuration_.getBox2dToAllegroScale();
	for( auto &onePrimitive : oldPrimitives ){
		Point newPos( onePrimitive.getPosition().getX() * scale.getX(), onePrimitive.getPosition().getY() * scale.getY());
		newPrimitives.push_back(ImagePrimitive(newPos, onePrimitive.getRotation(), onePrimitive.getScale(), onePrimitive.getActorId(), onePrimitive.getImageType()));
	}
	return newPrimitives;
}

void  OutGameScreenModelScaler::OnUpdate() {
	originalOutGameScreenModel_->OnUpdate();
}