//
// Created by defacto on 28.11.15.
//

#include "Rotation.h"

Rotation::Rotation( double rotation ) {
	setRotationInDegrees(rotation);
}

Rotation::operator double() { return rotationInDegrees_ ; }


Rotation Rotation::operator+(const Rotation& b){
	Rotation rot( b.rotationInDegrees_ + rotationInDegrees_ );
	return rot;
}

Rotation& Rotation::operator+=(const Rotation& b){
	setRotationInDegrees(rotationInDegrees_ + b.rotationInDegrees_);
	return * this;
}

void Rotation::setRotationInDegrees( double rotation ) {
	rotationInDegrees_ = turncateTo360Degrees(rotation);
}

double Rotation::turncateTo360Degrees( double rotation) {
	if( rotation < 0){
		while ( rotation < 0){
			rotation += 360;
		}
		return rotation;
	} else {
		while ( rotation > 360 ){
			rotation -= 360;
		}
		return  rotation;
	}
}