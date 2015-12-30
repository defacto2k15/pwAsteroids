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

    double getLength(){
        return dimensions_.getX() * 2 + dimensions_.getY() * 2;
    }

    Point getPointByLength( double x ){
        if( x < dimensions_.getX( )){
            return Point(x, 0) + leftTopPoint_;
        }
        x -= dimensions_.getX();
        if( x < dimensions_.getY( )){
            return Point( dimensions_.getX(), x) + leftTopPoint_;
        }
        x -= dimensions_.getY();
        if( x < dimensions_.getX()){
            return Point( dimensions_.getX() - x, dimensions_.getY()) + leftTopPoint_;
        } else {
            return Point(0, dimensions_.getY() - (x - dimensions_.getX())) + leftTopPoint_;
        }
    }
};


#endif //PWASTEROIDS_RECTANGLE_H
