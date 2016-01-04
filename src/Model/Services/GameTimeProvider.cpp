//
// Created by defacto on 24.10.15.
//

#include <ostream>
#include "GameTimeProvider.h"

long GameTimeProvider::getMilisecondsSinceGameStart() {
	std::chrono::duration<double> elapledMiliseconds = currentFrameTime - gameStartTime;
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<double>(elapledMiliseconds)).count();
}

long GameTimeProvider::getMilisecondsBetweenFrames() {
	std::chrono::duration<double> elapledMiliseconds = currentFrameTime - lastFrameTime;
	return std::chrono::duration_cast<std::chrono::milliseconds>(elapledMiliseconds).count();
}

void GameTimeProvider::OnStart() {
	gameStartTime = std::chrono::high_resolution_clock::now();
	lastFrameTime = std::chrono::high_resolution_clock::now();
	currentFrameTime = std::chrono::high_resolution_clock::now();
}

void GameTimeProvider::OnUpdate() {
	if( isOn_ ) {
		lastFrameTime = currentFrameTime;
		currentFrameTime = std::chrono::high_resolution_clock::now();
	}
}