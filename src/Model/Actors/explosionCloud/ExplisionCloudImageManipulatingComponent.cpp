//
// Created by root on 2016.01.20..
//

#include "ExplisionCloudImageManipulatingComponent.h"

ExplisionCloudImageManipulatingComponent::ExplisionCloudImageManipulatingComponent(double size_, GameConfiguration &configuration_,
                                                                                   std::shared_ptr<ActorsContainer> actorsContainer_,
                                                                                   const std::shared_ptr<GameTimeProvider> &gameTimeProvider_)
        : size_(size_), configuration_(configuration_), actorsContainer_(actorsContainer_),
          gameTimeProvider_(gameTimeProvider_) {
}

void ExplisionCloudImageManipulatingComponent::OnStart(IActor &actor) {
    id_ = actor.getActorId();
    drawingComponent_ = actor.getOnlyComponent<DrawingComponent>();

}

void ExplisionCloudImageManipulatingComponent::OnUpdate() {
    if( timeOfCreation_ == 0){
        timeOfCreation_ = gameTimeProvider_->getMilisecondsSinceGameStart();
    }
    if (isCloudInMaxSize == false) {
        double multiplier = std::min(double(1.0f), configuration_.getExplosionCloudGrowthRatio()
                                                   * (gameTimeProvider_->getMilisecondsSinceGameStart() - timeOfCreation_) *0.1f);
  //      std::cout << "MULT IS " << multiplier << " and ttt is " << gameTimeProvider_->getMilisecondsSinceGameStart() << " - " <<  timeOfCreation_<<
  //               "and ir is " << configuration_.getExplosionCloudGrowthRatio() << std::endl;
        if(multiplier >= 0.999){
            isCloudInMaxSize = true;
            timeOfFadeStart_ = gameTimeProvider_->getMilisecondsSinceGameStart();
        }
        double currentSize = size_ * multiplier;
        drawingComponent_->setSize(currentSize);
    } else {
        double opacity = std::max( double(0.0f), 1 - (configuration_.getExplosionCloudFadingRatio() *
                                                      (gameTimeProvider_->getMilisecondsSinceGameStart() - timeOfFadeStart_)));
        if( opacity <= 0.001){
            actorsContainer_->removeActorById(id_);
        } else {
            drawingComponent_->setOpacity(opacity);
        }
    }



}