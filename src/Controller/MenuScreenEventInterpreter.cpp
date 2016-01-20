//
// Created by defacto on 2016.01.13..
//

#include "MenuScreenEventInterpreter.h"
#include "ResolutionsContainer.h"
#include <View/MenuScreen.h>
#include <View/ViewManager.h>


MenuScreenEventInterpreter::MenuScreenEventInterpreter(MenuScreen *menuScreen, ResolutionsContainer &resolutions,
                        Game &game) : resolutions_(resolutions), menuScreen_(menuScreen), game_(game) {
}

void MenuScreenEventInterpreter::keyDown(int keynum) {
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

    if( keynum == ALLEGRO_KEY_ENTER ){
        auto option = menuScreen_->getCurrentOption();
        if( currentSubmenu == SUBMENU::SUBMENU_MAIN) {
            switch(option){
                case MenuOptionTypes::StartGame:
                    menuScreen_->enterSubmenu(SUBMENU::SUBMENU_GAME);
                    //viewManager_->changeActiveScreen("GameScreen");
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
                case MenuOptionTypes::Back:
                    menuScreen_->enterSubmenu(SUBMENU::SUBMENU_MAIN );
                    break;
                case MenuOptionTypes::Apply:
                    auto resolutionButtonText = menuScreen_->getValueOfOption(MenuOptionTypes::Resolution);
                    auto res = resolutions_.getResolutionForText(resolutionButtonText);
                    viewManager_->resizeDisplay(res.first, res.second);
                    viewManager_->updateScreensAfterDisplayChanges();
                    break;
            }
        } else if ( currentSubmenu == SUBMENU_GAME ){
            switch (option){
                case MenuOptionTypes::Play:
                    if( game_.isGameFinished() ) {
                        auto gameMode = menuScreen_->getValueOfOption(MenuOptionTypes::GameMode);
                        auto dificultyLevel = menuScreen_->getValueOfOption(MenuOptionTypes::Difficulty);
                        int level =  *(dificultyLevel.rbegin()) - '0';
                        assert( level > 0);
                        assert( level < 9);
                        if (gameMode.find( "Single") != std::string::npos) {
                            game_.startSinglePlayerGame(level);
                        } else {
                            game_.startMultiplayerGame(level);
                        }
                    }
                    viewManager_->changeActiveScreen("GameScreen");
                    break;
            }
        }
    }
}

void MenuScreenEventInterpreter::timeEvent() {
    menuScreen_->updateScreen();
}

std::string MenuScreenEventInterpreter::getScreenName() {
    return "MenuScreen";
}
