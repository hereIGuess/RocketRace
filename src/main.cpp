#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(500,500,OF_WINDOW);

	ofGLFWWindowSettings settings;
	settings.setSize(500, 500);
	settings.resizable = false;
	ofCreateWindow(settings);
	return ofRunApp(new ofApp);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
}
