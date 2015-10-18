//
// Created by defacto on 18.10.15.
//

#ifndef PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H
#define PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H

#include <ModelDrawing/ImagePrimitive.h>
#include <vector>
#include <Observer/Observable.h>

class OutGameScreenModel : public Observable{
public:
	virtual std::vector<ImagePrimitive> getImagePrimitives();
};
#endif //PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H


