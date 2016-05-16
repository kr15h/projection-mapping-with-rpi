#include "TriangleSource.h"

TriangleSource::TriangleSource(){
	name = "Triangle FBO Source";
	allocate(1000, 1000);
}

void TriangleSource::draw(){
	ofClear(0);
	
	// Draw white background as a rectangle that covers
	// the whole area of the FBO source canvas.
	ofSetColor(255, 255, 255);
	ofDrawRectangle(0, 0, 1000, 1000);

	// Draw diognal line. Black.
	ofSetColor(0, 0, 0);
        ofSetLineWidth(10);
        ofDrawLine(0, 0, 1000, 1000);

	// Get amount of secconds our application is running as floating point number.
        float seconds = ofGetElapsedTimef();

	// By using the cosinus function, get a number ranging 
	// between -500.0 and 500.0 for animation.
        float osc = cos(seconds) * 500;

	// Draw a triangle on the screen. The size depends on the osc
	// variable calculated above.
        ofPoint center = ofPoint(1000 / 2, 1000 / 2);
        ofPoint p1 = ofPoint(center.x, center.y - osc);
        ofPoint p2 = ofPoint(center.x - osc, center.y + osc/2);
        ofPoint p3 = ofPoint(center.x + osc, center.y + osc/2);
        ofDrawTriangle(p1, p2, p3);
}
