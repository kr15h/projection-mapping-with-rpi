#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "CustomSource.h"
#include "CrossSource.h"
#include "VideoSource.h"
#include "TriangleSource.h" // Include triangle source h file

class ofApp : public ofBaseApp {
	public:
		void setup();
		void draw();

		ofxPiMapper piMapper;

		// By using a custom source that is derived from FboSource
		// you will be able to see the source listed in sources editor
		CustomSource * customSource;
		CrossSource * crossSource;
		TriangleSource * triangleSource; // Declare a variable for the TriangleSource instance here
};
