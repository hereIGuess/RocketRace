#pragma once
#include "ofGraphics.h"
#include "point.h"

extern Point screen;

class Timer {
private:
	//ofTimer timer;
	int time;
	float passedTime = 0;

	//could just check if time is 0 but I think a bool is easier to read
	bool gameOver = false;

public:
	bool getGameState() {
		return gameOver;
	}

	Timer() {
		time = 60;
	}

	void countDown() {
		if (gameOver) return;

		passedTime += ofGetLastFrameTime();

		if (passedTime >= 1) {
			time--;
			passedTime = 0;
		}

		if (time == 0) {
			gameOver = true;
			std::cout << "gameover";
		}
	}

	void render() {
		ofDrawRectangle(screen.x / 2, 0, 5, time * 10);
	}
};