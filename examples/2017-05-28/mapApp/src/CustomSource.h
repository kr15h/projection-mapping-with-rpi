#pragma once

#include "ofMain.h"
#include "FboSource.h"

class CustomSource : public ofx::piMapper::FboSource {
public:
	void setup();
	void update();
	void draw();
	
	void setRadius(float newRadius);
	
	float radius;
	float maxRadius;
	
	// For Pedro
	ofVideoPlayer player;
};
