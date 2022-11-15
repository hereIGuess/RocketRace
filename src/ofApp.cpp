#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
	player1.move();
	//player2.move();

	player1.checkCollision(asteroid);
}

//--------------------------------------------------------------
void ofApp::draw(){
	player1.render();

	asteroid.render();
	//player2.render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == player1UpButton || key == player1DownButton) player1.direction(key);

	//if (key == player2UpButton || key == player2DownButton) player2.direction(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	player1.checkMoving(key);
	//player2.checkMoving(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
