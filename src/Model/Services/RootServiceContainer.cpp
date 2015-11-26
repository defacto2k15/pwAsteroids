//
// Created by defacto on 24.10.15.
//

#include "RootServiceContainer.h"

RootServiceContainer::RootServiceContainer(std::initializer_list<std::shared_ptr<IService>> services )
		: servicesVec_(services.size()) {
	std::copy(begin(services), end(services), begin(servicesVec_));
}

std::vector<std::shared_ptr<IService>> RootServiceContainer::getServices() {
	return servicesVec_;
}

RootServiceContainer::RootServiceContainer(std::vector<std::shared_ptr<IService>> inVec) : servicesVec_(inVec) {}

void RootServiceContainer::addService(std::initializer_list<std::shared_ptr<IService>> services ) {
	for( auto& oneService : services){
		servicesVec_.push_back(oneService);
	}
}

void RootServiceContainer::addService(std::shared_ptr<IService> service) {
	addService({service});
}

void RootServiceContainer::addService(std::vector<std::shared_ptr<IService>> inVec) {
	for( auto& oneService : inVec){
		servicesVec_.push_back(oneService);
	}
}