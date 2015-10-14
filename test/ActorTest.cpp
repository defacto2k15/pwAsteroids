//
// Created by defacto on 14.10.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <Actor.h>
#include <mock/MockComponent.h>
#include <lib/gmock-1.7.0/include/gmock/gmock-generated-matchers.h>

using ::testing::Ge;

class ActorTests : public ::testing::Test{
public:

};
MATCHER(IsEven, "") { return (arg % 2) == 0; }
MATCHER_P(HasTheSameAddress, n, "They " + std::string( negation ? "" : "don' t ")+"have same address"){ return &arg == &n;}

TEST_F(ActorTests, ActorCallsOnStartOfComponents){
	Actor actor;
	auto component = std::make_shared<MockComponent>();
	actor.addComponent(component);
	actor.OnStart();
	EXPECT_CALL(*component, OnStart(HasTheSameAddress(actor))).Times(1); // tu gdzies jest leak ale nie wiadomo gdzie....

}