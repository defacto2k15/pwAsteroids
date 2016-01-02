//
// Created by defacto on 01.12.15.
//

#ifndef PWASTEROIDS_IOUTGAMESCREENMODEL_H
#define PWASTEROIDS_IOUTGAMESCREENMODEL_H

#include <vector>
#include <Model/ModelDrawing/ImagePrimitive.h>
#include <Model/ModelDrawing/IPrimitivesToDrawContainer.h>
#include <Model/Services/IService.h>
#include <Model/ModelDrawing/TextPrimitive.h>

class IOutGameScreenModel : public IPrimitivesToDrawContainer, public IService {
public:

	virtual std::vector<ImagePrimitive> getImagePrimitives()=0;
	virtual std::vector<TextPrimitive> getTextPrimitives()=0;
	virtual std::vector<ActorId> getRemovedActorsIds()=0;
};
#endif //PWASTEROIDS_IOUTGAMESCREENMODEL_H
