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

	ScaleToScreen& operator*=(double scale ){
		p_ *= scale;
		return *this;
	}
private:
	void assertArgumentsAreAcceptable(double x, double y);
};

std::ostream & operator<<(std::ostream& stream,  ScaleToScreen& scale);

ScaleToScreen operator*(ScaleToScreen scale1, double scale2);


#endif //PWASTEROIDS_SCALE_H
