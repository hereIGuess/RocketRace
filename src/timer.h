#pragma once
#include "ofGraphics.h"
#include "point.h"

extern Point screen;

class Timer {
private:
	int currentTime;
	int timer = 120;
	float passedTime = 0;

	//could just check if time is 0 but I think a bool is easier to read
	bool gameOver = false;

public:
	bool getGameState() {
		return gameOver;
	}

	Timer() {
		currentTime = timer;
	}

	void countDown() {
		if (gameOver) return;

		passedTime += ofGetLastFrameTime();

		if (passedTime >= 1) {
			currentTime--;
			passedTime = 0;
		}

		if (currentTime == 0) {
			gameOver = true;
			std::cout << "gameover";
		}
	}

	void render() {
		ofDrawRectangle(screen.x / 2 + 5, (timer - currentTime) * ofGetWindowHeight() / timer, 10,  ofGetWindowHeight() - ((timer - currentTime) * ofGetWindowHeight() / timer));
	}
};