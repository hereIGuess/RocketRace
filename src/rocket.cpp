#include "rocket.h"

Score Rocket::getScore() {
	return score;
}

Rocket::Rocket(int upButton, int downButton, int xPos) {
	up = upButton;
	down = downButton;
	position = { xPos, screen.y - size / 2 };

	crash.load("Sounds/hit.mp3");

	movement = Direction::still;

	score = Score(0, Point{ position.x, position.y + size * 2});
}

void Rocket::increaseScore() {
	respawnPlayer();
	score.increaseScore();
}

void Rocket::respawnPlayer() {
	position.y = screen.y - size / 2;
}

void Rocket::reset() {
	respawnPlayer();
	score.reset();
}

void Rocket::move() {
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

void Rocket::checkMoving(int key) {
	if (key == up || key == down) {
		movement = Direction::still;
		keyHeld = false;
	}
}

void Rocket::direction(int key) {
	if (keyHeld) return;

	if (key == up && movement == Direction::still) {
		keyHeld = true;
		movement = Direction::up;
	}
	else if (key == down && movement == Direction::still) {
		keyHeld = true;
		movement = Direction::down;
	}
	else {
		movement = Direction::still;
	}
}

void Rocket::checkCollision(Asteroid asteroid) {
	Point asteroidPosition = asteroid.getPosition();

	//if asteroid hits player, play crash sound and respawn player
	if (asteroidPosition.x - asteroid.getSize() / 2 <= position.x + size / 2 &&
		asteroidPosition.y - asteroid.getSize() / 2 <= position.y + size / 2 &&
		asteroidPosition.x + asteroid.getSize() / 2 >= position.x - size / 2 &&
		asteroidPosition.y + asteroid.getSize() / 2 >= position.y - size / 2) {
		crash.play();
		respawnPlayer();
	}
}

void Rocket::render() {
	rocket.draw(position.x, position.y);

	score.render();
}
