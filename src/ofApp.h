#pragma once

#include "ofMain.h"
#include "rocket.h"
#include "asteroid.h"
#include "timer.h"
#include "title.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);

		int player1UpButton = 119;
		int player1DownButton = 115;
		Rocket player1 = Rocket(20, player1UpButton, player1DownButton);

		//int player2UpButton = 57357;
		//int player2DownButton = 57359;

		//Asteroid asteroid = Asteroid();
		vector<Asteroid> asteroids;
		const int& asteroidsOnScreen = 15;

		Timer timer = Timer();

		Title titleScreen = Title();
};
