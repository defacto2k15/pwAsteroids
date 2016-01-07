//
// Created by defacto on 2016.01.06..
//

#include "MusicInstance.h"

MusicInstance::MusicInstance(MusicElements element_, float volume_) : element_(element_), volume_(volume_) {
}

MusicElements MusicInstance::getElement() const {
    return element_;
}

float MusicInstance::getVolume() const {
    return volume_;
}