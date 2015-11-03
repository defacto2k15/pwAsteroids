//
// Created by defacto on 24.10.15.
//

#include "ActorsContainer.h"

std::vector<std::shared_ptr<IService>> ActorsContainer::getServices() {
	std::vector<std::shared_ptr<IService>> outVec(actorsVec_.size());
	std::copy(begin(actorsVec_), end(actorsVec_), begin(outVec));
	return outVec;
}
