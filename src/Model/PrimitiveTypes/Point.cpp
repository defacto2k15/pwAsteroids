//
// Created by defacto on 16.10.15.
//

#include "Point.h"

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point() : Point(0.0, 0.0) {}

double Point::getX() const {
	return x_;
}

double Point::getY() const {
	return y_;
}

Point Point::move(double x, double y) {
	return Point( x_ + x, y_ + y);
}

std::ostream &operator<<(std::ostream& stream, const Point& point) {
	stream << "<"<<point.getX()<<","<<point.getY()<<">";
	return stream;
}

std::string Point::toString() {
	std::stringstream ss;
	ss << "<"<<this->getX()<<","<<this->getY()<<">";
	return ss.str();
}

bool operator==(const Point& p1, const Point& p2) {
	return p1.getY() == p2.getY() && p1.getX() == p2.getX();
}

bool operator!=(const Point& p1, const Point& p2) {
	return !(p1==p2);
}