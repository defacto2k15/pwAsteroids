//
// Created by defacto on 2015.12.20..
//

#ifndef PWASTEROIDS_PYTHONCLASSDATA_H
#define PWASTEROIDS_PYTHONCLASSDATA_H
#include <string>
#include <vector>
#include <typeinfo>
#include <Model/help/StdContainers.h>
#include <memory>

template<typename TPythonClass>
class PythonClassData {
    const char * classTypeinfoName_;
    std::vector< std::string > methodNames_;
    std::shared_ptr<TPythonClass> pythonClass_;

    template <typename T>
    PythonClassData( std::shared_ptr<TPythonClass> pythonClass) : pythonClass_(pythonClass){
        classTypeinfoName_ = typeid(T).name();
    }

    void addMethod( std::string name ){
        methodNames_.push_back(name);
    }

    bool containsMethod( std::string name){
        return contains(methodNames_,name);
    }


};


#endif //PWASTEROIDS_PYTHONCLASSDATA_H
