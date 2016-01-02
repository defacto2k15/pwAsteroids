//
// Created by defacto on 2016.01.02..
//

#ifndef PWASTEROIDS_DRAWABLEPRIMITIVEVISITOR_H
#define PWASTEROIDS_DRAWABLEPRIMITIVEVISITOR_H

class ImagePrimitive;
class TextPrimitive;

class DrawablePrimitiveVisitor {
public:
    virtual void visit( ImagePrimitive &image)=0;
    virtual void visit( TextPrimitive &text)=0;
};
#endif //PWASTEROIDS_DRAWABLEPRIMITIVEVISITOR_H
