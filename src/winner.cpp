#include "winner.h"

//winner contructor: literally does nothing
Winner::Winner() { }

//compares the two player scores and checks whose won
//then it sets the winner text and position to the correct values
void Winner::compareScores(Score p1Score, Score p2Score) {
	//instead of 1 insert player 2's score
	if (p1Score.getScore() > p2Score.getScore()) {
		//player 1 has won
		winnerText = "Player 1 wins!";
		position = Point{ p1Score.getPosition().x - int(winnerText.size() * 4), p1Score.getPosition().y + 30 };
	}
	else if (p1Score.getScore() < p2Score.getScore()) {
		//player 2 has won
		winnerText = "Player 2 wins!";
		position = Point{ p2Score.getPosition().x - int(winnerText.size() * 4), p2Score.getPosition().y + 30 };
	}
	else if (p1Score.getScore() == p2Score.getScore()) {
		//tie
		winnerText = "It was a tie!";
		position = Point{ screen.x / 2 - int(winnerText.size() * 4), p1Score.getPosition().y + 30 };
	}
}

//draws winner and continue text
void Winner::render() {
	ofDrawBitmapString(winnerText, position.x, position.y);

	ofSetColor(150);
	ofDrawRectangle(screen.x / 2, screen.y / 2 - 5, 320, 30);

	ofSetColor(255);
	ofDrawBitmapString(continueText, screen.x / 2 - continueText.size() * 4, screen.y / 2);
}
