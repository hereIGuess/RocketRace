#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofSetRectMode(OF_RECTMODE_CENTER);

	menuMusic.load("Sounds/menu.mp3");
	menuMusic.setLoop(true);
	menuMusic.play();

	gameMusic.load("Sounds/background.mp3");
	gameMusic.setLoop(true);
	gameMusic.setVolume(0.5f);
}

//--------------------------------------------------------------
void ofApp::update() {
	//only update when title screen is not active
	if (!titleScreen.getTitle()) {
		//if the timer has finished, check who won
		if (timer.getGameState()) {
			winner.compareScores(player1.getScore(), player2.getScore());
			return;
		}

		timer.countDown();

		player1.move();
		player2.move();

		for (int a = 0; a < asteroids.size(); a++) {
			//check if asteroid has collided with either player
			player1.checkCollision(asteroids[a]);
			player2.checkCollision(asteroids[a]);

			asteroids[a].move();

			//check if the asteroid is off the screen
			if (asteroids[a].checkForDeletion()) {
				//if it is, remove it from the array and add a new one
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

		//set the rectMode to corner for math reasons
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
	//when the title screen is active...
	if (titleScreen.getTitle()) {
		//check if color should change
		//p1Color.checkForColorChange(key);
		//p2Color.checkForColorChange(key);

		//check if the game should start (both players ready)
		if (titleScreen.checkGameStart(key)) {
			timer.reset();

			player1.reset();
			player2.reset();

			//resize the asteroids array to 0 and add new asteroids
			asteroids.resize(0);
			for (int x = 0; x < asteroidsOnScreen; x++) {
				Asteroid asteroid = Asteroid();
				asteroids.push_back(asteroid);
			}

			menuMusic.stop();
			gameMusic.play();
		}
	}

	//if the timer is done, the title isn't active, and a player has pressed SPACE
	if (timer.getGameState() && !titleScreen.getTitle() && key == 32) {
		//change background music and reset the title screen
		gameMusic.stop();
		menuMusic.play();
		titleScreen.reset();
		return;
	}

	//move players in correct direction if the correct input is pressed
	if (key == p1UpButton || key == p1DownButton) player1.direction(key);
	if (key == p2UpButton || key == p2DownButton) player2.direction(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//check if the player should continue moving
	player1.checkMoving(key);
	player2.checkMoving(key);
}