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


class MockClass;

Game::Game() {
	rootServiceContainer_.addService(pythonModule_); // must be one of first
	outGameScreenModel_= std::make_shared<OutGameScreenModelScaler>( std::make_shared<OutGameScreenModelImageCentering>(std::make_shared<OutGameScreenModel>(), actorsConfiguration_), actorsConfiguration_);
	drawingSystem_ = std::make_shared<DrawingSystem>(outGameScreenModel_);

	std::shared_ptr<ActorsContainer> actorsContainer = std::make_shared<ActorsContainer>(pythonModule_);
	rootServiceContainer_.addService(actorsContainer);
	std::shared_ptr<GameTimeProvider> gameTimeProvider( new GameTimeProvider) ;
	rootServiceContainer_.addService(gameTimeProvider);


	rootServiceContainer_.addService(boxService_);
	auto rocket = std::make_shared<Actor>(idGenerator.getActorId());

	rocket->addComponent(std::make_shared<RocketBox2dComponent>(boxService_, actorsConfiguration_));
	rocket->addComponent(std::make_shared<PositionComponent>(pythonModule_));
	rocket->addComponent(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Rocket, ScaleToScreen(0.053, 0.1)));
	auto rocketMovingComponent = std::make_shared<RocketMovingComponent>(keyboardManager_, pythonModule_);
	rocket->addComponent(rocketMovingComponent);
	rocket->addComponent( std::make_shared<PythonActorComponent>(pythonModule_));
	rocket->addComponent( std::make_shared<ActorTypeComponent>(ActorType_Rocket, pythonModule_));
	rocket->addComponent( std::make_shared<Box2dPositionSettingComponent>(pythonModule_));

	auto rocketTail = std::make_shared<Actor>(idGenerator.getActorId());
	rocketTail->addComponent(std::make_shared<RocketTailPositionComponent>(rocket, actorsConfiguration_));
	rocketTail->addComponent(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::RocketTail, ScaleToScreen(0.053, 0.1)));
	rocketTail->addComponent(std::make_shared<PositionComponent>(pythonModule_));

	actorsContainer->addActor(rocket);
	actorsContainer->addActor(rocketTail);
	rocketMovingComponent->setRocketTail(rocketTail);

	//auto actorTypeVisualisator = std::make_shared<ActorTypeEnumInPythonVisualisator>( pythonModule_ );
	//rootServiceContainer_.addService(actorTypeVisualisator);
	auto commonTypesVisualizer = std::make_shared<CommonTypesVisualizer>( pythonModule_);
	rootServiceContainer_.addService(commonTypesVisualizer);

	rootServiceContainer_.addService(keyboardManager_); // MUST BE ONE OF LAST!
	rootServiceContainer_.OnStart();
	outGameScreenModel_->OnStart();


	pythonModule_->addVectorOfClass<PythonActorComponent>("PythonActorComponentVector");
}

std::shared_ptr<IOutGameScreenModel> Game::getOutGameScreenModel() {
	return outGameScreenModel_;
}

std::shared_ptr<IInKeyboardStateGetter> Game::getInKeyboardStateGetter() {
	return keyboardManager_;
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