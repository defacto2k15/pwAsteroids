//
// Created by root on 2016.01.20..
//

#ifndef PWASTEROIDS_PYTHONRUNNER_H
#define PWASTEROIDS_PYTHONRUNNER_H


#include "GameRunner.h"

class PythonRunner {
    GameRunner &gameRunner_;
public:

    PythonRunner(GameRunner &gameRunner_) : gameRunner_(gameRunner_) { }
};


#endif //PWASTEROIDS_PYTHONRUNNER_H
