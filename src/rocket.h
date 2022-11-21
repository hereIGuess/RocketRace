#pragma once
#include "asteroid.h"
#include "score.h"

extern Point screen;

class Rocket {
private:
	ofImage rocket = ofImage("Images/spaceship.png");
	ofSoundPlayer crash;

	enum class Direction { up, down, still };
	Direction movement;
	int up;
	int down;

	Point position;
	int size = 15;

	Score score = Score(0, Point{ 0, 0 });

	//added this to stop some choppy movement from happening
	bool keyHeld = false;

public:
	Score getScore();

	Rocket(int upButton, int downButton, int xPos);

	void increaseScore();

	void respawnPlayer();

	void reset();

	void move();

	void checkMoving(int key);

	void direction(int key);

	void checkCollision(Asteroid asteroid);

	void render();
};
