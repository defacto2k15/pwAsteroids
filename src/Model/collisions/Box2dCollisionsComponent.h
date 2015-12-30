//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_BOX2DCOLLISIONSCOMPONENT_H
#define PWASTEROIDS_BOX2DCOLLISIONSCOMPONENT_H

#include <Model/components/Component.h>
#include <Model/Actors/Rocket/Box2dComponent.h>
#include <Model/Services/ActorsContainer.h>

class ContactComponentsContainer;

class Box2dCollisionsComponent : public Component {
    ContactComponentsContainer & contactContainer_;

    std::vector<double> collisionImpulses_;
    b2Body *body_ = nullptr;
protected:
    std::shared_ptr<Box2dComponent> box2dComponent_;
public:
    Box2dCollisionsComponent(ContactComponentsContainer &contactContainer);

    void OnStart(IActor &actor );

    void OnStop();

    void OnUpdate();

    void addColision(double impulse );

private:
    virtual bool manageCollision( double impulseValue )=0;

};


#endif //PWASTEROIDS_BOX2DCOLLISIONSCOMPONENT_H
