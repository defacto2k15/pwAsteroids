//
// Created by defacto on 09.11.15.
//


#include "FakeKeyboardStateToGameProvider.h"

FakeKeyboardStateToGameProvider::FakeKeyboardStateToGameProvider(std::shared_ptr<Game> g) : g_(g) {
}

void FakeKeyboardStateToGameProvider::connectToGame() {
	g_->getInKeyboardStateGetter()->addObserver(this);
}

void FakeKeyboardStateToGameProvider::addKeyToPress(Keys key) {
	keysBeingPressed_.push_back(key);
}

void FakeKeyboardStateToGameProvider::notify() {
	for(auto &key : keysBeingPressed_){
		g_->getInKeyboardStateGetter()->gameKeyIsPressed(key); // maybe gameKeyIsPressed?
	}
}