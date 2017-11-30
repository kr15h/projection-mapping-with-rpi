#include "ofApp.h"

void ofApp::setup(){
	ofBackground(ofColor::black);
	mapper.registerFboSource(tekstura);
	mapper.setup();
	oscIn.setup(54321);
	
	oscOut.resize(7);
	oscOut[0].setup("192.168.0.102", 54321);
	oscOut[1].setup("192.168.0.110", 54321);
	oscOut[2].setup("192.168.0.111", 54321);
	oscOut[3].setup("192.168.0.112", 54321);
	oscOut[4].setup("192.168.0.101", 54321);
	oscOut[5].setup("192.168.0.109", 54321);
	oscOut[6].setup("localhost", 54321);
}

void ofApp::update(){
	mapper.update();
	while(oscIn.hasWaitingMessages()){
		ofxOscMessage message;
		oscIn.getNextMessage(message);
		
		ofLog() << "message received";
		
		if(message.getAddress() == "/immigration"){
			string country = message.getArgAsString(0);
			int amount = message.getArgAsInt(1);
			tekstura.addPeople(country, amount);
		}
		
		if(message.getAddress() == "/emigration"){
			string country = message.getArgAsString(0);
			int amount = message.getArgAsInt(1);
			tekstura.remPeople(country, amount);
		}
	}
	
	
	int randomIndex = (int)ofRandom(tekstura.json.size());
	if(randomIndex >= tekstura.json.size()){
		randomIndex = 0;
	}
	
	ofxOscMessage message;
	
	int emigImmig = ofRandom(2);
	if(emigImmig > 1){
		message.setAddress("/emigration");
	}else{
		message.setAddress("/immigration");
	}
	
	string country = tekstura.json[randomIndex].asString();
	int amount = (int)ofRandom(100000);
	
	message.addStringArg(country);
	message.addIntArg(amount);
	
	ofLog() << amount;
	
	for(int i = 0; i < oscOut.size(); i = i + 1){
		
		oscOut[i].sendMessage(message);
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
