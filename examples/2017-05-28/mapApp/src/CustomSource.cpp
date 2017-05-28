#include "CustomSource.h"

void CustomSource::setup(){
	allocate(500, 500);
	name = "My Custom Source";
	radius = 0.0f;
}

void CustomSource::update(){
	radius = radius / 2.0f;
}

void CustomSource::draw(){
	ofClear(0, 0, 0, 0);

	ofSetCircleResolution(200);
	ofSetColor( ofColor::magenta );
	ofDrawCircle(
		getWidth() / 2,
		getHeight() / 2,
		radius);
}

void CustomSource::setRadius(float newRadius){
	radius = newRadius;
}
