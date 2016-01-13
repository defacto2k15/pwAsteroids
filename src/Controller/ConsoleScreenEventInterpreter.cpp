//
// Created by defacto on 2016.01.13..
//

#include "ConsoleScreenEventInterpreter.h"
#include "View/ViewManager.h"

void ConsoleScreenEventInterpreter::keyDown(int keynum) {
    if( keynum == ALLEGRO_KEY_TILDE ){
        consoleScreen_->removeScreenshot();
        viewManager_->changeActiveScreen("GameScreen");
    } else if( keynum == ALLEGRO_KEY_BACKSPACE){
        consoleScreen_->removeCharacter();
    } else if( keynum == ALLEGRO_KEY_ENTER ){
        std::string line = consoleScreen_->getLastLine();
        game_.getInPythonModule().addCommand(line);
        consoleScreen_->addNewLine();
    }

}

void ConsoleScreenEventInterpreter::timeEvent() {
    if(consoleScreen_->isScreenshotTaken() == false){
        consoleScreen_->takeScreenshot();
    }
    auto pythonOutput = game_.getOutPythonModule().getOutput();
    if( pythonOutput.size() != 0 ){
        consoleScreen_->writeText(pythonOutput);
    }

    consoleScreen_->updateScreen();
}

std::string ConsoleScreenEventInterpreter::getScreenName() {
    return "ConsoleScreen";
}

void ConsoleScreenEventInterpreter::charKeyDown(int unicode) {
    if( unicode  >= 32 && unicode != 96){
        consoleScreen_->addCharacter(unicode);
    }
}

ConsoleScreenEventInterpreter::ConsoleScreenEventInterpreter(ConsoleScreen *consoleScreen, Game &game)
        : consoleScreen_(consoleScreen),
          game_(game) {
}