//
// Created by defacto on 16.10.15.
//

#include <Model/help/StdContainers.h>
#include <stdexcept>
#include "Observable.h"
#include "IObserver.h"
void Observable::assertObserverIsNotArleadyAdded(IObserver *pObserver) {
	if (contains(observers_, pObserver) ){
		throw std::runtime_error("Adding an observer that was arleady added!");
	}
}

void Observable::assertObserverWasAdded(IObserver *pObserver) {
	if(!contains(observers_, pObserver)){
		throw std::runtime_error("Removing an observer that is not in Observable's collection");
	}
}

void Observable::addObserver( IObserver* newObserver ) {
	assertObserverIsNotArleadyAdded(newObserver);
	observers_.push_back(newObserver);
}

void Observable::removeObserver( IObserver* observerToRemove ) {
	assertObserverWasAdded(observerToRemove);
}

void Observable::notifyObservers() {
	for( auto observer : observers_ ){
		observer->notify();
	}
}