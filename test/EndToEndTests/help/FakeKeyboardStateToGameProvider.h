//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_FAKEKEYBOARDSTATETOKAMEPROVIDER_H
#define PWASTEROIDS_FAKEKEYBOARDSTATETOKAMEPROVIDER_H

#include <test/EndToEndTests/expectations/IEndToEndExpectation.h>
#include <memory>
#include "src/Model/Observer/IObserver.h"

class FakeKeyboardStateToGameProvider : public IObserver{
	std::shared_ptr<Game> g_;
	std::vector<Keys> keysBeingPressed_;
public:
	FakeKeyboardStateToGameProvider(std::shared_ptr<Game> g);

	void connectToGame();

	void addKeyToPress(Keys key);

	virtual void notify();
};
#endif //PWASTEROIDS_FAKEKEYBOARDSTATETOKAMEPROVIDER_H
