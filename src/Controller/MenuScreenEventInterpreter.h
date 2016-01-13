//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H
#define PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H



#include <menu/MenuOptionTypes.h>
#include "ScreenEventInterpreter.h"
#include "AbstractAllegroEventListener.h"
#include <string>

class MenuScreen;
class ViewManager;
class ResolutionsContainer;


class MenuScreenEventInterpreter : public ScreenEventInterpreter {
    MenuScreen *menuScreen_;
    ResolutionsContainer &resolutions_;
public:
    MenuScreenEventInterpreter(MenuScreen *menuScreen, ResolutionsContainer &resolutions);

    virtual void keyDown(int keynum);

    virtual void timeEvent();

    virtual std::string getScreenName();
};


#endif //PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H
