//
// Created by defacto on 2015.12.31..
//

#include "TextPrimitive.h"
#include "DrawablePrimitiveVisitor.h"

TextPrimitive::TextPrimitive(const Point &position_, const Rotation &rotation_, const ScaleToScreen &scale_, const ActorId &id,
                             const std::string &textToWrite) : BaseDrawablePrimitive(position_, rotation_, scale_, id), textToWrite(textToWrite) { }

std::string TextPrimitive::getTextToWrite() const {
    return textToWrite;
}

void TextPrimitive::accept(DrawablePrimitiveVisitor &visitor) {
    visitor.visit(*this);
}
