#pragma once

#include "ofxPiMapper.h"

class SlideshowSource :
	public ofx::piMapper::FboSource{
	public:
		void setup();
		void update();
		void draw();
	
		ofDirectory imageDir;
		
		ofImage currImage;
		ofImage nextImage;
		
		int getNextImageIndex();
		int currImageIndex;
		int alpha;
		
		float timer;
		
		bool fading;
};
