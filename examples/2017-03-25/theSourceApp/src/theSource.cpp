#include "theSource.h"

void theSource::setup(){
	name = "The Source";
	allocate(500, 500);
}

void theSource::update(){
	width = getWidth();
	height = getHeight();

	center.x = width / 2;
	center.y = height / 2;

	point.x = cos(ofGetElapsedTimef()) * center.x + center.x;
	point.y = sin(ofGetElapsedTimef()) * center.y + center.y;
	
	point.x = point.x + ofRandom(-5, 5);
	point.y = point.y + ofRandom(-5, 5);
}

void theSource::draw(){
	ofClear(0);

	ofPushStyle();
	
	ofSetColor(ofColor::yellow);
	ofDrawRectangle(
		center.x, center.y,
		point.x - center.x,
		point.y - center.y);
	
	ofSetColor(ofColor::fuchsia);
	ofDrawTriangle(
		center.x, center.y,
		width, point.y,
		point.x, height);
	
	ofSetColor(ofColor::aqua);
	ofSetLineWidth(5);
	ofDrawLine(point.x, 0, point.x, height);
	
	ofSetColor(ofColor::orangeRed);
	ofDrawLine(0, point.y, width, point.y);
	
	ofSetColor(ofColor::magenta);
	ofDrawLine(center.x, center.y, point.x, point.y);
	
	ofSetColor(ofColor::black, 150);
	ofDrawCircle(center.x, center.y, 30);
	ofDrawCircle(point.x, point.y, 15);
	
	ofPopStyle();
	
	ofDrawBitmapString(
		"frame num: " + ofToString(ofGetFrameNum()) + "\n" +
		"elap time: " + ofToString(ofGetElapsedTimef()) ,
		10, 20);
}