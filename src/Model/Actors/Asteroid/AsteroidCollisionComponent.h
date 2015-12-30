//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_ASTEROIDCOLLISIONCOMPONENT_H
#define PWASTEROIDS_ASTEROIDCOLLISIONCOMPONENT_H


#include <Model/collisions/Box2dCollisionsComponent.h>
#include "AsteroidSizeComponent.h"

class AsteroidsGenerator;


class AsteroidCollisionComponent : public Box2dCollisionsComponent{
    std::shared_ptr<ActorsContainer> actorsContainer_;
    AsteroidsGenerator &asteroidsGenerator_;
    std::shared_ptr<PositionComponent> positionComponent_;
    std::shared_ptr<AsteroidSizeComponent> sizeComponent_;
    ActorId id_;
    double size_;
public:
    AsteroidCollisionComponent(ContactComponentsContainer &contactContainer, std::shared_ptr<ActorsContainer> actorsContainer,
                               AsteroidsGenerator &asteroidsGenerator);

    void OnStart(IActor &actor );

    bool manageCollision(double impulseValue ) override;

    void createAsteroidAtAngleRelativeToCurrentAsteroid(double impulseValue, Rotation angle, int asteroidFranctions);

};


#endif //PWASTEROIDS_ASTEROIDCOLLISIONCOMPONENT_H
