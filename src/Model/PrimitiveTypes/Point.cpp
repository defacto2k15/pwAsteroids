//
// Created by defacto on 16.10.15.
//

#include "Point.h"
#include <cmath>

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

void Point::normalize() {
	double alphaInRadians = atan2( y_ , x_);
	x_ = 1 * cos( alphaInRadians);
	y_ = 1 * sin( alphaInRadians);
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

bool operator==( Point p1,  Point p2) {
	return p1.getY() == p2.getY() && p1.getX() == p2.getX();
}

bool operator!=( Point p1,  Point p2) {
	return !(p1==p2);
}

Point operator+(Point p1, Point p2) {
	return Point(p1.getX()+p2.getX(), p1.getY()+p2.getY());
}

Point operator-(Point p1) {
	return Point( -p1.getX(), -p1.getY());
}

Point operator-(Point p1, Point p2 ) {
	return p1 + (-p2);
}

//double Point::getX(void) const {
//	return x_;
//}
//
//double Point::getY(void) const {
//	return y_;
//}

Point operator*(Point p1, double scale) {
	return Point(p1.getX()*scale, p1.getY()*scale);
}

Point operator/(Point p1, double divisor) {
	return Point(p1.getX()/divisor, p1.getY()/divisor);
}
Point operator/(Point p1, Point p2) {
	return Point( p1.getX() / p2.getX(), p1.getY() / p2.getY());
}