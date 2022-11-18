#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	for (int x = 0; x < asteroidsOnScreen; x++) {
		Asteroid asteroid = Asteroid();
		asteroids.push_back(asteroid);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if (titleScreen.getTitle()) {
		titleScreen.update();
	} else if (!titleScreen.getTitle()) {
		if (timer.getGameState()) {
			titleScreen = Title();
			return;
		}

		timer.countDown();

		player1.move();
		//player2.move();

		for (int a = 0; a < asteroids.size(); a++) {
			player1.checkCollision(asteroids[a]);

			asteroids[a].move();

			if (asteroids[a].checkForDeletion()) {
				asteroids.erase(asteroids.begin() + a);

				Asteroid asteroid = Asteroid();
				asteroids.push_back(asteroid);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	if (titleScreen.getTitle()) {
		titleScreen.render();
	}
	else if (!titleScreen.getTitle()) {
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofSetColor(20);
		ofDrawRectangle(screen.x / 2, screen.y / 2, screen.x, screen.y);

		ofSetColor(255);
		player1.render();
		//player2.render();

		for (auto a : asteroids) {
			a.render();
		}

		ofSetRectMode(OF_RECTMODE_CORNER);
		timer.render();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (titleScreen.getTitle()) {
		titleScreen.checkGameStart(key);
	}

	if (key == player1UpButton || key == player1DownButton) player1.direction(key);

	//if (key == player2UpButton || key == player2DownButton) player2.direction(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	player1.checkMoving(key);
	//player2.checkMoving(key);
}