#pragma once

#include "ofMain.h"
#include "rocket.h"
#include "asteroid.h"
#include "timer.h"
#include "title.h"
#include "winner.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);

		ofImage smallRocket = ofImage("Images/spaceship.png");
		ofImage largeRocket = ofImage("Images/spaceship.png");


		int player1UpButton = 119;
		int player1DownButton = 115;
		Rocket player1 = Rocket(player1UpButton, player1DownButton);

		//int player2UpButton = 57357;
		//int player2DownButton = 57359;

		vector<Asteroid> asteroids;
		const int& asteroidsOnScreen = 15;

		Timer timer = Timer();

		Title titleScreen = Title();

		Winner winner = Winner();
};
