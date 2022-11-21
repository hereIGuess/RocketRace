#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update() {
	if (titleScreen.getTitle()) {
		titleScreen.update();
	} else if (!titleScreen.getTitle()) {
		if (timer.getGameState()) {
			winner = Winner(player1.getScore());
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

		if (timer.getGameState()) {
			winner.render();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (titleScreen.getTitle()) {
		if (titleScreen.checkGameStart(key)) {
			timer = Timer();

			asteroids.resize(0);
			for (int x = 0; x < asteroidsOnScreen; x++) {
				Asteroid asteroid = Asteroid();
				asteroids.push_back(asteroid);
			}

			player1 = Rocket(player1UpButton, player1DownButton);
		}
	}

	if (timer.getGameState() && !titleScreen.getTitle() && key == 32) {
		titleScreen = Title();
		return;
	}

	if (key == player1UpButton || key == player1DownButton) player1.direction(key);

	//if (key == player2UpButton || key == player2DownButton) player2.direction(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	player1.checkMoving(key);
	//player2.checkMoving(key);
}