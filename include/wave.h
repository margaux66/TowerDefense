#ifndef DEF_WAVE_H
#define DEF_WAVE_H

#include "include.h"
#include "tower.h"

using namespace std;

class Wave {
	Wave();
    ~Wave();
	//Méthodes
public:
	/* Getters */
    int getCountWave(){ return countWave;}
    vector<Monster> getMonsters(){ return monsters;}
    /* Setters */
    void setCountWave(int newCountWave){ countWave = newCountWave; }
    void setMonsters(vector<Monster> newMonsters){ monsters = newMonsters; }

    void create_wave();

	//Attributs
private:
	int countWave;
	vector<Monster> monsters;

};

#endif