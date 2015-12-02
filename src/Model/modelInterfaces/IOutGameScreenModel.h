//
// Created by defacto on 01.12.15.
//

#ifndef PWASTEROIDS_IOUTGAMESCREENMODEL_H
#define PWASTEROIDS_IOUTGAMESCREENMODEL_H

#include <vector>
#include <Model/ModelDrawing/ImagePrimitive.h>
#include <Model/ModelDrawing/IPrimitivesToDrawContainer.h>
#include <Model/Services/IService.h>

class IOutGameScreenModel : public IPrimitivesToDrawContainer, public IService {
public:

	virtual std::vector<ImagePrimitive> getImagePrimitives()=0;
};
#endif //PWASTEROIDS_IOUTGAMESCREENMODEL_H
