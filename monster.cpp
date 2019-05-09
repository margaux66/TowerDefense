#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "monster.h"

using namespace std;

void Monster::create_monster(){
	SDL_Rect pos = { 22 , 170};
	if (type == 1){
		image = IMG_load(monster_1.png);
		velocity = 1;
		resist = 2
		money = 5;
		life = 80;
	}

	else if (type == 2){
		image = IMG_load(monster_2.png);
		velocity = 2;
		resist = 1;
		money = 7;
		life = 60;
	}
	current_frame = { RIGHT * SIZEWIND, 0, SIZEWIND, SIZEWIND};
	position = pos;
};

SDL_Rect Monster::getFrame(){
	return this->current_frame;
};

SDL_Rect Monster::getPosition(){
	return this->position;
};

SDL_Surface* Monster::getImage(){
	return this->image;
};

int Monster::getLife(){
	return this->life;
};

int Monster::setLife(int new_life){
	this->life = new_life;
};

void Monster::draw_monster(){

};

void Monster::update_monster(){

};

void Monster::dead_monster(){

};

void Monster::delete_monster(){

};