//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_MOCKSERVICE_H
#define PWASTEROIDS_MOCKSERVICE_H

#include <lib/gmock-1.7.0/include/gmock/gmock-generated-function-mockers.h>
#include <Model/Services/IService.h>

class MockIService : public IService {
public:
	MOCK_METHOD0(OnStart,
	void());
	MOCK_METHOD0(OnStop,
	void());
	MOCK_METHOD0(OnUpdate,
	void());
};

#endif //PWASTEROIDS_MOCKSERVICE_H
