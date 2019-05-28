#include "../include/wave.h"

using namespace std;

void Wave::create_wave(){
	int i =0;
	vector<Monster> wave;
	for(i =0; i<10;i++){
		int randNumb = rand()%(3-1)+1;
		Monster monster;
		monster.create_monster(randNumb);
		wave.push_back(monster);
	}
	this->setCountWave(i);
	this->setMonsters(wave);


}

