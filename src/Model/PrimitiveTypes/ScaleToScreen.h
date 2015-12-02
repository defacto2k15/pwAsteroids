//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_SCALE_H
#define PWASTEROIDS_SCALE_H


#include "Point.h"

class ScaleToScreen {
	Point p_;
public:
	ScaleToScreen(double x, double y);

	ScaleToScreen();;

	double getX() const;

	double getY() const;;

	Point scalePoint(Point p) const;
private:
	void assertArgumentsAreAcceptable(double x, double y);
};

std::ostream & operator<<(std::ostream& stream, const ScaleToScreen& scale);


#endif //PWASTEROIDS_SCALE_H
