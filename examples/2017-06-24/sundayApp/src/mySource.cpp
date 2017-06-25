#include "mySource.h"

void mySource::setup(){
	name = "My Source";
	allocate(500, 500);
	color = ofColor(250, 200, 150);
}

void mySource::update(){
	p1 = p1 + (s1 * ofGetLastFrameTime());
	p2 = p2 + (s2 * ofGetLastFrameTime());
	p3 = p3 + (s3 * ofGetLastFrameTime());
	
	if(ofGetElapsedTimef() > (lastRandomizeTime + 10)){
		randomize();
	}
}

void mySource::randomize(){
	p1 = ofPoint(
		ofRandom(getWidth()),
		ofRandom(getHeight()));
	
	p2 = ofPoint(
		ofRandom(getWidth()),
		ofRandom(getHeight()));
	
	p3 = ofPoint(
		ofRandom(getWidth()),
		ofRandom(getHeight()));
	
	s1 = ofPoint(
		ofRandom(5, 10),
		ofRandom(5, 10));
	
	s2 = ofPoint(
		ofRandom(5, 10),
		ofRandom(5, 10));
	
	s3 = ofPoint(
		ofRandom(5, 10),
		ofRandom(5, 10));
	
	lastRandomizeTime = ofGetElapsedTimef();
}

void mySource::draw(){
	ofClear(0, 0, 0, 0);
	ofSetColor(color);
	ofDrawTriangle(p1, p2, p3);
}
