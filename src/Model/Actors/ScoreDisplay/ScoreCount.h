//
// Created by defacto on 2015.12.31..
//

#ifndef PWASTEROIDS_SCORECOUNT_H
#define PWASTEROIDS_SCORECOUNT_H


class ScoreCount {
    unsigned int score_ = 0;
public:
    unsigned int getScore(){
        return score_;
    }

    void addScore(unsigned int delta){
        score_ += delta;
    }

    void resetScore(){
        score_ = 0;
    }
};


#endif //PWASTEROIDS_SCORECOUNT_H
