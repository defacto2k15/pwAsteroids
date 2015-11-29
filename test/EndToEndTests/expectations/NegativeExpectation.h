//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_NEGATIVEEXPECTATION_H
#define PWASTEROIDS_NEGATIVEEXPECTATION_H
#include <memory>
#include "IEndToEndExpectation.h"
#include <string>

class NegativeExpectation : public IEndToEndExpectation {
	std::shared_ptr<IEndToEndExpectation> negatedExpectation_;

public:
	NegativeExpectation( std::shared_ptr<IEndToEndExpectation> negatedExpectation )
			: negatedExpectation_(negatedExpectation){
	}

	virtual std::string getExpectationDescription(){
		return std::string("Negated expectation of : "+negatedExpectation_->getExpectationDescription());
	}

	virtual bool checkExpectation(){
		return !negatedExpectation_->checkExpectation();
	}

	virtual std::string getFailureMessage(){
		return std::string("Negated expectation was true!");
	}

	virtual void beforeFirstUpdate( std::shared_ptr<Game> g){
		negatedExpectation_->beforeFirstUpdate(g);
	}
};


#endif //PWASTEROIDS_NEGATIVEEXPECTATION_H
