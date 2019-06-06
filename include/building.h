#ifndef DEF_BUILDING_H
#define DEF_BUILDING_H

//include
#include "include.h"
#include "utils.h"
#include "tower.h"

class Building{
	
//Méthodes
public:
	Building(); //constructeur
	Building(int type_building, SDL_Rect position); //parametre des batiments
	~Building(); //destructeur

	void draw_building(GLuint texture); //dessin dess sprites des batiments
	float installation(Tower* tower); //gestion des ameliorations en fonction du type de tour et de ses parametre
	void colision(std::vector<Tower> *towers); //gestion de la colision avec la tour
	int cost_building(int type); //gestion de l'achat d'un batiment

	//getteurs
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

#endif /* BUILDING_H */
