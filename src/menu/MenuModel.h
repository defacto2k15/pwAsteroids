//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_MENUMODEL_H
#define PWASTEROIDS_MENUMODEL_H

#include <menu/Submenu.h>
#include "MenuOption.h"

class MenuModel{
public:
    SUBMENU menuType;
    std::vector<MenuOption> menuOptions;
};


#endif //PWASTEROIDS_MENUMODEL_H
