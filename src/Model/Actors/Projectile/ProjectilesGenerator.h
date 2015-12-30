//
// Created by defacto on 2015.12.28..
//

#ifndef PWASTEROIDS_PROJECTILESGENERATOR_H
#define PWASTEROIDS_PROJECTILESGENERATOR_H


#include <Model/Actors/ActorsGenerator.h>

class ProjectilesGenerator : public ActorsGenerator{
public:
    ProjectilesGenerator(std::shared_ptr<ActorsContainer> actorsContainer,
                         ActorIdGenerator &idGenerator,
                         std::shared_ptr<PythonModule> pythonModule,
                         std::shared_ptr<DrawingSystem> drawingSystem,
                         ActorsConfiguration &actorsConfiguration,
                         std::shared_ptr<Box2DService> boxService,
                         Box2dObjectsContainer &container,
                         ImageScalesContainer &imageScalesContainer,
                        ContactComponentsContainer &contactComponentsContainer);

    void generateProjectile(Point position, Rotation rotation, Point speedVector, double rotationSpeed);
};


#endif //PWASTEROIDS_PROJECTILESGENERATOR_H
