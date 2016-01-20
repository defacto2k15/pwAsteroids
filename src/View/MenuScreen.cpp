#include "MenuScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"


void MenuScreen::eventAction(ALLEGRO_EVENT &ev, ViewManager *vm, Game *g)
{

}

void MenuScreen::updateScreenAfterDisplayChanges()
{
	for( auto &pair : menus_ ){
		for(auto drawableObject : pair.second.second.second){
			drawableObject->setPozX(al_get_display_width(al_get_current_display())/2 - 175);
		}
	}
	selectedButton->setPozX(al_get_display_width(al_get_current_display()) / 2 - 195);
	logo->setPozX(al_get_display_width(al_get_current_display()) / 2 - 85);
}

void MenuScreen::initializeScreenElements()
{
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
	selectedButton->setPozY(170 + currentOption*80);
	drawAllScenesOnDisplay(display_);
}

MenuScreen::MenuScreen(std::string newTitle, std::vector<MenuModel> menus, Display *display)
		: title(newTitle), display_(display) {
	background = createNewScene();
	logo = background->addDrawableObject(410, 80, NULL, "pwAsteroids (cool logo)");
	selectedButton = background->addDrawableObject(320, 10, "../res/aa.bmp", NULL, 1.570796f, 0.75f);

	for( auto &menuModel : menus){
		auto newScene = createNewScene();
		std::vector<DrawableObject *>objectsVec;
		int i = 0;
		for( auto &menuOption : menuModel.menuOptions){
			objectsVec.push_back(
					newScene->addDrawableObject(
							340, 160 + i*80, "../res/button.bmp",
							menuOption.optionTexts[menuOption.currentlySelectedText].c_str(),0.0f, 1.0f, 110, 15  ));
			i++;
		}
		newScene->changeActiveState();
		menus_[menuModel.menuType] = std::make_pair(menuModel, std::make_pair(newScene, objectsVec));
	}

	menus_[SUBMENU::SUBMENU_MAIN].second.first->changeActiveState();
	currentOption = 0;
	currentMenu = SUBMENU::SUBMENU_MAIN;
}