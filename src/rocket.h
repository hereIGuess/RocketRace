#pragma once

#include "asteroid.h"
#include "ofGraphics.h"
#include "score.h"

class Rocket {
private:
	enum class Direction { up, down, still };
	Direction movement;

	int up;
	int down;
	ofVec2f spawnPosition; //make a point
	Score score = Score(0, ofVec2f(0, 0));
	//image sprite;

public:
	//turn these into getters
	int size;
	//int yPos;
	ofVec2f position; //make a point

	//spawn position is a 2D vector incase I want to add left and right movement
	Rocket(int size, int upButton, int downButton, ofVec2f spawn) {
		this->size = size;
		this->up = upButton;
		this->down = downButton;
		this->spawnPosition = spawn;
		this->position = spawnPosition;
		this->movement = Direction::still;
		this->score.position = ofVec2f(spawnPosition.x, spawnPosition.y + 35);
	}

	void move() {
		if (movement == Direction::still) return;

		if (movement == Direction::down && position.y <= spawnPosition.y + size / 2) {
			position.y += 5;
		}
		else if (movement == Direction::up && position.y >= 0 - size / 2) {
			//put inside here because otherwise the player could reach 0
			//then move downwards and still get a point (which isn't right)
			if (position.y == 0) increaseScore();

			position.y -= 5;
		}
	}

	void increaseScore() {
		respawnPlayer();
		score.setScore();
	}

	void respawnPlayer() {
		position.y = spawnPosition.y;
	}

	void checkCollision(Asteroid asteroid) {
		Point asteroidPosition = asteroid.getPosition();

		if (asteroidPosition.x - asteroid.size / 2 <= position.x + size / 2 &&
			asteroidPosition.y - asteroid.size / 2 <= position.y + size / 2 &&
			asteroidPosition.x + asteroid.size / 2 >= position.x - size / 2 &&
			asteroidPosition.y + asteroid.size / 2 >= position.y - size / 2) {
			respawnPlayer();
		}
	}

	void checkMoving(int key) {
		if (key == up || key == down) {
			movement = Direction::still;
		}
	}

	void direction(int key) {
		if (key == up && movement == Direction::still) {
			movement = Direction::up;
		} else if (key == down && movement == Direction::still) {
			movement = Direction::down;
		} else {
			movement = Direction::still;
		}
	}

	void render() {
		ofDrawRectangle(position.x, position.y, size, size);

		score.render();
	}
};
