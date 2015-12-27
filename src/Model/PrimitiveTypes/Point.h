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

	void normalize();
};

bool operator==( Point p1,  Point p2);

bool operator!=( Point p1,  Point p2);

Point operator+(Point p1, Point p2);

Point operator-(Point p1);

Point operator-(Point p1, Point p2 );

Point operator*(Point p1, double scale);

std::ostream & operator<<(std::ostream& stream,  Point& point);

#endif //PWASTEROIDS_POINT_H
