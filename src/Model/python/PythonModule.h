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
#include <map>
#include <Model/help/StdContainers.h>

//class PythonActorComponent;

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
	std::shared_ptr<class_<A>> rootClass ;
	A root;

	/*std::shared_ptr< class_<... pisz tutaj konkretnie o klasie handler aktora*/
	std::map<std::string, std::vector<std::string> > classesAndMethodsMap_;

	bool onceUpdated_ = false;
public:
	PythonModule() {
		// empty ctor to shut up compiler
	}

	virtual void addCommand(std::string commandText);

	virtual std::string getOutput();

	virtual void OnStart();;

	virtual void OnStop();;

	virtual void OnUpdate();;

	template< typename T>
	void addVectorOfClass(std::string name){
		class_< std::vector<T>> (name.c_str()).def(boost::python::vector_indexing_suite< std::vector<T>>());
	}

	template< typename TRet, typename ... TArg>
	void addRootFunction( std::string functionName, std::function<TRet(TArg ...)> functionToCall ){
		auto boostFunction = boost::python::make_function(
			functionToCall,
			boost::python::default_call_policies(),
			boost::mpl::vector<TRet, TArg ...>());
		main_namespace[functionName.c_str()] = boostFunction;
	}

	template< typename T>
	void registerClass(  ){
		T *ptr = nullptr;
		registerClassGeneric(ptr,typeid(T).name());
	}



	template< typename T>
	void registerClass( boost::python::class_<T, boost::shared_ptr<T> > &cls){
		main_namespace[typeid(T).name()] = cls;
	}

	template< typename T>
	void registerMethod ( std::string methodName, boost::python::object method){
		if( contains( classesAndMethodsMap_[typeid(T).name()], methodName) == false ){
			//classesAndMethodsMap_[typeid(T).name()].push_back(methodName);
			//class_<T, boost::shared_ptr<T> >(typeid(T).name() ).def(methodName.c_str(), method);
			//ZAPISUJ STWORZONE OBIEKTY KLAS DO JAKIEJS KOLEKCJI BY NIE TWORZYC NOWYCH class_ tylko tamtych uzywac!!
		}
	}

	template <typename T>
	void registerActorMethod( std::string methodName, boost::python::object method ){

	}

	std::shared_ptr<class_<A>> getPythonClass (){
		return rootClass;
	}


};

//#include "PythonActorComponent.h"


#endif //PWASTEROIDS_PYTHONMODULE_H
