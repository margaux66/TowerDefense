#ifndef DEF_WAVE_H
#define DEF_WAVE_H

//include
#include "include.h"
#include "tower.h"

using namespace std;

class Wave {

//Méthodes
public:
	Wave(); //constructeur
	~Wave(); //destructeur

	// Getters //
    int getCountWave(){ return countWave;} //compteur des vagues de monstres
    vector<Monster> getMonsters(){ return monsters;} //creation des monstres de la vague
	
	// Setters //
    void setCountWave(int newCountWave){ countWave = newCountWave; } //incrementer le compteur des vagues de monstres
    void setMonsters(vector<Monster> newMonsters){ monsters = newMonsters; } //incrementer la creation des monstres

    void create_wave(); //creation de la vague

//Attributs
private:
	int countWave = 0;
	vector<Monster> monsters;
};

#endif /* WAVE_H */
