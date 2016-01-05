//
// Created by defacto on 2015.12.28..
//

#ifndef PWASTEROIDS_PROJECTILESGENERATOR_H
#define PWASTEROIDS_PROJECTILESGENERATOR_H


#include <Model/Actors/ActorsGenerator.h>
#include <Model/Actors/ScoreDisplay/ScoreCount.h>

class ProjectilesGenerator : public ActorsGenerator{
    ScoreCount &scoreCount_;
public:
    ProjectilesGenerator(std::shared_ptr<ActorsContainer> actorsContainer,
                         ActorIdGenerator &idGenerator,
                         PythonModule &pythonModule,
                         DrawingSystem &drawingSystem,
                         GameConfiguration &gameConfiguration,
                         std::shared_ptr<Box2DService> boxService,
                         Box2dObjectsContainer &container,
                         ImageScalesContainer &imageScalesContainer,
                        ContactComponentsContainer &contactComponentsContainer,
                        ScoreCount &scoreCount);

    void generateProjectile(Point position, Rotation rotation, Point speedVector, double rotationSpeed);
};


#endif //PWASTEROIDS_PROJECTILESGENERATOR_H
