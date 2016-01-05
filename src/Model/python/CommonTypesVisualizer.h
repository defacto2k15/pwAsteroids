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
    CommonTypesVisualizer( PythonModule &python )
            :  pointVisibilityModule_(python), rotationVisibilityModule_(python),
               scaleToScreenVisibilityModule_(python), rectVisibilityModule_(python), pythonModule_(python){
    }

    void OnStart() override{
        pointVisibilityModule_.registerClass("Point");
        pointVisibilityModule_.registerMethod("getX", &Point::getX);
        pointVisibilityModule_.registerMethod("getY", &Point::getY);

        rotationVisibilityModule_.registerClass("Rotation");
        rotationVisibilityModule_.registerMethod("getAsDouble", &Rotation::getAsDouble);

        scaleToScreenVisibilityModule_.registerClass("ScaleToScreen");
        scaleToScreenVisibilityModule_.registerMethod("getX", &ScaleToScreen::getX);
        scaleToScreenVisibilityModule_.registerMethod("getY", &ScaleToScreen::getY);
        scaleToScreenVisibilityModule_.registerMethod("scalePoint", &ScaleToScreen::scalePoint);

        rectVisibilityModule_.registerClass("Rect");
        rectVisibilityModule_.registerMethod("isPointInRectangle", &Rect::isPointInRectangle);
        rectVisibilityModule_.registerMethod("getLength", &Rect::getLength);

        pythonModule_.addVectorOfClass<PythonActorComponent>("PythonActorComponentVector");
    }
};


#endif //PWASTEROIDS_COMMONTYPESVISUALIZER_H
