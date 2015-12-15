//
// Created by defacto on 16.10.15.
//

#include <Model/python/PythonRootMethodNames.h>
#include "Game.h"

class MockClass;

Game::Game() {
	rootServiceContainer_.addService(pythonModule_); // must be one of first
	outGameScreenModel_= std::make_shared<OutGameScreenModelScaler>( std::make_shared<OutGameScreenModelImageCentering>(std::make_shared<OutGameScreenModel>(), actorsConfiguration_), actorsConfiguration_);
	drawingSystem_ = std::make_shared<DrawingSystem>(outGameScreenModel_);

	std::shared_ptr<ActorsContainer> actorsContainer = std::make_shared<ActorsContainer>();
	rootServiceContainer_.addService(actorsContainer);
	std::shared_ptr<GameTimeProvider> gameTimeProvider( new GameTimeProvider) ;
	rootServiceContainer_.addService(gameTimeProvider);


	rootServiceContainer_.addService(boxService_);
	auto rocket = std::make_shared<Actor>(idGenerator.getActorId());

	rocket->addComponent(std::make_shared<RocketBox2dComponent>(boxService_, actorsConfiguration_));
	rocket->addComponent(std::make_shared<PositionComponent>());
	rocket->addComponent(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::Rocket, ScaleToScreen(0.053, 0.1)));
	auto rocketMovingComponent = std::make_shared<RocketMovingComponent>(keyboardManager_);
	rocket->addComponent(rocketMovingComponent);

	auto rocketTail = std::make_shared<Actor>(idGenerator.getActorId());
	rocketTail->addComponent(std::make_shared<RocketTailPositionComponent>(rocket, actorsConfiguration_));
	rocketTail->addComponent(std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::RocketTail, ScaleToScreen(0.053, 0.1)));
	rocketTail->addComponent(std::make_shared<PositionComponent>());

	actorsContainer->addActor(rocket);
	actorsContainer->addActor(rocketTail);
	rocketMovingComponent->setRocketTail(rocketTail);

	rootServiceContainer_.addService(keyboardManager_); // MUST BE ONE OF LAST!
	rootServiceContainer_.OnStart();
	outGameScreenModel_->OnStart();


	//std::function< void(MockClass*) > function = [](MockClass *ptr){ ; };
	pythonModule_->addVectorOfClass<PythonActorHandle>("PythonActorHandleClass");
	pythonModule_->addRootFunction( PythonRootMethodNames::getAllActorsName, [actorsContainer](){ return actorsContainer->getAllActors();});
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