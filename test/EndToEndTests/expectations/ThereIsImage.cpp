//
// Created by defacto on 16.10.15.
//

#include "ThereIsImage.h"

bool ThereIsImage::checkExpectation() {
	auto images = game_->getOutGameScreenModel()->getImagePrimitives();
	lastLoopImageCount_ = images.size();
	for( auto &image : images){
		if( image.getImageType() == imageType_ ){
			wasThereSuchImageInLastLoop_ = true;
			return true;
		}
	}
	wasThereSuchImageInLastLoop_ = false;
	return false;
}

std::string ThereIsImage::getExpectationDescription() {
	return std::string("Expect that GameScreenModel will have image of type nr: "+std::to_string(imageType_));
}

std::string ThereIsImage::getFailureMessage() {
	return std::string("Among "+std::to_string(lastLoopImageCount_)+" images there was no image with given type nr: " + std::to_string(imageType_));
}

void ThereIsImage::beforeFirstUpdate(std::shared_ptr<Game> g) {
	game_ = g;
}



ThereIsImage::ThereIsImage(ImagePrimitiveType imageType) : imageType_(imageType) {}