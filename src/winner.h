#pragma once
#include "ofGraphics.h"
#include "point.h"
#include "score.h"

extern Point screen;

class Winner {
private:
	Point position = Point{0, 0};
	std::string winnerText;
	std::string continueText = "Press SPACE to return to title screen";

public:
	Winner();

	void compareScores(Score score1, Score score2);

	void render();
};
