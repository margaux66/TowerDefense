#ifndef DEF_INCLUDE_H
#define DEF_INCLUDE_H

/* Liste des bibliotheques a inclure pour le projet */
	#include <SDL/SDL.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <SDL/SDL_image.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string>
	#include <iostream>
	#include <cstdlib>
	#include <unistd.h>
	#include <vector>
	#include <fstream>
	#include <sstream>
	#include <math.h>

/* Definition des valeurs necessaires pour le projet */
	#define SIZEWIND 20
	#define WINDOW_W SIZEWIND * 10
	#define WINDOW_H SIZEWIND * 10

	#define EPSILON 2
	#define MAP_WIDTH 200
	#define MAP_HEIGHT 200

#endif /* INCLUDE_H */
