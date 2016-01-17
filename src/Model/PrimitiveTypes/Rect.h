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

    Rect();

    bool isPointInRectangle(Point point );

    double getLength();

    Point getPointByLength(double x );


    Point getLeftTopPoint() const;

    Point getDimensions() const;
};


#endif //PWASTEROIDS_RECTANGLE_H
