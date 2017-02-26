#include "SlideshowSource.h"

void SlideshowSource::setup(){
	name = "Slideshow";
	allocate(500, 500);
	
	imageDir.listDir("./images");
	imageDir.sort();
	for(int i = 0; i < imageDir.size(); i++){
		ofLog() << "- " << imageDir.getName(i);
	}
	
	if(imageDir.size() > 0){
		currImageIndex = 0;
	}else{
		currImageIndex = -1;
	}
	
	if(currImageIndex != -1){
		currImage.load(
			"./images/" +
			imageDir.getName(currImageIndex));
	}
	
	timer = 0.0f;
	alpha = 0;
	fading = false;
}

void SlideshowSource::update(){
	timer = timer + ofGetLastFrameTime();
	if(timer > 10.0f){
		timer = 0.0f;
		alpha = 0;
		fading = true;
		currImageIndex = getNextImageIndex();
		nextImage.load(
			"./images/" +
			imageDir.getName(currImageIndex));
		
	}
	
	if(fading == true){
		alpha = alpha + 10;
	}
	if(alpha >= 255){
		fading = false;
		currImage = nextImage;
	}
}

void SlideshowSource::draw(){
	ofClear(0, 0, 0, 0);
	if(currImageIndex == -1){
		return;
	}
	
	if(currImage.isAllocated()){
		currImage.draw(0, 0, getWidth(), getHeight());
	}
	
	if(nextImage.isAllocated()){
		if(fading == true){
			ofSetColor(255, alpha);
			nextImage.draw(0, 0, getWidth(), getHeight());
		}
	}
}

int SlideshowSource::getNextImageIndex(){
	int index = currImageIndex + 1;
	if(index >= imageDir.size()){
		index = 0;
	}
	return index;
}
