//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_THEREISIMAGE_H
#define PWASTEROIDS_THEREISIMAGE_H


#include <Model/Observer/IObserver.h>
#include "IEndToEndExpectation.h"
#include "src/Model/ModelDrawing/ImagePrimitiveType.h"

class ThereIsImage : public IEndToEndExpectation, IObserver {
	ImagePrimitiveType imageType_;
	bool wasThereSuchImageInLastLoop_ = false;
	unsigned long lastLoopImageCount_ = 0;
	std::shared_ptr<Game> game_;
public:
	ThereIsImage(ImagePrimitiveType imageType);;

	virtual bool checkExpectation();

	virtual std::string getExpectationDescription();;

	virtual std::string getFailureMessage();;

	virtual void beforeFirstUpdate(std::shared_ptr<Game> g);;

	virtual void notify();
};


#endif //PWASTEROIDS_THEREISIMAGE_H
