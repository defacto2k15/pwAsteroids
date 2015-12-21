//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_ROTATION_H
#define PWASTEROIDS_ROTATION_H


class Rotation { // in DEGREES
	double rotationInDegrees_;
public:
	Rotation( double rotation );

	operator double();


	Rotation operator+(const Rotation& b);

	Rotation &operator+=(const Rotation& b);

private:
	void setRotationInDegrees( double rotation );

	double turncateTo360Degrees( double rotation);

};


#endif //PWASTEROIDS_ROTATION_H
