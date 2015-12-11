//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_LAMBDAEXPECTATION_H
#define PWASTEROIDS_LAMBDAEXPECTATION_H

#include <string>
#include <memory>
#include "IEndToEndExpectation.h"
#include "src/Model/Observer/IObserver.h"
#include "InputVariableLambdaExpectation.h"


class LambdaExpectation : public InputVariableLambdaExpectation<std::shared_ptr<Game>> {

public:
	LambdaExpectation( std::function<LastCheck (std::shared_ptr<Game> g)> function ) : InputVariableLambdaExpectation(function){
	}

	virtual bool checkExpectation(){
		lastCheck_ = checkingFunction_(game_);
		lastLoopCount_++;
		return lastCheck_.wasCheckOk;
	}

};


#endif //PWASTEROIDS_LAMBDAEXPECTATION_H
