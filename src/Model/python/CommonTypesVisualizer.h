//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_COMMONTYPESVISUALIZER_H
#define PWASTEROIDS_COMMONTYPESVISUALIZER_H


#include <Model/PrimitiveTypes/Point.h>
#include "PythonClassVisibilityModule.h"

class CommonTypesVisualizer : public IService {
    PythonClassVisibilityModule<Point, double, double> pointVisibilityModule_;
    PythonClassVisibilityModule<Rotation, double > rotationVisibilityModule_;
public:
    CommonTypesVisualizer( std::shared_ptr<PythonModule> python )
            :  pointVisibilityModule_(python), rotationVisibilityModule_(python){
    }

    void OnStart() override{
        pointVisibilityModule_.registerClass();
        pointVisibilityModule_.registerMethod("getX", &Point::getX);
        pointVisibilityModule_.registerMethod("getY", &Point::getY);

        rotationVisibilityModule_.registerClass();
        rotationVisibilityModule_.registerMethod("getAsDouble", &Rotation::getAsDouble);
    }
};


#endif //PWASTEROIDS_COMMONTYPESVISUALIZER_H
