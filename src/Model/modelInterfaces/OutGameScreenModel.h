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

class OutGameScreenModel :  public IService,  public IPrimitivesToDrawContainer {
	std::vector<ImagePrimitive> imagePrimitives_;
public:
	virtual void AddImage(ImagePrimitive image);

	virtual std::vector<ImagePrimitive> getImagePrimitives();

	virtual void OnUpdate() override;
};
#endif //PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H


