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
                                         std::shared_ptr<GameTimeProvider> &timeProvider_) : Box2dCollisionsComponent(
            contactContainer), actorsContainer_(actorsContainer_), rocketActor_(rocketActor_), configuration(
            configuration), projectilesGenerator(projectilesGenerator), inputStateProvider_(inputStateProvider_),
                                                                                             musicManager_(
                                                                                                     musicManager_),
                                                                                             timeProvider_(
                                                                                                     timeProvider_) {
    }

    void OnStart(IActor &actor){
        id = actor.getActorId();
        Box2dCollisionsComponent::OnStart(actor);
    }

    bool manageCollision(CollisionData &data ){
        if( rocketActor_->isComponentPresent<TemporaryRocketShootingComponent>() == false) {
           rocketActor_->addComponent(createTemporaryRocketShootingComponent(-30));
            rocketActor_->addComponent(createTemporaryRocketShootingComponent(30));
        }
        musicManager_->addMusicElement(MusicElements::PowerupGainSound, 0.5);
        actorsContainer_->removeActorById(id);
        return true;
    }

private:
    std::shared_ptr<Component> createTemporaryRocketShootingComponent( double angle){
        auto tempComponent = std::make_shared<TemporaryRocketShootingComponent>(
                configuration, projectilesGenerator, inputStateProvider_, timeProvider_, musicManager_,  Rotation(angle) );
        return  tempComponent;
    }
};


#endif //PWASTEROIDS_TRIPLESHOOTPOWERUPCOLLISIONCOMPONENT_H
