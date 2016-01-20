//
// Created by root on 2016.01.20..
//

#ifndef PWASTEROIDS_ROCKETACTORPROXY_H
#define PWASTEROIDS_ROCKETACTORPROXY_H


#include <Model/Actors/IActor.h>

class RocketActorProxy : public IActor { // todo push data to cpp
    std::shared_ptr<IActor> realRocket_;
public:
    RocketActorProxy( std::shared_ptr<IActor> realRocket) : realRocket_(realRocket) { }

    void setNewRocketActor( std::shared_ptr<IActor> newRocket){
        realRocket_ = newRocket;
    }

    virtual void addComponent(std::shared_ptr<Component> component){
        realRocket_->addComponent(component);
    }

    virtual void removeComponent(Component *componentToDelete){
        realRocket_->removeComponent(componentToDelete);
    }

    virtual ActorId getActorId() const{
        return realRocket_->getActorId();
    }

    std::shared_ptr<IActor> getRocketActor(){
        return  realRocket_;
    };

protected:
    virtual std::shared_ptr<Component> getOnlyComponent(ComponentTypeChecker checker){
        return realRocket_->getOnlyComponent(checker);
    }

    virtual bool isComponentPresent(ComponentTypeChecker checker){
        return realRocket_->isComponentPresent(checker);
    }
};


#endif //PWASTEROIDS_ROCKETACTORPROXY_H
