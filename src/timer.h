#pragma once
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "point.h"

extern Point screen;

class Timer {
private:
	int maxTime; //how long the game will last

	int currentTime; //time left
	float timePassed; //how much milliseconds have passed

	//could just check if time is 0 but I think a bool is easier to read
	bool gameOver = false;

public:
	bool getGameState();

	Timer(int maxTime);

	void reset();

	void countDown();

	void render();
};