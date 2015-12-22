//
// Created by defacto on 16.10.15.
//

#include "Point.h"

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point() : Point(0.0, 0.0) {}

double Point::getX(void)  {
	return x_;
}

double Point::getY(void)  {
	return y_;
}

Point Point::move(double x, double y) {
	return Point( x_ + x, y_ + y);
}

std::ostream &operator<<(std::ostream& stream,  Point& point) {
	stream << "<"<<point.getX()<<","<<point.getY()<<">";
	return stream;
}

std::string Point::toString() {
	std::stringstream ss;
	ss << "<"<<this->getX()<<","<<this->getY()<<">";
	return ss.str();
}

bool operator==( Point& p1,  Point& p2) {
	return p1.getY() == p2.getY() && p1.getX() == p2.getX();
}

bool operator!=( Point& p1,  Point& p2) {
	return !(p1==p2);
}