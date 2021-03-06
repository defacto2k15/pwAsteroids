//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_PROJECTILECOLLISIONCOMPONENT_H
#define PWASTEROIDS_PROJECTILECOLLISIONCOMPONENT_H


#include <Model/collisions/Box2dCollisionsComponent.h>
#include <Model/Services/ActorsContainer.h>
#include <Model/Actors/ScoreDisplay/ScoreCount.h>

class ProjectileCollisionComponent : public Box2dCollisionsComponent{
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorId id_;
    ScoreCount &scoreCount_;
    GameConfiguration &gameConfiguration_;
public:

    ProjectileCollisionComponent(ContactComponentsContainer &contactContainer,
                                 const std::shared_ptr<ActorsContainer> actorsContainer,
                                ScoreCount &scoreCount,
                                GameConfiguration &gameConfiguration);

    void OnStart(IActor &actor );

    bool manageCollision(CollisionData &data );


};


#endif //PWASTEROIDS_PROJECTILECOLLISIONCOMPONENT_H
