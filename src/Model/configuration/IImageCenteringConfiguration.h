//
// Created by defacto on 02.12.15.
//

#ifndef PWASTEROIDS_IIMAGECENTERINGCONFIGURATION_H
#define PWASTEROIDS_IIMAGECENTERINGCONFIGURATION_H

#include <Model/PrimitiveTypes/Point.h>

class IImageCenteringConfiguration {
public:
	virtual Point getBox2dScreenDimensions() const = 0;
};
#endif //PWASTEROIDS_IIMAGECENTERINGCONFIGURATION_H
