//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_GAMESCREENEVENTINTERPRETER_H
#define PWASTEROIDS_GAMESCREENEVENTINTERPRETER_H


#include <View/GameScreen.h>
#include <Sound/SoundModule.h>
#include "AbstractAllegroEventListener.h"
#include "KeyStateFetcher.h"
#include "MousePositionFetcher.h"
#include "AllegroToGameKeyMapper.h"
#include "ImageDataContainer.h"
#include "ScreenSize.h"
#include "ScreenEventInterpreter.h"

class GameScreenEventInterpreter : public ScreenEventInterpreter {
    AllegroToGameKeyMapper &keyMapper_;
    MousePositionFetcher &mousePositionFetcher_;
    ImageDataContainer &imageDataContainer_;
    ScreenSize &screenSize_;
    GameScreen *gameScreen_;
    Game &game_;
    SoundModule &soundModule_;
    std::vector<ActorId> createdObjectsIds_;
public:
    GameScreenEventInterpreter(AllegroToGameKeyMapper &keyMapper, MousePositionFetcher &mousePositionFetcher,
                               GameScreen *gameScreen, ImageDataContainer &imageDataContainer,
                               Game &game, ScreenSize &screenSize, SoundModule &soundModule);


    virtual void keyDown(int keynum);

    virtual void timeEvent();

    virtual std::string getScreenName();

private:
    void updateDrawableObject(BaseDrawablePrimitive &primitive, double zoom);
};


#endif //PWASTEROIDS_GAMESCREENEVENTINTERPRETER_H
