//
// Created by defacto on 2015.12.27..
//

#ifndef PWASTEROIDS_RECTANGLE_H
#define PWASTEROIDS_RECTANGLE_H


#include "Point.h"

class Rect {
    Point leftTopPoint_;
    Point dimensions_;
public:
    Rect(Point leftTopPoint, Point dimensions );

    bool isPointInRectangle(Point point );
};


#endif //PWASTEROIDS_RECTANGLE_H
