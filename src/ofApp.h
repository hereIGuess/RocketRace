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

		//create player1
		int p1UpButton = 119;
		int p1DownButton = 115;
		//Colors p1Color = Colors(97, 100);
		Rocket player1 = Rocket(p1UpButton, p1DownButton, screen.x / 4);

		//create player2
		int p2UpButton = 57357;
		int p2DownButton = 57359;
		//Colors p2Color = Colors(57356, 57358);
		Rocket player2 = Rocket(p2UpButton, p2DownButton, screen.x - screen.x / 4);

		//create title screen
		Title titleScreen = Title(p1UpButton, p2UpButton);

		//create asteroids
		std::vector<Asteroid> asteroids;
		const int& asteroidsOnScreen = 15;

		//create timer
		Timer timer = Timer(120);
		
		//create winner
		Winner winner = Winner();

		//create music
		ofSoundPlayer menuMusic;
		ofSoundPlayer gameMusic;
};
