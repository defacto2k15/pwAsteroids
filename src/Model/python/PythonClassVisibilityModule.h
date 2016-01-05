//
// Created by defacto on 2015.12.21..
//

#ifndef PWASTEROIDS_PYTHONCLASSVISIBILITYMODULE_H
#define PWASTEROIDS_PYTHONCLASSVISIBILITYMODULE_H

#include <memory>
#include "PythonModule.h"

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

template< class T, class ... TConstructorArgs >
struct IsTypeEmpty{
    static const bool value = false;
    typedef class_<T, boost::shared_ptr<T> > classType;

    static std::shared_ptr< classType > createClass( std::string name ){
        return std::make_shared<classType>(name.c_str(), boost::python::init<TConstructorArgs ... >());
    }
};

template<class T>
struct IsTypeEmpty<T>{
    static const bool value = true;
    typedef class_<T, boost::shared_ptr<T>> classType;

    static std::shared_ptr< classType > createClass( std::string name ){
        return std::make_shared<classType>(name.c_str(), boost::python::no_init );
    }
};

template< typename T, typename ... TConstructorArgs >
class PythonClassVisibilityModule {
    PythonModule &pythonModule_;
public:
    PythonClassVisibilityModule(PythonModule &pythonModule)
            : pythonModule_(pythonModule){
    }

    void registerClass(){
        registerClass( typeid(T).name());
    }

    void registerClass(std::string name){
        if (pythonModule_.isPythonEnabled_) {
            //std::string name = typeid(T).name();
            if( pythonClass_ == false){
                pythonClass_ = IsTypeEmpty<T, TConstructorArgs ...>::createClass(name);
                /* pythonClass_ = std::make_shared<class_<T, boost::shared_ptr<T>> >
                         (name.c_str(), boost::python::init<TConstructorArgs ... >() );*/
                pythonModule_.registerClass(*pythonClass_, name);
            }
        }
    }


    template< typename TReturn, typename ... TArgs >
    void registerMethodInternal(std::string name, std::function<TReturn(TArgs ...)> method );

    template< typename TReturn, typename ... TArgs >
    void registerMethod(std::string methodName,  TReturn( T::* function)( TArgs ...) );

    template<typename TComponent, typename TReturn, typename ... TArgs >
    void registerActorMethod( std::string methodName, TReturn( TComponent::* function)( TArgs ...) );//{

    template<typename TComponent, typename TField >
    void registerProperty(std::string propertyName, TField(TComponent::* getter)(void) const, void(TComponent::* setter)(TField));

private:
    static std::vector<std::string> registeredMethods_;
    static std::shared_ptr<typename IsTypeEmpty<T, TConstructorArgs ...>::classType> pythonClass_;
//    static std::shared_ptr<class_<T, boost::shared_ptr<T> >> pythonClass_;
};

template< typename T, typename ... TConstructorArgs >
 std::vector<std::string> PythonClassVisibilityModule<T, TConstructorArgs ...>::registeredMethods_;

template< typename T, typename ... TConstructorArgs >
std::shared_ptr<typename IsTypeEmpty<T, TConstructorArgs ...>::classType> PythonClassVisibilityModule<T, TConstructorArgs ...>::pythonClass_;

#include "PythonActorComponent.h"

template< typename T, typename ... TConstructorArgs >
template< typename TReturn, typename ... TArgs >
void PythonClassVisibilityModule<T,TConstructorArgs ...>::registerMethodInternal(std::string name, std::function<TReturn(TArgs ...)> method ){
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
template< typename TReturn, typename ... TArgs >
void PythonClassVisibilityModule<T,TConstructorArgs ...>::registerMethod(std::string methodName,  TReturn( T::* function)( TArgs...) ){
    if (pythonModule_.isPythonEnabled_) {
        if( contains(registeredMethods_, methodName) == false ) {
            //  registeredMethods_.push_back(methodName); will be added in PythonActorComponent
            std::function<TReturn(T & , TArgs ...)> functionToPython
                    = [function](T &object, TArgs ... args) {
                        return ((&object)->*function)(args ...);
                    };
            registerMethodInternal(methodName, functionToPython);
        }
    }
};

template< typename T, typename ... TConstructorArgs >
template<typename TComponent, typename TReturn, typename ... TArgs >
void PythonClassVisibilityModule<T,TConstructorArgs ...>::registerActorMethod( std::string methodName, TReturn( TComponent::* function)( TArgs...) ){
    if (pythonModule_.isPythonEnabled_) {
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

            //pythonModule_.registerActorMethod(methodName, boostFunction);
            PythonClassVisibilityModule< PythonActorComponent, PythonModule &> actorVisibilityModule(pythonModule_);
            actorVisibilityModule.registerClass();
            actorVisibilityModule.registerMethodInternal(methodName, functionToPython);
        }
    }
};


template< typename T, typename ... TConstructorArgs >
template<typename TComponent, typename TField >

void PythonClassVisibilityModule<T,TConstructorArgs ...>::registerProperty(
        std::string propertyName, TField(TComponent::* getter)(void) const, void(TComponent::* setter)(TField)){
    if( pythonModule_.isPythonEnabled_){
        (*pythonClass_).add_property(propertyName.c_str(), getter, setter);
    }
};

#endif //PWASTEROIDS_PYTHONCLASSVISIBILITYMODULE_H
