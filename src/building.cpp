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
	SDL_FreeSurface(this->getBTexture());
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

void Building::draw_building(GLuint texture){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glScalef(10, 10, 1.f);
		drawCircle(1);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	
};

float Building::installation(Tower* tower){
	float install=0;
	if(this->getType() ==1){
		install = tower->getDistance() + (tower->getDistance()*1.25);
		tower->setDistance(install);
	}

	else if(this->getType() ==2){
		install = tower->getPower() + (tower->getPower()*1.25);
		tower->setPower(install);
	}

	else if(this->getType() ==3){
		install = tower->getSpeed() + (tower->getSpeed()*1.25);
		tower->setSpeed(install);
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
			this->installation(&(*tower));
		}
	}
}

