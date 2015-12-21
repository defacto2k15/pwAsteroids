//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_FAKEKEYBOARDSTATETOKAMEPROVIDER_H
#define PWASTEROIDS_FAKEKEYBOARDSTATETOKAMEPROVIDER_H

#include <test/EndToEndTests/expectations/IEndToEndExpectation.h>
#include <memory>
#include "src/Model/Observer/IObserver.h"

class FakeKeyboardStateToGameProvider {
	std::shared_ptr<Game> g_;
	std::vector<Keys> keysBeingPressed_;
public:
	FakeKeyboardStateToGameProvider(std::shared_ptr<Game> g);

	void sendKeysPressedToGame();

	void addKeyToPress(Keys key);

};
#endif //PWASTEROIDS_FAKEKEYBOARDSTATETOKAMEPROVIDER_H
