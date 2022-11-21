#include "score.h"

//gets score's position
Point Score::getPosition() {
	return position;
}

//gets score
int Score::getScore() {
	return score;
}

//score constructor: sets up score and position
Score::Score(int score, Point position) {
	this->score = score;
	this->position = Point{ position.x, position.y };

	//could not get the font to load
	//myFont.load("cour.tff", 24);
}

//increases score by 1
void Score::increaseScore() {
	score++;
}

//resets score to 0
void Score::reset() {
	score = 0;
}

//draws score text
void Score::render() {
	ofDrawBitmapString(std::to_string(score), position.x - std::to_string(score).size() * 4, position.y);
	
	//myFont.drawString(std::to_string(score), position.x, position.y);
}
