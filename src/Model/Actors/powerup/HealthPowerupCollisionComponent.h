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
                                    std::shared_ptr<MusicManager> musicManager_, RocketLife &rocketLife)
            : Box2dCollisionsComponent(contactContainer), actorsContainer_(actorsContainer_),
              musicManager_(musicManager_), rocketLife(rocketLife) {
    }

    void OnStart(IActor &actor) override{
        id_ = actor.getActorId();
        Box2dCollisionsComponent::OnStart(actor);
    }

    bool manageCollision(CollisionData &data) override{
        rocketLife.increaseLife();
        //musicManager_->addMusicElement(MusicElements::PowerupGainSound, 0.5f);
        actorsContainer_->removeActorById(id_);
    }

};


#endif //PWASTEROIDS_HEALTHPOWERUP_H
