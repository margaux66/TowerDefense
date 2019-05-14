#include "../include/tower.h"

using namespace std;

Tower::Tower(){

};

Tower::Tower(int type_tower, SDL_Rect position, int time) : type(type_tower), position(position), timer(time){
	if(type_tower ==1){
		textures = IMG_Load("./image/tower_1.png");
		cost = 100;
		power =80;
		distance =50;
		speed =20;
	}

	else if(type_tower ==2){
		textures = IMG_Load("./image/tower_1.png");
		cost = 100;
		power =50;
		distance =20;
		speed =80;
	}

	else if(type_tower ==3){
		textures = IMG_Load("./image/tower_1.png");
		cost = 30;
		power =50;
		distance =10;
		speed =60;
	}

	else if(type_tower ==4){
		textures = IMG_Load("./image/tower_1.png");
		cost = 50;
		power =30;
		distance =65;
		speed =65;
	}

}

Tower::~Tower(){

};

SDL_Rect Tower::getFrame(){
	return this->current_frame;
}

SDL_Rect Tower::getPosition(){
	return this->position;
}

SDL_Rect Tower::getFirePos(){
	return this->firePos;
}

SDL_Surface* Tower::getTexture(){
	return this->textures;
}

int Tower::getType(){
	return this->type;
}

int Tower::getCost(){
	return this->cost;
}

int Tower::getPower(){
	return this->power;
}

int Tower::getDistance(){
	return this->distance;
}

int Tower::getSpeed(){
	return this->speed;
}

void Tower::draw_tower(){
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

SDL_Surface* getTexture(int type){
	switch(type){
		case 1:
			return IMG_Load("./image/tower_1");
		case 2:
			return IMG_Load("./image/tower_2");
		case 3:
			return IMG_Load("./image/tower_3");
		case 4:
			return IMG_Load("./image/tower_4");
		default:
			return IMG_Load("./image/tower_1");
	}
}

void Tower::fire(int time){
	if(time>=timer){
		firePos = getFirePos();
		firePos.x +=2;
		firePos.y +=2;
	}
}

int Tower::touch(Monster* monster){
	int tch=0;
	if(type ==1){
		tch = monster->getResist() - ((this->power*this->distance*this->speed)/3);
	}

	else if(type ==2){
		tch = monster->getResist() - ((this->power*this->distance*this->speed)/3);
	}

	else if(type ==3){
		tch = monster->getResist() - ((this->power*this->distance*this->speed)/3);
	}

	else if(type ==4){
		tch = monster->getResist() - ((this->power*this->distance*this->speed)/3);
	}
	return tch;
}

void Tower::colision(vector<Monster> *monsters){
	int leftFire, leftMonster;
	int rightFire, rightMonster;
	int topFire, topMonster;
	int bottomFire, bottomMonster;

	leftFire = firePos.x;
	rightFire = firePos.x + firePos.w;
	topFire = firePos.y;
	bottomFire = firePos.y + firePos.h;

	for(vector<Monster>::iterator monster = monsters->begin(); monster != monsters->end(); ++monster){
		bool shoot = true;
		leftMonster = monster->getPosition().x;
		rightMonster = monster->getPosition().x + SIZEWIND;
		topMonster = monster->getPosition().y;
		bottomMonster = monster->getPosition().y + SIZEWIND;

		if(bottomFire <= topMonster)
			shoot = false;
		if(topFire >= bottomMonster)
			shoot = false;
		if(rightFire <= leftMonster)
			shoot = false;
		if(leftFire >= rightMonster)
			shoot = false;

		if(shoot){
			firePos.y = position.y + (SIZEWIND/2);
			monster->setLife(monster->getLife()- this->touch(monsters*));
			timer += SDL_GetTicks + 50;
		}
	}
}

int Tower::cost_tower(int type){
	switch(type){
		case 1:
			return 100;
		case 2:
			return 100;
		case 3:
			 return 50;
		case 4:
			return 50;
		default:
			return 50;
	}
}