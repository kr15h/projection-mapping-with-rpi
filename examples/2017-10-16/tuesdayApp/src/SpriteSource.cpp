#include "SpriteSource.h"

void SpriteSource::setup(){
	allocate(400, 400);
	name = "Sprite Source";
	sheet.setup();
}

void SpriteSource::update(){
	sheet.update();
}

void SpriteSource::draw(){
	ofClear(0, 0, 0, 0);
	sheet.draw(getWidth(), getHeight());
}
