#include "CustomSource.h"

void CustomSource::setup(){
	allocate(500, 500);
	name = "My Custom Source";
	radius = 0.0f;
	
	// For Pedro
	player.load("out.mp4");
	player.setLoopState(OF_LOOP_NORMAL);
	player.setVolume(0.0f);
	player.play();
}

void CustomSource::update(){
	// For Pedro
	player.setPosition(radius / maxRadius);
	player.update();
}

void CustomSource::draw(){
	ofClear(0, 0, 0, 0);

	// For Pedro
	player.draw(0, 0, getWidth(), getHeight());

	ofSetCircleResolution(200);
	ofSetColor( ofColor::magenta );
	ofDrawCircle(
		getWidth() / 2,
		getHeight() / 2,
		radius);
}

void CustomSource::setRadius(float newRadius){
	radius = newRadius;
	if(radius > maxRadius){
		maxRadius = radius;
	}
}
