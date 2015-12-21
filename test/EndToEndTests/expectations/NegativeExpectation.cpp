//
// Created by defacto on 28.11.15.
//

#include "NegativeExpectation.h"


NegativeExpectation::NegativeExpectation( std::shared_ptr<IEndToEndExpectation> negatedExpectation )
		: negatedExpectation_(negatedExpectation) {
}

std::string NegativeExpectation::getExpectationDescription() {
	return std::string("Negated expectation of : "+negatedExpectation_->getExpectationDescription());
}

bool NegativeExpectation::checkExpectation() {
	return !negatedExpectation_->checkExpectation();
}

std::string NegativeExpectation::getFailureMessage() {
	return std::string("Negated expectation was true!");
}

void NegativeExpectation::beforeFirstUpdate( std::shared_ptr<Game> g) {
	negatedExpectation_->beforeFirstUpdate(g);
}