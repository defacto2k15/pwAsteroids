//
// Created by defacto on 18.10.15.
//

#ifndef PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H
#define PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H

#include <Model/ModelDrawing/ImagePrimitive.h>
#include <vector>
#include <Model/Observer/Observable.h>
#include <Model/Services/IService.h>
#include <Model/ModelDrawing/IPrimitivesToDrawContainer.h>
#include "IOutGameScreenModel.h"

class OutGameScreenModel : public IOutGameScreenModel {
	std::vector<ImagePrimitive> imagePrimitives_;
public:
	virtual void AddImage(ImagePrimitive image) override;

	virtual std::vector<ImagePrimitive> getImagePrimitives() override;

	virtual void OnUpdate() override;
};
#endif //PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H


