//
// Created by root on 2016.01.20..
//

#ifndef PWASTEROIDS_PYTHONRUNNER_H
#define PWASTEROIDS_PYTHONRUNNER_H


#include "GameRunner.h"
#include <boost/format.hpp>

class PythonRunner {
    GameRunner &gameRunner_;
public:
    PythonRunner(GameRunner &gameRunner_) : gameRunner_(gameRunner_) {
    }

    void removeAllActors(){
        gameRunner_.AddInPythonCommand("RemoveAllActors()");
    }

    void createAsteroid( Point position, Point speed){
        std::stringstream ss;
        ss << boost::format("generateAsteroid( Point(%1%, %2%), Rotation(0), 1, Point(%3%, %4%), 0)")
              % position.getX() %position.getY() % speed.getX() % speed.getY();
        gameRunner_.AddInPythonCommand(ss.str());
    }

    void createProjectile( Point position, Rotation rotation, Point velocity){
        std::stringstream ss;
        ss << boost::format("generateProjectile( Point(%1%, %2%), Rotation(%3%), Point(%4%, %5%), 0)")
              % position.getX() %position.getY() % float(rotation) % velocity.getX() % velocity.getY();
        gameRunner_.AddInPythonCommand(ss.str());
    }
};


#endif //PWASTEROIDS_PYTHONRUNNER_H
