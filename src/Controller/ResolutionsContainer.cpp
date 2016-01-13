//
// Created by defacto on 2016.01.13..
//

#include "ResolutionsContainer.h"

ResolutionsContainer::ResolutionsContainer(std::vector< std::pair<int, int>>  resolutions )
        : resolutions_(resolutions) {
}

std::vector< std::string > ResolutionsContainer::getResoutionsAsText() {
    std::vector<std::string> outVec;
    for( auto pair : resolutions_){
        outVec.push_back( createResolutionString( pair ));
    }
    return outVec;
}

std::pair<int, int> ResolutionsContainer::getResolutionForText(std::string str) {
    auto it = std::find_if(begin(resolutions_), end(resolutions_),
                           [this, str](std::pair<int,int> pair){ return createResolutionString(pair) == str;});
    assert(it != resolutions_.end());
    return *it;
}

std::string ResolutionsContainer::createResolutionString(std::pair<int, int> pair) {
    std::stringstream ss;
    ss << pair.first << " x " << pair.second;
    return ss.str();
}