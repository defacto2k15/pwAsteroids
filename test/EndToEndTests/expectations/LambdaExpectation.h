//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_LAMBDAEXPECTATION_H
#define PWASTEROIDS_LAMBDAEXPECTATION_H

#include <string>
#include <memory>
#include "IEndToEndExpectation.h"
#include "src/Model/Observer/IObserver.h"

struct LastCheck{
	bool wasCheckOk;
	std::string badCheckDescription;

	LastCheck() : wasCheckOk(true){
	}

	LastCheck( bool wasCheckOk2, std::string badCheckDescription2 )
			: wasCheckOk(wasCheckOk2), badCheckDescription(badCheckDescription2){
	}
};

class LambdaExpectation : public IEndToEndExpectation {
private:
	LastCheck lastCheck_;
	std::shared_ptr<Game> game_;
	std::function<LastCheck (std::shared_ptr<Game> g)> checkingFunction_;
	int lastLoopCount_ = 0;

public:
	LambdaExpectation( std::function<LastCheck (std::shared_ptr<Game> g)> function ) :
			checkingFunction_(function){
	}

	virtual bool checkExpectation(){
		lastCheck_ = checkingFunction_(game_);
		lastLoopCount_++;
		return lastCheck_.wasCheckOk;
	}

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


#endif //PWASTEROIDS_LAMBDAEXPECTATION_H
