//
// Created by defacto on 2015.12.31..
//

#ifndef PWASTEROIDS_SCORECOUNT_H
#define PWASTEROIDS_SCORECOUNT_H


class ScoreCount {
    unsigned int score_ = 0;
public:
    unsigned int getScore();

    void addScore(unsigned int delta);

    void resetScore();
};


#endif //PWASTEROIDS_SCORECOUNT_H
