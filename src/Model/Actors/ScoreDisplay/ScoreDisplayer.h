//
// Created by defacto on 2015.12.31..
//

#ifndef PWASTEROIDS_SCOREDISPLAYER_H
#define PWASTEROIDS_SCOREDISPLAYER_H


#include <Model/components/Component.h>
#include <Model/ModelDrawing/IDrawingSystem.h>
#include <Model/configuration/GameConfiguration.h>
#include "ScoreCount.h"

class ScoreDisplayer : public Component {
    ScoreCount &count_;
    IDrawingSystem & drawingSystem_;
    GameConfiguration &gameConfiguration_;
    ActorId  id_;
public:

    ScoreDisplayer(ScoreCount &count_, IDrawingSystem &drawingSystem_,
                   GameConfiguration &gameConfiguration_);

    virtual void OnStart(IActor &actor);

    virtual void OnUpdate();

    virtual void OnStop();
};


#endif //PWASTEROIDS_SCOREDISPLAYER_H
