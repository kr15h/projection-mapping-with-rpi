#include "SlideshowSource.h"

void SlideshowSource::setup(){
	name = "Slideshow";
	allocate(500, 500);
	
	imageDir.listDir("./images");
	imageDir.sort();
	for(int i = 0; i < imageDir.size(); i++){
		ofLog() << "- " << imageDir.getName(i);
		//ofLog() << "- " << imageDir.getFile(asd)
		ofFile file = imageDir.getFile(i);
		unsigned int fileSize = file.getSize();
		ofLog() << "  " << fileSize;
		currFiles[imageDir.getName(i)] = fileSize;
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
	dirTimer = 0.0f;
	alpha = 0;
	fading = false;
}

void SlideshowSource::update(){
	dirTimer = dirTimer + ofGetLastFrameTime();
	if(dirTimer > 1.0f){
		dirTimer = 0.0f;
		bool dirChanged = hasChanged();
		if(dirChanged){
			ofLog(OF_LOG_WARNING) << "Directory changed";
			relistDir();
		}
	}

	timer = timer + ofGetLastFrameTime();
	if(timer > 5.0f){
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

void SlideshowSource::relistDir(){
	//ofDirectory newDir;
	imageDir.close();
	//imageDir = newDir;
	
	// Populate with freshness
	imageDir.listDir("./images");
	imageDir.sort();
	currFiles.clear();
	for(int i = 0; i < imageDir.size(); i++){
		ofFile file = imageDir.getFile(i);
		currFiles[imageDir.getName(i)] = file.getSize();
	}
}

int SlideshowSource::getNextImageIndex(){
	int index = currImageIndex + 1;
	if(index >= imageDir.size()){
		index = 0;
	}
	return index;
}

bool SlideshowSource::hasChanged(){
	ofDirectory dir;
	dir.listDir("./images");
	dir.sort();
	
	// Check if number of items has changed
	if(dir.size() != imageDir.size()){
		ofLog() << "Number of items differ";
		return true;
	}
	
	// Check if one of the names of the files has changed
	for(int i = 0; i < dir.size(); i++){
		map<string, unsigned int>::iterator it;
		it = currFiles.find(dir.getName(i));
		if(it == currFiles.end()){
			ofLog() << "Name changed";
			return true;
		}
	}
	
	// Check if one of the files has changed its size
	for(int i = 0; i < dir.size(); i++){
		ofFile file = dir.getFile(i);
		if(file.getSize() != currFiles[dir.getName(i)]){
			ofLog() << "Size changed";
			return true;
		}
	}
}
