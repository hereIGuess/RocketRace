#pragma once

#include "ofMain.h"
#include "ofVec2f.h"
#include "rocket.h"
#include "asteroid.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int player1UpButton = 119;
		int player1DownButton = 115;
		Rocket player1 = Rocket(20, player1UpButton, player1DownButton, ofVec2f(120, 500 - 40));

		//int player2UpButton = 57357;
		//int player2DownButton = 57359;
		//Rocket player2 = Rocket(20, player2UpButton, player2DownButton, ofVec2f(370, 500 - 40));

		//Asteroid asteroid = Asteroid();
		vector<Asteroid> asteroids;

		ofRectMode(CENTER);
};
