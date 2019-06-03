#ifndef TIMER_H
#define TIMER_H

	#include "include.h"
	
	class Timer
	{
	public:
		// CTOR DTOR
		Timer();
		~Timer();
		// METHOD
		void	start();
		void	pause();
		void	unpause();
		void	stop();
		// GETTER SETTER
		int		getTicks();
		bool	isPaused();
		bool	isStarted();
	private:
		float		startTicks;
		float		pausedTicks;
		bool	paused;
		bool	started;
	};

#endif /* !TIMER_H */