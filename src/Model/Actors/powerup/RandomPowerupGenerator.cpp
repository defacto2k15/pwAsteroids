//
// Created by defacto on 2016.01.16..
//

#include "RandomPowerupGenerator.h"

RandomPowerupGenerator::RandomPowerupGenerator(std::shared_ptr<IActor> rocketActor_, GameConfiguration &configuration_,
                                               std::shared_ptr<GameTimeProvider> timeProvider_, PowerupGenerator &generator_,
                                               PowerupCounter &counter_, RandomNumbersProvider &randomNumbers_)
        : rocketActor_(rocketActor_), configuration_(configuration_), timeProvider_(timeProvider_),
          generator_(generator_), counter_(counter_), randomNumbers_( randomNumbers_) {
}

void RandomPowerupGenerator::OnUpdate() {
    if( timeProvider_->getMilisecondsSinceGameStart() - timeOfLastCreation_
        > configuration_.getMinTimeBetweenPowerupGeneration() ){
        timeOfLastCreation_ = timeProvider_->getMilisecondsSinceGameStart();
        if( counter_.getCount() < configuration_.getMaxPowerupsCount()){
            if( (rand() % configuration_.getPowerupCreationPropabilityRatio()) == 0 ){
                Rect screenDimensions( Point(0,0), configuration_.getBox2dScreenDimensions()  );
                Point position = randomNumbers_.generateRandomPointInRectangle(screenDimensions);
                if( rocketActor_->getOnlyComponent<PositionComponent>()->getPosition().getDistanceFrom( position)
                    > configuration_.getMinPowerupDistanceFromRocket()){
                    generator_.generatePowerup(position, generateRandomPowerup());
                }
            }
        }
    }
}