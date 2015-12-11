//
// Created by defacto on 10.12.15.
//

#ifndef PWASTEROIDS_INPUTVARIABLELAMBDAEXPECTATION_H
#define PWASTEROIDS_INPUTVARIABLELAMBDAEXPECTATION_H

#include <string>
#include "IEndToEndExpectation.h"

struct LastCheck{
	bool wasCheckOk;
	std::string badCheckDescription;

	LastCheck() : wasCheckOk(true){
	}

	LastCheck( bool wasCheckOk2, std::string badCheckDescription2 )
			: wasCheckOk(wasCheckOk2), badCheckDescription(badCheckDescription2){
	}
};

template <typename T>
class InputVariableLambdaExpectation : public IEndToEndExpectation {
protected:
	LastCheck lastCheck_;
	int lastLoopCount_ = 0;
	std::function<LastCheck (T g)> checkingFunction_;
	std::shared_ptr<Game> game_;

public:
	InputVariableLambdaExpectation ( std::function<LastCheck (T g)> function ) :
			checkingFunction_(function){
	}

	virtual bool checkExpectation()=0;

	virtual std::string getExpectationDescription(){
		return "lambda expectation";
	}

	virtual std::string getFailureMessage(){
		return "During loop "+std::to_string(lastLoopCount_)
		       +" there was error:\n" + lastCheck_.badCheckDescription;
	}

	virtual void beforeFirstUpdate(std::shared_ptr<Game> g){
		game_ = g;
	}

};

#endif //PWASTEROIDS_INPUTVARIABLELAMBDAEXPECTATION_H
