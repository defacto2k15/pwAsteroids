//
// Created by defacto on 16.10.15.
//

#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include "ImagePrimitive.h"
#include "DrawablePrimitiveVisitor.h"

ImagePrimitiveType ImagePrimitive::getImageType() const {
	return imageType_;
}

void ImagePrimitive::accept(DrawablePrimitiveVisitor &visitor) {
	visitor.visit(*this);
}
