#ifndef DEF_MONSTER_H
#define DEF_MONSTER_H

#include "include.h"

enum DirectMonster { UP, RIGHT, DOWN, LEFT};

class Monster {
	//Méthodes
public:
	Monster();
	~Monster();

	void create_monster(int type_monster, int time);

	void draw_monster();

	void update_monster();

	void dead_monster();

	SDL_Rect getFrame();
	SDL_Rect getPosition();
	SDL_Surface *getMTexture();
	int getLife();
	void setLife(int new_life);
	int getType();
	int getVelocity();
	int getResist();
	int getMoney();
	void setMoney(int new_money);

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