#include "ofMain.h"
#include "ofApp.h"

//========================================================================
// This function does crazy things
// Do not pass any parameters to it
/*
  THis is a multiline comment. Yes.
*/
int main( ){

	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());

}
