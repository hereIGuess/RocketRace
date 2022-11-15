#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"

class Asteroid {
private:
	//right now just 1 asteroid
	//needs spawn position
	//needs direction
	//needs collision
	ofVec2f spawnPosition;
	ofVec2f position;

public:
	Asteroid() {
		this->spawnPosition = ofVec2f(0, 0);
	}

	void collision() {

	}

	void move() {

	}

	void render() {
		ofDrawRectangle(spawnPosition.x, spawnPosition.y, 10, 10);
	}
};