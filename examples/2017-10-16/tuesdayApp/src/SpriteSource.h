#pragma once

#include "ofMain.h"
#include "ofxPiMapper.h"
#include "SpriteSheet.h"

class SpriteSource : public ofx::piMapper::FboSource{
public:
	void setup();
	void update();
	void draw();
	
	SpriteSheet sheet;
};
