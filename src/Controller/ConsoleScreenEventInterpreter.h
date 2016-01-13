//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_CONSOLESCREENEVENTLISTENER_H
#define PWASTEROIDS_CONSOLESCREENEVENTLISTENER_H


#include <View/ConsoleScreen.h>
#include "AbstractAllegroEventListener.h"
#include "KeyStateFetcher.h"
#include "ScreenEventInterpreter.h"

class ConsoleScreenEventInterpreter : public ScreenEventInterpreter {
    ConsoleScreen *consoleScreen_;
    Game &game_;
public:

    ConsoleScreenEventInterpreter(ConsoleScreen *consoleScreen, Game &game) : consoleScreen_(consoleScreen),
                                                                                game_(game) {
    }

    virtual void keyDown(int keynum);

    virtual void charKeyDown(int unicode);

    virtual void timeEvent();

    virtual std::string getScreenName();
};


#endif //PWASTEROIDS_CONSOLESCREENEVENTLISTENER_H
