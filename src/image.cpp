#include "../include/image.h"

void freeNode(Node* node)
{
	if(node == NULL)
		return;

	freeNode(node->next);
	free(node);
}

void freeList(Node** node){
	if(node == NULL || *node == NULL)
		return;

	freeNode(*node);
}

GLuint loadTexture(SDL_Surface* tex){

	GLuint textures;
	glGenTextures(1, &textures);
	
	glBindTexture(GL_TEXTURE_2D, textures);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	GLenum format;
	switch(tex->format->BytesPerPixel) {
		case 1:
			format = GL_RED;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			if(tex->format->Rshift == 16)
				format = GL_BGRA;
			else
				format = GL_RGBA;
			break;
		default:
			fprintf(stderr, "Format des pixels de l’image non pris en charge\n");
			return 0;
	}
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->w, tex->h, 0, format, GL_UNSIGNED_BYTE, tex->pixels); 
	
	glBindTexture(GL_TEXTURE_2D, 0);
	
	return textures;
}

SDL_Surface* loadImage(const char* image){
	SDL_Surface* tex = IMG_Load(image);
	if (tex == NULL){
		fprintf(stderr, "Impossible d'afficher l'image %s.\n", image);
	}
	return tex;
}	

void deleteImage(SDL_Surface* tex){
	SDL_FreeSurface(tex);
}

void deleteTexture(GLuint image){
	glDeleteTextures(1, &image);
}


void GetPixel(SDL_Surface* surface, int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a) {
    int bpp = surface->format->BytesPerPixel;
    
    Uint8* p = (Uint8*) surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        
        break;

    case 2:

        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            *r = p[0];
            *g = p[1];
            *b = p[2];
        } else {
            *r = p[2];
            *g = p[1];
            *b = p[0];
        }
        break;

    case 4:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            *r = p[0];
            *g = p[1];
            *b = p[2];
			*a = p[3];
        } else {
            *r = p[3];
            *g = p[2];
            *b = p[1];
			*a = p[0];
        }
        break;
    }
}

void PutPixel(SDL_Surface* surface, int x, int y, Uint32 pixel) {
    int bpp = surface->format->BytesPerPixel;
    
    Uint8* p = (Uint8*) surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16*)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32*)p = pixel;
        break;
    }
};
