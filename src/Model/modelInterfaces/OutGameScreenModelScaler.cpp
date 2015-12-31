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
	for( auto &onePrimitive : oldPrimitives ){
		newPrimitives.push_back(ImagePrimitive( calculateNewPosition(onePrimitive.getPosition()),
												onePrimitive.getRotation(), onePrimitive.getScale(), onePrimitive.getActorId(), onePrimitive.getImageType()));
	}
	return newPrimitives;
}

void  OutGameScreenModelScaler::OnUpdate() {
	originalOutGameScreenModel_->OnUpdate();
}