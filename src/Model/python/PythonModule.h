//
// Created by defacto on 10.12.15.
//

#ifndef PWASTEROIDS_PYTHONMODULE_H
#define PWASTEROIDS_PYTHONMODULE_H

#include <boost/python.hpp>
#include <boost/algorithm/string/join.hpp>
#include <Model/Services/IService.h>
#include "IOutPythonModule.h"
#include "IInPythonModule.h"

class PythonStdIoRedirect {
public:
	void Write( std::string const& str ) {
		m_outputs.push_back(str);
	}

	static std::vector<std::string> GetOutput()
	{
		std::vector<std::string> toReturn(m_outputs);
		m_outputs.clear();
		return toReturn;
	}
private:
	static std::vector<std::string> m_outputs; // must be static, otherwise output is missing
};

std::vector<std::string> PythonStdIoRedirect::m_outputs; // must be static, otherwise output is missing


using namespace boost::python;

class PythonModule : public IOutPythonModule, public IInPythonModule, public IService{
	PythonStdIoRedirect redirector;
	boost::python::object main_namespace;
	boost::python::object main_module;
public:
	virtual void addCommand(std::string commandText){
		try {
			handle<> ignored(( PyRun_String(commandText.c_str(),
											Py_file_input,
											main_namespace.ptr(),
											main_namespace.ptr())));
		}catch( error_already_set ){
			PyErr_Print();
		}
	}

	virtual std::string getOutput(){
		std::string joinedString = boost::algorithm::join( redirector.GetOutput(), "\n");
		return joinedString;
	}

	virtual void OnStart(){

	//	try{
			Py_Initialize();
		main_module = import("__main__");
		main_namespace = main_module.attr("__dict__");
		main_namespace["PythonStdIoRedirect"] = class_<PythonStdIoRedirect>("PythonStdIoRedirect", init<>())
					.def("write", &PythonStdIoRedirect::Write);
		import("sys").attr("stderr") = redirector;
		import("sys").attr("stdout") = redirector;


		//} catch( error_arleady_set ){
	//		PyErr_Print();
	//	}
	};
	virtual void OnStop(){};
	virtual void OnUpdate(){};
};


#endif //PWASTEROIDS_PYTHONMODULE_H
