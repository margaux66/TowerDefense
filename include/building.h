#ifndef DEF_BUILDING_H
#define DEF_BUILDING_H

#include "include.h"
#include "utils.h"
#include "tower.h"

class Building{
	//Méthodes
public:
	Building();
	Building(int type_building, SDL_Rect position);
	~Building();

	void draw_building(GLuint texture);
	float installation(Tower* tower);
	void colision(std::vector<Tower> *towers);
	int cost_building(int type);


	SDL_Rect getFrame();
	SDL_Rect getPosition();
	SDL_Surface *getBTexture();
	SDL_Rect getBuildPos();
	int getType();
	int getCost();
	int getDistance();
	float getBonus();

	//Attributs
private:
	SDL_Rect current_frame;
	SDL_Rect position;
	SDL_Surface *textures;
	SDL_Rect buildPos;
	int type;
	int cost;
	int distance;
	float bonus;
};

#endif