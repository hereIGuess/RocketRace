#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "point.h"

class Asteroid {
private:
	int direction;
	int speed;
	Point position;
	int randomYPos;
	ofVec2f movement;

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

		randomYPos = floor(ofRandom(10, 400));

		if (direction == -1) {
			position = Point{ofGetWindowWidth() - size, randomYPos};
		}
		else if (direction == 1) {
			position = Point{ 0, randomYPos };
		}
		else {
			std::cout << "something broke";
		}
	}

	void move() {
		position.x += speed;
	}

	void render() {
		ofDrawRectangle(position.x, position.y, size, size);
	}
};
