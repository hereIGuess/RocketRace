#pragma once
#include "ofGraphics.h"
#include "point.h"

extern Point screen;

class Asteroid {
private:
	int direction;
	int speed;
	Point position;
	int randomYPos;

public:
	int size = 10;

	Point getPosition() {
		return position;
	}

	Asteroid() {
		do {
			direction = floor(ofRandom(-1, 2));
		} while (direction == 0);

		speed = ofRandom(1, 8);

		speed *= direction;

		randomYPos = floor(ofRandom(10, screen.y - 40));

		if (direction == -1) {
			position = Point{(int)screen.x + size, randomYPos};
		} else if (direction == 1) {
			position = Point{ 0 - size, randomYPos };
		}
	}

	void move() {
		position.x += speed;
	}

	bool checkForDeletion() {
		if (direction == -1) {
			if (position.x < 0 - size * 2) return true;
		} else if (direction == 1) {
			if (position.x > screen.x + size * 2) return true;
		}

		return false;
	}

	void render() {
		ofDrawRectangle(position.x, position.y, size, size);
	}
};
