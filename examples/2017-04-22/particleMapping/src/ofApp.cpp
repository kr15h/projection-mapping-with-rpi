#include "ofApp.h"

void ofApp::setup(){
	mapper.registerFboSource(source);
	mapper.setup();
	ofBackground(ofColor::black);
	
	#ifdef TARGET_RASPBERRY_PI
		ofSetFullscreen(true);
	#endif
	
	oscReceiver.setup(12345);
}

void ofApp::update(){
	mapper.update();
	
	while(oscReceiver.hasWaitingMessages()){
		ofxOscMessage message;
		oscReceiver.getNextMessage(message);
		if(message.getAddress() == "/speed"){
			float speed = message.getArgAsFloat(0);
			source.setSpeed(speed);
		}
	}
}

void ofApp::draw(){
	mapper.draw();
}

void ofApp::keyPressed(int key){
	mapper.keyPressed(key);
}

void ofApp::keyReleased(int key){
	mapper.keyReleased(key);
}

void ofApp::mouseDragged(int x, int y, int button){
	mapper.mouseDragged(x, y, button);
}

void ofApp::mousePressed(int x, int y, int button){
	mapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	mapper.mouseReleased(x, y, button);
}
