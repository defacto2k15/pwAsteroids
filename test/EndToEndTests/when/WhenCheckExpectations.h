//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_IWHENCHECKEXPECTATIONS_H
#define PWASTEROIDS_IWHENCHECKEXPECTATIONS_H

#include <Game.h>

class WhenCheckExpectations {
public:
	virtual void GameStarted();;

	virtual void GameLoopCompleted(Game &g);;

	virtual bool CheckExpectations()=0;
};
#endif //PWASTEROIDS_IWHENCHECKEXPECTATIONS_H
