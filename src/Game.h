//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_GAME_H
#define PWASTEROIDS_GAME_H


#include <Model/modelInterfaces/OutGameScreenModel.h>
#include <Model/Services/RootServiceContainer.h>
#include <Model/ModelDrawing/DrawingSystem.h>
#include <Model/box2d/Box2DService.h>
#include <Model/python/PythonModule.h>
#include <Model/Actors/ActorIdGenerator.h>
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
#include <Model/Actors/ScoreDisplay/ScoreCount.h>
#include <Model/modelInterfaces/InputStateManager.h>
#include <Model/modelInterfaces/ScallingMousePositionGetter.h>
#include <Model/configuration/GameConfiguration.h>
#include <Model/Services/GameStopService.h>
#include <Model/sounds/MusicManager.h>
#include <Model/Actors/powerup/PowerupCounter.h>
#include <Model/Actors/powerup/PowerupGenerator.h>
#include <Model/Actors/powerup/RandomPowerupGenerator.h>
#include <Model/python/CommonTypesVisualizer.h>
#include <Model/python/PythonScriptsExecutingSerivce.h>
#include <Model/Actors/Asteroid/RandomAsteroidsGenerator.h>
#include <Model/Services/GameEndingIndicatingService.h>
#include <Model/Actors/explosionCloud/ExplosionCloudGenerator.h>
#include <Model/Actors/Rocket/RocketActorProxy.h>


/**
 * @brief Main class of model, encapsulates logic of game in separation of graphics liblaries. All servicies used in game are placed as fields.
 */
class Game {
private:
    PythonModule pythonModule_;
    GameConfiguration gameConfiguration_;
    ActorIdGenerator idGenerator;
    std::shared_ptr<RocketActorProxy> rocketProxy_;
	RootServiceContainer rootServiceContainer_;
	std::shared_ptr<ActorsContainer> actorsContainer_;
	std::shared_ptr<IOutGameScreenModel> outGameScreenModel_;
	std::shared_ptr<MusicManager> musicManager_;
	std::shared_ptr<InputStateManager> inputManager_ = std::make_shared<InputStateManager>();
	std::shared_ptr<IInputStateGetter> inputStateGetter_ = std::make_shared<ScallingMousePositionGetter>( inputManager_, gameConfiguration_);
	std::shared_ptr<Box2DService> boxService_ = std::make_shared<Box2DService>( &contactListener_);
	std::shared_ptr<GameTimeProvider> gameTimeProvider_;
	std::shared_ptr<RandomAsteroidsGenerator> randomAsteroidsGenerator_;
	std::shared_ptr<LifeIndicatorService> lifeIndicatorService_;
	std::shared_ptr<GameStopService> gameStopService_;
    std::shared_ptr<RandomPowerupGenerator> randomPowerupsGenerator_;
    std::shared_ptr<GameEndingIndicatingService> gameEndingIndicatingService_;

	std::shared_ptr<CommonTypesVisualizer> commonTypesVisualizer_;

	std::shared_ptr<PythonScriptsExecutingSerrive> pythonScriptsExecutor_;
    DrawingSystem drawingSystem_;
    ExplosionCloudGenerator explosionCloudGenerator_;
    BoundariesDuplicationsDrawingSystem boundariesDuplicationsDrawingSystem_;
    ContactComponentsContainer contactComponentsContainer_;
    MyContactListener contactListener_;
    ImageScalesContainer imageScalesContainer_;
    Box2dObjectsContainer box2dObjectsContainer_;
    AsteroidsGenerator asteroidGenerator_;
    ProjectilesGenerator projectilesGenerator_;
    AsteroidsCounter asteroidsCounter_;
    RandomNumbersProvider randomNumbersProvider_;

    PowerupGenerator powerupGenerator_;


	RocketLife rocketLife_;
	ScoreCount scoreCount_;
	PowerupCounter powerupCounter_;

	bool isGameFinished_ = true;

	int result_ = 0;
public:
    /**
     * @brief Only constructor of Game class
     *
     * @param screenResolution The resolution which game will start with, this can be changed later.
     * @param imagesSizesMap Sizes of objects simulated in Box2d are taken from this paramerer/
     */
	Game( Point screenResolution, std::map<ImagePrimitiveType, Point> imagesSizesMap );

    /**
     * @param difficulty Some settings in GameConfiguraion are calculated using difficulty setting passed as argument here.
     */
    void startSinglePlayerGame( int difficulty );

    /**
     * @param difficulty Some settings in GameConfiguraion are calculated using difficulty setting passed as argument here.
     */
    void startMultiplayerGame( int difficulty);

    /**
     * @brief Part of Controller - Model interface
     *
     * @return Shared pointer to field of Game, which contains data about images and text to be displayed;
     */
	std::shared_ptr<IOutGameScreenModel> getOutGameScreenModel();;

    /**
     * @brief Part of Controller - Model interface
     *
     * @return object to which input of user is passed to
     */
	std::shared_ptr<IInputStateGetter> getInputStateGetter();

    /**
     * @brief Part of Controller - Model interface"
     *
     * @return object to which python commands are passed
     */
	IInPythonModule &getInPythonModule();

    /**
     * @brief Part of Controller - Model interface"
     *
     * @return  objects that contains output of python generated in one loop.
     */
	IOutPythonModule &getOutPythonModule();

	std::shared_ptr<IOutGameMusicModel> getOutGameMusicModel(){
		return musicManager_;
	}

	void update();;

	void setGameFinished( int newResult){
		isGameFinished_ = true;
	}

	void setResolution(Point newResolution );

	bool isGameFinished(){
		return isGameFinished_;
	}

    void createBothModesActors();

    void createMultiplayerActors();
 };


#endif //PWASTEROIDS_GAME_H
