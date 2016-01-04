//
// Created by defacto on 24.10.15.
//

#include <chrono>
#include "IService.h"

#ifndef PWASTEROIDS_GAMETIMEPROVIDER_H
#define PWASTEROIDS_GAMETIMEPROVIDER_H

class GameTimeProvider : public IService{
	std::chrono::time_point<std::chrono::high_resolution_clock > gameStartTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> currentFrameTime;
	bool isOn_ = true;
public:
	virtual void OnStart();;

	virtual void OnUpdate();;

	long getMilisecondsSinceGameStart();
	long getMilisecondsBetweenFrames();

	void turnOff(){
		isOn_ = false;
	}

	void turnOn(){
		isOn_ = true;
	}
};

#endif //PWASTEROIDS_GAMETIMEPROVIDER_H
