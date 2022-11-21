#pragma once
#include "ofGraphics.h"
#include "point.h"
#include "score.h"

extern Point screen;

class Winner {
private:
	Point position;
	std::string winnerText;
	std::string continueText = "Press SPACE to return to title screen";

public:
	Winner();;

	Winner(Score score1);

	void compareScores(Score score1);

	void render();
};
