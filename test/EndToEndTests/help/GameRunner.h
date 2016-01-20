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

enum ExpectationType{ FirstLoop = 0, EachLoop = 1, AfterTest = 2 };

class GameRunner {
	std::shared_ptr<Game> g_;
	std::vector<std::vector<std::shared_ptr<IEndToEndExpectation>>> allExpectations_;
	FakeKeyboardStateToGameProvider input_;

public:
	GameRunner();

	void AddEachLoopExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation);

	void AddFirstLoopExpectations( std::shared_ptr<IEndToEndExpectation> newExpectation);

	void AddAfterRunExpectations( std::shared_ptr<IEndToEndExpectation> newExpectation);

	std::string createErrorMessage(std::shared_ptr<IEndToEndExpectation> failedExpectation);

	void RunForLoops(int loopsToRun);

	void AddKeyPressed(Keys keyPressed);

	void makeUncheckedUpdate();

	void removeExpectation( std::shared_ptr<IEndToEndExpectation> expectationToRemove );

    void clearExpectations();

	void AddInPythonCommand(std::string command);
private:
	std::vector<std::shared_ptr<IEndToEndExpectation>> & getExpectations(ExpectationType type);
};


#endif //PWASTEROIDS_GAMERUNNER_H
