#include "winner.h"

Winner::Winner() { }

Winner::Winner(Score score1) {
	compareScores(score1);
}

void Winner::compareScores(Score score1) {
	//instead of 1 insert player 2's score
	if (score1.getScore() >= 1) {
		//player 1 has won
		winnerText = "Player 1 wins!";
		position = Point{ score1.getPosition().x - int(winnerText.size() * 4), score1.getPosition().y + 30 };
	} else if (score1.getScore() < 1) {
		//player 2 has won
		winnerText = "Player 2 wins!";
		position = Point{ score1.getPosition().x - int(winnerText.size() * 4), score1.getPosition().y + 30 };
	}
}

void Winner::render() {
	ofDrawBitmapString(winnerText, position.x, position.y);

	ofSetColor(150);
	ofDrawRectangle(screen.x / 2, screen.y / 2 - 5, 320, 30);

	ofSetColor(255);
	ofDrawBitmapString(continueText, screen.x / 2 - continueText.size() * 4, screen.y / 2);
}
