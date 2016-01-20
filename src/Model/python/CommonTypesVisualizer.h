//
// Created by defacto on 2015.12.22..
//

#ifndef PWASTEROIDS_COMMONTYPESVISUALIZER_H
#define PWASTEROIDS_COMMONTYPESVISUALIZER_H


#include <Model/PrimitiveTypes/Point.h>
#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include <Model/PrimitiveTypes/Rect.h>
#include "PythonClassVisibilityModule.h"

class CommonTypesVisualizer : public IService {
    PythonClassVisibilityModule<Point, double, double> pointVisibilityModule_;
    PythonClassVisibilityModule<Rotation, double > rotationVisibilityModule_;
    PythonClassVisibilityModule<ScaleToScreen, double, double > scaleToScreenVisibilityModule_;
    PythonClassVisibilityModule<Rect, Point, Point> rectVisibilityModule_;
    PythonModule &pythonModule_;
public:
    CommonTypesVisualizer(PythonModule &python );

    void OnStart();
};


#endif //PWASTEROIDS_COMMONTYPESVISUALIZER_H
