//
// Created by defacto on 10.12.15.
//

#ifndef PWASTEROIDS_PYTHONMODULE_H
#define PWASTEROIDS_PYTHONMODULE_H

#include <boost/python.hpp>
#include <Model/Services/IService.h>
#include "IOutPythonModule.h"
#include "IInPythonModule.h"

class PythonModule : public IOutPythonModule, public IInPythonModule, public IService{

public:
	virtual void addCommand(std::string commandText){

	}

	virtual std::string getOutput(){

	}

	virtual void OnStart(){
		using namespace boost::python;
	//	try{
			Py_Initialize();
		//} catch( error_arleady_set ){
	//		PyErr_Print();
	//	}
	};
	virtual void OnStop(){};
	virtual void OnUpdate(){};
};


#endif //PWASTEROIDS_PYTHONMODULE_H
