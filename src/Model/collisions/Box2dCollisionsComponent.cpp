//
// Created by defacto on 2015.12.29..
//

#include "Box2dCollisionsComponent.h"
#include "ContactComponentsContainer.h"
#include <Model/Actors/Asteroid/AsteroidsGenerator.h>

Box2dCollisionsComponent::Box2dCollisionsComponent(ContactComponentsContainer &contactContainer)
        : contactContainer_(contactContainer) {
}

void Box2dCollisionsComponent::OnStart(IActor &actor ) {
    box2dComponent_ = actor.getOnlyComponent<Box2dComponent>();
    body_ =  box2dComponent_->getBody();
    contactContainer_.registerCollisionComponent( body_, this);
}

void Box2dCollisionsComponent::OnStop() {
    contactContainer_.deregisterCollisionComponent(body_);
}

void Box2dCollisionsComponent::OnUpdate() {
    for( auto oneImpulse : collisionImpulses_ ){
        if( manageCollision(oneImpulse )){

            break; // has to be last command in method
        }
    }
    collisionImpulses_.clear();
}

void Box2dCollisionsComponent::addColision(double impulse ) {
    collisionImpulses_.push_back(impulse);
}