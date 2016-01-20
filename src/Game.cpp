//
// Created by defacto on 16.10.15.
//

#include <Model/python/PythonRootMethodNames.h>
#include "Game.h"
#include <Model/Services/ActorsContainer.h>
#include <Model/Services/GameTimeProvider.h>
#include <Model/components/PositionComponent.h>
#include <Model/Actors/Rocket/RocketMovingComponent.h>
#include <Model/Actors/RocketTail/RocketTailPositionComponent.h>
#include <Model/modelInterfaces/OutGameScreenModelScaler.h>
#include <Model/modelInterfaces/OutGameScreenModelImageCentering.h>
#include <Model/python/PythonActorComponent.h>
#include <Model/Services/EnumInPythonVisualisator.h>
#include <Model/components/ActorTypeComponent.h>
#include <Model/box2d/Box2dPositionSettingComponent.h>
#include <Model/python/CommonTypesVisualizer.h>
#include <Model/components/ScreenBoundariesTeleportationComponent.h>
#include <Model/box2d/Box2dObjectsContainer.h>
#include <Model/Actors/Asteroid/RandomAsteroidsGenerator.h>
#include <Model/Actors/Projectile/ProjectilesGenerator.h>
#include <Model/Actors/Rocket/RocketShootingComponent.h>
#include <Model/Actors/secondPlayer/BorderIndicatorComponent.h>
#include <Model/components/StaticPositionSettingComponent.h>
#include <Model/Actors/Rocket/RocketCollisionComponent.h>
#include <Model/Actors/ScoreDisplay/ScoreDisplayer.h>
#include <Model/modelInterfaces/IInputStateGetter.h>
#include <Model/Actors/secondPlayer/SecondPlayerTargetComponent.h>
#include <Model/components/PositionSettingComponent.h>
#include <Model/python/PythonScriptsExecutingSerivce.h>
#include <Model/Actors/powerup/RandomPowerupGenerator.h>


class MockClass;

