#ifndef DEF_IMAGE_H
#define DEF_IMAGE_H

#include "include.h"

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Color3ub;

typedef struct {
	float x;
	float y;
} Position;

typedef struct {
	float x;
	float y;
	float z;
} Vector3;

typedef struct _node{
	Color3ub color, path;
	Position coord;
	struct _node* next;
} Node;

void freeList(Node** node);

GLuint loadTexture(SDL_Surface* tex);

SDL_Surface* loadImage(const char* image);

void deleteImage(SDL_Surface* tex);

void deleteTexture(GLuint image);

void GetPixel(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a);

#endif
