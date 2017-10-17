#pragma once

#include "ofMain.h"
#include "SpriteSource.h"
#include "ofxPiMapper.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseDragged(int x, int y, int button);
	
	SpriteSource sheetSource;
	ofxPiMapper mapper;
	ofxOscReceiver osc;
	
	vector<ofxOscSender> senders;
};
