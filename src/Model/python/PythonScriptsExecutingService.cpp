//
// Created by defacto on 2016.01.05..
//
#include <iostream>
#include "PythonScriptsExecutingSerivce.h"

void  PythonScriptsExecutingSerrive::OnUpdate() {
    std::string onUpdateExecutionScriptString(
            "exec(onUpdateScriptString, globals() )\n");
    python_.addCommand(onUpdateExecutionScriptString);
}

void  PythonScriptsExecutingSerrive::OnStart() {
    std::string pythonCommandTemplate(
                     "%1% = ''\n"
                    "try:\n"
                    "\tfn = open('%2%', 'r' )\n"
                    "\t%1% = fn.read()\n"
                    "except IOError:\n"
                    "\tprint('Cant read %3% python file')\n"
                    "exec(%1%, globals() )\n");
    std::stringstream ss;

    ss << boost::format(pythonCommandTemplate) % "onStartScriptString"
          % gameConfiguration_.getOnStartPythonScriptPath() % "OnStart" ;
    python_.addCommand(ss.str());

    ss.str("");

    ss << boost::format(pythonCommandTemplate) % "onUpdateScriptString"
          % gameConfiguration_.getOnUpdatePythonScriptPath() % "OnUpdate" ;

    python_.addCommand(ss.str());
}

PythonScriptsExecutingSerrive::PythonScriptsExecutingSerrive(PythonModule &python_, GameConfiguration &gameConfiguration_)
        : python_(python_), gameConfiguration_(gameConfiguration_) { }
