#include "../include/monster.h"

using namespace std;

Monster::Monster(){

};

void Monster::create_monster(int type_monster, int time){
	SDL_Rect pos = { -45 , -70};
	if (type_monster == 1){
		textures = IMG_Load("./image/monster_1.png");
		velocity = 1;
		resist = 2;
		money = 5;
		life = 80;
	}

	else if (type_monster == 2){
		textures = IMG_Load("./image/monster_2.png");
		velocity = 2;
		resist = 1;
		money = 7;
		life = 60;
	}
	current_frame = { RIGHT * SIZEWIND, 0, SIZEWIND, SIZEWIND };
	position = pos;
};

Monster::~Monster(){

};

SDL_Rect Monster::getFrame(){
	return this->current_frame;
};

SDL_Rect Monster::getPosition(){
	return this->position;
};

SDL_Surface* Monster::getMTexture(){
	return this->textures;
};

int Monster::getLife(){
	return this->life;
};

void Monster::setLife(int new_life){
	this->life = new_life;
};

int Monster::getType(){
	return this->type;
};

int Monster::getVelocity(){
	return this->velocity;
};

int Monster::getResist(){
	return this->resist;
};

int Monster::getMoney(){
	return this->money;
};
void Monster::setMoney(int new_money){
	this->money += new_money;
}

void Monster::draw_monster(GLuint texture){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glScalef(10, 10, 1.f);
	glBegin(GL_TRIANGLES);
		glColor3ub(255,255,255);
		glTexCoord2f(5.f,1.f);
		glVertex2f(-0.5, 0.5);

		glTexCoord2f(5.f,0.01f);
		glVertex2f(-0.5, -0.5);

		glTexCoord2f(5.f,0.01f);
		glVertex2f(0.5, -0.5);

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

};

void Monster::update_monster(){
	if(wave +=1){
		velocity += 1;
		resist += 1;
		money += 3;
		life += 2;
	}
};

void Monster::dead_monster(){
	if (life==0){
		current_frame.x = -SIZEWIND;
		current_frame.y = 0;
		current_frame.h = SIZEWIND;
		current_frame.w = SIZEWIND;
		life = -1;
	}
};

void Monster::deplacement(int avancee_monster){
	SDL_Rect pos;
	int speed = this->getVelocity();
		if (avancee_monster % speed == 0) {						
			pos.x = this->getPosition().x;
			pos.y = this->getPosition().y;
			if(avancee_monster<42 && avancee_monster>0){
				pos.y += 4;
				this->setPosition(pos);
			}
			if(avancee_monster<78 && avancee_monster>42){
				pos.x += 4;
				this->setPosition(pos);
			}
			if(avancee_monster<115 && avancee_monster>78){
				pos.y += 4;
				this->setPosition(pos);
			}
			
			
			//cout << pos.x << "\n";
			/*if (pos.x<=nodeX){
				pos.x++;
				this->setPosition(pos);
			}
			if(pos.x>=nodeX){
				pos.x--;
				this->setPosition(pos);
			}
			if(pos.y <=nodeY){
				pos.y++;
				this->setPosition(pos);
			}
			if(pos.y >=nodeY){
				pos.y--;
				this->setPosition(pos);
			}*/
		}	
		return;
}
	
