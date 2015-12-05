//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_MOCKIACTOR_H
#define PWASTEROIDS_MOCKIACTOR_H

#include <lib/gmock-1.7.0/include/gmock/gmock-generated-function-mockers.h>
#include <Model/Actors/IActor.h>

class MockIActor : public IActor {
public:
	MOCK_METHOD1(addComponent, void(std::shared_ptr<Component> component));
	MOCK_CONST_METHOD0(getActorId, ActorId());
protected:
	MOCK_METHOD1(getOnlyComponent, std::shared_ptr<Component> (ComponentTypeChecker checker));
};

#endif //PWASTEROIDS_MOCKIACTOR_H
