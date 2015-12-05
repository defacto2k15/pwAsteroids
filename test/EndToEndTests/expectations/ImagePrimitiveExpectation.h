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
			std::function<void (ImagePrimitive &)> primitivesAssertionFunction )
			: primitivesSelectingFunction_(primitivesSelectingFunction),
			  primitivesAssertionFunction_(primitivesAssertionFunction){
	}

	virtual std::string getExpectationDescription(){
		return " Expectation checking image primitives";
	}

	virtual bool checkExpectation(){
		std::vector<ImagePrimitive> allPrimitives = g_->getOutGameScreenModel()->getImagePrimitives();
		auto newEnd = std::remove_if(allPrimitives.begin(), allPrimitives.end(), [=](ImagePrimitive &primitive){ return !primitivesSelectingFunction_(primitive);} );
		allPrimitives.erase(newEnd, allPrimitives.end());

		if( allPrimitives.size() == 0){
			return false;
		}

		for( auto &onePrimitive : allPrimitives){
			primitivesAssertionFunction_(onePrimitive);
		}
		return true;
	}

	virtual std::string getFailureMessage(){
		return "There was no primitive found that would match selecting expectation";
	}

	virtual void beforeFirstUpdate( std::shared_ptr<Game> g){
		g_ = g;
	};
};


#endif //PWASTEROIDS_IMAGEPRIMITIVEEXPECTATION_H
