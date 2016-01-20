//
// Created by root on 2016.01.20..
//

#ifndef PWASTEROIDS_EXPLISIONCLOUDIMAGEMANIPULATINGCOMPONENT_H
#define PWASTEROIDS_EXPLISIONCLOUDIMAGEMANIPULATINGCOMPONENT_H


#include <Model/components/Component.h>
#include <Model/configuration/GameConfiguration.h>
#include <Model/Services/GameTimeProvider.h>
#include <Model/components/DrawingComponent.h>
#include <Model/Services/ActorsContainer.h>
#include <algorithm>

class ExplisionCloudImageManipulatingComponent : public Component{
    double size_;
    GameConfiguration &configuration_;
    std::shared_ptr<ActorsContainer> actorsContainer_;
    std::shared_ptr<GameTimeProvider> gameTimeProvider_;

    std::shared_ptr<DrawingComponent> drawingComponent_;
    ActorId id_;

    long long timeOfCreation_=0;
    long long timeOfFadeStart_;
    bool isCloudInMaxSize = false;
public:
    ExplisionCloudImageManipulatingComponent(double size_, GameConfiguration &configuration_,
                                             std::shared_ptr<ActorsContainer> actorsContainer_,
                                             const std::shared_ptr<GameTimeProvider> &gameTimeProvider_);

    void OnStart(IActor &actor);

    void OnUpdate();

};


#endif //PWASTEROIDS_EXPLISIONCLOUDIMAGEMANIPULATINGCOMPONENT_H
