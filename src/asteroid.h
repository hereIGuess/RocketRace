#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"

class Asteroid {
private:
	int direction;
	float speed;
	ofVec2f position;
	int randomYPos;

public:
	int size = 10;

	ofVec2f getPosition() {
		return position;
	}

	Asteroid() {
		this->randomYPos = floor(ofRandom(10, 400));

		if (direction == -1) {
			this->position = ofVec2f(0, randomYPos);
		}
		else if (direction == 1) {
			this->position = ofVec2f(ofGetWindowWidth() - size, randomYPos);
		}
	}

	void move() {

	}

	void render() {
		ofDrawRectangle(position.x, position.y, size, size);
	}
};