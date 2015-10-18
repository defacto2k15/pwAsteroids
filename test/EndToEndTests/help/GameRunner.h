//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_GAMERUNNER_H
#define PWASTEROIDS_GAMERUNNER_H


#include <Game.h>
#include <memory>
#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include "test/EndToEndTests/expectations/IEndToEndExpectation.h"

class GameRunner {
	std::shared_ptr<Game> g_;
	std::vector<std::shared_ptr<IEndToEndExpectation>> expectations_;
public:
	GameRunner();;

	void AddExpectations(std::shared_ptr<IEndToEndExpectation> newExpectation);

	std::string createErrorMessage(std::shared_ptr<IEndToEndExpectation> failedExpectation);

	void RunForLoops(int loopsToRun);
};


#endif //PWASTEROIDS_GAMERUNNER_H
