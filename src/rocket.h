#pragma once

#include "asteroid.h"
#include "score.h"

extern Point screen;

class Rocket {
private:
	enum class Direction { up, down, still };
	Direction movement;
	ofImage rocket = ofImage("Images/spaceship.png");
	ofSoundPlayer crash;
	int up;
	int down;
	Score score = Score(0, Point{0, 0});

public:
	//turn these into getters
	int size = 15;
	Point position;

	Score getScore() {
		return score;
	}

	Rocket(int upButton, int downButton, int xPos) {
		up = upButton;
		down = downButton;
		position = { xPos, screen.y - size / 2 };
		movement = Direction::still;

		score = Score(0, Point{ position.x, position.y + size * 2});

		crash.load("Sounds/hit.mp3");
	}

	void move() {
		if (movement == Direction::still) return;

		if (movement == Direction::down && position.y <= screen.y - size) {
			position.y += 5;
		}
		else if (movement == Direction::up && position.y >= size / 2) {
			//put inside here because otherwise the player could reach top
			//then move downwards and still get a point (which isn't right)
			if (position.y <= size / 2 + 1) increaseScore();

			position.y -= 5;
		}
	}

	void increaseScore() {
		respawnPlayer();
		score.increaseScore();
	}

	void respawnPlayer() {
		position.y = screen.y - size / 2;
	}

	void reset() {
		respawnPlayer();
		score.reset();
	}

	void checkCollision(Asteroid asteroid) {
		Point asteroidPosition = asteroid.getPosition();

		if (asteroidPosition.x - asteroid.size / 2 <= position.x + size / 2 &&
			asteroidPosition.y - asteroid.size / 2 <= position.y + size / 2 &&
			asteroidPosition.x + asteroid.size / 2 >= position.x - size / 2 &&
			asteroidPosition.y + asteroid.size / 2 >= position.y - size / 2) {

			crash.play();
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
		rocket.draw(position.x, position.y);

		score.render();
	}
};
