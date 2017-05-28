#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	mapper.registerFboSource(source);
	mapper.setup();
	
	stream.printDeviceList();
	stream.setDeviceID(0);
	
	// 0 output channels,
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	stream.setup(this, 0, 2, 44100, 256, 4);
	
	smoothAudioVolume = 0.0f;
	
	oscReceiver.setup(12345);
	
	vector<string> clientIPs;
	clientIPs.push_back("192.168.0.131");
	clientIPs.push_back("192.168.0.129");
	clientIPs.push_back("192.168.0.130");
	
	for(auto i = 0; i < clientIPs.size(); i++){
		oscSenders.push_back(new ofxOscSender);
		oscSenders.back()->setup(clientIPs[i], 12345);
	}
}

void ofApp::update(){
	mapper.update();
	
	// This code is for the one sending only
	
	smoothAudioVolume = smoothAudioVolume / 1.2f;
	
	for(auto i = 0; i < oscSenders.size(); i++){
		ofxOscMessage m;
		m.setAddress("volume");
		m.addFloatArg(smoothAudioVolume);
		oscSenders[i]->sendMessage(m);
	}
	
	// This code is for the one receiving
	
	while( oscReceiver.hasWaitingMessages() ){
		ofxOscMessage message;
		oscReceiver.getNextMessage(message);
		string address = message.getAddress();
		if(address == "volume"){
			smoothAudioVolume = message.getArgAsFloat(0);
		}
	}
	
	source.setRadius(smoothAudioVolume * 1000);
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

void ofApp::mousePressed(int x, int y, int button){
	mapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	mapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	mapper.mouseDragged(x, y, button);
}

void ofApp::audioIn(
	float * inputBuffer,
	int bufferSize,
	int numChannels){
	
	float audioVolume = 0.0f;
	
	for(int i = 0; i < bufferSize * numChannels; i = i + 1){
		audioVolume =
			audioVolume +
			inputBuffer[i] *
			inputBuffer[i];
	}
	
	audioVolume = sqrt(audioVolume);
	audioVolume = audioVolume /
		(float)(bufferSize * numChannels);
	
	if(audioVolume > smoothAudioVolume){
		smoothAudioVolume = audioVolume;
	}
}
