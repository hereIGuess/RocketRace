#include "asteroid.h"

Point Asteroid::getPosition() {
	return position;
}

int Asteroid::getSize() {
	return size;
}

Asteroid::Asteroid() {
	meteor.load("Images/meteor.png");

	//find what direction the asteroid should go (left or right)
	do {
		direction = floor(ofRandom(-1, 2));
	} while (direction == 0);

	speed = ofRandom(1, 8);

	speed *= direction;

	int randomYPos = floor(ofRandom(10, screen.y - 40));

	//set the position to the correct side of the screen
	if (direction == -1) {
		position = Point{screen.x + size, randomYPos};
	} else if (direction == 1) {
		position = Point{ 0 - size, randomYPos };
	}
}

void Asteroid::move() {
	position.x += speed;
}

bool Asteroid::checkForDeletion() {
	//check what direction the asteroid is going and if it is out of bounds return true
	if (direction == -1) {
		if (position.x < 0 - size * 2) return true;
	} else if (direction == 1) {
		if (position.x > screen.x + size * 2) return true;
	}

	return false;
}

void Asteroid::render() {
	meteor.draw(position.x, position.y);
}
