//
// Created by defacto on 18.10.15.
//

#ifndef PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H
#define PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H

#include <ModelDrawing/ImagePrimitive.h>
#include <vector>
#include <Observer/Observable.h>
#include <Services/IService.h>
#include "ModelDrawing/IPrimitivesToDrawContainer.h"

class OutGameScreenModel : public Observable, public IService,  public IPrimitivesToDrawContainer {
	std::vector<ImagePrimitive> imagePrimitives_;
public:
	virtual void AddImage(ImagePrimitive image);

	virtual std::vector<ImagePrimitive> getImagePrimitives();

	virtual void OnUpdate() override;
};
#endif //PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H


