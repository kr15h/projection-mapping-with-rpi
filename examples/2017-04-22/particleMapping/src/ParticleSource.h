#pragma once

#include "ofxPiMapper.h"

class Particle{
public:
	void setup();
	void update();
	void draw();
	
	float x;
	float y;
	float radius;
	int alpha;
	
	// Pixels per second
	float speedX;
	float speedY;
	float speedMultiplier;
	
	ofColor color;
};

class ParticleSource : public ofx::piMapper::FboSource{
public:
	void setup();
	void update();
	void draw();
	void setSpeed(float speed);
	
	vector<Particle> particles;
};
