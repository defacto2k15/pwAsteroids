//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_ROTATION_H
#define PWASTEROIDS_ROTATION_H


class Rotation { // in DEGREES
	double rotationInDegrees_;
public:
	Rotation( double rotation ){
		setRotationInDegrees(rotation);
	}

	operator double() { return rotationInDegrees_ ; } const


	Rotation operator+(const Rotation& b){
		Rotation rot( b.rotationInDegrees_ + rotationInDegrees_ );
		return rot;
	}

	Rotation &operator+=(const Rotation& b){
		setRotationInDegrees(rotationInDegrees_ + b.rotationInDegrees_);
		return * this;
	}

private:
	void setRotationInDegrees( double rotation ){
		rotationInDegrees_ = turncateTo360Degrees(rotation);
	}

	double  turncateTo360Degrees( double rotation){
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

};


#endif //PWASTEROIDS_ROTATION_H
