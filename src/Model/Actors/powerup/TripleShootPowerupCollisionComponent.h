//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_TRIPLESHOOTPOWERUPCOLLISIONCOMPONENT_H
#define PWASTEROIDS_TRIPLESHOOTPOWERUPCOLLISIONCOMPONENT_H


#include <Model/collisions/Box2dCollisionsComponent.h>
#include <Model/Actors/Rocket/TemporaryRocketShootingComponent.h>

class TripleShootPowerupCollisionComponent : public Box2dCollisionsComponent {
    std::shared_ptr<ActorsContainer> actorsContainer_;
    std::shared_ptr<IActor> rocketActor_;
    GameConfiguration &configuration;
    ProjectilesGenerator &projectilesGenerator;
    std::shared_ptr<IInputStateProvider> &inputStateProvider_;
    std::shared_ptr<MusicManager> &musicManager_;
    std::shared_ptr<GameTimeProvider> &timeProvider_;
    ActorId id;
public:
    TripleShootPowerupCollisionComponent(ContactComponentsContainer &contactContainer,
                                         std::shared_ptr<ActorsContainer> &actorsContainer_,
                                         std::shared_ptr<IActor> rocketActor_,
                                         GameConfiguration &configuration,
                                         ProjectilesGenerator &projectilesGenerator,
                                         std::shared_ptr<IInputStateProvider> &inputStateProvider_,
                                         std::shared_ptr<MusicManager> &musicManager_,
                                         std::shared_ptr<GameTimeProvider> &timeProvider_);

    void OnStart(IActor &actor);

    bool manageCollision(CollisionData &data );

private:
    std::shared_ptr<Component> createTemporaryRocketShootingComponent(double angle);
};


#endif //PWASTEROIDS_TRIPLESHOOTPOWERUPCOLLISIONCOMPONENT_H
