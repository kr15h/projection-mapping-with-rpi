#pragma once

#include "FboSource.h"

class theSource : public ofx::piMapper::FboSource{
	public:
		void setup();
		void update();
		void draw();
	
		ofPoint point;
		ofPoint center;
	
		int width;
		int height;
};
