#include "timer.h"

bool Timer::getGameState() {
	return gameOver;
}

Timer::Timer(int maxTime) {
	this->maxTime = maxTime;

	reset();
}

void Timer::reset() {
	currentTime = maxTime;
	timePassed = 0;
}

void Timer::countDown() {
	//add the last frame time to time passed
	timePassed += ofGetLastFrameTime();

	//when 1 second has passed, subtract from currentTime and reset timePassed
	if (timePassed >= 1) {
		currentTime--;
		timePassed = 0;
	}

	//when the timer reaches 0, set gameOver to true; 
	if (currentTime == 0) {
		gameOver = true;
	}
}

void Timer::render() {
	ofDrawRectangle(screen.x / 2 - 5, (maxTime - currentTime) * ofGetWindowHeight() / maxTime, 
								10,  ofGetWindowHeight() - ((maxTime - currentTime) * ofGetWindowHeight() / maxTime));
}
