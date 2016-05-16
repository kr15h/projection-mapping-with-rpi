#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0, 0, 0);
	ofSetLineWidth(10);
	ofDrawLine(0, 0, ofGetWidth(), ofGetHeight());

	float seconds = ofGetElapsedTimef();
	string secondsStr = ofToString(seconds);
	ofDrawBitmapString(secondsStr, 50, 60);

	float fps = ofGetFrameRate();
	string fpsStr = ofToString(fps);
	ofDrawBitmapString(fpsStr, 50, 100);

	float osc = cos(seconds) * 500;
	
	ofPoint center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
	ofPoint p1 = ofPoint(center.x, center.y - osc);
	ofPoint p2 = ofPoint(center.x - osc, center.y + osc/2);
	ofPoint p3 = ofPoint(center.x + osc, center.y + osc/2);
	ofDrawTriangle(p1, p2, p3);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'f'){
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
