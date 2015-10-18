//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_IMAGEPRIMITIVE_H
#define PWASTEROIDS_IMAGEPRIMITIVE_H

#include "IDrawablePrimitive.h"
class ImagePrimitive : public IDrawablePrimitive {
	Point position_;
	Rotation rotation_;
	ScaleToScreen scale_;
	ImagePath  path_;
public:
	ImagePrimitive(const Point &position, Rotation rotation, const ScaleToScreen &scale, const ImagePath &path);

	virtual Point getPosition() const;

	virtual Rotation getRotation() const;

	virtual ScaleToScreen getScale() const;

	ImagePath getPathToImage() const;
};


#endif //PWASTEROIDS_IMAGEPRIMITIVE_H
