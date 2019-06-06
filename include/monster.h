#ifndef DEF_MONSTER_H
#define DEF_MONSTER_H

#include "include.h"

enum DirectMonster { UP, RIGHT, DOWN, LEFT};

class Monster {
//Méthodes
public:
	Monster();//constructeur
	~Monster();//destructeur

	void create_monster(int type_monster, int time); //créé un monstre

	void draw_monster(GLuint texture); //dessine le monstre

	void update_monster(); //met à jour le monstre en fonction des évênements

	void dead_monster(); //action si le monstres est mort

	void deplacement(int avancee_monster); //déplacement du monstre avec en paramètre la valeur de la boucle

	// Getters//
	SDL_Rect getFrame();
	SDL_Rect getPosition();
	SDL_Surface *getMTexture();
	int getLife();
	int getType();
	int getVelocity();
	int getResist();
	int getMoney();

	//Setters//
	void setMoney(int new_money);
	void setLife(int new_life);
	void setPosition(SDL_Rect newPosition){ position = newPosition;}
	
//Attributs
private:

	SDL_Rect current_frame;
	SDL_Rect position;
	SDL_Surface *textures;

	int life;
	int type;
	int velocity;
	int resist;
	int money = 200;
	int time;
	int wave;
};

#endif