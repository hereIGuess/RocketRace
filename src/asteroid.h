#pragma once
#include "ofImage.h"
#include "point.h"

extern Point screen;

class Asteroid {
private:
	ofImage meteor;

	Point position;
	int size = 10;
	int direction;
	int speed;

public:
	Point getPosition();

	int getSize();

	Asteroid();

	void move();

	bool checkForDeletion();

	void render();
};
