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

	ScaleToScreen( Point p ) : ScaleToScreen(p.getX(), p.getY()){
	}

	ScaleToScreen();;

	double getX() ;

	double getY() ;;

	Point scalePoint(Point p) ;

	ScaleToScreen& operator*=(double scale ){
		p_ *= scale;
		return *this;
	}

	ScaleToScreen operator/(ScaleToScreen secondScale){
		ScaleToScreen newScale( p_.getX() / secondScale.getX(), p_.getY() / secondScale.getY() );
		return newScale;
	}

	ScaleToScreen getInverted(){
		return ScaleToScreen( 1/p_.getX(), 1/p_.getY() );
	}
private:
	void assertArgumentsAreAcceptable(double x, double y);
};

std::ostream & operator<<(std::ostream& stream,  ScaleToScreen& scale);

ScaleToScreen operator*(ScaleToScreen scale1, double scale2);




#endif //PWASTEROIDS_SCALE_H
