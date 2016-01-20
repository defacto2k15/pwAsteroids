//
// Created by root on 2016.01.20..
//
#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <test/EndToEndTests/help/GameRunner.h>
#include <test/EndToEndTests/help/PythonRunner.h>
#include <test/EndToEndTests/expectations/ThereIsGivenAmountOfImages.h>

class  AsteroidsTest : public ::testing::Test
{
public:
    GameRunner gameRunner;
    PythonRunner pythonRunner;

    AsteroidsTest() : pythonRunner(gameRunner){
    }
};

TEST_F( AsteroidsTest, createAsteroidPythonFunctionCreatesOneAsteroid){
    pythonRunner.removeAllActors();
    pythonRunner.createAsteroid(Point(1,1), Point(0,0));
    gameRunner.AddAfterRunExpectations(std::make_shared<ThereIsGivenAmountOfImages>(ImagePrimitiveType::Asteroid, 1));
    gameRunner.RunForLoops(5);
}

TEST_F( AsteroidsTest, asteroidIsNotDuplicatedWhenItIsOnScreenBorder){
    gameRunner.makeUncheckedUpdate();
    pythonRunner.removeAllActors();
    pythonRunner.createAsteroid(Point(0,2), Point(0,0));
    gameRunner.AddAfterRunExpectations(std::make_shared<ThereIsGivenAmountOfImages>(ImagePrimitiveType::Asteroid, 1));
    gameRunner.RunForLoops(5);
}

TEST_F( AsteroidsTest, WhenTwoAsteroidsCrashAtLowSpeedTheyAreNotDestroyed){
    gameRunner.makeUncheckedUpdate();
    pythonRunner.removeAllActors();
    pythonRunner.createAsteroid(Point(0,2), Point(0.05,0));
    pythonRunner.createAsteroid(Point(2,2), Point(-0.05,0));
    gameRunner.AddAfterRunExpectations(std::make_shared<ThereIsGivenAmountOfImages>(ImagePrimitiveType::Asteroid, 2));
    gameRunner.RunForLoops(55);
}

TEST_F( AsteroidsTest, WhenTwoAsteroidsCrashAtMediumSpeedTheyAreBothSplitted){
    gameRunner.makeUncheckedUpdate();
    pythonRunner.removeAllActors();
    pythonRunner.createAsteroid(Point(0,2), Point(0.20,0));
    pythonRunner.createAsteroid(Point(2,2), Point(-0.20,0));
    gameRunner.AddAfterRunExpectations(std::make_shared<ThereIsGivenAmountOfImages>(ImagePrimitiveType::Asteroid, 4));
    gameRunner.RunForLoops(55);
}

TEST_F( AsteroidsTest, WhenTwoAsteroidsCrashAtHighSpeedTheyAreDestroyed){
    gameRunner.makeUncheckedUpdate();
    pythonRunner.removeAllActors();
    pythonRunner.createAsteroid(Point(0,2), Point(1,0));
    pythonRunner.createAsteroid(Point(2,2), Point(-1,0));
    gameRunner.AddAfterRunExpectations(std::make_shared<ThereIsGivenAmountOfImages>(ImagePrimitiveType::Asteroid, 0));
    gameRunner.RunForLoops(55);
}

TEST_F( AsteroidsTest, AfterProjectileCrashIntoAsteroidTheAsteroidIsSplitted){
    gameRunner.makeUncheckedUpdate();
    pythonRunner.removeAllActors();
    pythonRunner.createAsteroid(Point(2,2), Point(0,0));
    pythonRunner.createProjectile(Point(3,2), Rotation(270), Point(-1,0));
    gameRunner.AddAfterRunExpectations(std::make_shared<ThereIsGivenAmountOfImages>(ImagePrimitiveType::Asteroid, 2));
    gameRunner.RunForLoops(55);
}