//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_ROOTSERVICECONTAINER_H
#define PWASTEROIDS_ROOTSERVICECONTAINER_H


#include "ServiceContainer.h"

class RootServiceContainer : public ServiceContainer {
	std::vector<std::shared_ptr<IService>> servicesVec_;
public:
	RootServiceContainer(){};
	RootServiceContainer(std::initializer_list<std::shared_ptr<IService>> services );

	RootServiceContainer(std::vector<std::shared_ptr<IService>> inVec);

	void addService(std::initializer_list<std::shared_ptr<IService>> services );

	void addService(std::vector<std::shared_ptr<IService>> inVec);

	void addService(std::shared_ptr<IService> service);

protected:
	virtual std::vector<std::shared_ptr<IService>> getServices();
};


#endif //PWASTEROIDS_ROOTSERVICECONTAINER_H
