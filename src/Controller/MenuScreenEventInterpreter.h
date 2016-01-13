//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H
#define PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H


#include <View/MenuScreen.h>
#include <View/ViewManager.h>
#include <menu/MenuOptionTypes.h>
#include "AbstractAllegroEventListener.h"
#include "IScreenEventInterpreter.h"
#include "ResolutionsContainer.h"


class MenuScreenEventInterpreter : public AbstractAllegroEventListener {
    MenuScreen *menuScreen_;
    ViewManager *viewManager_;
    ResolutionsContainer &resolutions_;
public:
    MenuScreenEventInterpreter(MenuScreen *menuScreen, ResolutionsContainer &resolutions)
            : resolutions_(resolutions), menuScreen_(menuScreen){
    }

    void setViewManager( ViewManager *manager ) override{
        viewManager_ = manager;
    }

    virtual void keyDown(int keynum) override{
        if( keynum == ALLEGRO_KEY_DOWN){
            menuScreen_->goDown();
        } else if( keynum == ALLEGRO_KEY_UP ){
            menuScreen_->goUp();
        } else if ( keynum == ALLEGRO_KEY_LEFT){
            menuScreen_->goLeft();
        } else if ( keynum == ALLEGRO_KEY_RIGHT ){
            menuScreen_->goRight();
        }

        SUBMENU currentSubmenu = menuScreen_->getCurrentSubmenu();
        int index = menuScreen_->getCurrentOption();

        if( keynum == ALLEGRO_KEY_ENTER ){
            auto option = menuScreen_->getCurrentOption();
            if( currentSubmenu == SUBMENU::SUBMENU_MAIN) {
                switch(option){
                    case MenuOptionTypes::StartGame:
                        viewManager_->changeActiveScreen("GameScreen");
                        break;
                    case MenuOptionTypes::Options:
                        menuScreen_->enterSubmenu( SUBMENU::SUBMENU_OPTIONS);
                        break;
                    case MenuOptionTypes::About:
                        break;
                    case MenuOptionTypes::Exit:
                        viewManager_->exit();
                        break;
                    default:
                    std::cout << " not expected option " << std::endl;
                }
            } else if (currentSubmenu == SUBMENU_OPTIONS ){
                switch(option){
                    case MenuOptionTypes::Apply:
                        auto resolutionButtonText = menuScreen_->getValueOfOption(MenuOptionTypes::Resolution);
                        auto res = resolutions_.getResolutionForText(resolutionButtonText);
                        viewManager_->resizeDisplay(res.first, res.second);
                        viewManager_->updateScreensAfterDisplayChanges();
                        break;
                    case MenuOptionTypes::Back:
                        menuScreen_->enterSubmenu(SUBMENU::SUBMENU_MAIN );
                        break;
                    default:
                        break;
                }
            }
        }
    }

    virtual void timeEvent() override{
        menuScreen_->updateScreen();
    }
};


#endif //PWASTEROIDS_MENUSCREENEVENTINTERPRETER_H
