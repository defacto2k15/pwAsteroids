//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_IMAGEPRIMITIVE_H
#define PWASTEROIDS_IMAGEPRIMITIVE_H

#include "IDrawablePrimitive.h"
#include "ImagePrimitiveType.h"

class ImagePrimitive : public IDrawablePrimitive {
	Point position_;
	Rotation rotation_;
	ScaleToScreen scale_;
	ImagePrimitiveType imageType_;
public:
	ImagePrimitive(const Point &position, Rotation rotation, const ScaleToScreen &scale, const ImagePrimitiveType &imageType);

	virtual Point getPosition() const;

	virtual Rotation getRotation() const;

	virtual ScaleToScreen getScale() const;

	ImagePrimitiveType getImageType() const;
};


#endif //PWASTEROIDS_IMAGEPRIMITIVE_H
