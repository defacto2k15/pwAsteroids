//
// Created by defacto on 16.10.15.
//

#include <Model/exceptions/BadScaleArgumentException.h>
#include "ScaleToScreen.h"

ScaleToScreen::ScaleToScreen(double x, double y) {
	assertArgumentsAreAcceptable(x,y);
	p_ = Point(x,y);
}

ScaleToScreen::ScaleToScreen() : p_(1.0, 1.0) {}

double ScaleToScreen::getX()  {
	return p_.getX();
}

double ScaleToScreen::getY()  {
	return p_.getY();
}

void ScaleToScreen::assertArgumentsAreAcceptable(double x, double y) {
	if( x < 0 ||  y < 0 ){
		throw BadScaleArgumentException("Both parameters of scaleToScreen shoulb be positibe: "
		                                +std::to_string(x)+std::to_string(y));
	}
}

std::ostream &operator<<(std::ostream& stream,  ScaleToScreen& scale) {
	stream << "<"<<scale.getX()<<","<<scale.getY()<<">";
	return stream;
}

Point ScaleToScreen::scalePoint(Point p)  {
	Point newPoint( p.getX()*p_.getX(), p.getY()*p_.getY());
	return newPoint;
}

ScaleToScreen operator*(ScaleToScreen scale1, double scale2) {
	scale1 *= scale2;
	return scale1;
}