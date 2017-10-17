#include "ofApp.h"

void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	mapper.registerFboSource(sheetSource);
	mapper.setup();
	osc.setup(12345);
	
	senders.resize(4);
	senders[0].setup("127.0.0.1", 12345);
	senders[1].setup("192.168.0.103", 12345);
	senders[2].setup("192.168.0.102", 12345);
	senders[3].setup("192.168.0.101", 12345);
	
#ifdef TARGET_RASPBERY_PI
	ofSetFullscreen(true);
#endif
}

void ofApp::update(){
	mapper.update();
	if(osc.hasWaitingMessages()){
		ofxOscMessage message;
		osc.getNextMessage(message);
		
		if(message.getAddress() == "/play"){
			sheetSource.sheet.play();
		}
		
		if(message.getAddress() == "/stop"){
			sheetSource.sheet.stop();
		}
		
		if(message.getAddress() == "/frame"){
			int frame = message.getArgAsInt(0);
			sheetSource.sheet.currentFrame = frame;
		}
	}
}

void ofApp::draw(){
	mapper.draw();
}

void ofApp::keyPressed(int key){
	mapper.keyPressed(key);
	
	if(key == 'p'){
		ofxOscMessage message;
		message.setAddress("/play");
		for(auto i = 0; i < senders.size(); i = i + 1){
			senders[i].sendMessage(message);
		}
	}
	
	if(key == 's'){
		ofxOscMessage message;
		message.setAddress("/stop");
		for(auto i = 0; i < senders.size(); i = i + 1){
			senders[i].sendMessage(message);
		}
	}
	
	if(key == '1'){
		ofxOscMessage message;
		message.setAddress("/frame");
		message.addIntArg(0);
		for(auto i = 0; i < senders.size(); i = i + 1){
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

