//
// Created by defacto on 05.12.15.
//

#ifndef PWASTEROIDS_IMAGEPRIMITIVEEXPECTATION_H
#define PWASTEROIDS_IMAGEPRIMITIVEEXPECTATION_H


#include "IEndToEndExpectation.h"

class ImagePrimitiveExpectation  : public IEndToEndExpectation {
	std::function<bool (ImagePrimitive &)> primitivesSelectingFunction_;
	std::function<void (ImagePrimitive &)> primitivesAssertionFunction_;
	std::shared_ptr<Game> g_;

public:
	ImagePrimitiveExpectation(std::function<bool (ImagePrimitive &)> primitivesSelectingFunction,
				std::function<void (ImagePrimitive &)> primitivesAssertionFunction );

	virtual std::string getExpectationDescription();

	virtual bool checkExpectation();

	virtual std::string getFailureMessage();

	virtual void beforeFirstUpdate( std::shared_ptr<Game> g);;
};


#endif //PWASTEROIDS_IMAGEPRIMITIVEEXPECTATION_H
