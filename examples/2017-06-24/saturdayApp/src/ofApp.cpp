#include "ofApp.h"

void ofApp::setup(){
	ofBackground(ofColor::black);
}

void ofApp::update(){
	
}

void ofApp::draw(){
	
	ofSetColor(ofColor::magenta);
	
	ofSetLineWidth(5);
	
	float y = sin( ofGetElapsedTimef() ) * (ofGetHeight() / 2);

	ofDrawLine(
		0, ofGetHeight() / 2 + y,
		ofGetWidth(), ofGetHeight() / 2 + y);
}
