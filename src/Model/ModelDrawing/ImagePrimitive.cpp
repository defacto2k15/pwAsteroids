//
// Created by defacto on 16.10.15.
//

#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include "ImagePrimitive.h"

Point ImagePrimitive::getPosition() const {
	return position_;
}

Rotation ImagePrimitive::getRotation() const {
	return rotation_;
}

ScaleToScreen ImagePrimitive::getScale() const {
	return scale_;
}

ImagePrimitive::ImagePrimitive(const Point &position, Rotation rotation, const ScaleToScreen &scale,  const ActorId &actorId, const ImagePrimitiveType &type)
		: position_(position), rotation_(rotation), scale_(scale), actorId_(actorId), imageType_(type) { }

ImagePrimitiveType ImagePrimitive::getImageType() const {
	return imageType_;
}

ActorId ImagePrimitive::getActorId() const {
	return actorId_;
}
