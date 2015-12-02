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
	std::shared_ptr<IImageCenteringConfiguration> configuration_;

public:
	OutGameScreenModelImageCentering(std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel,
										std::shared_ptr<IImageCenteringConfiguration> configuration) :
										originalOutGameScreenModel_(originalOutGameScreenModel), configuration_(configuration){
	}

	virtual void AddImage(ImagePrimitive image) override{
		originalOutGameScreenModel_->AddImage(image);
	}

	virtual std::vector<ImagePrimitive> getImagePrimitives() override{
		auto originalPrimitives = originalOutGameScreenModel_->getImagePrimitives();
		std::vector<ImagePrimitive> outPrimitives;
		for( auto &oldPrimitive : originalPrimitives){
			Point imageSize =oldPrimitive.getScale().scalePoint( configuration_->getBox2dScreenDimensions());
			Point newPos(
					oldPrimitive.getPosition().getX() + (0.5f)*imageSize.getX() * myMath::sinDeg( oldPrimitive.getRotation() ),
					oldPrimitive.getPosition().getY() - (0.5)*imageSize.getX() * myMath::cosDeg(oldPrimitive.getRotation())
			);
			Point newPos2(
					newPos.getX() - (0.5f)*imageSize.getY() * myMath::cosDeg( oldPrimitive.getRotation() ),
					newPos.getY() - (0.5f)*imageSize.getY() * myMath::sinDeg( oldPrimitive.getRotation() )
			);

			outPrimitives.push_back( ImagePrimitive(newPos2, oldPrimitive.getRotation(), oldPrimitive.getScale(), oldPrimitive.getImageType()));
		}
		//std::cout << std::endl;
		return outPrimitives;
	}

	virtual void OnUpdate() override{
		originalOutGameScreenModel_->OnUpdate();
	}

};


#endif //PWASTEROIDS_OUTGAMESCREENMODELIMAGECENTERING_H
