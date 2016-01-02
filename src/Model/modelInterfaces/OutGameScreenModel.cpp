//
// Created by defacto on 18.10.15.
//
#include <stdexcept>
#include <memory>
#include "OutGameScreenModel.h"

std::vector<ImagePrimitive> OutGameScreenModel::getImagePrimitives() {
	std::vector<ImagePrimitive> vecToReturn(imagePrimitives_);
	return vecToReturn;
}


void OutGameScreenModel::OnUpdate() {
	imagePrimitives_.clear();
	textPrimitives_.clear();
	actorIdsToRemove_.clear();
}

std::vector<TextPrimitive> OutGameScreenModel::getTextPrimitives() {
	return textPrimitives_;
}


void OutGameScreenModel::AddPrimitive(std::shared_ptr<IDrawablePrimitive> primitive) {
	primitive->accept(*this);
}

void OutGameScreenModel::visit(ImagePrimitive &image) {
	imagePrimitives_.push_back(image);
}

void OutGameScreenModel::visit(TextPrimitive &text) {
	textPrimitives_.push_back(text);
}

std::vector<ActorId> OutGameScreenModel::getRemovedActorsIds() {
	return actorIdsToRemove_;
}

void OutGameScreenModel::AddRemovedPrimitiveId(ActorId id) {
	actorIdsToRemove_.push_back(id);
}
