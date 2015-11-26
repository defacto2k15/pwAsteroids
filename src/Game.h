//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_GAME_H
#define PWASTEROIDS_GAME_H


#include <Model/modelInterfaces/OutGameScreenModel.h>
#include <stdexcept>
#include <Model/Services/ActorsContainer.h>
#include <Model/Services/GameTimeProvider.h>
#include <Model/Services/RootServiceContainer.h>
#include <Model/components/PositionComponent.h>
#include <Model/Actors/Rocket/RocketDrawableComponent.h>
#include <Model/Actors/Rocket/RocketMovingComponent.h>
#include <Model/Actors/Actor.h>
#include <Model/ModelDrawing/DrawingSystem.h>
#include <Model/modelInterfaces/IInKeyboardStateGetter.h>
#include <Model/modelInterfaces/KeyboardStateManager.h>

class Game {
private:
	OutGameScreenModel outGameScreenModel_;
	RootServiceContainer rootServiceContainer_;
	DrawingSystem drawingSystem_;
	std::shared_ptr<KeyboardStateManager> keyboardManager_ = std::make_shared<KeyboardStateManager>();
	std::shared_ptr<Box2DService> boxService_ = std::make_shared<Box2DService>();
public:
	Game() : drawingSystem_(outGameScreenModel_)
	{
		rootServiceContainer_.addService(keyboardManager_);
		std::shared_ptr<ActorsContainer> actorsContainer (new ActorsContainer);
		rootServiceContainer_.addService(actorsContainer);
		std::shared_ptr<GameTimeProvider> gameTimeProvider( new GameTimeProvider) ;
		rootServiceContainer_.addService(gameTimeProvider);

		rootServiceContainer_.addService(boxService_);
		auto rocket = std::make_shared<Actor>();
		rocket->addComponent(std::make_shared<RocketBox2dComponent>(boxService_));
		rocket->addComponent(std::make_shared<PositionComponent>());
		rocket->addComponent(std::make_shared<RocketDrawableComponent>(drawingSystem_));
		rocket->addComponent(std::make_shared<RocketMovingComponent>(keyboardManager_));

		actorsContainer->addActor(rocket);
		rootServiceContainer_.OnStart();
		outGameScreenModel_.OnStart();
	}
	OutGameScreenModel &getOutGameScreenModel(){
		return outGameScreenModel_;
	};

	std::shared_ptr<IInKeyboardStateGetter> getInKeyboardStateGetter(){
		return keyboardManager_;
	}

	void update(){
		rootServiceContainer_.OnUpdate(); // ugly but works!
		outGameScreenModel_.OnUpdate();
	};
};


#endif //PWASTEROIDS_GAME_H
