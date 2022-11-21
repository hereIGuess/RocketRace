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
	std::string continueText = "Press SPACE to return to title screen";

public:
	Winner() {};

	Winner(Score score1) {
		compareScores(score1);
	}

	void compareScores(Score score1) {
		//instead of 1 insert player 2's score
		if (score1.getScore() >= 1) {
			position = Point{ score1.getPosition().x - 50, score1.getPosition().y + 30 };
			winnerText = "Player 1 wins!";
		} else if (score1.getScore() < 1) {
			position = Point{ score1.getPosition().x - 50, score1.getPosition().y + 30 };
			winnerText = "Player 2 wins!";
		}
	}

	void render() {
		ofDrawBitmapString(winnerText, position.x, position.y);

		ofSetColor(150);
		ofDrawRectangle(screen.x / 5 - 10, screen.y / 2 - 20, 320, 30);

		ofSetColor(255);
		ofDrawBitmapString(continueText, screen.x / 5, screen.y / 2);
	}
};
