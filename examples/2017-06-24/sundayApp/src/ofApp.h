#pragma once

#include "ofMain.h"
#include "ofxPiMapper.h"
#include "mySource.h"
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
	
	ofxPiMapper mapper;
	mySource source;
	ofxOscReceiver receiver;
	
	vector<ofxOscSender> senders;
	
};
