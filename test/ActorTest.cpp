//
// Created by defacto on 14.10.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <mock/MockComponent.h>
#include <lib/gmock-1.7.0/include/gmock/gmock-generated-matchers.h>
#include <lib/gmock-1.7.0/include/gmock/gmock-generated-nice-strict.h>
#include <Actors/Actor.h>

using ::testing::Ge;
using ::testing::Mock;
using ::testing::_;

class ActorTests : public ::testing::Test{
public:
	Actor actor;

	std::vector<std::shared_ptr<MockComponent>> createStrictMockComponentsVector() {
		std::vector<std::shared_ptr<MockComponent>> outVec;
		for(int i = 0; i < 10; i++){
			auto newComponent = std::make_shared<::testing::StrictMock<MockComponent>>();
			Mock::AllowLeak(newComponent.get());
			outVec.push_back(newComponent);
		}
		return outVec;
	}

	std::vector<std::shared_ptr<MockComponent>> createMockComponentsVector() {
		std::vector<std::shared_ptr<MockComponent>> outVec;
		for(int i = 0; i < 10; i++){
			auto newComponent = std::make_shared<MockComponent>();
			Mock::AllowLeak(newComponent.get());
			outVec.push_back(newComponent);
		}
		return outVec;
	}


	void addComponentsToActor( std::vector<std::shared_ptr<MockComponent>> inVec ){
		for( auto &oneComponent : inVec ){
			actor.addComponent(oneComponent);
		}
	}
};
MATCHER(IsEven, "") { return (arg % 2) == 0; }
MATCHER_P(HasTheSameAddress, n, "They " + std::string( negation ? "" : "don' t ")+"have same address."){ return &arg == n;}



TEST_F(ActorTests, ActorCallsOnStartOfComponent){
	auto component = std::make_shared<::testing::StrictMock<MockComponent>>();
	Mock::AllowLeak(component.get());
	actor.addComponent(component);
	EXPECT_CALL(*component, OnStart(HasTheSameAddress(&actor))).Times(1); // tu gdzies jest leak ale nie wiadomo gdzie....
	actor.OnStart();
	createStrictMockComponentsVector();
}

TEST_F(ActorTests, ActorCallsOnStartOfMultipleComponents ) {
	auto components = createStrictMockComponentsVector();
	addComponentsToActor(components);
	for (auto oneComponent : components) {
		EXPECT_CALL(*oneComponent, OnStart(HasTheSameAddress(&actor))).Times(1);
	}
	actor.OnStart();
}

TEST_F(ActorTests, ActorCallsComponentsOnUpdateWhenItIsUpdated){
	auto components = createStrictMockComponentsVector();
	addComponentsToActor(components);
	for (auto oneComponent : components) {
		EXPECT_CALL(*oneComponent, OnUpdate()).Times(1);
	}
	actor.OnUpdate();
}

TEST_F( ActorTests, ActorCallComponentsOnStopWhenItIsStopped ){
	auto components = createStrictMockComponentsVector();
	addComponentsToActor(components);
	for (auto oneComponent : components) {
		EXPECT_CALL(*oneComponent, OnStop()).Times(1);
	}
	actor.OnStop();
}
