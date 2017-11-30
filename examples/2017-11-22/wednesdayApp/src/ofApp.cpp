#include "ofApp.h"

void ofApp::setup(){
	ofLog() << "Hello One One";
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
}

void ofApp::update(){

}

void ofApp::draw(){
	string text = "FPS: " + ofToString(ofGetFrameRate());
	ofDrawBitmapString(text, 10, 20);
}
