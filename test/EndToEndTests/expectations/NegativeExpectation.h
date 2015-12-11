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
	NegativeExpectation( std::shared_ptr<IEndToEndExpectation> negatedExpectation );

	virtual std::string getExpectationDescription();

	virtual bool checkExpectation();

	virtual std::string getFailureMessage();

	virtual void beforeFirstUpdate( std::shared_ptr<Game> g);
};


#endif //PWASTEROIDS_NEGATIVEEXPECTATION_H
