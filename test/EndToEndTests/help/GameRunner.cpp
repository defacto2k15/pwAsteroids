//
// Created by defacto on 16.10.15.
//

#include <memory>
#include <test/EndToEndTests/expectations/IEndToEndExpectation.h>
#include "GameRunner.h"


std::string GameRunner::createErrorMessage(std::shared_ptr<IEndToEndExpectation> failedExpectation) {
	return "FAILED:\n"+failedExpectation->getExpectationDescription()+"\n BECOUSE OF: \n " + failedExpectation->getFailureMessage();
}

GameRunner::GameRunner() : g_(std::make_shared<Game>()) {}

void GameRunner::AddExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation) {
	expectations_.push_back(newExpectation);
}

void GameRunner::RunForLoops(int loopsToRun) {
	for( auto &expectation  : expectations_){
		expectation->beforeFirstUpdate(g_);
	}

	for( int i = 0; i < loopsToRun; i++ ){
		g_->update();
		for( auto& expectation : expectations_){
			if(!expectation->checkExpectation()){
				std::string errorMessage = createErrorMessage(expectation);
				FAIL() << errorMessage;
			}
		}
	}
}