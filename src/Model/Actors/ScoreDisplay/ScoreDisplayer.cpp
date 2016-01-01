//
// Created by defacto on 2015.12.31..
//

#include "ScoreDisplayer.h"


ScoreDisplayer::ScoreDisplayer(ScoreCount &count_, const std::shared_ptr<IDrawingSystem> &drawingSystem_,
                               ActorsConfiguration &actorsConfiguration_)
        : count_(count_), drawingSystem_(drawingSystem_),
          actorsConfiguration_(actorsConfiguration_) {
}

void ScoreDisplayer::OnStart(IActor &actor) {
    id_ = actor.getActorId();
}

void ScoreDisplayer::OnUpdate() {
    int k = count_.getScore();
    std::string textToDraw = "Score: "+std::to_string(count_.getScore());
    drawingSystem_->drawText(textToDraw, actorsConfiguration_.getScoreTextPosition(), id_);
}