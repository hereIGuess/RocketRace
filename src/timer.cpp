#include "timer.h"

//gets gameOver
bool Timer::getGameState() {
	return gameOver;
}

//timer constructor: sets up maxTime and resets timer
Timer::Timer(int maxTime) {
	this->maxTime = maxTime;

	reset();
}

//sets up gameOver, currentTime, and timePassed to default values
void Timer::reset() {
	gameOver = false;
	currentTime = maxTime;
	timePassed = 0;
}

//checks if 1 second has passed and if it has it the timer goes down
//if the timer runs out gameOver will be set to true
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

//draws the timer
void Timer::render() {
	ofDrawRectangle(screen.x / 2 - 5, (maxTime - currentTime) * ofGetWindowHeight() / maxTime, 
								10,  ofGetWindowHeight() - ((maxTime - currentTime) * ofGetWindowHeight() / maxTime));
}
