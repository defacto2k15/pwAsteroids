//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_PROJECTILECOLLISIONCOMPONENT_H
#define PWASTEROIDS_PROJECTILECOLLISIONCOMPONENT_H


#include <Model/collisions/Box2dCollisionsComponent.h>
#include <Model/Services/ActorsContainer.h>

class ProjectileCollisionComponent : public Box2dCollisionsComponent{
    std::shared_ptr<ActorsContainer> actorsContainer_;
    ActorId id_;
public:

    ProjectileCollisionComponent(ContactComponentsContainer &contactContainer,
                                 const std::shared_ptr<ActorsContainer> actorsContainer) : Box2dCollisionsComponent(
            contactContainer), actorsContainer_(actorsContainer) {
    }

    void OnStart( IActor &actor ) override{
        Box2dCollisionsComponent::OnStart(actor);
        id_ = actor.getActorId();
    }

    bool manageCollision(double impulseValue ) override{
        actorsContainer_->removeActorById(id_);
        return true;
    }
};


#endif //PWASTEROIDS_PROJECTILECOLLISIONCOMPONENT_H
