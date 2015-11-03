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

class Game {
private:
	OutGameScreenModel outGameScreenModel_;
	RootServiceContainer rootServiceContainer_;
	DrawingSystem drawingSystem_;
public:
	Game() : drawingSystem_(outGameScreenModel_)
	{
		std::shared_ptr<ActorsContainer> actorsContainer (new ActorsContainer);
		rootServiceContainer_.addService(actorsContainer);
		std::shared_ptr<GameTimeProvider> gameTimeProvider( new GameTimeProvider) ;
		rootServiceContainer_.addService(gameTimeProvider);
		auto rocket = std::make_shared<Actor>();
		rocket->addComponent(std::make_shared<PositionComponent>());
		rocket->addComponent(std::make_shared<RocketDrawableComponent>(drawingSystem_));
		//rocket->addComponent(std::make_shared<RocketMovingComponent>());
		actorsContainer->addActor(rocket);
		rootServiceContainer_.OnStart();
		outGameScreenModel_.OnStart();
	}
	OutGameScreenModel &getOutGameScreenModel(){
		return outGameScreenModel_;
	};
	void update(){
		rootServiceContainer_.OnUpdate(); // ugly but works!
		outGameScreenModel_.OnUpdate();
	};
};


#endif //PWASTEROIDS_GAME_H
