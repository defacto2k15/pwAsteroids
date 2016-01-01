//
// Created by defacto on 2015.12.31..
//

#ifndef PWASTEROIDS_SCOREDISPLAYER_H
#define PWASTEROIDS_SCOREDISPLAYER_H


#include <Model/components/Component.h>
#include <Model/ModelDrawing/IDrawingSystem.h>
#include <Model/configuration/ActorsConfiguration.h>
#include "ScoreCount.h"

class ScoreDisplayer : public Component {
    ScoreCount &count_;
    IDrawingSystem & drawingSystem_;
    ActorsConfiguration &actorsConfiguration_;
    ActorId  id_;
public:

    ScoreDisplayer(ScoreCount &count_, IDrawingSystem &drawingSystem_,
                   ActorsConfiguration &actorsConfiguration_);

    virtual void OnStart(IActor &actor);

    virtual void OnUpdate();
};


#endif //PWASTEROIDS_SCOREDISPLAYER_H
