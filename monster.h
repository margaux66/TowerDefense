#ifndef DEF_MONSTER
#define DEF_MONSTER

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define SIZEWIND = 20
#define WINDOW_W = SIZEWIND * 10
#define WINDOW_H = SIZEWIND * 10


enum DirectMonster { UP, RIGHT, DOWN, LEFT};

class Monster {
	//Méthodes
public:
	void create_monster();

	void draw_monster();

	void update_monster();

	void dead_monster();

	SDL_Rect getFrame();
	SDL_Rect getPosition();
	SDL_Surface *getImage();
	int getLife();
	void setLife(int new_life);
	int getType();
	int getVelocity();
	int getResist();
	int getMoney();

	//Attributs
private:

	SDL_Rect current_frame;
	SDL_Rect position;
	SDL_Surface *image;

	int life;
	int type;
	int velocity;
	int resist;
	int money;
};

#endif