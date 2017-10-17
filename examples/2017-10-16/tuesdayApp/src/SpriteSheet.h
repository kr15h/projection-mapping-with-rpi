#pragma once

#include "ofMain.h"

class SpriteSheet{
public:
	void setup();
	void update();
	void draw(int width, int height);
	
	void play();
	void stop();
	
	ofImage image;
	bool isPlaying;
	int numFrames;
	int currentFrame;
};
