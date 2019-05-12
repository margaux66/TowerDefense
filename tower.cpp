#include "tower.h"

using namespace std;

Tower::Tower(){

};

Tower::Tower(int type_tower, SDL_Rect pos, int time) : type(type_tower), position(pos), time(timer){
	if(type_tower ==1){
		image = getTexture("image/tower_1.png");
		cost = 100;
		power =80;
		distance =50;
		speed =20;
	}

	else if(type_tower ==2){
		image = getTexture("image/tower_1.png");
		cost = 100;
		power =50;
		distance =20;
		speed =80;
	}

	else if(type_tower ==3){
		image = getTexture("image/tower_1.png");
		cost = 30;
		power =50;
		distance =10;
		speed =60;
	}

	else if(type_tower ==4){
		image = getTexture("image/tower_1.png");
		cost = 50;
		power =30;
		distance =65;
		speed =65;
	}

}

Tower::~Tower(){

}

SDL_Rect Tower::getFrame(){
	return this->current_frame;
}

SDL_Rect Tower::getPosition(){
	return this->position;
}

SDL_Rect Tower::getFirePos(){
	return this->firePos;
}

SDL_Surface* Tower::getImage(){
	return this->image;
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
	glBindTexture(GL_TEXTURE_2D, image);
	glPushMatrix();
	glScalef(size.x, size.y, 1.f);
	glBegin(GL.GL_LINE_LOOP);
		for(int i=0, i<=300, i++){
			double angle = 2 * Math.PI * i / 300;
			double x = Math.cos(angle);
			double y = Math.sin(angle);
			gl.glVertex2d(x,y);
		}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

};

Gluint getTowerText(int type){
	switch(type){
		case 1:
			return getTexture("image/tower_1");
		case 2:
			return getTexture("image/tower_2");
		case 3:
			return getTexture("image/tower_3");
		case 4:
			return getTexture("image/tower_4");
		default:
			return getTexture("image/tower_1");
	}
}

void Tower::fire(int time){
	if(time>=timer){
		firePos = getFirePos();
		firePos.x +=2;
		firePos.y +=2;
	}
}

int Tower::touch(){
	int tch=0;
	if(type ==1){
		tch = monster->resist - type_tower.1((power*distance*speed)/3);
	}

	else if(type ==2){
		tch = monster->resist - type_tower.2((power*distance*speed)/3);
	}

	else if(type ==3){
		tch = monster->resist - type_tower.3((power*distance*speed)/3);
	}

	else if(type ==4){
		tch = monster->resist - type_tower.4((power*distance*speed)/3);
	}
	return tch;
}

int Tower::colision(vector<Monster> *monsters){
	int leftFire, leftMonster;
	int rightFire, rightMonster;
	int topFire, topMonster;
	int bottomFire, bottomMonster;

	leftFire = firePos.x;
	rightFire = firePos.x + fire>w;
	topFire = firePos.y;
	bottomFire = firePos.y + fire->h

	for(vector<Monster>::iterator &monster = monsters->begin(); monster != monsters->end(), ++monster){
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
			firePos.y = pos.y + (SIZEWIND/2);
			monster->setLife(monster->getLife()-tch);
			timer += SDL_GetTicks + 50;
		}
	}
}

int Tower::cost_tower(int type){
	switch(type){
		case 1;
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