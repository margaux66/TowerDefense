#ifndef DEF_TOWER_H
#define DEF_TOWER_H

#include "include.h"
#include "monster.h"

class Tower{
	//Méthodes
public:
	Tower();
	Tower(int type_tower, SDL_Rect pos, int time);
	~Tower();

	void draw_tower();
	void fire(int time);
	int touch();
	void colision(std::vector<Monster> *monsters);
	int cost_tower(int type);


	SDL_Rect getFrame();
	SDL_Rect getPosition();
	SDL_Surface *getImage();
	SDL_Rect getFirePos();
	int getType();
	int getCost();
	int getPower();
	int getDistance();
	int getSpeed();

	//Attributs
private:
	SDL_Rect current_frame;
	SDL_Rect getPosition;
	SDL_Surface *image;
	SDL_Rect firePos;
	int type;
	int cost;
	int power;
	int distance;
	int speed;
	int timer	
};

#endif