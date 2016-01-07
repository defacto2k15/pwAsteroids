//
// Created by defacto on 2015.12.26..
//

#include "AsteroidsCounter.h"

void AsteroidsCounter::Increment() {
    ++value;
}

void AsteroidsCounter::Decrement() {
    --value;
}

int AsteroidsCounter::getValue() {
    return value;
}