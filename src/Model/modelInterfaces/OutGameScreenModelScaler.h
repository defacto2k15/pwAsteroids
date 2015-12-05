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

	virtual void AddImage(ImagePrimitive image) override{
		originalOutGameScreenModel_->AddImage(image);
	}

	virtual std::vector<ImagePrimitive> getImagePrimitives() override{
		auto oldPrimitives = originalOutGameScreenModel_->getImagePrimitives();
		std::vector<ImagePrimitive> newPrimitives;
		ScaleToScreen scale = configuration_->getBox2dToAllegroScale();
		for( auto &onePrimitive : oldPrimitives ){
			Point newPos( onePrimitive.getPosition().getX() * scale.getX(), onePrimitive.getPosition().getY() * scale.getY());
			newPrimitives.push_back(ImagePrimitive(newPos, onePrimitive.getRotation(), onePrimitive.getScale(), onePrimitive.getActorId(), onePrimitive.getImageType()));
		}
		return newPrimitives;
	}

	virtual void OnUpdate() override{
		originalOutGameScreenModel_->OnUpdate();
	}
};


#endif //PWASTEROIDS_OUTGAMESCREENMODELSCALER_H
