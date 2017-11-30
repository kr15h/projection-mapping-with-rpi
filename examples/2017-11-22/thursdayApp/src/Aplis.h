#pragma once

#include "ofMain.h"
#include "ofxPiMapper.h"
#include "ofxJSON.h"

class Aplis : public ofx::piMapper::FboSource{
public:
	void setup();
	void update();
	void draw();
	
	void addPeople(string country, int amount);
	void remPeople(string country, int amount);
	
	ofxJSONElement json;
	vector<int> iedzSkaits;
	int maxIedzSkaits;
};
