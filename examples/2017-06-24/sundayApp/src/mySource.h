#pragma once

#include "ofMain.h"
#include "ofxPiMapper.h"

class mySource : public ofx::piMapper::FboSource{
public:

	void setup();
	void update();
	void randomize();
	void draw();
	
	ofPoint p1;
	ofPoint p2;
	ofPoint p3;
	
	ofPoint s1;
	ofPoint s2;
	ofPoint s3;
	
	ofColor color;
	
	float lastRandomizeTime;
	
};
