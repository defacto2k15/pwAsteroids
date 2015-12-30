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
#include <Model/ModelDrawing/BoundariesDuplicationsDrawingSystem.h>
#include <Model/Actors/Asteroid/AsteroidsGenerator.h>
#include <Model/help/RandomNumbersProvider.h>
#include <Model/ModelDrawing/ImageScalesContainer.h>
#include <Model/Actors/Projectile/ProjectilesGenerator.h>
#include <Model/collisions/ContactComponentsContainer.h>
#include <Model/Actors/Rocket/RocketLife.h>
#include <Model/Actors/lifeIndicator/LifeIndicatorService.h>


class Game {
private:
	std::shared_ptr<IOutGameScreenModel> outGameScreenModel_;
	RootServiceContainer rootServiceContainer_;
	std::shared_ptr<DrawingSystem> drawingSystem_;
	std::shared_ptr<BoundariesDuplicationsDrawingSystem> boundariesDuplicationsDrawingSystem_;
	std::shared_ptr<KeyboardStateManager> keyboardManager_ = std::make_shared<KeyboardStateManager>();

	ContactComponentsContainer contactComponentsContainer_;
	MyContactListener contactListener_;
	std::shared_ptr<Box2DService> boxService_ = std::make_shared<Box2DService>( &contactListener_);
	std::shared_ptr<PythonModule> pythonModule_ = std::make_shared<PythonModule>();
	ActorIdGenerator idGenerator;
	std::shared_ptr<AsteroidsGenerator> asteroidGenerator_;
	std::shared_ptr<ProjectilesGenerator> projectilesGenerator_;
	std::shared_ptr<AsteroidsCounter> asteroidsCounter_ = std::make_shared<AsteroidsCounter>();
	RandomNumbersProvider randomNumbersProvider_;
	ImageScalesContainer imageScalesContainer_;

	Box2dObjectsContainer box2dObjectsContainer_;
	ActorsConfiguration actorsConfiguration_;

	RocketLife rocketLife_;
	std::shared_ptr<LifeIndicatorService> lifeIndicatorService_;
public:
	Game();

	std::shared_ptr<IOutGameScreenModel> getOutGameScreenModel();;

	std::shared_ptr<IInKeyboardStateGetter> getInKeyboardStateGetter();

	std::shared_ptr<IInPythonModule> getInPythonModule();

	std::shared_ptr<IOutPythonModule> getOutPythonModule();

	void update();;
};


#endif //PWASTEROIDS_GAME_H
