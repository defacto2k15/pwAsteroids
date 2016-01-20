//
// Created by root on 2016.01.19..
//
#include <Game.h>
#include <Model/Actors/Rocket/RocketLife.h>
#include <Model/Actors/ScoreDisplay/ScoreCount.h>
#include "IService.h"
#include "GameEndingIndicatingService.h"

GameEndingIndicatingService::GameEndingIndicatingService(RocketLife &rocketLife_, ScoreCount &scoreCount_,
                                                         std::shared_ptr<GameStopService> gameStopService_, Game &game_, ActorId scoreId,
                                                         GameConfiguration &configuration, IDrawingSystem &drawingSystem,
                                                         std::shared_ptr<IInputStateProvider> inputStateProvider)
        : rocketLife_(rocketLife_), scoreCount_(scoreCount_), gameStopService_(gameStopService_),
          game_(game_), configuration_(configuration), drawingSystem_(drawingSystem), scoreId_(scoreId),
          inputStateProvider_ ( inputStateProvider){
}

void GameEndingIndicatingService::OnUpdate() {
    if(!isEndScoreDisplayed_ && (rocketLife_.getLife() == 0)){
        gameStopService_->stopGame();
        isEndScoreDisplayed_ = true;
    }

    if( isEndScoreDisplayed_ ){
        std::stringstream ss;
        ss << "Gra skonczona!!! Twoj wynik to " << scoreCount_.getScore() <<"   " << "Aby kontynuowac nacisnij strzal";
        drawingSystem_.drawText(ss.str(), configuration_.getGoodbyeMessagePosition(), scoreId_);

        if( inputStateProvider_->isPressed(Keys::Player1AttackKey)){
            game_.setGameFinished( scoreCount_.getScore());
        }
    }
}

void GameEndingIndicatingService::reset() {
    isEndScoreDisplayed_ = false;
    drawingSystem_.drawText("", configuration_.getGoodbyeMessagePosition(), scoreId_);
    gameStopService_->startGame();
}