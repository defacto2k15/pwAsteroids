//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_IENDTOENDEXPECTATION_H
#define PWASTEROIDS_IENDTOENDEXPECTATION_H

#include <string>
#include <Game.h>
#include <memory>

class IEndToEndExpectation {
public:
	virtual std::string getExpectationDescription()=0;
	virtual bool checkExpectation()=0;
	virtual std::string getFailureMessage()=0;
	virtual void beforeFirstUpdate( std::shared_ptr<Game> ){};
};
#endif //PWASTEROIDS_IENDTOENDEXPECTATION_H
