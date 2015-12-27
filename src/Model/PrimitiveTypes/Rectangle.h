//
// Created by defacto on 2015.12.27..
//

#ifndef PWASTEROIDS_RECTANGLE_H
#define PWASTEROIDS_RECTANGLE_H


#include "Point.h"

class Rectangle {
    Point leftTopPoint_;
    Point dimensions_;
public:
    Rectangle( Point leftTopPoint, Point dimensions ) : leftTopPoint_(leftTopPoint), dimensions_(dimensions){
    }

    bool isPointInRectangle( Point point ){
        return (point.getX() >= leftTopPoint_.getX() ) && (point.getY() >= leftTopPoint_.getY() ) &&
                ( point.getX() <= leftTopPoint_.getX() + dimensions_.getX()) &&
                ( point.getY() <= leftTopPoint_.getY() + dimensions_.getY() );
    }
};


#endif //PWASTEROIDS_RECTANGLE_H
