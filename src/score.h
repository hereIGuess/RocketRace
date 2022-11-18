#pragma once
//#include "ofTrueTypeFont.h"
#include "point.h"

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
		//myFont.load("cour.tff", 24, true, true, false, 0.3, 0);
	}

	void setScore() {
		score++;
	}
	
	void render() {
		ofDrawBitmapString(std::to_string(score), position.x, position.y);
	
		//myFont.drawString(std::to_string(score), position.x, position.y);
	}
};
