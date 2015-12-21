//
// Created by defacto on 2015.12.21..
//

#ifndef PWASTEROIDS_IPYTHONACTORCOMPONENT_H
#define PWASTEROIDS_IPYTHONACTORCOMPONENT_H

#include <Model/components/Component.h>

class IPythonActorComponent : public Component {
public:
   virtual IActor *getActor()=0;
   virtual bool operator==( const IPythonActorComponent &other);
};
#endif //PWASTEROIDS_IPYTHONACTORCOMPONENT_H
