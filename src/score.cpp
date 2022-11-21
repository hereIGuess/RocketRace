#include "score.h"

Point Score::getPosition() {
	return position;
}

int Score::getScore() {
	return score;
}

Score::Score(int score, Point position) {
	this->score = score;
	this->position = Point{ position.x, position.y };

	//could not get the font to load
	//myFont.load("cour.tff", 24);
}

void Score::increaseScore() {
	score++;
}

void Score::reset() {
	score = 0;
}

void Score::render() {
	ofDrawBitmapString(std::to_string(score), position.x - std::to_string(score).size() * 4, position.y);
	
	//myFont.drawString(std::to_string(score), position.x, position.y);
}
