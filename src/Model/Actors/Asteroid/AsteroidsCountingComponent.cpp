//
// Created by defacto on 2015.12.26..
//

#include "AsteroidsCountingComponent.h"

AsteroidsCountingComponent::AsteroidsCountingComponent(std::shared_ptr<AsteroidsCounter> counter ) : counter_(counter) {
}

void AsteroidsCountingComponent::OnStart(IActor &actor) {
    counter_->Increment();
}

void AsteroidsCountingComponent::OnStop() {
    counter_->Decrement();
}