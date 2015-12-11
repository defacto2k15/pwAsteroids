//
// Created by defacto on 09.11.15.
//

#include "InputVariableLambdaExpectation.h"
#include "LambdaExpectation.h"

LambdaExpectation::LambdaExpectation( std::function<LastCheck (std::shared_ptr<Game> g)> function )
		: InputVariableLambdaExpectation(function) {
}

bool  LambdaExpectation::checkExpectation() {
	lastCheck_ = checkingFunction_(game_);
	lastLoopCount_++;
	return lastCheck_.wasCheckOk;
}