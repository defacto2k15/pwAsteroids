//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_ALLEGROTOGAMEKEYMAPPER_H
#define PWASTEROIDS_ALLEGROTOGAMEKEYMAPPER_H


#include <Model/modelInterfaces/Keys.h>
#include <bits/stl_bvector.h>
#include "KeyStateFetcher.h"

class AllegroToGameKeyMapper {
    KeyStateFetcher &keyStateFetcher_;
    std::map<int, Keys> keyboardToGameKeyMap_;
    std::map<int, Keys> mouseToGameKeyMap_;
public:
    AllegroToGameKeyMapper(KeyStateFetcher &keyStateFetcher,
                           std::map<int, Keys> keyboardToGameKeyMap,
                           std::map<int, Keys> mouseToGameKeyMap)
            : keyStateFetcher_(keyStateFetcher), keyboardToGameKeyMap_(keyboardToGameKeyMap),
              mouseToGameKeyMap_(mouseToGameKeyMap){
    }

    std::vector<Keys> getPressedKeys(){
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


};


#endif //PWASTEROIDS_ALLEGROTOGAMEKEYMAPPER_H
