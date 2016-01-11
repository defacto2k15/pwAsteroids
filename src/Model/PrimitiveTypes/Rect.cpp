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