//
// Created by root on 2016.01.19..
//

#ifndef PWASTEROIDS_GAMEENDINGINDICATINGSERVICE_H
#define PWASTEROIDS_GAMEENDINGINDICATINGSERVICE_H




class RocketLife;
class ScoreCount;
class GameStopService;
class Game;

class GameEndingIndicatingService : public IService {
    RocketLife &rocketLife_;
    ScoreCount &scoreCount_;
    std::shared_ptr<GameStopService> gameStopService_;
    Game &game_;
    ActorId scoreId_;
    GameConfiguration &configuration_;
    std::shared_ptr<IInputStateProvider> inputStateProvider_;
    IDrawingSystem &drawingSystem_;

    bool isEndScoreDisplayed_ = false;
public:
    GameEndingIndicatingService(RocketLife &rocketLife_, ScoreCount &scoreCount_,
                                    std::shared_ptr<GameStopService> gameStopService_, Game &game_, ActorId scoreId,
                                    GameConfiguration &configuration, IDrawingSystem &drawingSystem,
                                    std::shared_ptr<IInputStateProvider> inputStateProvider);

    void OnUpdate();

    void reset();
};


#endif //PWASTEROIDS_GAMEENDINGINDICATINGSERVICE_H
