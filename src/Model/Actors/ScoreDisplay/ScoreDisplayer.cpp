//
// Created by defacto on 2015.12.31..
//

#include "ScoreDisplayer.h"


ScoreDisplayer::ScoreDisplayer(ScoreCount &count_, IDrawingSystem &drawingSystem_,
                               GameConfiguration &gameConfiguration_)
        : count_(count_), drawingSystem_(drawingSystem_),
          gameConfiguration_(gameConfiguration_) {
}

void ScoreDisplayer::OnStart(IActor &actor) {
    id_ = actor.getActorId();
}

void ScoreDisplayer::OnUpdate() {
    int k = count_.getScore();
    std::string textToDraw = "Score: "+std::to_string(count_.getScore());
    drawingSystem_.drawText(textToDraw, gameConfiguration_.getScoreTextPosition(), id_);
}

void ScoreDisplayer::OnStop(){
    drawingSystem_.addRemovedActorId(id_);
}