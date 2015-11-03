//
// Created by defacto on 24.10.15.
//

#include "ServiceContainer.h"

void ServiceContainer::foreachService(std::function<void(IService &)> functionToDoOnService) {
	for( auto &service : getServices() ){
		functionToDoOnService(*service);
	}
}

void ServiceContainer::OnStart() {
	foreachService( [](IService &s){s.OnStart();});
}

void ServiceContainer::OnStop() {
	foreachService( [](IService &s){s.OnStop();});
}

void ServiceContainer::OnUpdate() {
	foreachService( [](IService &s){s.OnUpdate();});
}