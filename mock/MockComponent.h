//
// Created by defacto on 14.10.15.
//

#ifndef PWASTEROIDS_MOCKCOMPONENT_H
#define PWASTEROIDS_MOCKCOMPONENT_H

#include <lib/gmock-1.7.0/include/gmock/gmock-generated-function-mockers.h>
#include <Model/components/Component.h>

class IActor;

class MockComponent : public Component {
public:
	MOCK_METHOD1(OnStart,
	             void(IActor &actor));
	MOCK_METHOD0(OnUpdate,
	             void());
	MOCK_METHOD0(OnStop,
	             void());
};


#endif //PWASTEROIDS_MOCKCOMPONENT_H
