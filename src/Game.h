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
#include <Model/python/PythonModule.h>

class Game {
private:
	std::shared_ptr<IOutGameScreenModel> outGameScreenModel_;
	RootServiceContainer rootServiceContainer_;
	std::shared_ptr<DrawingSystem> drawingSystem_;
	std::shared_ptr<KeyboardStateManager> keyboardManager_ = std::make_shared<KeyboardStateManager>();
	std::shared_ptr<Box2DService> boxService_ = std::make_shared<Box2DService>();
	std::shared_ptr<PythonModule> pythonModule_ = std::make_shared<PythonModule>();
	ActorIdGenerator idGenerator;

	std::shared_ptr<ActorsConfiguration> actorsConfiguration_ = std::make_shared<ActorsConfiguration>();
public:
	Game();

	std::shared_ptr<IOutGameScreenModel> getOutGameScreenModel();;

	std::shared_ptr<IInKeyboardStateGetter> getInKeyboardStateGetter();

	std::shared_ptr<IInPythonModule> getInPythonModule();

	std::shared_ptr<IOutPythonModule> getOutPythonModule();

	void update();;
};


#endif //PWASTEROIDS_GAME_H
