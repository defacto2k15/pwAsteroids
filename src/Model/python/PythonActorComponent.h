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
    PythonModule &python_;
    PythonClassVisibilityModule<PythonActorComponent, PythonModule&> *module_; // this should not be ptr, but shared_ptr has some const problems
public:

    PythonActorComponent(PythonModule &python);

    PythonActorComponent & operator=(const PythonActorComponent &other);

    virtual void OnStart(IActor &actor) override;

    IActor * getActor();

    bool operator==(const PythonActorComponent &other);

    virtual ~PythonActorComponent(){
        //delete module_; should delete that really todo
    }

    int getActorId();
};



#endif //PWASTEROIDS_PYTHONACTORCOMPONENT_H
