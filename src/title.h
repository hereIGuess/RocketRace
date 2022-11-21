#pragma once

class Title {
private:
	bool title;
	bool player1Ready;
	int player1UpButton = 119;

	bool player2Ready;
	int player2UpButton = 57357;

	ofImage largeRocket = ofImage("Images/largeSpaceship.png");
	ofImage player1 = largeRocket;
	ofImage player2 = largeRocket;

public:
	bool getTitle() {
		return title;
	}

	Title() {
		title = true;
		player1Ready = false;
		player2Ready = false;
	}

	void update() {
		if (player1Ready && player2Ready) title = false;
	}

	bool checkGameStart(int key) {
		if (key == 119) {
			player1Ready = !player1Ready;
		}

		if (key == 57357) {
			player2Ready = !player2Ready;
		}

		if (player1Ready && player2Ready) return true;
		return false;
	}

	void render() {
		ofSetColor(255);
		ofDrawBitmapString("ROCKET RACE", ofGetWindowWidth() / 2 - 50, 50);

		//PLAYER 1'S SPACESHIP:
		player1.draw(ofGetWindowWidth() / 4 - player1.getWidth() / 2, player1.getHeight());
		ofDrawBitmapString("PLAYER 1", ofGetWindowWidth() / 4 - player1.getWidth() / 3, player1.getHeight() * 2 + 20);


		ofColor p1ButtonColor;
		ofColor p1ButtonTextColor;
		std::string p1ButtonText;

		//decide button's colours and text
		if (player1Ready) {
			p1ButtonColor = ofColor(255, 0, 0);
			p1ButtonTextColor = ofColor(255);
			p1ButtonText = "READY";
		} else {
			p1ButtonColor = ofColor(255);
			p1ButtonTextColor = ofColor(255, 0, 0);
			p1ButtonText = "Press W";
		}

		ofSetColor(p1ButtonColor);
		ofDrawRectangle(ofGetWindowWidth() / 4 - player1.getWidth() / 2, player1.getHeight() * 2 + 30, player1.getWidth(), 30);
		ofSetColor(p1ButtonTextColor);
		ofDrawBitmapString(p1ButtonText, ofGetWindowWidth() / 4 - (p1ButtonText.size() * 4), player1.getHeight() * 2 + 50);


		//PLAYER 2'S SPACESHIP:
		ofColor p2ButtonColor;
		ofColor p2ButtonTextColor;
		std::string p2ButtonText;

		ofSetColor(255);
		player2.draw(ofGetWindowWidth() - ofGetWindowWidth() / 4 - player2.getWidth() / 2, player2.getHeight());
		ofDrawBitmapString("PLAYER 2", ofGetWindowWidth() -  ofGetWindowWidth() / 4 - player2.getWidth() / 3, player2.getHeight() * 2 + 20);

		/*//decide button colour
		if (player2Ready) ofSetColor(255, 0, 0);
		else ofSetColor(255);
		ofDrawRectangle(ofGetWindowWidth() - ofGetWindowWidth() / 4 - player2.getWidth() / 2, player2.getHeight() * 2 + 30, player2.getWidth(), 30);

		//decide button text
		if (player2Ready) {
			ofSetColor(255);
			ofDrawBitmapString("READY", ofGetWindowWidth() - ofGetWindowWidth() / 4 - 20, player2.getHeight() * 2 + 50);
		} else {
			ofSetColor(255, 0, 0);
			ofDrawBitmapString("Press UP", ofGetWindowWidth() - ofGetWindowWidth() / 4 - 30, player2.getHeight() * 2 + 50);
		}*/

		if (player2Ready) {
			p2ButtonColor = ofColor(255, 0, 0);
			p2ButtonTextColor = ofColor(255);
			p2ButtonText = "READY";
		}
		else {
			p2ButtonColor = ofColor(255);
			p2ButtonTextColor = ofColor(255, 0, 0);
			p2ButtonText = "Press UP";
		}

		ofSetColor(p2ButtonColor);
		ofDrawRectangle(ofGetWindowWidth() - ofGetWindowWidth() / 4 - player2.getWidth() / 2, player2.getHeight() * 2 + 30, player2.getWidth(), 30);
		ofSetColor(p2ButtonTextColor);
		ofDrawBitmapString(p2ButtonText, ofGetWindowWidth() - ofGetWindowWidth() / 4 - (p2ButtonText.size() * 4), player2.getHeight() * 2 + 50);
	}
};
