//
// Created by defacto on 09.11.15.
//


#include "FakeKeyboardStateToGameProvider.h"

FakeKeyboardStateToGameProvider::FakeKeyboardStateToGameProvider(std::shared_ptr<Game> g) : g_(g) {
}

void FakeKeyboardStateToGameProvider::sendKeysPressedToGame() {
	for(auto &key : keysBeingPressed_){
		g_->getInKeyboardStateGetter()->gameKeyIsPressed(key); // maybe gameKeyIsPressed?
	}
}

void FakeKeyboardStateToGameProvider::addKeyToPress(Keys key) {
	keysBeingPressed_.push_back(key);
}
