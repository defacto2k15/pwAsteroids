//
// Created by defacto on 2016.01.06..
//

#ifndef PWASTEROIDS_MUSICINSTANCE_H
#define PWASTEROIDS_MUSICINSTANCE_H
#include "MusicElements.h"

class MusicInstance {
    MusicElements element_;
    float volume_;
public:
    MusicInstance(MusicElements element_, float volume_) : element_(element_), volume_(volume_) {
    }


    MusicElements getElement() const {
        return element_;
    }

    float getVolume() const {
        return volume_;
    }
};


#endif //PWASTEROIDS_MUSICINSTANCE_H
