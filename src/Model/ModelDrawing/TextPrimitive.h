//
// Created by defacto on 2015.12.31..
//

#ifndef PWASTEROIDS_TEXTPRIMITIVE_H
#define PWASTEROIDS_TEXTPRIMITIVE_H
#include <string>
#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/AliasedTypes.h>
#include <iostream>
#include "BaseDrawablePrimitive.h"
#include "DrawablePrimitiveVisitor.h"

class TextPrimitive : public BaseDrawablePrimitive {
    std::string textToWrite;

public:

    TextPrimitive(const Point &position_, const Rotation &rotation_, const ScaleToScreen &scale_, const ActorId &id,
                  const std::string &textToWrite);

    std::string getTextToWrite() const;


    virtual void accept(DrawablePrimitiveVisitor &visitor) override;
};


#endif //PWASTEROIDS_TEXTPRIMITIVE_H
