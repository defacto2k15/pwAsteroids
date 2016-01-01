//
// Created by defacto on 2015.12.31..
//

#include "ScoreCount.h"

unsigned int ScoreCount::getScore() {
    return score_;
}

void ScoreCount::addScore(unsigned int delta) {
    score_ += delta;
}

void ScoreCount::resetScore() {
    score_ = 0;
}