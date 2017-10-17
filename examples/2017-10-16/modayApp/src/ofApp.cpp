#include "ofApp.h"

void ofApp::setup(){
	ofBackground(ofColor::paleTurquoise);
	cout << "Hola mundo!" << endl;
}

void ofApp::update(){
	cout << "Current frame: " << ofGetFrameNum() << endl;
}

void ofApp::draw(){
	ofSetColor(ofColor::skyBlue);
	ofDrawCircle(ofGetWidth()/2,
				 ofGetHeight()/2,
				 ofGetHeight()/2);

	float framerate = ofGetFrameRate();
	string output = ofToString(framerate);
	ofDrawBitmapString(output, 10, 20);
}
