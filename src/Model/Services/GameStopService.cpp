//
// Created by defacto on 2016.01.04..
//

#include "GameStopService.h"
#include <iostream>

GameStopService::GameStopService(PythonModule &python_,
                                 const std::shared_ptr<GameTimeProvider> gameTimeProvider_,
                                 const std::shared_ptr<Box2DService> box2dService_,
                                 std::shared_ptr<InputStateManager> inputManager)
        : python_(
        python_), gameTimeProvider_(gameTimeProvider_), box2dService_(box2dService_), inputManager(inputManager) { }

void GameStopService::OnUpdate() {
    if( inputManager->wasClicked(Keys::PauseKey)){
        if( isPaused_ == false ){
            stopGame();
        } else {
            startGame();
        }
    }
}

void GameStopService::stopGame() {
    inputManager->turnOffAllKeysInterpretationBut( std::vector<Keys>{Keys::PauseKey});
    //inputManager->turnOffGameKeysInterpretation();
    gameTimeProvider_->turnOff();
    box2dService_->turnOffSimulation();
    isPaused_ = false;
}

void GameStopService::startGame() {
    inputManager->turnOnAllKeysInterpretation();
    //inputManager->turnOnGameKeysInterpretation();
    gameTimeProvider_->turnOn();
    box2dService_->turnOnSimulation();
    isPaused_ = true;
}
