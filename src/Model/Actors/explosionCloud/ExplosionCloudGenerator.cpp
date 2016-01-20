//
// Created by root on 2016.01.20..
//

#include "ExplosionCloudGenerator.h"

ExplosionCloudGenerator::ExplosionCloudGenerator(const std::shared_ptr<ActorsContainer> &actorsContainer, ActorIdGenerator &idGenerator,
                                                 PythonModule &pythonModule, DrawingSystem &drawingSystem,
                                                 GameConfiguration &gameConfiguration, ImageScalesContainer &imageScalesContainer,
                                                 std::shared_ptr<GameTimeProvider> gameTimeProvider)
        : actorsContainer_(actorsContainer), idGenerator_(idGenerator), pythonModule_(pythonModule), drawingSystem_(drawingSystem),
          imageScalesContainer_(imageScalesContainer), gameConfiguration_(gameConfiguration), gameTimeProvider_(gameTimeProvider) {
    std::function< void (Point position, double size)>
            func =  [this](Point position, double size){ generateExplosionCloud(position, size);};
    pythonModule_.addRootFunction("generateExplosionCloud", func );
}

void ExplosionCloudGenerator::generateExplosionCloud(Point position, double size) {
    std::vector<std::shared_ptr<Component>> componentsForcloud;
    componentsForcloud.push_back(std::make_shared<PositionComponent>(pythonModule_));
    componentsForcloud.push_back( std::make_shared<PythonActorComponent>(pythonModule_));
    auto positionSettingComponent = std::make_shared<PositionSettingComponent >(false, pythonModule_);
    componentsForcloud.push_back( positionSettingComponent);
    componentsForcloud.push_back(
            std::make_shared<DrawingComponent>(drawingSystem_, ImagePrimitiveType::ExplosionCloud,
                                               imageScalesContainer_.getImageScale(
                                                       ImagePrimitiveType::ExplosionCloud)));
    componentsForcloud.push_back(std::make_shared<ActorTypeComponent>(ActorType_ExplosionCloud, pythonModule_));
    componentsForcloud.push_back(std::make_shared<ExplisionCloudImageManipulatingComponent>(
            size, gameConfiguration_, actorsContainer_, gameTimeProvider_));

    auto newCloud = std::make_shared<Actor>(idGenerator_.getActorId());
    for( auto oneComponent : componentsForcloud){
        newCloud->addComponent(oneComponent);
    }
    actorsContainer_->addActorDuringRuntime(newCloud);
    positionSettingComponent->setPosition(position.getX(), position.getY());
}