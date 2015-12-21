//
// Created by defacto on 05.12.15.
//

#include "ImagePrimitiveExpectation.h"

ImagePrimitiveExpectation::ImagePrimitiveExpectation(std::function<bool (ImagePrimitive &)> primitivesSelectingFunction,
                                                     std::function<void (ImagePrimitive &)> primitivesAssertionFunction ) : primitivesSelectingFunction_(primitivesSelectingFunction),
                                                                                                                            primitivesAssertionFunction_(primitivesAssertionFunction) {
}

std::string  ImagePrimitiveExpectation::getExpectationDescription() {
    return " Expectation checking image primitives";
}

bool  ImagePrimitiveExpectation::checkExpectation() {
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

std::string  ImagePrimitiveExpectation::getFailureMessage() {
    return "There was no primitive found that would match selecting expectation";
}

void  ImagePrimitiveExpectation::beforeFirstUpdate( std::shared_ptr<Game> g) {
    g_ = g;
}