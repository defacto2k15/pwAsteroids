//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_ALLEGROTOGAMEKEYMAPPER_H
#define PWASTEROIDS_ALLEGROTOGAMEKEYMAPPER_H


#include <Model/modelInterfaces/Keys.h>
#include <vector>
#include "KeyStateFetcher.h"

class AllegroToGameKeyMapper {
    KeyStateFetcher &keyStateFetcher_;
    std::map<int, Keys> keyboardToGameKeyMap_;
    std::map<int, Keys> mouseToGameKeyMap_;
public:
    AllegroToGameKeyMapper(KeyStateFetcher &keyStateFetcher,
                           std::map<int, Keys> keyboardToGameKeyMap,
                           std::map<int, Keys> mouseToGameKeyMap);

    std::vector<Keys> getPressedKeys();


};


#endif //PWASTEROIDS_ALLEGROTOGAMEKEYMAPPER_H
