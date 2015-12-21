//
// Created by defacto on 14.12.15.
//

#ifndef PWASTEROIDS_PYTHONACTORHANDLE_H
#define PWASTEROIDS_PYTHONACTORHANDLE_H


#include <Model/Actors/IActor.h>

class PythonActorHandle {
    std::shared_ptr<IActor> actor_;
public:
    PythonActorHandle( std::shared_ptr<IActor> actor ): actor_(actor) {}
    bool operator==( const PythonActorHandle &other){
        return actor_ == other.actor_;
    }
};


#endif //PWASTEROIDS_PYTHONACTORHANDLE_H
