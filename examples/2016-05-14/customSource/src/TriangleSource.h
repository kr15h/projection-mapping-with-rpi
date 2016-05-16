#pragma once

#include "ofMain.h"
#include "FboSource.h"

class TriangleSource : public ofx::piMapper::FboSource {
	public:
		TriangleSource();

		void draw();
};
