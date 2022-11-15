#pragma once
#include "ofTrueTypeFont.h"
#include "ofVec2f.h"

class Score {
private:
	int score;

	//ofTrueTypeFont myFont;

public:
	ofVec2f position;
	//Score() = default();

	Score(int score, ofVec2f position) {
		this->score = score;
		this->position = position;
		//myFont.load("arial.ttf", 32);
		//myFont.loadFont("arial.ttf", 32);
	}

	void setScore() {
		score++;
	}
	
	void render() {
		ofDrawBitmapString(std::to_string(score), position.x, position.y);
		//myFont.drawString(std::to_string(score), position.x, position.y);
	}
};
