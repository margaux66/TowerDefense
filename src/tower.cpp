#include "../include/tower.h"

using namespace std;

Tower::Tower(){
};

Tower::Tower(int type_tower, SDL_Rect position, int time) : type(type_tower), position(position), timer(time){
	if(type_tower ==1){
		textures = IMG_Load("./image/tower_1.png");
		cost = 100;
		power =80.;
		distance =50.;
		speed =20.;
		name = "Rouge";
	}

	else if(type_tower ==2){
		textures = IMG_Load("./image/tower_2.png");
		cost = 100;
		power =50.;
		distance =20.;
		speed =80.;
		name = "Verte";
	}

	else if(type_tower ==3){
		textures = IMG_Load("./image/tower_3.png");
		cost = 30;
		power =50.;
		distance =10.;
		speed =60.;
		name = "Jaune";
	}

	else if(type_tower ==4){
		textures = IMG_Load("./image/tower_4.png");
		cost = 50;
		power =30.;
		distance =65.;
		speed =65.;
		name = "Bleue";
	}
}

Tower::~Tower(){
	SDL_FreeSurface(this->getTTexture());
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

SDL_Surface* Tower::getTTexture(){
	return this->textures;
}

int Tower::getType(){
	return this->type;
}

int Tower::getCost(){
	return this->cost;
}

float Tower::getPower(){
	return this->power;
}

float Tower::getDistance(){
	return this->distance;
}

float Tower::getSpeed(){
	return this->speed;
}
string Tower::getName(){
	return this->name;
}

void Tower::draw_tower(GLuint texture){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glScalef(10, 10, 1.f);
		drawCircle(1);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

};

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
			monster->setLife(monster->getLife()- this->touch(&(*monster)));
			timer += SDL_GetTicks() + 10;
		}
	}
}

void Tower::informations(){
	cout<<"----------------------------------------------- \n";
	cout << "Information sur la tour : " << this->getName()<<" \n";
	cout <<"Puissance : " << this->getPower()<<"\n";
	cout <<"Cadence : " << this->getSpeed()<<"\n";
	cout <<"Portée : " << this->getDistance()<<"\n";
	cout <<"Coût : " << this->getCost()<<"\n";
	cout<<"----------------------------------------------- \n";
}
