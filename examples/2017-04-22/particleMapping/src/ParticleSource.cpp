#include "ParticleSource.h"

void ParticleSource::setup(){
	name = "Particle Source";
	allocate(500, 500); // Relates to getWidth(), getHeight()
	
	for(auto i = 0; i < 10; i = i + 1){
		particles.push_back(Particle());
		particles.back().setup();
	}
}

void ParticleSource::update(){
	for(auto i = 0; i < particles.size(); i = i + 1){
		particles[i].update();
	}
	
	if(ofRandomf() > 0.5f){
		particles.push_back(Particle());
		particles.back().setup();
	}
	
	for(auto i = 0; i < particles.size(); i = i + 1){
		ofRectangle canvasRect = ofRectangle(
			-getWidth() / 2,
			-getHeight() / 2,
			getWidth(),
			getHeight());
		
		ofRectangle particleRect = ofRectangle(
			particles[i].x - particles[i].radius,
			particles[i].y - particles[i].radius,
			particles[i].radius * 2,
			particles[i].radius * 2);
		
		if( canvasRect.intersects( particleRect ) == false ){
			particles.erase(particles.begin() + i);
		}
	}
}

void ParticleSource::draw(){
	ofClear(0, 0);
	
	ofPushMatrix();
	ofTranslate(getWidth() / 2, getHeight() / 2);
	for(auto i = 0; i < particles.size(); i = i + 1){
		particles[i].draw();
	}
	ofPopMatrix();
	
	ofDrawBitmapStringHighlight("numParticles: " + ofToString(particles.size()), 10, 20);
}

void ParticleSource::setSpeed(float speed){
	for(auto i = 0; i < particles.size(); i = i + 1){
		particles[i].speedMultiplier = speed;
	}
}

// Particle class method definitions start here

void Particle::setup(){
	x = 0.0f;
	y = 0.0f;
	radius = ofRandom(25.0f, 50.0f);
	alpha = 255;
	
	speedX = ofRandomf() * 50.0f;
	speedY = ofRandomf() * 50.0f;
	speedMultiplier = 1.0f;
	
	color = ofColor::white;
	color.a = alpha;
}

void Particle::update(){
	float deltaX = speedX * ofGetLastFrameTime() * speedMultiplier;
	float deltaY = speedY * ofGetLastFrameTime() * speedMultiplier;
	
	x = x + deltaX;
	y = y + deltaY;
	
	alpha = alpha - 1;
	if(alpha < 0){
		alpha = 0;
	}
	
	color.a = alpha;
}

void Particle::draw(){
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}
