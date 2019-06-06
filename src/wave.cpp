#include "../include/wave.h"

using namespace std;

Wave::Wave(){
};

Wave::~Wave(){
};

void Wave::create_wave(){
	int i =0;
	SDL_Rect position;
	vector<Monster> wave;
	for(i =0; i<3;i++){
		int randNumb = rand()%(3-1)+1;
		Monster monster;
		position.x = monster.getPosition().x;
		position.y = monster.getPosition().y+(10-i);
		monster.setPosition(position);
		monster.create_monster(randNumb,0);
		wave.push_back(monster);
	}
	this->setCountWave(this->getCountWave()+1);
	this->setMonsters(wave);
};
