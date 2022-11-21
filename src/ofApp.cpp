#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofSetRectMode(OF_RECTMODE_CENTER);

	menu.load("Sounds/menu.mp3");
	menu.setLoop(true);
	menu.play();

	background.load("Sounds/background.mp3");
	background.setLoop(true);
	background.setVolume(0.5f);
}

//--------------------------------------------------------------
void ofApp::update() {
	if (!titleScreen.getTitle()) {
		if (timer.getGameState()) {
			winner.compareScores(player1.getScore(), player2.getScore());
			return;
		}

		timer.countDown();

		player1.move();
		player2.move();

		for (int a = 0; a < asteroids.size(); a++) {
			player1.checkCollision(asteroids[a]);
			player2.checkCollision(asteroids[a]);

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
		ofSetColor(20);
		ofDrawRectangle(screen.x / 2, screen.y / 2, screen.x, screen.y);

		ofSetColor(255);
		player1.render();
		player2.render();

		for (auto& a : asteroids) {
			a.render();
		}

		ofSetRectMode(OF_RECTMODE_CORNER);
		timer.render();

		ofSetRectMode(OF_RECTMODE_CENTER);
		if (timer.getGameState()) {
			winner.render();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (titleScreen.getTitle()) {
		if (titleScreen.checkGameStart(key)) {
			timer.reset();

			asteroids.resize(0);
			for (int x = 0; x < asteroidsOnScreen; x++) {
				Asteroid asteroid = Asteroid();
				asteroids.push_back(asteroid);
			}

			player1.reset();
			player2.reset();

			menu.stop();
			background.play();
		}
	}

	if (timer.getGameState() && !titleScreen.getTitle() && key == 32) {
		background.stop();
		menu.play();
		titleScreen.reset();
		return;
	}

	if (key == p1UpButton || key == p1DownButton) player1.direction(key);

	if (key == p2UpButton || key == p2DownButton) player2.direction(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	player1.checkMoving(key);
	player2.checkMoving(key);
}