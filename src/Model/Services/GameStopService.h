//
// Created by defacto on 2016.01.04..
//

#ifndef PWASTEROIDS_GAMESTOPSERVICE_H
#define PWASTEROIDS_GAMESTOPSERVICE_H


#include <Model/python/PythonModule.h>
#include <Model/modelInterfaces/IInputStateProvider.h>
#include <Model/modelInterfaces/InputStateManager.h>
#include <Model/box2d/Box2DService.h>
#include "GameTimeProvider.h"

class GameStopService : public IService {
    PythonModule &python_;
    std::shared_ptr<GameTimeProvider> gameTimeProvider_;
    std::shared_ptr<Box2DService> box2dService_;
    std::shared_ptr<InputStateManager> inputManager;
    bool isPaused_ = false;


public:
    GameStopService(PythonModule &python_,
                    const std::shared_ptr<GameTimeProvider> gameTimeProvider_,
                    const std::shared_ptr<Box2DService> box2dService_, std::shared_ptr<InputStateManager> inputManager);

private:
    void OnUpdate();


};


#endif //PWASTEROIDS_GAMESTOPSERVICE_H
