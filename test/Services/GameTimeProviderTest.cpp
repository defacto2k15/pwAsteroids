//
// Created by defacto on 24.10.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <Model/Services/GameTimeProvider.h>
#include <thread>

class GameTimeProviderTest : public ::testing::Test{
public:
	int tolerableDiffrenceInMiliseconds = 4;
};

TEST_F(GameTimeProviderTest, correctlyMeasuresTimeSinceGameStart ){
	GameTimeProvider provider;
	provider.OnStart();
	int milisecondsToSleep = 400;
	std::this_thread::sleep_for(std::chrono::milliseconds(milisecondsToSleep));
	provider.OnUpdate();
	int milisecondsSinceGameStart = provider.getMilisecondsSinceGameStart();
	std::cout<<milisecondsSinceGameStart - milisecondsToSleep<<std::endl;
	ASSERT_GE(milisecondsSinceGameStart, milisecondsToSleep);
	ASSERT_TRUE( (milisecondsSinceGameStart - milisecondsToSleep) <  tolerableDiffrenceInMiliseconds);
}

TEST_F(GameTimeProviderTest, correctlyMeasuresTimeBetweenFrames){
	GameTimeProvider provider;
	std::vector<int> timesToSleepBetweenUpdates{120, 94, 155, 40, 32, 90, 13, 38};
	provider.OnStart();
	for(auto & oneTimeToSleep : timesToSleepBetweenUpdates){
		std::this_thread::sleep_for(std::chrono::milliseconds(oneTimeToSleep));
		provider.OnUpdate();
		ASSERT_GE(provider.getMilisecondsBetweenFrames(), oneTimeToSleep);
		ASSERT_TRUE(provider.getMilisecondsBetweenFrames() - oneTimeToSleep < tolerableDiffrenceInMiliseconds );
	}
}
