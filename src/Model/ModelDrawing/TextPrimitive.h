//
// Created by defacto on 2015.12.31..
//

#ifndef PWASTEROIDS_TEXTPRIMITIVE_H
#define PWASTEROIDS_TEXTPRIMITIVE_H
#include <string>
#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include <iostream>

class TextPrimitive {
    std::string textToWrite;
    Point position;
    ActorId actorId;

public:
    TextPrimitive(const std::string &textToWrite, const Point &position, ActorId actorId) : textToWrite(textToWrite),
                                                                                            position(position){
    }

    std::string getTextToWrite() const {
        return textToWrite;
    }

    Point getPosition() const {
        return position;
    }

    ActorId getActorId() const {
        return actorId;
    }
};


#endif //PWASTEROIDS_TEXTPRIMITIVE_H
