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

	double getX() ;

	double getY() ;;

	Point scalePoint(Point p) ;
private:
	void assertArgumentsAreAcceptable(double x, double y);
};

std::ostream & operator<<(std::ostream& stream,  ScaleToScreen& scale);


#endif //PWASTEROIDS_SCALE_H
