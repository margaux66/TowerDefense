#include "../include/timer.h"

using namespace std; 

Timer::Timer(){
};

Timer::~Timer(){
};

void Timer::start(){
	this->setStarted(true);
	this->setPaused(false);
	this->setStartTicks(SDL_GetTicks());
	cout << SDL_GetTicks()<<"\n";
	cout << this->getStartTicks()/1000;
}


void Timer::pause(){
	if (this->getStarted() && !this->getPaused()){
		this->setPaused(true);
		this->setPausedTicks(SDL_GetTicks() - this->getStartTicks());
	}
}

void Timer::unpause(){
	if (this->getPaused()){
		this->setPaused(false);
		this->setStartTicks(SDL_GetTicks() - this->getPausedTicks());
		this->setPausedTicks(0.);
	}
}


void Timer::stop(){
	this->setStarted(false);
	this->setPaused(false);
}


unsigned int Timer::getTicks(){
	if (getStarted()){
		if (getPaused())
			return this->getPausedTicks();
		else
			return SDL_GetTicks()-this->getStartTicks();
	}
	
	return 0;
}
