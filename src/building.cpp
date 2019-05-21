#include "../include/building.h"

using namespace std;

Building::Building(){

};

Building::Building(int type_build, SDL_Rect position) : type(type_build), position(position){
	if(type_build ==1){
		textures = IMG_Load("./image/building_1.png");
		cost = 150;
		distance = 50;
		bonus = 1.25;
	}

	else if(type_build ==2){
		textures = IMG_Load("./image/building_2.png");
		cost = 120;
		distance = 50;
		bonus = 1.25;
	}

	else if(type_build ==3){
		textures = IMG_Load("./image/building_3.png");
		cost = 100;
		distance = 50;
		bonus = 1.25;
	}
}

Building::~Building(){

};

SDL_Rect Building::getFrame(){
	return this->current_frame;
}

SDL_Rect Building::getPosition(){
	return this->position;
}

SDL_Rect Building::getBuildPos(){
	return this->buildPos;
}

SDL_Surface* Building::getBTexture(){
	return this->textures;
}

int Building::getType(){
	return this->type;
}

int Building::getCost(){
	return this->cost;
}

int Building::getDistance(){
	return this->distance;
}

float Building::getBonus(){
	return this->bonus;
}

void Building::draw_building(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPushMatrix();
	glScalef(25, 25, 1.f);
	glBegin(GL_LINE_LOOP);
		for(int i=0; i<=300; i++){
			double angle = 2 * M_PI * i / 300;
			double x = cos(angle);

			double y = sin(angle);
			glVertex2d(x,y);
		}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

};

SDL_Surface* getBTexture(int type){
	switch(type){
		case 1:
			return IMG_Load("./image/building_1");
		case 2:
			return IMG_Load("./image/building_2");
		case 3:
			return IMG_Load("./image/building_3");
		default:
			return IMG_Load("./image/building_1");
	}
}


float Building::installation(Tower* tower){
	float install=0;
	if(type ==1){
		install = tower->getDistance() + (tower->getDistance()*1.25);
	}

	else if(type ==2){
		install = tower->getPower() + (tower->getPower()*1.25);
	}

	else if(type ==3){
		install = tower->getSpeed() + (tower->getSpeed()*1.25);
	}

	return install;
}

void Building::colision(vector<Tower> *towers){
	int leftbuild, leftTower;
	int rightbuild, rightTower;
	int topbuild, topTower;
	int bottombuild, bottomTower;

	leftbuild = buildPos.x;
	rightbuild = buildPos.x + buildPos.w;
	topbuild = buildPos.y;
	bottombuild = buildPos.y + buildPos.h;

	for(vector<Tower>::iterator tower = towers->begin(); tower != towers->end(); ++tower){
		bool interval = true;
		leftTower = tower->getPosition().x;
		rightTower = tower->getPosition().x + SIZEWIND;
		topTower = tower->getPosition().y;
		bottomTower = tower->getPosition().y + SIZEWIND;

		if(bottombuild <= topTower)
			interval = false;
		if(topbuild >= bottomTower)
			interval = false;
		if(rightbuild <= leftTower)
			interval = false;
		if(leftbuild >= rightTower)
			interval = false;

		if(interval){
			buildPos.y = position.y + (SIZEWIND/2);
			switch(type){
				case 1:
					tower->getDistance() + this->installation(&(*tower));
					break;
				case 2:
					tower->getPower() + this->installation(&(*tower));
					break;
				case 3:
					tower->getSpeed() + this->installation(&(*tower));
					break;
			}
		}
	}
}

int Building::cost_building(int type){
	switch(type){
		case 1:
			return 150;
		case 2:
			return 120;
		case 3:
			 return 100;
		default:
			return 100;
	}
}