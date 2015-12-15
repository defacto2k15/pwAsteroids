//
// Created by defacto on 10.12.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <test/EndToEndTests/help/GameRunner.h>
#include <test/EndToEndTests/expectations/LambdaExpectation.h>
#include <test/EndToEndTests/expectations/OutPythonCollectorExpectation.h>

TEST(PythonEndToEndTests, SimpleMathTest ){
	GameRunner runner;
	runner.AddAfterRunExpectations(std::make_shared<OutPythonCollectorExpectation>( [](std::string outPython){
		if( outPython.find("16") == std::string::npos ){
			return LastCheck(false, "There was no power result 16 that we expected");
		} else {
			return LastCheck(true,"");
		}
	}));
	runner.AddInPythonCommand("print(2**4)");
	runner.RunForLoops(3);
}

TEST(PythonEndToEndTest, RocketPositionWritingTest ){
	GameRunner runner;
	ActorsConfiguration configuration;
	runner.AddAfterRunExpectations(std::make_shared<OutPythonCollectorExpectation>( [configuration](std::string outPython){
		if(( outPython.find(std::to_string(configuration.getInitialPosition().getX())) == std::string::npos ) ||
			( outPython.find(std::to_string(configuration.getInitialPosition().getY())) == std::string::npos )	){
			return LastCheck(false, std::string("there was no written position of rocket: ")
									+configuration.getInitialPosition().toString()+"As expected");
		} else {
			return LastCheck(true,"");
		}
	}));
	runner.AddInPythonCommand("rocket = ActorsContainer.getActorByName(\"Rocket\")");
	runner.AddInPythonCommand("print(rocket.getPosition())");
	runner.RunForLoops(3);
}
