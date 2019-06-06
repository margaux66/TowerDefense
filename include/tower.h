#ifndef DEF_TOWER_H
#define DEF_TOWER_H

//include
#include "include.h"
#include "monster.h"
#include "utils.h"

using namespace std;

class Tower{
	
	//Méthodes
public:
	Tower(); //constructeur
	Tower(int type_tower, SDL_Rect position, int time); //parametre des tours
	~Tower(); //destrcuteur

	void draw_tower(GLuint texture); //dessin de la tour
	void fire(int time); //tir des tours
	int touch(Monster* monster); //toucher un monstre
	void colision(std::vector<Monster> *monsters); //gestion des collisions
	void informations(); //informations sur les tours : type, cadence, puissance, portee

	//getters
	SDL_Rect getFrame();
	SDL_Rect getPosition();
	SDL_Surface *getTTexture();
	SDL_Rect getFirePos();
	int getType();
	int getCost();
	float getPower();
	float getDistance();
	float getSpeed();
	string getName();
	
	//setters
	void setPosition(SDL_Rect newPosition){ position = newPosition;}
	void setDistance(float newDistance){ distance = newDistance;}
	void setPower(float newPower){ power = newPower;}
	void setSpeed(float newSpeed){ speed = newSpeed;}
	
	//Attributs
private:
	SDL_Rect current_frame;
	SDL_Rect position;
	SDL_Surface *textures;
	SDL_Rect firePos;
	int type;
	int cost;
	float power;
	float distance;
	float speed;
	int timer;	
	string name;
};

#endif /* TOWER_H */
