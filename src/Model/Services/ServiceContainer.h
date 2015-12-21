//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_SERVICECONTAINER_H
#define PWASTEROIDS_SERVICECONTAINER_H

#include <vector>
#include <memory>
#include <functional>
#include "IService.h"

class ServiceContainer : public IService { // wzorzec kompozyt???

public:

	virtual void OnStart();

	virtual void OnStop();

	virtual void OnUpdate();
protected:
	virtual std::vector<std::shared_ptr<IService>> getServices()=0;
	void foreachService(std::function<void(IService &)> functionToDoOnService);
};


#endif //PWASTEROIDS_SERVICECONTAINER_H
