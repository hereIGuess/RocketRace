#pragma once
#include <utility>

#include "ofGraphics.h"
#include "score.h"

class Rocket {
private:
	enum class Direction { up, down, still };
	Direction movement;
	int size;
	int yPos;
	bool moving;
	int up;
	int down;
	ofVec2f spawnPosition; //make a point
	Score score = Score(0, ofVec2f(0, 0));
	//image sprite;

public:
	//spawn position is a 2D vector incase I want to add left and right movement
	Rocket(int size, int upButton, int downButton, ofVec2f spawn) {
		this->size = size;
		this->moving = false;
		this->up = upButton;
		this->down = downButton;
		this->spawnPosition = spawn;
		this->yPos = spawnPosition.y;
		this->movement = Direction::still;
		this->score.position = ofVec2f(spawnPosition.x + 5, spawnPosition.y + 35);
	}

	void move() {
		if (movement == Direction::still) return;

		if (movement == Direction::down && yPos < spawnPosition.y) {
			yPos += 5;
		}
		else if (movement == Direction::up && yPos >= 0) {
			//put inside here because otherwise the player could reach 0
			//then move downwards and still get a point (which isn't right)
			if (yPos == 0) increaseScore();

			yPos -= 5;
		}
	}

	void increaseScore() {
		yPos = spawnPosition.y;
		score.setScore();
	}

	void checkMoving(int key) {
		if (key == up || key == down) {
			//moving = false;
			movement = Direction::still;
		}
	}

	void direction(int key) {
		if (key == up && movement == Direction::still) {
			movement = Direction::up;
			//moving = true;
		} else if (key == down && movement == Direction::still) {
			movement = Direction::down;
			//moving = true;
		} else {
			//moving = false;
			movement = Direction::still;
		}
	}

	void render() {
		ofDrawRectangle(spawnPosition.x, yPos, size, size);

		score.render();
	}
};
