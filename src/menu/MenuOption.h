//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_MENUOPTION_H
#define PWASTEROIDS_MENUOPTION_H
#include <string>
#include <vector>
#include "MenuOptionTypes.h"

class MenuOption{
public:
    MenuOptionTypes type;
    std::vector<std::string> optionTexts;
    int currentlySelectedText;
};

#endif //PWASTEROIDS_MENUOPTION_H
