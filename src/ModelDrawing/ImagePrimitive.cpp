//
// Created by defacto on 16.10.15.
//

#include <PrimitiveTypes/ScaleToScreen.h>
#include <PrimitiveTypes/AliasedTypes.h>
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

ImagePath ImagePrimitive::getPathToImage() const {
	return path_;
}

ImagePrimitive::ImagePrimitive(const Point &position, Rotation rotation, const ScaleToScreen &scale, const ImagePath &path)
		: position_(position), rotation_(rotation), scale_(scale), path_(path) { }