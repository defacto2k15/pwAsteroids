//
// Created by defacto on 24.10.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <mock/MockIActor.h>
#include <Model/Services/ActorsContainer.h>

class ActorsContainerTest : public ::testing::Test {
	std::vector<std::shared_ptr<MockIActor>> mockActorsVec_{std::make_shared<MockIActor>(),
	                                                        std::make_shared<MockIActor>(),
	                                                        std::make_shared<MockIActor>(),};

public:
	std::vector<std::shared_ptr<IActor>> getActorsVec(){
		std::vector<std::shared_ptr<IActor>> outVec( mockActorsVec_.size());
		std::copy(begin( mockActorsVec_), end( mockActorsVec_), begin(outVec));
		return outVec;
	}

	PythonModule &mockPython = std::make_shared<PythonModule>();

};

TEST_F(ActorsContainerTest, CanAddAndRemoveActorsAndNotingBadWillHappen){
	ActorsContainer container(mockPython);
	for(auto &actor : getActorsVec()){
		container.addActor(actor);
	};
	container.removeActor(getActorsVec()[0]);
}

TEST_F(ActorsContainerTest, IfRemovingNotExistingActorExceptionIsThrown){
	ActorsContainer container(mockPython);
	container.addActor(getActorsVec()[0]);
	container.addActor(getActorsVec()[1]);
	ASSERT_THROW(container.removeActor(getActorsVec()[2]), RemovingNotAddedActorException);
}

TEST_F(ActorsContainerTest, WeCantRemoveTheSameActorTwoTimes){
	ActorsContainer container(mockPython);
	container.addActor(getActorsVec()[0]);
	container.addActor(getActorsVec()[1]);
	container.addActor(getActorsVec()[2]);

	container.removeActor(getActorsVec()[2]);
	ASSERT_THROW(container.removeActor(getActorsVec()[2]), RemovingNotAddedActorException);
}
