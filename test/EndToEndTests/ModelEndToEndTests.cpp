#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <chrono>
#include <test/EndToEndTests/help/GameRunner.h>
#include <test/EndToEndTests/expectations/ThereIsImage.h>
#include <test/EndToEndTests/expectations/LambdaExpectation.h>
#include <test/EndToEndTests/expectations/NegativeExpectation.h>
#include <test/EndToEndTests/expectations/ImagePrimitiveExpectation.h>

//Created by defacto on 16.10.15.

TEST(EndToEndTests, RocketAppearsOnScreen ){
	GameRunner runner;
	runner.AddEachLoopExpectations(  std::make_shared<ThereIsImage>(ImagePrimitiveType::Rocket)) ;
	runner.makeUncheckedUpdate();
	runner.RunForLoops(10);
}

TEST(EndToEndTests, ThereIsOnlyOneImageOfRocketOnScreen){
	GameRunner runner;
	runner.AddEachLoopExpectations(std::make_shared<LambdaExpectation>( [](std::shared_ptr<Game> g) {
		auto images = g->getOutGameScreenModel()->getImagePrimitives();
		int imageCount = 0;
		for( auto &image : images){
			if( image.getImageType() == ImagePrimitiveType::Rocket ){
				imageCount++;
			}
		}
		if( imageCount > 1){
			return LastCheck(false, "There is more than one rocket in outImages, there are rockets: "+std::to_string(imageCount));
		}
		return LastCheck(true, "");
	}));
	runner.RunForLoops(10);
}

TEST(EndToEndTests, WhenNoButtonIsClickedRocketDontMovesForAtLeast15Frames){
	GameRunner runner;
	Point firstPositionOfRocket;

	runner.AddFirstLoopExpectations(std::make_shared<LambdaExpectation>( [&firstPositionOfRocket](std::shared_ptr<Game> g) {
		auto images = g->getOutGameScreenModel()->getImagePrimitives();
		for( auto &image : images){
			if(image.getImageType() == ImagePrimitiveType::Rocket ){
				firstPositionOfRocket = image.getPosition();
			}
		}
		return LastCheck(true, "");
	}));

	std::vector<Point> rocketPoints;

	runner.AddEachLoopExpectations(std::make_shared<LambdaExpectation>( [&firstPositionOfRocket, &rocketPoints](std::shared_ptr<Game> g) {
		auto images = g->getOutGameScreenModel()->getImagePrimitives();
			for( auto &image : images){
			if(image.getImageType() == ImagePrimitiveType::Rocket ){
				rocketPoints.push_back(image.getPosition());
			}
		}
		return LastCheck(true, "");
	}));
	runner.RunForLoops(10);

	int i = 0;
	for( auto & recordedPoint : rocketPoints ){
		if( recordedPoint != firstPositionOfRocket ){
			FAIL() << std::string("There was change in position withou button clicking! at frame ")
			        + std::to_string(i) + "\n" + std::string("At beginning ") + firstPositionOfRocket.toString() +
					std::string(" now ")+ recordedPoint.toString();
		}
		i++;
	}
}

TEST(EndToEndTests, WhenPlayer1UpButtonIsPressedRocketMovesUp ){
	GameRunner runner;
	bool firstLoopWasDone = false;
	Point lastPositionOfRocket(0.0f, 0.0f);
	Point firstPositionOfRocket(0.0f, 0.0f);
	runner.AddEachLoopExpectations(std::make_shared<LambdaExpectation>(
			[&lastPositionOfRocket, &firstLoopWasDone, &firstPositionOfRocket](std::shared_ptr<Game> g) {
		auto images = g->getOutGameScreenModel()->getImagePrimitives();
			for( auto &image : images){

			if(image.getImageType() == ImagePrimitiveType::Rocket ){
				if( firstLoopWasDone  == false){
					firstLoopWasDone = true;
					firstPositionOfRocket = image.getPosition();
				}
			   lastPositionOfRocket = image.getPosition();
			}
		}
		firstLoopWasDone = true;
		return LastCheck(true, "");
	}));
	runner.AddKeyPressed(Keys::Player1AccelerateKey);
	runner.RunForLoops(30);

	if( firstPositionOfRocket.getY() < lastPositionOfRocket.getY() ){
		FAIL() << " after 30 loops still rocket didnt move up. First pos  " << firstPositionOfRocket.toString() << " second"
			<< lastPositionOfRocket.toString() << std::endl;
	}
}

