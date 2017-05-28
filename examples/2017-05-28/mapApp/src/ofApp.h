#pragma once

#include "ofMain.h"
#include "ofxPiMapper.h"
#include "CustomSource.h"
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
	CustomSource source;
	
	ofSoundStream stream;
	float smoothAudioVolume;
	void audioIn(
		float * inputBuffer,
		int bufferSize,
		int numChannels);
	
	ofxOscReceiver oscReceiver;
	vector<ofxOscSender *> oscSenders;
};
