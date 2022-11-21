#pragma once

#include "ofSoundPlayer.h"
#include "ofMain.h"
#include "Point.h"
#include "title.h"
#include "rocket.h"
#include "asteroid.h"
#include "timer.h"
#include "winner.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);

		//import images
		ofImage smallRocket = ofImage("Images/spaceship.png");
		ofImage largeRocket = ofImage("Images/spaceship.png");

		//create player1
		int player1UpButton = 119;
		int player1DownButton = 115;
		Rocket player1 = Rocket(player1UpButton, player1DownButton);

		//create player2
		//int player2UpButton = 57357;
		//int player2DownButton = 57359;

		//create title screen
		Title titleScreen = Title(player1UpButton);

		//create asteroids
		vector<Asteroid> asteroids;
		const int& asteroidsOnScreen = 15;

		//create timer
		Timer timer = Timer(120);

		//create winner
		Winner winner = Winner();

		ofSoundPlayer menu;
		ofSoundPlayer background;
		ofSoundPlayer win;
};
