//
// Created by defacto on 10.12.15.
//

#include <Model/Actors/ActorType.h>
#include "PythonModule.h"

std::vector<std::string> PythonStdIoRedirect::m_outputs; // must be static, otherwise output is missing



void PythonModule::addCommand(std::string commandText) {
	if (isPythonEnabled_) {
		try {
			handle<> ignored((PyRun_String(commandText.c_str(),
				Py_file_input,
				main_namespace.ptr(),
				main_namespace.ptr())));
		}
		catch (error_already_set) {
			PyErr_Print();
		}
	}
}

std::string PythonModule::getOutput() {
	std::string joinedString = boost::algorithm::join( redirector.GetOutput(), " ");
	return joinedString;
}

PythonModule::PythonModule() {
    isPythonEnabled_ = false;

#ifndef NO_USE_PYTHON
	isPythonEnabled_ = true;
#endif

	if (isPythonEnabled_) {
		try{
            int val = Py_IsInitialized();
                Py_Initialize();
                main_module = import("__main__");
                main_namespace = main_module.attr("__dict__");
                boost::python::type_info info = boost::python::type_id<PythonStdIoRedirect>();
                const boost::python::converter::registration* reg = boost::python::converter::registry::query(info);
                if (reg == NULL || ((*reg).m_to_python == NULL))
                {
                    main_namespace["PythonStdIoRedirect"] = class_<PythonStdIoRedirect>("PythonStdIoRedirect", init<>())
                            .def("write", &PythonStdIoRedirect::Write);
                }

                import("sys").attr("stderr") = redirector;
                import("sys").attr("stdout") = redirector;

        } catch( boost::python::error_already_set ){
#ifndef TESTING
			PyErr_Print();
#endif
		}
	}
}

PythonModule::~PythonModule() {
	if (isPythonEnabled_) {
		Py_Finalize();
	}
}