TEST(EndToEndTests, WhenButtonsLeftAndAccelerateIsPressedRocketFlightsLeft ){
	GameRunner runner;
	bool firstLoopWasDone = false;
	Point lastPositionOfRocket(0.0f, 0.0f);
	Point firstPositionOfRocket(0.0f, 0.0f);
	runner.AddEachLoopExpectations(std::make_shared<LambdaExpectation>(
			[&lastPositionOfRocket, &firstLoopWasDone, &firstPositionOfRocket](std::shared_ptr<Game> g) {
				auto images = g->getOutGameScreenModel()->getImagePrimitives();
				for( auto &image : images){

					if(image.getImageType() == ImagePrimitiveType::Rocket ){
						if( firstLoopWasDone  == false){
							firstLoopWasDone = true;
							firstPositionOfRocket = image.getPosition();
						}
						lastPositionOfRocket = image.getPosition();
					}
				}
				firstLoopWasDone = true;
				return LastCheck(true, "");
			}));
	runner.AddKeyPressed(Keys::Player1AccelerateKey);
	runner.AddKeyPressed(Keys::Player1LeftKey);
	runner.RunForLoops(40);

	if( (firstPositionOfRocket.getY() > lastPositionOfRocket.getY())
	        ||( firstPositionOfRocket.getX() > lastPositionOfRocket.getX()) ){
		FAIL() << " after 40 loops  rocket didnt move up and left. First pos  "
		       << firstPositionOfRocket.toString() << " second "
		       << lastPositionOfRocket.toString() << std::endl;
	}
}

TEST(EndToEndTests, ThereIsRocketTailImageWhenAccelerateKeyIsPressed ){
	GameRunner runner;
	auto tailVisibleExpectation = std::make_shared<ThereIsImage>(ImagePrimitiveType::RocketTail);
	auto noTailExpectation = std::make_shared<NegativeExpectation>( tailVisibleExpectation );
	runner.AddEachLoopExpectations( noTailExpectation ) ;
	runner.makeUncheckedUpdate();
	runner.makeUncheckedUpdate();
	runner.RunForLoops(10);
	runner.removeExpectation( noTailExpectation );
	runner.AddEachLoopExpectations( tailVisibleExpectation );
	runner.AddKeyPressed(Keys::Player1AccelerateKey);
	runner.makeUncheckedUpdate();
	runner.makeUncheckedUpdate();
	runner.RunForLoops(10);
}

TEST(EndToEndTests, RocketImagePrimitiveHasTheSameActorId ){
	GameRunner runner;
	ActorId id = 9999;
	runner.AddFirstLoopExpectations(
			std::make_shared<ImagePrimitiveExpectation>(
					[](ImagePrimitive &primitite){ return primitite.getImageType() == ImagePrimitiveType::Rocket; },
					[&id](ImagePrimitive &primitive){ id = primitive.getActorId(); 	}
			));

	runner.AddEachLoopExpectations(
			std::make_shared<ImagePrimitiveExpectation>(
					[](ImagePrimitive &primitite){ return primitite.getImageType() == ImagePrimitiveType::Rocket; },
			         [&id](ImagePrimitive &primitive){
				         if( primitive.getActorId() != id ){
					         FAIL() << "Actor id changed. It was "<< id<<" but now is " << primitive.getActorId();
				         }
			         }));
	runner.makeUncheckedUpdate();
	runner.RunForLoops(10);
}

TEST(EndToEndTests, WhenAccelerationKeyIsNotPressedThereIsNoRocketTail ){
	GameRunner runner;
	std::shared_ptr<NegativeExpectation> noTailExpectation = std::make_shared<NegativeExpectation>( std::make_shared<ThereIsImage>(ImagePrimitiveType::RocketTail));
	runner.AddEachLoopExpectations(  noTailExpectation) ;
	runner.makeUncheckedUpdate();
	runner.RunForLoops(10);
}