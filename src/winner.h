#pragma once
#include <string>

#include "ofGraphics.h"
#include "point.h"
#include "score.h"

class Winner {
private:
	int player1Score;
	//int player2Score;
	Point position;
	std::string winnerText;

public:
	Winner(Score score1) {
		compareScores(score1);
	}

	void compareScores(Score score1) {
		//instead of 1 insert player 2's score
		if (score1.getScore() > 1) {
			position = Point{ score1.getPosition().x, score1.getPosition().y + 20 };
			winnerText = "Player 1 wins!";
		} else if (score1.getScore() < 1) {
			position = Point{ score1.getPosition().x, score1.getPosition().y + 20 };
			winnerText = "Player 2 wins!";
		}
	}

	void render() {
		ofDrawBitmapString(winnerText, position.x, position.y);
	}
};
