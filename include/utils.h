#ifndef DEF_UTILS_H
#define DEF_UTILS_H

//include
#include "include.h"

void drawCircle(int filled); //dessin cercle = base des tours et batiments

SDL_Surface* loadImage(SDL_Surface* image); //chargement de l'image
GLuint loadTexture(SDL_Surface* tex); //chargement de la texture

#endif /* UTILS_H */
