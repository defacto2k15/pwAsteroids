//
// Created by defacto on 2016.01.06..
//

#ifndef PWASTEROIDS_MUSICMANAGER_H
#define PWASTEROIDS_MUSICMANAGER_H


#include <Model/Services/IService.h>
#include <Model/modelInterfaces/IOutGameMusicModel.h>
#include <map>
#include "MusicElements.h"
#include "MusicInstance.h"

class MusicManager : public IOutGameMusicModel, public IService {
    std::map<MusicElements, float> elementsWithVolume_;
public:
    void addMusicElement(MusicElements element, float volume );

    virtual std::vector<MusicInstance> getMusicInstances();

    void OnUpdate();
};


#endif //PWASTEROIDS_MUSICMANAGER_H
