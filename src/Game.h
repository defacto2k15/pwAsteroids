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
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/components/DrawingComponent.h>
#include <Model/Actors/RocketTail/RocketTailPositionComponent.h>
#include <Model/modelInterfaces/OutGameScreenModelScaler.h>
#include <Model/modelInterfaces/OutGameScreenModelImageCentering.h>
#include <Model/Actors/ActorIdGenerator.h>

class Game {
private:
	std::shared_ptr<IOutGameScreenModel> outGameScreenModel_;
	RootServiceContainer rootServiceContainer_;
	std::shared_ptr<DrawingSystem> drawingSystem_;
	std::shared_ptr<KeyboardStateManager> keyboardManager_ = std::make_shared<KeyboardStateManager>();
	std::shared_ptr<Box2DService> boxService_ = std::make_shared<Box2DService>();
	ActorIdGenerator idGenerator;

	std::shared_ptr<ActorsConfiguration> actorsConfiguration_ = std::make_shared<ActorsConfiguration>();
public:
	Game()
	{
		outGameScreenModel_= std::make_shared<OutGameScreenModelScaler>( std::make_shared<OutGameScreenModelImageCentering>(std::make_shared<OutGameScreenModel>(), actorsConfiguration_), actorsConfiguration_);
		drawingSystem_ = std::make_shared<DrawingSystem>(outGameScreenModel_);

		std::shared_ptr<ActorsContainer> actorsContainer (new ActorsContainer);
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
	}
	std::shared_ptr<IOutGameScreenModel> getOutGameScreenModel(){
		return outGameScreenModel_;
	};

	std::shared_ptr<IInKeyboardStateGetter> getInKeyboardStateGetter(){
		return keyboardManager_;
	}

	void update(){
		outGameScreenModel_->OnUpdate();
		rootServiceContainer_.OnUpdate(); // ugly but works!

	};
};


#endif //PWASTEROIDS_GAME_H
