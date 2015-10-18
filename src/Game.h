//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_GAME_H
#define PWASTEROIDS_GAME_H


#include <modelInterfaces/OutGameScreenModel.h>
#include <stdexcept>

class Game {
public:
	OutGameScreenModel &getOutGameScreenModel(){throw std::runtime_error("NOT YET IMPLEMENTED");};
	void update(){throw std::runtime_error("NOT YET IMPLEMENTED");};
};


#endif //PWASTEROIDS_GAME_H
