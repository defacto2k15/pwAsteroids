//
// Created by defacto on 16.10.15.
//

#include <memory>
#include <test/EndToEndTests/expectations/IEndToEndExpectation.h>
#include "GameRunner.h"
#include "FakeKeyboardStateToGameProvider.h"


std::string GameRunner::createErrorMessage(std::shared_ptr<IEndToEndExpectation> failedExpectation) {
	return "FAILED:\n"+failedExpectation->getExpectationDescription()+"\n BECOUSE OF: \n " + failedExpectation->getFailureMessage();
}

GameRunner::GameRunner() : g_(std::make_shared<Game>()), keyboard_(g_) {}

void GameRunner::AddEachLoopExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation) {
	eachLoopExpectations_.push_back(newExpectation);
}

void GameRunner::AddFirstLoopExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation) {
	firstLoopExpectations_.push_back(newExpectation);
}


void GameRunner::AddAfterRunExpectations( std::shared_ptr<IEndToEndExpectation> newExpectation){
	afterTestExpectations_.push_back(newExpectation);
}

void GameRunner::RunForLoops(int loopsToRun) {
	for( auto &expectation  : eachLoopExpectations_){
		expectation->beforeFirstUpdate(g_);
	}

	for( auto &expectation  : afterTestExpectations_){
		expectation->beforeFirstUpdate(g_);
	}

	for( auto &expectation  : firstLoopExpectations_){
		expectation->beforeFirstUpdate(g_);
	}

	for( int i = 0; i < loopsToRun; i++ ){
		keyboard_.sendKeysPressedToGame();
		g_->update();
		if( i == 0){
			for( auto& expectation : firstLoopExpectations_){
				if(!expectation->checkExpectation()){
					std::string errorMessage = createErrorMessage(expectation);
					FAIL() << errorMessage;
				}
			}
		}

		for( auto& expectation : eachLoopExpectations_){
			if(!expectation->checkExpectation()){
				std::string errorMessage = createErrorMessage(expectation);
				FAIL() << errorMessage;
			}
		}
	}

	for( auto& expectation : afterTestExpectations_){
		if(!expectation->checkExpectation()){
			std::string errorMessage = createErrorMessage(expectation);
			FAIL() << "After all loops " << std::endl<< errorMessage;
		}
	}
}

void GameRunner::AddKeyPressed(Keys keyPressed) {
	keyboard_.addKeyToPress(keyPressed);
}

void GameRunner::makeUncheckedUpdate() {
	g_->update();
}

