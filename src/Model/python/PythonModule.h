//
// Created by defacto on 10.12.15.
//

#ifndef PWASTEROIDS_PYTHONMODULE_H
#define PWASTEROIDS_PYTHONMODULE_H

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/algorithm/string/join.hpp>
#include <Model/Services/IService.h>
#include "IOutPythonModule.h"
#include "IInPythonModule.h"
#include "ClassVisibleInPythonDuringBuild.h"
#include "PythonActorHandle.h"
#include <iostream>

class PythonStdIoRedirect {
public:
	void Write( std::string const& str ) {
		m_outputs.push_back(str);
		std::cout << "PyOut: "<<str<<std::endl;
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

class MockClass{

};

class A{
public:
	int a;
};


namespace boost {
	namespace python {
		namespace detail {

			template <class T, class... Args>
			inline boost::mpl::vector<T, Args...>
			get_signature(std::function<T(Args...)>, void* = 0)
			{
				return boost::mpl::vector<T, Args...>();
			}

		}
	}
}
using namespace boost::python;

class PythonModule : public IOutPythonModule, public IInPythonModule, public IService{
	PythonStdIoRedirect redirector;
	boost::python::object main_namespace;
	boost::python::object main_module;

	bool onceUpdated_ = false;
public:
	virtual void addCommand(std::string commandText);

	virtual std::string getOutput();

	virtual void OnStart();;

	virtual void OnStop();;

	virtual void OnUpdate();;

	template< typename T>
	void addVectorOfClass(std::string name){
		class_< std::vector<T>> (name.c_str()).def(boost::python::vector_indexing_suite< std::vector<T>>());
	}

	template< typename T>
	void addRootFunction( std::string functionName, T functionToCall ){
		//class_< std::vector<PythonActorHandle>> ("SupaVec").def(boost::python::vector_indexing_suite< std::vector<PythonActorHandle>>());
			auto cls = class_<A>("A");
			cls.def(functionName.c_str(),boost::python::make_function(
        [functionToCall](const A& a) { return functionToCall(); },
        boost::python::default_call_policies(),
        boost::mpl::vector<std::vector<PythonActorHandle>, const A&>()))
    ;
			//cls.add_property("a", +[](const A& a){return a.a;});
			main_namespace["A"] = cls;
	}
};


#endif //PWASTEROIDS_PYTHONMODULE_H
