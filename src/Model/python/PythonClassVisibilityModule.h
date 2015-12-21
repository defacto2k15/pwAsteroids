//
// Created by defacto on 2015.12.21..
//

#ifndef PWASTEROIDS_PYTHONCLASSVISIBILITYMODULE_H
#define PWASTEROIDS_PYTHONCLASSVISIBILITYMODULE_H

#include <memory>
#include "PythonModule.h"

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>


template< typename T, typename ... TConstructorArgs >
class PythonClassVisibilityModule {
    std::shared_ptr<PythonModule> pythonModule_;
public:
    PythonClassVisibilityModule(std::shared_ptr<PythonModule> pythonModule)
            : pythonModule_(pythonModule){
    }

    void registerClass(){
        std::string name = typeid(T).name();
        name.erase(0,2);
        if( pythonClass_ == false){
            pythonClass_ = std::make_shared<class_<T, boost::shared_ptr<T>> >
                    (name.c_str(), boost::python::init<TConstructorArgs ... >() );
            pythonModule_->registerClass(*pythonClass_);
        }
    }

    template< typename TReturn, typename ... TArgs >
    void registerMethod(std::string name, std::function<TReturn(TArgs ...)> method );//{
//        if( contains(registeredMethods_, methodName) == false ) {
//            registeredMethods_.push_back(methodName);
//            auto boostFunction = boost::python::make_function(
//                    method,
//                    boost::python::default_call_policies(),
//                    boost::mpl::vector<TReturn, TArgs ...>());
//            (*pythonClass_).def(name.c_str(), boostFunction);
//        }
//    }


    template<typename TComponent, typename TReturn, typename ... TArgs >
    void registerActorMethod( std::string methodName, TReturn( TComponent::* function)( TArgs...) );//{
//        if( contains(registeredMethods_, methodName) == false ) {
//            registeredMethods_.push_back(methodName);
//            std::function<TReturn(PythonActorComponent &, TArgs ...)> functionToPython
//                    = [function](PythonActorComponent &comp, TArgs ... args) {
//                        auto component = comp.getActor()->getOnlyComponent<TComponent>();
//                        return ((component.get())->*function)(args ...);
//                    };
//
//            auto boostFunction = boost::python::make_function(
//                    functionToPython,
//                    boost::python::default_call_policies(),
//                    boost::mpl::vector<TReturn, PythonActorComponent &, TArgs ...>());
//
//            //pythonModule_->registerActorMethod(methodName, boostFunction);
//            PythonClassVisibilityModule< PythonActorComponent, std::shared_ptr<PythonModule> > actorVisibilityModule(pythonModule_);
//            actorVisibilityModule.registerMethod(methodName, functionToPython)
//        }
//
//        //python_->getPythonClass()->def("SOMENAME", boostFunction);
//    };

private:
    static std::vector<std::string> registeredMethods_;
    static std::shared_ptr<class_<T, boost::shared_ptr<T> >> pythonClass_;

};

template< typename T, typename ... TConstructorArgs >
 std::vector<std::string> PythonClassVisibilityModule<T, TConstructorArgs ...>::registeredMethods_;

template< typename T, typename ... TConstructorArgs >
 std::shared_ptr<class_<T, boost::shared_ptr<T> >> PythonClassVisibilityModule<T, TConstructorArgs ...>::pythonClass_;

#include "PythonActorComponent.h"

template< typename T, typename ... TConstructorArgs >
template< typename TReturn, typename ... TArgs >
void PythonClassVisibilityModule<T,TConstructorArgs ...>::registerMethod(std::string name, std::function<TReturn(TArgs ...)> method ){
    if( contains(registeredMethods_, name) == false ) {
        registeredMethods_.push_back(name);
        auto boostFunction = boost::python::make_function(
                method,
                boost::python::default_call_policies(),
                boost::mpl::vector<TReturn, TArgs ...>());
        (*pythonClass_).def(name.c_str(), boostFunction);
    }
}

template< typename T, typename ... TConstructorArgs >
template<typename TComponent, typename TReturn, typename ... TArgs >
void PythonClassVisibilityModule<T,TConstructorArgs ...>::registerActorMethod( std::string methodName, TReturn( TComponent::* function)( TArgs...) ){
    if( contains(registeredMethods_, methodName) == false ) {
        registeredMethods_.push_back(methodName);
        std::function<TReturn( PythonActorComponent &, TArgs ...)> functionToPython
                = [function]( PythonActorComponent &comp, TArgs ... args) {
                    auto component = comp.getActor()->getOnlyComponent<TComponent>();
                    return ((component.get())->*function)(args ...);
                };

        auto boostFunction = boost::python::make_function(
                functionToPython,
                boost::python::default_call_policies(),
                boost::mpl::vector<TReturn, PythonActorComponent &, TArgs ...>());

        //pythonModule_->registerActorMethod(methodName, boostFunction);
        PythonClassVisibilityModule< PythonActorComponent, std::shared_ptr<PythonModule> > actorVisibilityModule(pythonModule_);
        actorVisibilityModule.registerClass();
        actorVisibilityModule.registerMethod(methodName, functionToPython);
    }
};

#endif //PWASTEROIDS_PYTHONCLASSVISIBILITYMODULE_H
