//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H
#define PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H



#include <menu/MenuOptionTypes.h>
#include "AbstractAllegroEventListener.h"
#include "IScreenEventInterpreter.h"


class MenuScreen;
class ViewManager;
class ResolutionsContainer;


class MenuScreenEventInterpreter : public AbstractAllegroEventListener {
    MenuScreen *menuScreen_;
    ViewManager *viewManager_;
    ResolutionsContainer &resolutions_;
public:
    MenuScreenEventInterpreter(MenuScreen *menuScreen, ResolutionsContainer &resolutions);

    void setViewManager(ViewManager *manager );

    virtual void keyDown(int keynum);

    virtual void timeEvent();
};


#endif //PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H
