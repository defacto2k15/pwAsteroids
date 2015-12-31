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
	imagePrimitives_.clear();
	textPrimitives_.clear();
}

std::vector<TextPrimitive> OutGameScreenModel::getTextPrimitives() {
	return textPrimitives_;
}

void OutGameScreenModel::AddText(TextPrimitive text) {
	textPrimitives_.push_back(text);
}
