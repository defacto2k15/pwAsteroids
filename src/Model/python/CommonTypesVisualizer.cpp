//
// Created by defacto on 2015.12.22..
//

#include "CommonTypesVisualizer.h"

CommonTypesVisualizer::CommonTypesVisualizer(PythonModule &python )
        : pointVisibilityModule_(python), rotationVisibilityModule_(python),
          scaleToScreenVisibilityModule_(python), rectVisibilityModule_(python), pythonModule_(python) {
}

void CommonTypesVisualizer::OnStart() {
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

    boost::python::type_info info = boost::python::type_id<std::vector<PythonActorComponent>>();
    const boost::python::converter::registration* reg = boost::python::converter::registry::query(info);
    if (reg == NULL || ((*reg).m_to_python == NULL)) {
        pythonModule_.addVectorOfClass<PythonActorComponent>("PythonActorComponentVector");
    }
}