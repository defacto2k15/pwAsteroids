//
// Created by defacto on 14.10.15.
//

#ifndef PWASTEROIDS_IACTOR_H
#define PWASTEROIDS_IACTOR_H

#include <memory>
#include "Component.h"
class Component;

class IActor{
public:
	virtual void addComponent(std::shared_ptr<Component> component)=0;
	virtual void OnStart()=0;
	virtual void OnUpdate()=0;
	virtual void OnStop()=0;
	virtual ~IActor(){};
};
#endif //PWASTEROIDS_IACTOR_H
