//
// Created by defacto on 01.12.15.
//

#ifndef PWASTEROIDS_OUTGAMESCREENMODELSCALER_H
#define PWASTEROIDS_OUTGAMESCREENMODELSCALER_H


#include <memory>
#include <Model/configuration/IScreenScallingConfiguration.h>
#include "IOutGameScreenModel.h"

class OutGameScreenModelScaler : public IOutGameScreenModel {
	std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel_;
	std::shared_ptr<IScreenScalingConfiguration> configuration_;
public:
	OutGameScreenModelScaler(std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel,
	                         std::shared_ptr<IScreenScalingConfiguration> configuration) :
			originalOutGameScreenModel_(originalOutGameScreenModel), configuration_(configuration){
	}

	virtual void AddImage(ImagePrimitive image);

	virtual std::vector<ImagePrimitive> getImagePrimitives();

	virtual void OnUpdate();
};


#endif //PWASTEROIDS_OUTGAMESCREENMODELSCALER_H
