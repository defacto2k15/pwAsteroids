//
// Created by defacto on 16.10.15.
//

#include "ThereIsImage.h"

bool ThereIsImage::checkExpectation() {
	return wasThereSuchImageInLastLoop_;
}

std::string ThereIsImage::getExpectationDescription() {
	return std::string("Expect that GameScreenModel will have image with path: "+imageFileName_);
}

std::string ThereIsImage::getFailureMessage() {
	return std::string("Among "+std::to_string(lastLoopImageCount_)+" images there was no image with given path: " + imageFileName_);
}

void ThereIsImage::beforeFirstUpdate(std::shared_ptr<Game> g) {
	game_ = g;
	game_->getOutGameScreenModel().addObserver(this);
}

void ThereIsImage::notify() {
	auto images = game_->getOutGameScreenModel().getImagePrimitives();
	lastLoopImageCount_ = images.size();
	for( auto &image : images){
		if( image.getPathToImage() == imageFileName_ ){
			wasThereSuchImageInLastLoop_ = true;
			return;
		}
	}
	wasThereSuchImageInLastLoop_ = false;
	return;
}

ThereIsImage::ThereIsImage(std::string imageFileName) : imageFileName_(imageFileName) {}