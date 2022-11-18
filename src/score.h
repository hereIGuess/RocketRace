#pragma once
#include "ofTrueTypeFont.h"
#include "point.h"

class Score {
private:
	int score;
	Point position;
	ofTrueTypeFont myFont;

public:
	Score(int score, Point position) {
		this->score = score;
		this->position = position;

		//myFont.load("cour.tff", 24);
	}

	void setScore() {
		score++;
	}
	
	void render() {
		//ofDrawBitmapString(std::to_string(score), position.x, position.y);
		//myFont.drawString(std::to_string(score), position.x, position.y);
	}
};
