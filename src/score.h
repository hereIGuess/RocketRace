#pragma once
#include "ofSoundPlayer.h"
//#include "ofTrueTypeFont.h"

class Score {
private:
	int score;
	Point position;

	//ofTrueTypeFont myFont;

public:
	Point getPosition() {
		return position;
	}

	int getScore() {
		return score;
	}

	Score(int score, Point position) {
		this->score = score;
		this->position = Point{ position.x, position.y};

		//could not get the font to load
		//myFont.load("cour.tff", 24);
	}

	void increaseScore() {
		score++;
	}

	void reset() {
		score = 0;
	}
	
	void render() {
		ofDrawBitmapString(std::to_string(score), position.x - std::to_string(score).size() * 4, position.y);
	
		//myFont.drawString(std::to_string(score), position.x, position.y);
	}
};
