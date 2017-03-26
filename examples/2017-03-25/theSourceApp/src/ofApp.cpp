#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor::black);
	mapper.registerFboSource(source);
	mapper.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	mapper.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mapper.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'f'){
		ofToggleFullscreen();
	}
	
	mapper.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	mapper.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	// We leave this empty as it is not needed by ofxPiMapper
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	mapper.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mapper.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	mapper.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}