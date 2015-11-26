//
// Created by defacto on 18.10.15.
//
#include <stdexcept>
#include "OutGameScreenModel.h"

std::vector<ImagePrimitive> OutGameScreenModel::getImagePrimitives() {
	std::vector<ImagePrimitive> vecToReturn(imagePrimitives_);
	return vecToReturn;
}

void OutGameScreenModel::AddImage(ImagePrimitive primitive) {
	imagePrimitives_.push_back(primitive);
}

void OutGameScreenModel::OnUpdate() {
	notifyObservers();
	imagePrimitives_.clear();
}
