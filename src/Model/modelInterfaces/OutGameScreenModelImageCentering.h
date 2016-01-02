//
// Created by defacto on 02.12.15.
//

#ifndef PWASTEROIDS_OUTGAMESCREENMODELIMAGECENTERING_H
#define PWASTEROIDS_OUTGAMESCREENMODELIMAGECENTERING_H

#include <memory>
#include <Model/configuration/IScreenScallingConfiguration.h>
#include <Model/configuration/IImageCenteringConfiguration.h>
#include "IOutGameScreenModel.h"
#include <cmath>
#include <Model/help/myMath.h>

class OutGameScreenModelImageCentering : public IOutGameScreenModel {
	std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel_;
	IImageCenteringConfiguration &configuration_;

public:
	OutGameScreenModelImageCentering(std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel,
										IImageCenteringConfiguration &configuration) :
										originalOutGameScreenModel_(originalOutGameScreenModel), configuration_(configuration){
	}

	virtual std::vector<ImagePrimitive> getImagePrimitives() override;

	virtual std::vector<TextPrimitive> getTextPrimitives();

	virtual void OnUpdate();

	virtual void AddPrimitive(std::shared_ptr<IDrawablePrimitive> primitive) override;

	virtual std::vector<ActorId> getRemovedActorsIds() override;

	virtual void AddRemovedPrimitiveId(ActorId id) override;
};


#endif //PWASTEROIDS_OUTGAMESCREENMODELIMAGECENTERING_H
