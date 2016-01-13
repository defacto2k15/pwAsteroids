#include "MenuScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"

//enum OPTION { FIRST, SECOND, THIRD, FOURTH };
//
//int option = FIRST;
//
//std::pair<int, int> resolutions[6];
//int selectedResolution = 0;

void MenuScreen::eventAction(ALLEGRO_EVENT &ev, ViewManager *vm, Game *g)
{
//	if (ev.type == ALLEGRO_EVENT_TIMER) {
//		drawAllScenesOnDisplay(vm->getDisplay()); // remember to refresh the screen in a proper place
//	}
//	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//		vm->exit();		// remember to include exit signal!
//	}
//	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
//		switch (ev.keyboard.keycode) {
//		case ALLEGRO_KEY_UP:
//			if (option > 0) {
//				--option;
//				selectedButton->setPozY(selectedButton->getPozY() - 80);
//			}
//			break;
//
//		case ALLEGRO_KEY_DOWN:
//			if (option < 3) {
//				++option;
//				selectedButton->setPozY(selectedButton->getPozY() + 80);
//			}
//			break;
//
//		case ALLEGRO_KEY_LEFT:
//			if (menus[SUBMENU_OPTIONS]->isActive()) {
//				if (option == FIRST && selectedResolution > 0) {
//					--selectedResolution;
//					std::string str = "Resolution: " + boost::lexical_cast<std::string>(resolutions[selectedResolution].first);
//					str+= " x " + boost::lexical_cast<std::string>(resolutions[selectedResolution].second);
//					resolutionButton->setText(str);
//				}
//			}
//			break;
//
//		case ALLEGRO_KEY_RIGHT:
//			if (menus[SUBMENU_OPTIONS]->isActive()) {
//				if (option == FIRST && selectedResolution < 5) {
//					++selectedResolution;
//					std::string str = "Resolution: " + boost::lexical_cast<std::string>(resolutions[selectedResolution].first);
//					str += " x " + boost::lexical_cast<std::string>(resolutions[selectedResolution].second);
//					resolutionButton->setText(str);
//				}
//			}
//			break;
//		case ALLEGRO_KEY_SPACE:
//			if (menus[SUBMENU_MAIN]->isActive()) {
//				if (option == FIRST) {
//					std::string str = "GameScreen";
//					vm->changeActiveScreen(str);
//				}
//				else if (option == SECOND) {
//					menus[SUBMENU_MAIN]->changeActiveState();
//					menus[SUBMENU_OPTIONS]->changeActiveState();
//					option = FIRST;
//					selectedButton->setPozY(170);
//				}
//				else if (option == FOURTH) {
//					vm->exit();
//				}
//			}
//			else if (menus[SUBMENU_OPTIONS]->isActive()) {
//				if (option == FOURTH) {
//					menus[SUBMENU_OPTIONS]->changeActiveState();
//					menus[SUBMENU_MAIN]->changeActiveState();
//					option = FIRST;
//					selectedButton->setPozY(170);
//				}
//				else if (option == THIRD) {
//					vm->resizeDisplay(resolutions[selectedResolution].first, resolutions[selectedResolution].second);
//					vm->updateScreensAfterDisplayChanges();
//				}
//			}
//			break;
//		}
//	}
}

void MenuScreen::updateScreenAfterDisplayChanges()
{
	for( auto &pair : menus_ ){
		for(auto drawableObject : pair.second.second.second){
			drawableObject->setPozX(al_get_display_width(al_get_current_display())/2 - 175);
		}
	}
	resolutionButton->setPozX(al_get_display_width(al_get_current_display()) / 2 - 175);
	selectedButton->setPozX(al_get_display_width(al_get_current_display()) / 2 - 195);
	logo->setPozX(al_get_display_width(al_get_current_display()) / 2 - 85);
}

