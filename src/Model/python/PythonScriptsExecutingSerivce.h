//
// Created by defacto on 2016.01.05..
//

#ifndef PWASTEROIDS_PYTHONSCRIPTSEXECUTINGSERRIVE_H
#define PWASTEROIDS_PYTHONSCRIPTSEXECUTINGSERRIVE_H

#include <boost/format.hpp>
#include <Model/configuration/GameConfiguration.h>

class PythonScriptsExecutingSerrive : public IService{
    PythonModule &python_;
    GameConfiguration &gameConfiguration_;
public:


    PythonScriptsExecutingSerrive(PythonModule &python_, GameConfiguration &gameConfiguration_);

    virtual void OnStart();

    virtual void OnUpdate();

};



#endif //PWASTEROIDS_PYTHONSCRIPTSEXECUTINGSERRIVE_H
