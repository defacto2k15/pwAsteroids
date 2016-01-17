//
// Created by defacto on 2016.01.17..
//

#ifndef PWASTEROIDS_HEALTHPOWERUP_H
#define PWASTEROIDS_HEALTHPOWERUP_H


#include <Model/collisions/Box2dCollisionsComponent.h>
#include <Model/sounds/MusicManager.h>
#include <Model/Actors/Rocket/RocketLife.h>

class HealthPowerupCollisionComponent : public Box2dCollisionsComponent {
    std::shared_ptr<ActorsContainer> actorsContainer_;
    std::shared_ptr<MusicManager> &musicManager_;
    RocketLife &rocketLife;
    ActorId id_;
public:
    HealthPowerupCollisionComponent(ContactComponentsContainer &contactContainer,
                                    std::shared_ptr<ActorsContainer> actorsContainer_,
                                    std::shared_ptr<MusicManager> musicManager_, RocketLife &rocketLife);

    void OnStart(IActor &actor);

    bool manageCollision(CollisionData &data);

};


#endif //PWASTEROIDS_HEALTHPOWERUP_H
