//
// Created by defacto on 2015.12.28..
//

#ifndef PWASTEROIDS_MYCONTACTLISTENER_H
#define PWASTEROIDS_MYCONTACTLISTENER_H


#include <lib/Box2D/Dynamics/b2WorldCallbacks.h>
#include <lib/Box2D/Dynamics/Contacts/b2Contact.h>
#include <iostream>
class ContactComponentsContainer;

class MyContactListener  : public b2ContactListener {
    ContactComponentsContainer &container_;
public:
    MyContactListener(ContactComponentsContainer &container);

    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse );
};


#endif //PWASTEROIDS_MYCONTACTLISTENER_H
