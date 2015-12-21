//
// Created by defacto on 02.12.15.
//

#include "OutGameScreenModelImageCentering.h"

void  OutGameScreenModelImageCentering::AddImage(ImagePrimitive image) {
	originalOutGameScreenModel_->AddImage(image);
}

std::vector<ImagePrimitive>  OutGameScreenModelImageCentering::getImagePrimitives() {
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

		outPrimitives.push_back( ImagePrimitive(newPos2, oldPrimitive.getRotation(), oldPrimitive.getScale(), oldPrimitive.getActorId(), oldPrimitive.getImageType()));
	}
	//std::cout << std::endl;
	return outPrimitives;
}

void  OutGameScreenModelImageCentering::OnUpdate() {
	originalOutGameScreenModel_->OnUpdate();
}