#include "SpriteSheet.h"

void SpriteSheet::setup(){
	image.load("spritesheet.png");
	numFrames = 5;
	currentFrame = 0;
	isPlaying = true;
}

void SpriteSheet::update(){
	if(isPlaying == true){
		currentFrame = currentFrame + 1;
		if(currentFrame >= numFrames){
			currentFrame = 0;
		}
	}
}

void SpriteSheet::draw(int width, int height){
	int h = image.getHeight();
	int w = image.getWidth() / numFrames;
	int x = w * currentFrame;
	int y = 0;

	image.drawSubsection(0, 0, width, height,
						 x, y, w, h);
}

void SpriteSheet::play(){
	isPlaying = true;
}

void SpriteSheet::stop(){
	isPlaying = false;
}
