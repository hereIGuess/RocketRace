#pragma once

#include "asteroid.h"
#include "ofGraphics.h"
#include "score.h"

extern ofVec2f screen;

class Rocket {
private:
	enum class Direction { up, down, still };
	Direction movement;

	int up;
	int down;
	Score score = Score(0, ofVec2f(0, 0));
	//image sprite;

public:
	//turn these into getters
	int size;
	//int yPos;
	ofVec2f position; //make a point

	Rocket(int size, int upButton, int downButton) {
		this->size = size;
		this->up = upButton;
		this->down = downButton;
		this->position = ofVec2f(screen.x / 3, screen.y - size / 2);
		this->movement = Direction::still;

		//instead of rocket moving score, move score according to rocket position
		//this->score.position = ofVec2f(spawnPosition.x, spawnPosition.y + 35);
	}

	void move() {
		if (movement == Direction::still) return;

		if (movement == Direction::down && position.y <= screen.y - size) {
			position.y += 5;
		}
		else if (movement == Direction::up && position.y >= size / 2) {
			//put inside here because otherwise the player could reach top
			//then move downwards and still get a point (which isn't right)
			if (position.y == size / 2) increaseScore();

			position.y -= 5;
		}
	}

	void increaseScore() {
		respawnPlayer();
		score.setScore();
	}

	void respawnPlayer() {
		position.y = screen.y - size / 2;
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
