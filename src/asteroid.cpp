#include "asteroid.h"

//gets asteroid's position
Point Asteroid::getPosition() {
	return position;
}

//gets asteroid's size
int Asteroid::getSize() {
	return size;
}

//asteroid constructor: finds a random direction, speed, and y position, then sets the asteroid's position
Asteroid::Asteroid() {
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

//move the asteroid
void Asteroid::move() {
	position.x += speed;
}

//checks if the asteroid is off screen
bool Asteroid::checkForDeletion() {
	//check what direction the asteroid is going and if it is out of bounds return true
	if (direction == -1) {
		if (position.x < 0 - size * 2) return true;
	} else if (direction == 1) {
		if (position.x > screen.x + size * 2) return true;
	}

	return false;
}

//draws the asteroid
void Asteroid::render() {
	meteor.draw(position.x, position.y);
}
