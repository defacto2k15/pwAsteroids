//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_GAME_H
#define PWASTEROIDS_GAME_H


#include <Model/modelInterfaces/OutGameScreenModel.h>
#include <Model/Services/RootServiceContainer.h>
#include <Model/ModelDrawing/DrawingSystem.h>
#include <Model/modelInterfaces/KeyboardStateManager.h>
#include <Model/box2d/Box2DService.h>
#include <Model/python/PythonModule.h>
#include <Model/Actors/ActorIdGenerator.h>
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/modelInterfaces/IInKeyboardStateGetter.h>
#include <Model/python/IInPythonModule.h>
#include <Model/python/IOutPythonModule.h>


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