void MenuScreen::initializeScreenElements()
{
//	// scenes
//	background = createNewScene();
//	for (int i = 0; i < NUMBER_OF_MENUS; ++i) {
//		menus[i] = createNewScene();
//		menus[i]->changeActiveState();
//	}
//	// resolutions
//	resolutions[0] = { 800, 600 };
//	resolutions[1] = { 1024, 600 };
//	resolutions[2] = { 1280, 720 };
//	resolutions[3] = { 1368, 768 };
//	resolutions[4] = { 1600, 900 };
//	resolutions[5] = { 1920, 1080 };
//	selectedResolution = 0;
//	// drawable objects
//	logo = background->addDrawableObject(410, 80, NULL, "pwAsteroids (cool logo)");
//	selectedButton = background->addDrawableObject(320, 170, "../res/aa.bmp", NULL, 1.570796f, 0.75f);
//
//	obj[0] = menus[SUBMENU_MAIN]->addDrawableObject(340, 160, "../res/button.bmp", "Start the game", 0.0f, 1.0f, 110, 15);
//	obj[1] = menus[SUBMENU_MAIN]->addDrawableObject(340, 240, "../res/button.bmp", "Options", 0.0f, 1.0f, 140, 15);
//	obj[2] = menus[SUBMENU_MAIN]->addDrawableObject(340, 320, "../res/button.bmp", "About", 0.0f, 1.0f, 150, 15);
//	obj[3] = menus[SUBMENU_MAIN]->addDrawableObject(340, 400, "../res/button.bmp", "Exit", 0.0f, 1.0f, 155, 15);
//	menus[SUBMENU_MAIN]->changeActiveState();
//
//	std::string str = "Resolution: " + boost::lexical_cast<std::string>(resolutions[0].first) + " x " + boost::lexical_cast<std::string>(resolutions[0].second);
//	resolutionButton = menus[SUBMENU_OPTIONS]->addDrawableObject(340, 160, "../res/button.bmp", str.c_str(), 0.0f, 1.0f, 40, 15);
//	obj[4] = menus[SUBMENU_OPTIONS]->addDrawableObject(340, 320, "../res/button.bmp", "Apply", 0.0f, 1.0f, 150, 15);
//	obj[5] = menus[SUBMENU_OPTIONS]->addDrawableObject(340, 400, "../res/button.bmp", "Back", 0.0f, 1.0f, 155, 15);
//
//	std::cout << title << " initialized\n";
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::goUp() {
	currentOption = ((currentOption - 1 ) + (menus_[currentMenu].first.menuOptions.size()) )
					%  (menus_[currentMenu].first.menuOptions.size() );
}

void MenuScreen::goDown() {
	currentOption = (currentOption + 1 )  % (menus_[currentMenu].first.menuOptions.size() );
}

void MenuScreen::goLeft() {
	int selectedTextIndex = menus_[currentMenu].first.menuOptions[currentOption].currentlySelectedText;
	int size = menus_[currentMenu].first.menuOptions[currentOption].optionTexts.size() ;
	if( size == 0 ){
		selectedTextIndex = 0;
	}else {
		selectedTextIndex = ((selectedTextIndex - 1)
							+ (size))
							  % size;
	}

	menus_[currentMenu].first.menuOptions[currentOption].currentlySelectedText = selectedTextIndex;
	menus_[currentMenu].second.second[currentOption]->setText( menus_[currentMenu].first.menuOptions[currentOption].optionTexts[selectedTextIndex] );
}

void MenuScreen::goRight() {
	int selectedTextIndex = menus_[currentMenu].first.menuOptions[currentOption].currentlySelectedText;
	int size = menus_[currentMenu].first.menuOptions[currentOption].optionTexts.size()
	;
	if( size == 0 ){
		selectedTextIndex = 0;
	}else {
		selectedTextIndex = ((selectedTextIndex + 1)
							+ (size))
							  % size;
	}

	menus_[currentMenu].first.menuOptions[currentOption].currentlySelectedText = selectedTextIndex;
	menus_[currentMenu].second.second[currentOption]->setText( menus_[currentMenu].first.menuOptions[currentOption].optionTexts[selectedTextIndex] );
}

SUBMENU MenuScreen::getCurrentSubmenu() {
	return currentMenu;
}

MenuOptionTypes MenuScreen::getCurrentOption() {
	return menus_[currentMenu].first.menuOptions[currentOption].type;
}

void MenuScreen::enterSubmenu(SUBMENU submenu) {
	currentOption = 0;
	menus_[currentMenu].second.first->changeActiveState();
	menus_[submenu].second.first->changeActiveState();
	currentMenu = submenu;
}

std::string MenuScreen::getValueOfOption(MenuOptionTypes typeToFind) {
	auto allOptions = menus_[currentMenu].first.menuOptions;
	for( auto &option : allOptions){
		if(option.type == typeToFind ){
			return option.optionTexts[option.currentlySelectedText];
		}
	}
	assert(false);
}

void MenuScreen::updateScreen() {
	selectedButton->setPozY(160 + currentOption*80);
	drawAllScenesOnDisplay(display_);
}
