#include "ofApp.h"

void ofApp::setup(){
	dataDir.listDir(".");
	dataDir.sort();
	int numImages = dataDir.size();
	ofLog() << "numImages: " << numImages;
	
	for(int i = 0; i < numImages; i = i + 1){
		ofLog() << "- " << dataDir.getName(i);
	}
	
	currentImage = 0;
	if(numImages > 0){
		image.load(dataDir.getName(currentImage));
	}
	
	timer = 0.0f;
}

void ofApp::update(){
	timer = timer + ofGetLastFrameTime();
	if(timer > 5.0f){
		currentImage = currentImage + 1;
		if(currentImage >= dataDir.size()){
			currentImage = 0;
		}
		timer = 0.0f;
		image.load(dataDir.getName(currentImage));
	}
}

void ofApp::draw(){
	if(image.isAllocated()){
		image.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
}
