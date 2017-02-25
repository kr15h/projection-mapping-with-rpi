#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
	
		ofDirectory dataDir;
		ofImage image;
		int currentImage;
		float timer;
};
