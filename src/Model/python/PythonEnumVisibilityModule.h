//
// Created by defacto on 2015.12.21..
//

#ifndef PWASTEROIDS_PYTHONENUMVISIBILITYMODULE_H
#define PWASTEROIDS_PYTHONENUMVISIBILITYMODULE_H

#include <memory>
#include "PythonModule.h"

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

template< typename T >
class PythonEnumVisibilityModule {
    PythonModule &pythonModule_;
public:
    PythonEnumVisibilityModule(PythonModule &pythonModule)
            : pythonModule_(pythonModule){
    }

    void registerClass(){
        if( pythonEnum_ == false){
           // auto kk = enum_<T>("TRE1");
            pythonEnum_ = std::make_shared<enum_<T>>(typeid(T).name());
            pythonModule_.registerInMainNamespace(typeid(T).name(), *pythonEnum_);
        }
    }

    template<typename R>
    void addEnumValue( std::string name, R value){
        pythonEnum_->value(name.c_str(), value);
    }

private:
    static std::shared_ptr<enum_<T >> pythonEnum_;

};

template< typename T>
std::shared_ptr<enum_<T>> PythonEnumVisibilityModule<T>::pythonEnum_;


#endif //PWASTEROIDS_PYTHONENUMVISIBILITYMODULE_H
