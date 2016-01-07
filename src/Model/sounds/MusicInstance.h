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
    MusicInstance(MusicElements element_, float volume_);


    MusicElements getElement() const;

    float getVolume() const;
};


#endif //PWASTEROIDS_MUSICINSTANCE_H
