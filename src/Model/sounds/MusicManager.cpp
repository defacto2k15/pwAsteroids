//
// Created by defacto on 2016.01.06..
//

#include "MusicManager.h"

void MusicManager::addMusicElement(MusicElements element, float volume ) {
    if( elementsWithVolume_.count(element) == 0){
        elementsWithVolume_[element] = volume;
    } else {
        if( elementsWithVolume_[element] < volume ){
            elementsWithVolume_[element] = volume;
        }
    }
}

std::vector<MusicInstance> MusicManager::getMusicInstances() {
    std::vector<MusicInstance> output;
    for( auto pair : elementsWithVolume_){
        output.push_back( MusicInstance(pair.first, pair.second));
    }
    return output;
}

void MusicManager::OnUpdate() {
    elementsWithVolume_.clear();
}