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
//#include <bits/shared_ptr.h>
#include "IOutGameScreenModel.h"


class OutGameScreenModel : public IOutGameScreenModel, public DrawablePrimitiveVisitor {
	std::vector<ImagePrimitive> imagePrimitives_;
	std::vector<TextPrimitive> textPrimitives_;
	std::vector<ActorId> actorIdsToRemove_;
public:
	virtual std::vector<ImagePrimitive> getImagePrimitives() override;

	virtual std::vector<TextPrimitive> getTextPrimitives() override;

	virtual void OnUpdate() override;

	virtual void visit(ImagePrimitive &image) override;

	virtual void visit(TextPrimitive &text) override;

	virtual std::vector<ActorId> getRemovedActorsIds() override;

	virtual void AddRemovedPrimitiveId(ActorId id) override;

	virtual void AddPrimitive(std::shared_ptr<IDrawablePrimitive> primitive) override;
};
#endif //PWASTEROIDS_OUTDRAWINGPRIMITIVESMODEL_H


