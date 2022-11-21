#pragma once
#include <ofImage.h>
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofSoundPlayer.h"

class Title {
private:
	//to see if title is active or not
	bool title;

	//image
	ofImage largeRocket = ofImage("Images/largeSpaceship.png");

	//player 1 variables
	bool p1Ready;
	int p1ReadyButton;
	ofImage p1Image = largeRocket;

	//player 2 variables
	bool p2Ready;
	int p2ReadyButton;
	ofImage p2Image = largeRocket;

	//sound effect
	ofSoundPlayer ready;

public:
	bool getTitle();

	Title(int p1UpButton, int p2UpButton);

	void reset();

	bool checkGameStart(int key);

	void render();
};
