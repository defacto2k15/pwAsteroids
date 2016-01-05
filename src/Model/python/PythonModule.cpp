//
// Created by defacto on 10.12.15.
//

#include <Model/Actors/ActorType.h>
#include "PythonModule.h"

std::vector<std::string> PythonStdIoRedirect::m_outputs; // must be static, otherwise output is missing

void PythonModule::addCommand(std::string commandText) {
	try {
		handle<> ignored(( PyRun_String(commandText.c_str(),
										Py_file_input,
										main_namespace.ptr(),
										main_namespace.ptr())));
	}catch( error_already_set ){
		PyErr_Print();
	}
}

std::string PythonModule::getOutput() {
	std::string joinedString = boost::algorithm::join( redirector.GetOutput(), " ");
	return joinedString;
}

PythonModule::PythonModule() {
	isPythonEnabled_ = true;
	if (isPythonEnabled_) {
		try{
			Py_Initialize();
			main_module = import("__main__");
			main_namespace = main_module.attr("__dict__");
			main_namespace["PythonStdIoRedirect"] = class_<PythonStdIoRedirect>("PythonStdIoRedirect", init<>())
					.def("write", &PythonStdIoRedirect::Write);
			import("sys").attr("stderr") = redirector;
			import("sys").attr("stdout") = redirector;

		} catch( boost::python::error_already_set ){
			PyErr_Print();
		}
	}
}

PythonModule::~PythonModule() {
	if (isPythonEnabled_) {
		Py_Finalize();
	}
}