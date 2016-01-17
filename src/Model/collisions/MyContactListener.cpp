//
// Created by defacto on 2015.12.28..
//
#include "ContactComponentsContainer.h"
#include "MyContactListener.h"

void MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse ) {
    if( contact->IsTouching() ){

        double impulseValue = impulse->tangentImpulses[0] + impulse->tangentImpulses[1] + impulse->normalImpulses[0] +
                              impulse->normalImpulses[1];

        container_.getComponentForBody( contact->GetFixtureB()->GetBody())
                ->addColision(CollisionData(CollisionGroup(contact->GetFixtureB()->GetFilterData().categoryBits), impulseValue, contact->GetFixtureB()));
        container_.getComponentForBody( contact->GetFixtureA()->GetBody())
                ->addColision(CollisionData(CollisionGroup(contact->GetFixtureA()->GetFilterData().categoryBits), impulseValue, contact->GetFixtureA()));
    }
}

MyContactListener::MyContactListener(ContactComponentsContainer &container) : container_(container) { }