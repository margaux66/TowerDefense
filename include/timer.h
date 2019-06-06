#ifndef TIMER_H
#define TIMER_H

//include
#include "include.h"
	
class Timer {
public:
	Timer(); //constructeur
	~Timer(); //destructeur

// Méthodes
	void start(); //temps de depart
	void pause(); //mettre en pausse : arret du temps
	void unpause(); //enlever la pause : relancer le temps
	void stop(); //arreter le temps
	unsigned int getTicks(); //recuperer la valeur du temps

	//getteurs
	unsigned int getStartTicks(){return startTicks;}
	unsigned int getPausedTicks(){return pausedTicks;}
	bool getPaused(){return paused;}
	bool getStarted(){return started;}

	//seteurs
	void setStartTicks(unsigned int newStartTicks){ startTicks = newStartTicks;}
	void setPausedTicks(unsigned int newPausedTicks){ pausedTicks = newPausedTicks;}
	void setPaused(bool newPaused){ paused = newPaused;}
	void setStarted(unsigned int newStarted){ started = newStarted;}

// Attributs
private:
	unsigned int startTicks= 0;
	unsigned int pausedTicks =0;
	bool paused = false;
	bool started = false;
};

#endif /* !TIMER_H */
