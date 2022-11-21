#include "title.h"

//gets title
bool Title::getTitle() {
	return title;
}

//title constructor: sets up ready buttons, resets the title screen, and loads the ready sound
Title::Title(int p1Button, int p2Button) {
	ready.load("Sounds/ready.mp3");
	p1ReadyButton = p1Button;
	p2ReadyButton = p2Button;
	colors = Colors();
	reset();
}

//resets the title to its default values
void Title::reset() {
	title = true;
	p1Ready = false;
	p2Ready = false;
}

//checks if both players are ready and if they are, deactivates the title screen
bool Title::checkGameStart(int key) {
	//if W is pressed, set ready to the opposite of it's old state
	if (key == p1ReadyButton) {
		p1Ready = !p1Ready;
		ready.play();
	}

	//if UP is pressed, set ready to the opposite of it's old state
	if (key == p2ReadyButton) {
		p2Ready = !p2Ready;
		ready.play();
	}

	//if both players are ready,  deactivate title and return true
	if (p1Ready && p2Ready) {
		title = false;
		return true;
	}

	//return false because both players aren't ready
	return false;
}

//draws the title screen
void Title::render() {
	//draw title
	ofSetColor(255);
	ofDrawBitmapString("ROCKET RACE", ofGetWindowWidth() / 2 - 50, 50);

	//PLAYER 1'S SPACESHIP:
	ofColor p1Color;
	ofColor p1ButtonColor;
	ofColor p1ButtonTextColor;
	std::string p1ButtonText;

	std::string p1Text = "PLAYER 1";
	std::string p1Controls = "CONTROLS: W & S";
	ofRectangle p1Positioning = ofRectangle(ofGetWindowWidth() / 4, ofGetWindowHeight() / 2 - p1Image.getHeight() / 2, p1Image.getWidth() + 70, p1Image.getHeight() * 2);

	ofSetColor(80);
	ofDrawRectangle(p1Positioning);

	//draw spaceship graphic and text
	ofSetColor(255);
	ofDrawBitmapString(p1Text, p1Positioning.x - p1Text.size() * 4, p1Positioning.y - p1Positioning.getHeight() / 2 + 20);
	ofDrawBitmapString(p1Controls, p1Positioning.x - p1Controls.size() * 4, p1Positioning.y - p1Positioning.getHeight() / 2 + 40);
	p1Image.draw(p1Positioning.x, p1Positioning.y);

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
	ofDrawRectangle(p1Positioning.x, p1Positioning.y + p1Positioning.height / 3 + 10, p1Image.getWidth(), 30);
	ofSetColor(p1ButtonTextColor);
	ofDrawBitmapString(p1ButtonText, p1Positioning.x - p1ButtonText.size() * 4, p1Positioning.y + p1Positioning.height / 3 + 15);
	//END OF PLAYER 1'S SPACESHIP:


	//PLAYER 2'S SPACESHIP:
	ofColor p2ButtonColor;
	ofColor p2ButtonTextColor;
	std::string p2ButtonText;

	std::string p2Text = "PLAYER 2";
	std::string p2Controls = "CONTROLS: UP & DOWN";
	ofRectangle p2Positioning = ofRectangle(ofGetWindowWidth() - ofGetWindowWidth() / 4, ofGetWindowHeight() / 2 - p2Image.getHeight() / 2, p2Image.getWidth() + 70, p2Image.getHeight() * 2);

	ofSetColor(80);
	ofDrawRectangle(p2Positioning);

	//draw spaceship graphic and text
	ofSetColor(255);
	ofDrawBitmapString(p2Text, p2Positioning.x - p2Text.size() * 4, p2Positioning.y - p2Positioning.getHeight() / 2 + 20);
	ofDrawBitmapString(p2Controls, p2Positioning.x - p2Controls.size() * 4, p2Positioning.y - p2Positioning.getHeight() / 2 + 40);
	p2Image.draw(p2Positioning.x, p2Positioning.y);

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
	ofDrawRectangle(p2Positioning.x, p2Positioning.y + p2Positioning.height / 3 + 10, p1Image.getWidth(), 30);
	ofSetColor(p2ButtonTextColor);
	ofDrawBitmapString(p2ButtonText, p2Positioning.x - p2ButtonText.size() * 4, p2Positioning.y + p2Positioning.height / 3 + 15);
	//END OF PLAYER 2'S SPACESHIP


	//draw instructions
	ofSetColor(255);
	std::string instructions = "INSTRUCTIONS: Avoid asteroids and reach\nthe top of the screen to gain points!";
	ofDrawBitmapString(instructions, (ofGetWindowWidth() / 2) - (instructions.size() * 2), ofGetWindowHeight() - 50);

	colors.render();
}
