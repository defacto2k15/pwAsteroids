//
// Created by defacto on 2016.01.06..
//

#ifndef PWASTEROIDS_IOUTGAMEMUSICMODEL_H
#define PWASTEROIDS_IOUTGAMEMUSICMODEL_H

#include <vector>
#include <Model/sounds/MusicInstance.h>

class IOutGameMusicModel{
public:
    virtual std::vector<MusicInstance> getMusicInstances()=0;
};
#endif //PWASTEROIDS_IOUTGAMEMUSICMODEL_H
