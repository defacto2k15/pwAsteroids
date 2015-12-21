//
// Created by defacto on 10.12.15.
//

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
	std::string joinedString = boost::algorithm::join( redirector.GetOutput(), "\n");
	return joinedString;
}

void PythonModule::OnStart() {
	try{
		Py_Initialize();
		main_module = import("__main__");
		main_namespace = main_module.attr("__dict__");
		main_namespace["PythonStdIoRedirect"] = class_<PythonStdIoRedirect>("PythonStdIoRedirect", init<>())
				.def("write", &PythonStdIoRedirect::Write);
		import("sys").attr("stderr") = redirector;
		import("sys").attr("stdout") = redirector;

		std::string ss = "A";
		rootClass = std::make_shared<class_<A>>(ss.c_str());
		main_namespace["RootClass"] = *rootClass;
		//main_namespace["GameRoot"] = ptr(root);

	} catch( boost::python::error_already_set ){
		PyErr_Print();
	}
}

void PythonModule::OnStop() {
	Py_Finalize();
}

void PythonModule::OnUpdate() {
	if( onceUpdated_ == false ){

		//	auto cls = 	class_<A>("A");
		//	cls.add_property("a", +[](const A& a){return a.a;});
		//	main_namespace["A"] = cls;
	}
}