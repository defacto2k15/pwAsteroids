//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_POINT_H
#define PWASTEROIDS_POINT_H

#include <iostream>
#include <sstream>
#include <string>

class Point {
	double x_;
	double y_;
public:
	Point();

	Point(double x, double y);

	double getX(void) ;

	double getY(void) ;

	//double getX(void) const;

	//double getY(void) const;

	Point move(double x, double y);

	std::string toString();

	Point& operator*=(double scale){
		x_ *=scale;
		y_ *=scale;
		return *this;
	}

	Point &operator+=( Point other){
		x_ += other.x_;
		y_ += other.y_;
		return  *this;
	}

	void normalize();

	double getDistanceFrom(Point point);
};

bool operator==( Point p1,  Point p2);

bool operator!=( Point p1,  Point p2);

Point operator+(Point p1, Point p2);

Point operator-(Point p1);

Point operator-(Point p1, Point p2 );

Point operator/(Point p1, Point p2);

Point operator*(Point p1, double scale);

Point operator/(Point p1, double divisor);

std::ostream & operator<<(std::ostream& stream,  Point& point);

#endif //PWASTEROIDS_POINT_H
