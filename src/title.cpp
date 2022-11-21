#include "title.h"

bool Title::getTitle() { return title; }

Title::Title(int p1Button) {
	p1ReadyButton = p1Button;
	reset();
}

void Title::reset() {
	title = true;
	p1Ready = false;
	p2Ready = false;
}

bool Title::checkGameStart(int key) {
	//if W is pressed, set ready to the opposite of it's old state
	if (key == p1ReadyButton) {
		p1Ready = !p1Ready;
	}

	//if UP is pressed, set ready to the opposite of it's old state
	if (key == p2ReadyButton) {
		p2Ready = !p2Ready;
	}

	//if both players are ready,  deactivate title and return true
	if (p1Ready && p2Ready) {
		title = false;
		return true;
	}

	//return false because both players aren't ready
	return false;
}

void Title::render() {
	ofSetColor(255);

	//draw title
	ofDrawBitmapString("ROCKET RACE", ofGetWindowWidth() / 2 - 50, 50);

	//PLAYER 1'S SPACESHIP:
	ofColor p1ButtonColor;
	ofColor p1ButtonTextColor;
	std::string p1ButtonText;
	std::string p1Controls = "CONTROLS: W and S";

	//draw spaceship graphic and text
	ofDrawBitmapString("PLAYER 1", ofGetWindowWidth() / 4 - p1Image.getWidth() / 3, p1Image.getHeight() + 10);
	p1Image.draw(ofGetWindowWidth() / 4 - p1Image.getWidth() / 2, p1Image.getHeight() + 20);
	ofDrawBitmapString(p1Controls, ofGetWindowWidth() / 4 - p1Controls.size() * 4, p1Image.getHeight() * 2 + 40);

	//decide button's colours and text
	if (p1Ready) {
		p1ButtonColor = ofColor(255, 0, 0);
		p1ButtonTextColor = ofColor(255);
		p1ButtonText = "READY";
	} else {
		p1ButtonColor = ofColor(255);
		p1ButtonTextColor = ofColor(255, 0, 0);
		p1ButtonText = "Press W";
	}

	//draw button
	ofSetColor(p1ButtonColor);
	ofDrawRectangle(ofGetWindowWidth() / 4 - p1Image.getWidth() / 2, p1Image.getHeight() * 2 + 50, p1Image.getWidth(), 30);
	ofSetColor(p1ButtonTextColor);
	ofDrawBitmapString(p1ButtonText, ofGetWindowWidth() / 4 - p1ButtonText.size() * 4, p1Image.getHeight() * 2 + 70);
	//END OF PLAYER 1'S SPACESHIP:


	ofSetColor(255);
	//PLAYER 2'S SPACESHIP:
	ofColor p2ButtonColor;
	ofColor p2ButtonTextColor;
	std::string p2ButtonText;
	std::string p2Controls = "CONTROLS: UP and DOWN";

	//draw spaceship graphic and text
	ofDrawBitmapString("PLAYER 2", ofGetWindowWidth() - ofGetWindowWidth() / 4 - p2Image.getWidth() / 3, p2Image.getHeight() + 10);
	p2Image.draw(ofGetWindowWidth() - ofGetWindowWidth() / 4 - p2Image.getWidth() / 2, p2Image.getHeight() + 20);
	ofDrawBitmapString(p2Controls, ofGetWindowWidth() -  ofGetWindowWidth() / 4 - p2Controls.size() * 4, p2Image.getHeight() * 2 + 40);

	//decide button's colours and text
	if (p2Ready) {
		p2ButtonColor = ofColor(255, 0, 0);
		p2ButtonTextColor = ofColor(255);
		p2ButtonText = "READY";
	}
	else {
		p2ButtonColor = ofColor(255);
		p2ButtonTextColor = ofColor(255, 0, 0);
		p2ButtonText = "Press UP";
	}

	//draw button
	ofSetColor(p2ButtonColor);
	ofDrawRectangle(ofGetWindowWidth() - ofGetWindowWidth() / 4 - p2Image.getWidth() / 2, p2Image.getHeight() * 2 + 50, p2Image.getWidth(), 30);
	ofSetColor(p2ButtonTextColor);
	ofDrawBitmapString(p2ButtonText, ofGetWindowWidth() - ofGetWindowWidth() / 4 - p2ButtonText.size() * 4, p2Image.getHeight() * 2 + 70);
	//END OF PLAYER 2'S SPACESHIP


	ofSetColor(255);
	//draw instructions
	std::string instructions = "INSTRUCTIONS: Avoid asteroids and reach\nthe top of the screen to gain points!";
	ofDrawBitmapString(instructions, (ofGetWindowWidth() / 2) - (instructions.size() * 2), ofGetWindowHeight() - 50);
}
