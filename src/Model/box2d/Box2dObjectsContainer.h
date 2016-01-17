//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
#define PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H

#include <vector>
#include <Model/help/DegreesCalculations.h>
#include <Model/ModelDrawing/ImageScalesContainer.h>
#include <Model/configuration/GameConfiguration.h>
#include <Model/collisions/CollisionGroupsData.h>
#include "Box2dObject.h"

class Box2dObjectsContainer {
    std::vector<std::shared_ptr<b2Shape>> polygonShapesVector_;
    ImageScalesContainer &imageScalesContainer_;
    GameConfiguration &gameConfiguration_;

public:
    Box2dObjectsContainer(ImageScalesContainer &imageScalesContainer, GameConfiguration &gameConfiguration );

    std::shared_ptr<Box2dObject> getRocketObject();


    std::shared_ptr<Box2dObject> getAsteriodObject(double size);

    std::shared_ptr<Box2dObject> getProjectileObject();

    std::shared_ptr<Box2dObject> getPowerupObject();


private:
    std::shared_ptr<Box2dObject> createObjectWithBoxShape(ScaleToScreen imageScale,
                                                              double densityPerSquareUnit,
                                                              CollisionGroupsData collisionGroupData);

    std::shared_ptr<Box2dObject> createObjectWithCircleShape(ScaleToScreen imageScale,
                                                          double densityPerSquareUnit,
                                                          CollisionGroupsData collisionGroupData);
};


#endif //PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