Game::Game( Point screenResolution, std::map<ImagePrimitiveType, Point> imageSizesMap ) :
		gameConfiguration_(pythonModule_, screenResolution),
		imageScalesContainer_(gameConfiguration_, imageSizesMap),
		outGameScreenModel_( new  OutGameScreenModelImageCentering(
								std::shared_ptr<IOutGameScreenModel>( new OutGameScreenModelScaler(
										std::shared_ptr<IOutGameScreenModel>( new OutGameScreenModel()),
										gameConfiguration_)),
								gameConfiguration_)),
		musicManager_( new MusicManager()),
		box2dObjectsContainer_(imageScalesContainer_, gameConfiguration_),
		contactListener_(contactComponentsContainer_),
		rocketLife_(gameConfiguration_, pythonModule_),
		drawingSystem_(outGameScreenModel_),
		 boundariesDuplicationsDrawingSystem_(drawingSystem_, gameConfiguration_),
		actorsContainer_( new ActorsContainer(pythonModule_)),
		idGenerator(),
		asteroidGenerator_( actorsContainer_, idGenerator, pythonModule_, drawingSystem_, gameConfiguration_, boxService_, box2dObjectsContainer_, imageScalesContainer_, contactComponentsContainer_, asteroidsCounter_, musicManager_, explosionCloudGenerator_),
		projectilesGenerator_(actorsContainer_, idGenerator, pythonModule_, drawingSystem_, gameConfiguration_, boxService_, box2dObjectsContainer_, imageScalesContainer_, contactComponentsContainer_, scoreCount_),
		gameTimeProvider_( new GameTimeProvider()),
		randomAsteroidsGenerator_( new RandomAsteroidsGenerator(asteroidGenerator_, asteroidsCounter_, gameConfiguration_, gameTimeProvider_, randomNumbersProvider_, pythonModule_)),
		lifeIndicatorService_( new LifeIndicatorService(actorsContainer_, pythonModule_, drawingSystem_, imageScalesContainer_, idGenerator, gameConfiguration_, rocketLife_)),
		gameStopService_( new GameStopService( pythonModule_, gameTimeProvider_, boxService_, inputManager_)),
		powerupGenerator_(	actorsContainer_, idGenerator, pythonModule_, drawingSystem_, gameConfiguration_, boxService_, box2dObjectsContainer_,
							  imageScalesContainer_, contactComponentsContainer_, rocket, projectilesGenerator_, inputManager_,
							  gameTimeProvider_, musicManager_, powerupCounter_, rocketLife_),
		randomPowerupsGenerator_( new RandomPowerupGenerator(rocket, gameConfiguration_, gameTimeProvider_, powerupGenerator_, powerupCounter_, randomNumbersProvider_)),
		commonTypesVisualizer_( new CommonTypesVisualizer(pythonModule_)),
		rocket( new Actor(idGenerator.getActorId())),
		pythonScriptsExecutor_( new PythonScriptsExecutingSerrive(pythonModule_, gameConfiguration_)),
		gameEndingIndicatingService_(
                new GameEndingIndicatingService(rocketLife_, scoreCount_, gameStopService_, *this, idGenerator.getActorId(),
                                                gameConfiguration_, drawingSystem_, inputManager_)),
        explosionCloudGenerator_(actorsContainer_, idGenerator, pythonModule_, drawingSystem_, gameConfiguration_,
                                 imageScalesContainer_, gameTimeProvider_){
	rootServiceContainer_.addService(musicManager_);
	rootServiceContainer_.addService(actorsContainer_);
	rootServiceContainer_.addService(gameTimeProvider_);
	rootServiceContainer_.addService(randomAsteroidsGenerator_);
	rootServiceContainer_.addService(boxService_);
	rootServiceContainer_.addService(lifeIndicatorService_);
	rootServiceContainer_.addService(gameStopService_);
	rootServiceContainer_.addService(randomPowerupsGenerator_);
	rootServiceContainer_.addService(commonTypesVisualizer_);
	rootServiceContainer_.addService(pythonScriptsExecutor_);
    rootServiceContainer_.addService(gameEndingIndicatingService_);
    rootServiceContainer_.addService(inputManager_); // MUST BE ONE OF LAST!


	auto scoreActor = std::make_shared<Actor>(idGenerator.getActorId());
	scoreActor->addComponent( std::make_shared<ScoreDisplayer>(scoreCount_, drawingSystem_, gameConfiguration_));
	actorsContainer_->addActor(scoreActor);

	rocket->addComponent(std::make_shared<Box2dComponent>(boxService_, gameConfiguration_, box2dObjectsContainer_.getRocketObject()));
	rocket->addComponent(std::make_shared<PositionComponent>(pythonModule_));
	rocket->addComponent(std::make_shared<DrawingComponent>(boundariesDuplicationsDrawingSystem_ , ImagePrimitiveType::Rocket, imageScalesContainer_.getImageScale(ImagePrimitiveType::Rocket)));
	auto rocketMovingComponent = std::make_shared<RocketMovingComponent>(inputManager_, pythonModule_, gameConfiguration_, gameTimeProvider_);
	rocket->addComponent(rocketMovingComponent);
	rocket->addComponent( std::make_shared<PythonActorComponent>(pythonModule_));
	rocket->addComponent( std::make_shared<ActorTypeComponent>(ActorType_Rocket,  pythonModule_));
	rocket->addComponent( std::make_shared<PositionSettingComponent >(true, pythonModule_));
	rocket->addComponent( std::make_shared<ScreenBoundariesTeleportationComponent>(gameConfiguration_));
	rocket->addComponent( std::make_shared<RocketShootingComponent>(gameConfiguration_, projectilesGenerator_, inputManager_, gameTimeProvider_, musicManager_, Rotation(0)));
	rocket->addComponent( std::make_shared<RocketCollisionComponent>( contactComponentsContainer_, rocketLife_, gameConfiguration_, gameTimeProvider_, musicManager_));

	auto rocketTail = std::make_shared<Actor>(idGenerator.getActorId());
	rocketTail->addComponent(std::make_shared<RocketTailPositionComponent>(rocket, gameConfiguration_));
	rocketTail->addComponent(std::make_shared<DrawingComponent>(boundariesDuplicationsDrawingSystem_ , ImagePrimitiveType::RocketTail, imageScalesContainer_.getImageScale(ImagePrimitiveType::RocketTail)));
	rocketTail->addComponent(std::make_shared<PositionComponent>(pythonModule_));

	auto borderIndicator = std::make_shared<Actor>(idGenerator.getActorId());
	borderIndicator->addComponent( std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::BorderIndicator, imageScalesContainer_.getImageScale(ImagePrimitiveType::BorderIndicator) ));
	borderIndicator->addComponent( std::make_shared<PositionComponent>(pythonModule_));
	auto borderIndicatorComponent =  std::make_shared<BorderIndicatorComponent>(gameConfiguration_, inputManager_);
	borderIndicator->addComponent(borderIndicatorComponent);
	borderIndicator->addComponent( std::make_shared<PositionSettingComponent >(false, pythonModule_));
	borderIndicator->addComponent( std::make_shared<ActorTypeComponent>(ActorType_Other, pythonModule_));
	actorsContainer_->addActor(borderIndicator);

	actorsContainer_->addActor(rocket);
	actorsContainer_->addActor(rocketTail);
	rocketMovingComponent->setRocketTail(rocketTail);

	auto secondPlayerTargetingActor = std::make_shared<Actor>(idGenerator.getActorId());
	secondPlayerTargetingActor->addComponent(
			std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::SecondPlayerTarget, imageScalesContainer_.getImageScale(ImagePrimitiveType::SecondPlayerTarget) ));
	secondPlayerTargetingActor->addComponent( std::make_shared<PositionComponent>(pythonModule_));
	secondPlayerTargetingActor->addComponent(
			std::make_shared<SecondPlayerTargetComponent>( borderIndicatorComponent, gameTimeProvider_, inputManager_, asteroidGenerator_, gameConfiguration_, musicManager_));
	secondPlayerTargetingActor->addComponent( std::make_shared<PositionSettingComponent >(false, pythonModule_));
	secondPlayerTargetingActor->addComponent( std::make_shared<ActorTypeComponent>(ActorType_Other, pythonModule_));
	actorsContainer_->addActor(secondPlayerTargetingActor);

	//auto enumsVisualizer = std::make_shared<EnumInPythonVisualisator>( pythonModule_);
	//rootServiceContainer_.addService(enumsVisualizer);

	rootServiceContainer_.OnStart();
	outGameScreenModel_->OnStart();

}

std::shared_ptr<IOutGameScreenModel> Game::getOutGameScreenModel() {
	return outGameScreenModel_;
}

std::shared_ptr<IInputStateGetter> Game::getInputStateGetter() {
	return inputStateGetter_;
}

IInPythonModule &Game::getInPythonModule() {
	return pythonModule_;
}

IOutPythonModule &Game::getOutPythonModule() {
	return pythonModule_;
}

void Game::update() {
	outGameScreenModel_->OnUpdate();
	rootServiceContainer_.OnUpdate(); // ugly but works!
}

void Game::setResolution(Point newResolution ) {
	gameConfiguration_.setScreenSizeInPixels(newResolution);
}