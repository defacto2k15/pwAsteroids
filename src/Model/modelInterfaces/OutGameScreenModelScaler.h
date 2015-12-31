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
	IScreenScalingConfiguration &configuration_;
public:
	OutGameScreenModelScaler(std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel,
	                         IScreenScalingConfiguration &configuration) :
			originalOutGameScreenModel_(originalOutGameScreenModel), configuration_(configuration){
	}

	virtual void AddImage(ImagePrimitive image);

	virtual void AddText( TextPrimitive text ){
		originalOutGameScreenModel_->AddText(text);
	}

	virtual std::vector<ImagePrimitive> getImagePrimitives();

	virtual std::vector<TextPrimitive> getTextPrimitives() override{
		auto oldPrimitives = originalOutGameScreenModel_->getTextPrimitives();
		std::vector<TextPrimitive> outVec;
		for( auto onePrimitive : oldPrimitives){
			outVec.push_back( TextPrimitive(onePrimitive.getTextToWrite(), calculateNewPosition(onePrimitive.getPosition()),
											onePrimitive.getActorId()));
		}
		return outVec;
	}

	virtual void OnUpdate();

private:
	Point calculateNewPosition( Point oldPosition){
		ScaleToScreen scale = configuration_.getBox2dToAllegroScale();
		Point newPos( oldPosition.getX() * scale.getX(), oldPosition.getY() * scale.getY());
		return newPos;
	}
};


#endif //PWASTEROIDS_OUTGAMESCREENMODELSCALER_H
