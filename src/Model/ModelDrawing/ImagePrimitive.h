//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_IMAGEPRIMITIVE_H
#define PWASTEROIDS_IMAGEPRIMITIVE_H

#include "IDrawablePrimitive.h"
#include "ImagePrimitiveType.h"
#include "BaseDrawablePrimitive.h"
#include "DrawablePrimitiveVisitor.h"

class ImagePrimitive : public BaseDrawablePrimitive {
	ImagePrimitiveType imageType_;
public:

	ImagePrimitive(const Point &position_, const Rotation &rotation_, const ScaleToScreen &scale_, const ActorId &id,
				   const ImagePrimitiveType &imageType_)
			: BaseDrawablePrimitive(position_, rotation_, scale_, id), imageType_(imageType_) { }

	ImagePrimitiveType getImageType() const;


	virtual void accept(DrawablePrimitiveVisitor &visitor) override;
};


#endif //PWASTEROIDS_IMAGEPRIMITIVE_H
