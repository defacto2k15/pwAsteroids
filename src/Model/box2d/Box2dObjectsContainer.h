//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
#define PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H

#include <vector>
#include <Model/help/DegreesCalculations.h>
#include <Model/ModelDrawing/ImageScalesContainer.h>
#include <Model/configuration/ActorsConfiguration.h>
#include "Box2dObject.h"

class Box2dObjectsContainer {
    std::vector<std::shared_ptr<b2PolygonShape>> polygonShapesVector_;
    ImageScalesContainer &imageScalesContainer_;
    ActorsConfiguration &actorsConfiguration_;

public:
    Box2dObjectsContainer(ImageScalesContainer &imageScalesContainer, ActorsConfiguration &actorsConfiguration );

    std::shared_ptr<Box2dObject> getRocketObject();


    std::shared_ptr<Box2dObject> getAsteriodObject(double size);

    std::shared_ptr<Box2dObject> getProjectileObject();


private:
    std::shared_ptr<Box2dObject> createObjectWithBoxShape(ScaleToScreen imageScale, double densityPerSquareUnit );
};


#endif //PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
