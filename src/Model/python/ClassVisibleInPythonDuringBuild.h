//
// Created by defacto on 15.12.15.
//

#ifndef PWASTEROIDS_CLASSVISIBLEINPYTHONDURINGBUILD_H
#define PWASTEROIDS_CLASSVISIBLEINPYTHONDURINGBUILD_H
#include <string>
#include <boost/algorithm/string/join.hpp>
#include <boost/python.hpp>

/*using namespace boost::python;
template<typename T>
class ClassVisibleInPythonDuringBuild {
     boost::python::object *main_namespace_;
     T *objPtr_;
     std::string className_;
     boost::python::class_<T> createdClass_;
public:
    ClassVisibleInPythonDuringBuild( boost::python::object *main_namespace, T *objPtr, std::string className ) :
            main_namespace_(main_namespace), objPtr_(objPtr), className_(className){/*,
             createdClass_(createClassName(className)){
		//main_namespace[createClassName(className)] = createdClass_;
    }

	template<typename M>
	ClassVisibleInPythonDuringBuild &addMethod( M method, std::string methodName ){
		createdClass_.def(methodName.c_str(), method);
		return *this;
	}

	void build(){
		main_namespace_->operator[](createClassName(className_)) = createdClass_;
		main_namespace_->operator[](className_) = ptr(objPtr_);
	}

private:
	const char *createClassName( std::string name ){
		return ("C"+name).c_str();
	}
};*/


#endif //PWASTEROIDS_CLASSVISIBLEINPYTHONDURINGBUILD_H
