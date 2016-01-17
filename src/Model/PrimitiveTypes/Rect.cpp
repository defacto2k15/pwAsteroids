//
// Created by defacto on 2015.12.27..
//

#include "Rect.h"

Rect::Rect(Point leftTopPoint, Point dimensions ) : leftTopPoint_(leftTopPoint), dimensions_(dimensions) {
}

bool Rect::isPointInRectangle(Point point ) {
    return (point.getX() >= leftTopPoint_.getX() ) && (point.getY() >= leftTopPoint_.getY() ) &&
           ( point.getX() <= leftTopPoint_.getX() + dimensions_.getX()) &&
           ( point.getY() <= leftTopPoint_.getY() + dimensions_.getY() );
}

Rect::Rect() : Rect(Point(0, 0), Point(0, 0)) {

}

double Rect::getLength() {
    return dimensions_.getX() * 2 + dimensions_.getY() * 2;
}

Point Rect::getPointByLength(double x ) {
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

Point Rect::getLeftTopPoint() const {
    return leftTopPoint_;
}

Point Rect::getDimensions() const {
    return dimensions_;
}