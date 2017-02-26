#pragma once

#include "ofxPiMapper.h"

class SlideshowSource :
	public ofx::piMapper::FboSource{
	public:
		void setup();
		void update();
		void draw();
		void relistDir();
	
		ofDirectory imageDir;
		
		ofImage currImage;
		ofImage nextImage;
		
		int getNextImageIndex();
		int currImageIndex;
		int alpha;
		
		float timer;
		float dirTimer;
		
		bool fading;
		bool hasChanged();
		
		map<string, unsigned int> currFiles;
};
