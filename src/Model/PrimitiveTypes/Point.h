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

	double getX() const;

	double getY() const;

	Point move(double x, double y);

	std::string toString();
};

bool operator==(const Point& p1, const Point& p2);

bool operator!=(const Point& p1, const Point& p2);

std::ostream & operator<<(std::ostream& stream, const Point& point);

#endif //PWASTEROIDS_POINT_H
