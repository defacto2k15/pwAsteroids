#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <chrono>
#include <test/EndToEndTests/help/GameRunner.h>
#include <test/EndToEndTests/when/ForEveryLoop.h>
#include <test/EndToEndTests/expectations/ThereIsImage.h>

//
// Created by defacto on 16.10.15.
//
TEST(EndToEndTests, RocketAppearsOnScreen ){
	GameRunner runner;
	runner.AddExpectations(  std::make_shared<ThereIsImage>("rakieta.png")) ;
	runner.RunForLoops(10);
}
