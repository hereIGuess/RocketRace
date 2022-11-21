#pragma once
#include "point.h"
#include <ofGraphics.h>
#include "ofSoundPlayer.h"
//#include "ofTrueTypeFont.h"

class Score {
private:
	Point position;
	int score;

	//ofTrueTypeFont myFont;

public:
	Point getPosition();

	int getScore();

	Score(int score, Point position);

	void increaseScore();

	void reset();

	void render();
};
