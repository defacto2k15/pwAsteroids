//
// Created by defacto on 2016.01.11..
//

#include "AllegroToGameKeyMapper.h"

AllegroToGameKeyMapper::AllegroToGameKeyMapper(KeyStateFetcher &keyStateFetcher,
                                               std::map<int, Keys> keyboardToGameKeyMap,
                                               std::map<int, Keys> mouseToGameKeyMap)
        : keyStateFetcher_(keyStateFetcher), keyboardToGameKeyMap_(keyboardToGameKeyMap),
          mouseToGameKeyMap_(mouseToGameKeyMap) {
}

std::vector<Keys> AllegroToGameKeyMapper::getPressedKeys() {
    std::vector<Keys> outVec;
    for( auto &pair : keyboardToGameKeyMap_ ){
        if( keyStateFetcher_.isKeyPressed(pair.first)){
            outVec.push_back(pair.second);
        }
    }
    for( auto &pair : mouseToGameKeyMap_ ){
        if( keyStateFetcher_.isMouseKeyPressed(pair.first )){
            outVec.push_back(pair.second);
        }
    }

    return outVec;
}