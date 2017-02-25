#include "ofApp.h"

void ofApp::setup(){
	ofLog() << "Welcome!";
	ofBackground(ofColor::aliceBlue);
	xPos = 0;
	xPerSecond = 100;
	radius = 20;
}

void ofApp::update(){
	xPerSecond = abs(sin(ofGetElapsedTimef()) * 100);
	float xPerFrame = xPerSecond * ofGetLastFrameTime();
	xPos = xPos + xPerFrame;
	if(xPos > (float)ofGetWidth() + (radius / 2.0f)){
		xPos = -(radius / 2.0f);
	}
}

void ofApp::draw(){
	ofSetColor(ofColor::lightSalmon);
	ofDrawCircle(xPos, ofGetHeight() / 2, radius);
}
