//
// Created by defacto on 2015.12.19..
//

#ifndef PWASTEROIDS_PYTHONACTORCOMPONENT_H
#define PWASTEROIDS_PYTHONACTORCOMPONENT_H

#include <Model/Actors/IActor.h>
#include <Model/components/Component.h>
#include "PythonModule.h"


template< typename T, typename ... TConstructorArgs >
class PythonClassVisibilityModule;

class PythonActorComponent : public Component {
    IActor *actor_;
    std::shared_ptr<PythonModule> python_;
    PythonClassVisibilityModule<PythonActorComponent, std::shared_ptr<PythonModule>> *module_; // this should not be ptr, but shared_ptr has some const problems
public:

    PythonActorComponent(std::shared_ptr<PythonModule> python);

    virtual void OnStart(IActor &actor) override;

    virtual void OnUpdate() override{

    }

    virtual void OnStop() override{

    }

     IActor *getActor(){
        return actor_;
    }

    bool operator==( const PythonActorComponent &other){
        return actor_ == other.actor_;
    }

    virtual ~PythonActorComponent(){
        //delete module_; should delete that really todo
    }
};



#endif //PWASTEROIDS_PYTHONACTORCOMPONENT_H
