//
// Created by defacto on 16.10.15.
//

#include <memory>
#include <test/EndToEndTests/expectations/IEndToEndExpectation.h>
#include <test/defaultTestValues/TestValues.h>
#include "GameRunner.h"
#include <iostream>
#include <chrono>
#include <thread>

std::string GameRunner::createErrorMessage(std::shared_ptr<IEndToEndExpectation> failedExpectation) {
	return "FAILED:\n"+failedExpectation->getExpectationDescription()+"\n BECOUSE OF: \n " + failedExpectation->getFailureMessage();
}

GameRunner::GameRunner() : g_(std::make_shared<Game>(TestValues::getScreenSize(), TestValues::getImageSizesMap())),
						   input_(g_) ,  allExpectations_(3){
    g_->startMultiplayerGame(3);
}

void GameRunner::AddEachLoopExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation) {
	getExpectations(ExpectationType::EachLoop).push_back(newExpectation);
}

void GameRunner::AddFirstLoopExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation) {
	getExpectations(ExpectationType::FirstLoop).push_back(newExpectation);
}


void GameRunner::AddAfterRunExpectations( std::shared_ptr<IEndToEndExpectation> newExpectation){
	getExpectations(ExpectationType::AfterTest).push_back(newExpectation);
}

void GameRunner::RunForLoops(int loopsToRun) {
	for( auto &expectationVec : allExpectations_ ){
		for( auto &expectation : expectationVec){
			expectation->beforeFirstUpdate(g_);
		}
	}

	for( int i = 0; i < loopsToRun; i++ ){
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
		input_.sendKeysPressedToGame();
		g_->update();
		if( i == 0){
			for( auto& expectation : getExpectations(ExpectationType::FirstLoop)){
				if(!expectation->checkExpectation()){
					std::string errorMessage = createErrorMessage(expectation);
					FAIL() << errorMessage;
				}
			}
		}

		for( auto& expectation : getExpectations(ExpectationType::EachLoop)){
			if(!expectation->checkExpectation()){
				std::string errorMessage = createErrorMessage(expectation);
				FAIL() << errorMessage;
			}
		}
	}

	for( auto& expectation : getExpectations(ExpectationType::AfterTest)){
		if(!expectation->checkExpectation()){
			std::string errorMessage = createErrorMessage(expectation);
			FAIL() << "After all loops " << std::endl<< errorMessage;
		}
	}
}

void GameRunner::AddKeyPressed(Keys keyPressed) {
	input_.addKeyToPress(keyPressed);
}

void GameRunner::makeUncheckedUpdate() {
	g_->update();
}

void GameRunner::AddInPythonCommand(std::string commandText) {
    std::cout << " PyIn: " << commandText << std::endl;
	g_->getInPythonModule().addCommand(commandText);
}

void GameRunner::removeExpectation( std::shared_ptr<IEndToEndExpectation> expectationToRemove ) {
	bool someExpectationWasRemoved = false;

	for( std::vector<std::shared_ptr<IEndToEndExpectation>> &oneVec : allExpectations_){
		if( contains(oneVec, expectationToRemove ) ){
			someExpectationWasRemoved = true;
			removeItem(oneVec, expectationToRemove);
		}
	}

	if( !someExpectationWasRemoved ){
		assert(false && " No item was removed");
	}

}

std::vector<std::shared_ptr<IEndToEndExpectation>> &GameRunner::getExpectations(ExpectationType type) {
	return allExpectations_[type];
}

void GameRunner::clearExpectations() {
    for( auto &vec : allExpectations_){
        vec.clear();
    }
}
