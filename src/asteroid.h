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


public:
	ofVec2f position;
	int size = 10;

	Asteroid() {
		this->spawnPosition = ofVec2f(125, 40);
		this->position = spawnPosition;
	}

	void move() {

	}

	void render() {
		ofDrawRectangle(spawnPosition.x, spawnPosition.y, size, size);
	}
};