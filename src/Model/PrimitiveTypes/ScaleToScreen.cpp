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

double ScaleToScreen::getX() const {
	return p_.getX();
}

double ScaleToScreen::getY() const {
	return p_.getY();
}

void ScaleToScreen::assertArgumentsAreAcceptable(double x, double y) {
	if( x < 0 || x > 1 || y < 0 || y > 1){
		throw BadScaleArgumentException("Both parameters of scaleToScreen shoulb be between 0 and 1, but they are: "
		                                +std::to_string(x)+std::to_string(y));
	}
}

std::ostream &operator<<(std::ostream& stream, const ScaleToScreen& scale) {
	stream << "<"<<scale.getX()<<","<<scale.getY()<<">";
	return stream;
}
