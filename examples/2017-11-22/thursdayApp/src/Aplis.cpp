#include "Aplis.h"

void Aplis::setup(){
	name = "Aplis";
	allocate(500, 500);
	
	if( json.open("countries.json") ){
		ofLog() << "Datne veiksmīgi ielādēta";
		
		int numCountries = json.size();
		
		for( int i = 0; i < numCountries ; i = i + 1 ){
			ofLog() << json[i].asString();
			iedzSkaits.push_back(100000);
		}
	}
	
	maxIedzSkaits = 100000;
}

void Aplis::update(){

}

void Aplis::draw(){
	ofClear(0, 0, 0, 0);
	
	float fullDegrees = 360.0f;
	float radius = getWidth() / 3.0f;
	float centerX = getWidth() / 2.0f;
	float centerY = getHeight() / 2.0f;
	float angleStep = fullDegrees / (float)json.size();
	
	ofSetColor(ofColor::magenta);
	ofSetLineWidth(2.0f);
	
	for( int i = 0; i < json.size() ; i = i + 1 ){
		float lineAngle = angleStep * (float)i;
		
		ofPushMatrix(); // Saglabājam
		   ofTranslate(centerX, centerY); // Mainam
		   ofRotate(lineAngle, 0, 0, 1);
		   float linGarums = radius * ((float)iedzSkaits[i] / (float)maxIedzSkaits);
		   ofDrawLine(0, 0, linGarums, 0);
		ofPopMatrix(); // Atgriežam atpakaļ
	}
}

void Aplis::addPeople(string country, int amount){
	int countryIndex = -1;
	for(int i = 0; i < json.size(); i = i + 1){
		if(country == json[i].asString()){
			countryIndex = i;
			break;
		}
	}
	
	// Šeit kods turpinās pēc break;
	if(countryIndex > -1){
		iedzSkaits[countryIndex] = iedzSkaits[countryIndex] + amount;
		
		if(iedzSkaits[countryIndex] > maxIedzSkaits){
			maxIedzSkaits = iedzSkaits[countryIndex];
		}
	}
}

void Aplis::remPeople(string country, int amount){
	int countryIndex = -1;
	for(int i = 0; i < json.size(); i = i + 1){
		if(country == json[i].asString()){
			countryIndex = i;
			break;
		}
	}
	
	// Šeit kods turpinās pēc break;
	if(countryIndex > -1){
		iedzSkaits[countryIndex] = iedzSkaits[countryIndex] - amount;
	}
}
