//
// Created by defacto on 2016.01.02..
//

#include "BaseDrawablePrimitive.h"

BaseDrawablePrimitive::BaseDrawablePrimitive(const Point &position_, const Rotation &rotation_, const ScaleToScreen &scale_, const ActorId &id)
        : position_(position_), rotation_(rotation_), scale_(scale_), id_(id) {
}

Point BaseDrawablePrimitive::getPosition() const {
    return position_;
}

void BaseDrawablePrimitive::setPosition(Point newPosition) {
    position_ = newPosition;
}

Rotation BaseDrawablePrimitive::getRotation() const {
    return rotation_;
}

void BaseDrawablePrimitive::setRotation(Rotation rotation) {
    rotation_ = rotation;
}

ScaleToScreen BaseDrawablePrimitive::getScale() const {
    return scale_;
}

ActorId BaseDrawablePrimitive::getActorId() const {
    return id_;
}