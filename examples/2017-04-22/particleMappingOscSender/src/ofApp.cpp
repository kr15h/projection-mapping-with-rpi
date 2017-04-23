#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	
	senders.push_back(ofxOscSender());
	senders.back().setup("172.26.2.140", 12345);
	
	senders.push_back(ofxOscSender());
	senders.back().setup("172.26.2.75", 12345);
	
	senders.push_back(ofxOscSender());
	senders.back().setup("127.0.0.1", 12345);
}

void ofApp::update(){
	speed = (float)ofGetMouseX() / (float)ofGetWidth() * 10.0f;
	
	for(auto i = 0; i < senders.size(); i++){
		ofxOscMessage message;
		message.setAddress("/speed");
		message.addFloatArg(speed);
		senders[i].sendMessage(message);
	}
}

void ofApp::draw(){
	ofDrawBitmapStringHighlight("speed: " + ofToString(speed), 10, 20);
}
