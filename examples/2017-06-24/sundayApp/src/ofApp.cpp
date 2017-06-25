#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	//ofSetFullscreen(true);
	
	mapper.registerFboSource(source);
	mapper.setup();
	
	 
	
	senders.resize(3);
	senders[0].setup("172.26.2.226", 12345);
	senders[1].setup("172.26.2.209", 12345);
	senders[2].setup("172.26.2.220", 12345);
}

void ofApp::update(){
	mapper.update();
	
	while(receiver.hasWaitingMessages()){
		ofxOscMessage message;
		receiver.getNextMessage(message);
		if(message.getAddress() == "/color"){
			int r = message.getArgAsInt(0);
			int g = message.getArgAsInt(1);
			int b = message.getArgAsInt(2);
			source.color = ofColor(r, g, b);
			source.randomize();
		}
	}
}

void ofApp::draw(){
	mapper.draw();
}

void ofApp::keyPressed(int key){
	mapper.keyPressed(key);
	source.randomize();
	source.color =
		ofColor(
			ofGetMouseX(),
			ofGetMouseY(),
			key);
	
	if(key == ' '){
		ofxOscMessage message;
		message.setAddress("/color");
		message.addIntArg(ofRandom(255));
		message.addIntArg(ofRandom(255));
		message.addIntArg(ofRandom(255));
		
		for(auto i = 0; i < senders.size(); ++i){
			senders[i].sendMessage(message);
		}
	}
}

void ofApp::keyReleased(int key){
	mapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
	mapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	mapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	mapper.mouseDragged(x, y, button);
}
