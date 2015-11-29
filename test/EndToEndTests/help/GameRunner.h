//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_GAMERUNNER_H
#define PWASTEROIDS_GAMERUNNER_H

#include "FakeKeyboardStateToGameProvider.h"
#include <Game.h>
#include <memory>
#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <Model/help/StdContainers.h>
#include "test/EndToEndTests/expectations/IEndToEndExpectation.h"

class GameRunner {
	std::shared_ptr<Game> g_;
	std::vector<std::shared_ptr<IEndToEndExpectation>> eachLoopExpectations_;
	std::vector<std::shared_ptr<IEndToEndExpectation>> afterTestExpectations_;
	std::vector<std::shared_ptr<IEndToEndExpectation>> firstLoopExpectations_;
	FakeKeyboardStateToGameProvider keyboard_;

public:
	GameRunner();

	void AddEachLoopExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation);

	void AddFirstLoopExpectations( std::shared_ptr<IEndToEndExpectation> newExpectation);

	void AddAfterRunExpectations( std::shared_ptr<IEndToEndExpectation> newExpectation);

	std::string createErrorMessage(std::shared_ptr<IEndToEndExpectation> failedExpectation);

	void RunForLoops(int loopsToRun);

	void AddKeyPressed(Keys keyPressed);

	void makeUncheckedUpdate();

	void removeExpectation( std::shared_ptr<IEndToEndExpectation> expectationToRemove ){
		bool someExpectationWasRemoved = false;
		std::vector< std::vector<std::shared_ptr<IEndToEndExpectation> > >vectorsOfExpectations {
				eachLoopExpectations_, afterTestExpectations_, firstLoopExpectations_
		};
		for( auto &oneVec : vectorsOfExpectations ){
			if ( contains(oneVec, expectationToRemove)){
				someExpectationWasRemoved = true;
				removeItem(oneVec, expectationToRemove);
			}
		}
		if( someExpectationWasRemoved ){
			assert(false && " No item was removed");
		}

	}
};


#endif //PWASTEROIDS_GAMERUNNER_H
