#ifndef DEF_TOWER_H
#define DEF_TOWER_H

#include "include.h"
#include "image.h"
#include "monster.h"

class Tower{
	//Méthodes
public:
	Tower();
	Tower(int type_tower, SDL_Rect position, int time);
	~Tower();

	void draw_tower();
	void fire(int time);
	int touch(Monster* monster);
	void colision(std::vector<Monster> *monsters);
	int cost_tower(int type);


	SDL_Rect getFrame();
	SDL_Rect getPosition();
	SDL_Surface *getTexture();
	SDL_Rect getFirePos();
	int getType();
	int getCost();
	int getPower();
	int getDistance();
	int getSpeed();

	//Attributs
private:
	SDL_Rect current_frame;
	SDL_Rect position;
	SDL_Surface *textures;
	SDL_Rect firePos;
	int type;
	int cost;
	int power;
	int distance;
	int speed;
	int timer;	
};

#endif