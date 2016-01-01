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
#include <Model/Services/ActorTypeEnumInPythonVisualisator.h>
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


class MockClass;

Game::Game() :
		outGameScreenModel_( new OutGameScreenModelScaler(
								std::shared_ptr<IOutGameScreenModel>( new OutGameScreenModelImageCentering(
										std::shared_ptr<IOutGameScreenModel>( new OutGameScreenModel()),
										actorsConfiguration_)),
								actorsConfiguration_)),
		box2dObjectsContainer_(imageScalesContainer_, actorsConfiguration_),
		contactListener_(contactComponentsContainer_),
		rocketLife_(actorsConfiguration_),
		drawingSystem_(outGameScreenModel_),
		 boundariesDuplicationsDrawingSystem_(drawingSystem_, actorsConfiguration_),
		actorsContainer_( new ActorsContainer(pythonModule_)),
		asteroidGenerator_( actorsContainer_, idGenerator, pythonModule_, drawingSystem_, actorsConfiguration_, boxService_, box2dObjectsContainer_, imageScalesContainer_, contactComponentsContainer_, asteroidsCounter_),
		projectilesGenerator_(actorsContainer_, idGenerator, pythonModule_, drawingSystem_, actorsConfiguration_, boxService_, box2dObjectsContainer_, imageScalesContainer_, contactComponentsContainer_, scoreCount_){

	rootServiceContainer_.addService(pythonModule_); // must be one of first

	//std::shared_ptr<ActorsContainer> actorsContainer = std::make_shared<ActorsContainer>(pythonModule_);
	rootServiceContainer_.addService(actorsContainer_);
	std::shared_ptr<GameTimeProvider> gameTimeProvider( new GameTimeProvider) ;
	rootServiceContainer_.addService(gameTimeProvider);
//	asteroidGenerator_ = std::make_shared<AsteroidsGenerator>(actorsContainer, idGenerator,
//		pythonModule_, drawingSystem_, actorsConfiguration_, boxService_,
//		 box2dObjectsContainer_, imageScalesContainer_, contactComponentsContainer_, asteroidsCounter_);
	rootServiceContainer_.addService(std::make_shared<RandomAsteroidsGenerator>(
			asteroidGenerator_, asteroidsCounter_, actorsConfiguration_, gameTimeProvider, randomNumbersProvider_
	));

//	projectilesGenerator_ = std::make_shared< ProjectilesGenerator>(actorsContainer_, idGenerator,
//			pythonModule_, drawingSystem_, actorsConfiguration_, boxService_,
//			box2dObjectsContainer_, imageScalesContainer_, contactComponentsContainer_, scoreCount_);


	rootServiceContainer_.addService(boxService_);

	lifeIndicatorService_ = std::make_shared<LifeIndicatorService>(
			actorsContainer_, pythonModule_, drawingSystem_, imageScalesContainer_, idGenerator, actorsConfiguration_, rocketLife_);
	rootServiceContainer_.addService(lifeIndicatorService_);

	auto rocket = std::make_shared<Actor>(idGenerator.getActorId());

	auto scoreActor = std::make_shared<Actor>(idGenerator.getActorId());
	scoreActor->addComponent( std::make_shared<ScoreDisplayer>(scoreCount_, drawingSystem_, actorsConfiguration_));
	actorsContainer_->addActor(scoreActor);

	rocket->addComponent(std::make_shared<Box2dComponent>(boxService_, actorsConfiguration_, box2dObjectsContainer_.getRocketObject()));
	rocket->addComponent(std::make_shared<PositionComponent>(pythonModule_));
	rocket->addComponent(std::make_shared<DrawingComponent>(boundariesDuplicationsDrawingSystem_ , ImagePrimitiveType::Rocket, imageScalesContainer_.getRocketImageScale()));
	auto rocketMovingComponent = std::make_shared<RocketMovingComponent>(inputManager_, pythonModule_, actorsConfiguration_);
	rocket->addComponent(rocketMovingComponent);
	rocket->addComponent( std::make_shared<PythonActorComponent>(pythonModule_));
	rocket->addComponent( std::make_shared<ActorTypeComponent>(ActorType_Rocket,  pythonModule_));
	rocket->addComponent( std::make_shared<Box2dPositionSettingComponent>(pythonModule_));
	rocket->addComponent( std::make_shared<ScreenBoundariesTeleportationComponent>(actorsConfiguration_));
	rocket->addComponent( std::make_shared<RocketShootingComponent>(actorsConfiguration_, projectilesGenerator_, inputManager_, gameTimeProvider));
	rocket->addComponent( std::make_shared<RocketCollisionComponent>( contactComponentsContainer_, rocketLife_, actorsConfiguration_, gameTimeProvider));

	auto rocketTail = std::make_shared<Actor>(idGenerator.getActorId());
	rocketTail->addComponent(std::make_shared<RocketTailPositionComponent>(rocket, actorsConfiguration_));
	rocketTail->addComponent(std::make_shared<DrawingComponent>(boundariesDuplicationsDrawingSystem_ , ImagePrimitiveType::RocketTail, imageScalesContainer_.getRocketTailImageScale()));
	rocketTail->addComponent(std::make_shared<PositionComponent>(pythonModule_));

	auto borderIndicator = std::make_shared<Actor>(idGenerator.getActorId());
	borderIndicator->addComponent( std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::BorderIndicator, imageScalesContainer_.getBorderIndicatorImageScale() ));
	borderIndicator->addComponent( std::make_shared<PositionComponent>(pythonModule_));
	auto borderIndicatorComponent =  std::make_shared<BorderIndicatorComponent>(actorsConfiguration_, inputManager_);
	borderIndicator->addComponent(borderIndicatorComponent);
	borderIndicator->addComponent( std::make_shared<StaticPositionSettingComponent>());
	actorsContainer_->addActor(borderIndicator);

	actorsContainer_->addActor(rocket);
	actorsContainer_->addActor(rocketTail);
	rocketMovingComponent->setRocketTail(rocketTail);

	auto secondPlayerTargetingActor = std::make_shared<Actor>(idGenerator.getActorId());
	secondPlayerTargetingActor->addComponent(
			std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::SecondPlayerTarget, imageScalesContainer_.getSecondPlayerTargetImageScale() ));
	secondPlayerTargetingActor->addComponent( std::make_shared<PositionComponent>(pythonModule_));
	secondPlayerTargetingActor->addComponent(
			std::make_shared<SecondPlayerTargetComponent>( borderIndicatorComponent, gameTimeProvider, inputManager_, asteroidGenerator_, actorsConfiguration_));
	secondPlayerTargetingActor->addComponent( std::make_shared<StaticPositionSettingComponent>());
	actorsContainer_->addActor( secondPlayerTargetingActor );
	//auto actorTypeVisualisator = std::make_shared<ActorTypeEnumInPythonVisualisator>( pythonModule_ );
	//rootServiceContainer_.addService(actorTypeVisualisator);
	auto commonTypesVisualizer = std::make_shared<CommonTypesVisualizer>( pythonModule_);
	rootServiceContainer_.addService(commonTypesVisualizer);

	rootServiceContainer_.addService(inputManager_); // MUST BE ONE OF LAST!
	rootServiceContainer_.OnStart();
	outGameScreenModel_->OnStart();



	//asteroidGenerator_.generateAsteroid(Point(actorsConfiguration_.getInitialPosition().getX(),0), 270.0f, 1, Point(0.0,0.1), 0.00);
	asteroidGenerator_.generateAsteroid(Point(8, actorsConfiguration_.getInitialPosition().getY()/2), 0.0f, 1, Point(0.0,0.0), 0.00);
	//projectilesGenerator_.generateProjectile( Point(6, 1), 0.0f, Point(-0.2, 0.0), 0.0);
	//asteroidGenerator_.generateAsteroid(Point(6, 1.6), 0.0f, 1, Point(-0.2,0.0), 0.00);

	pythonModule_->addVectorOfClass<PythonActorComponent>("PythonActorComponentVector");
}

std::shared_ptr<IOutGameScreenModel> Game::getOutGameScreenModel() {
	return outGameScreenModel_;
}

std::shared_ptr<IInputStateGetter> Game::getInputStateGetter() {
	return inputStateGetter_;
}

std::shared_ptr<IInPythonModule> Game::getInPythonModule() {
	return pythonModule_;
}

std::shared_ptr<IOutPythonModule> Game::getOutPythonModule() {
	return pythonModule_;
}

void Game::update() {
	outGameScreenModel_->OnUpdate();
	rootServiceContainer_.OnUpdate(); // ugly but works!

}