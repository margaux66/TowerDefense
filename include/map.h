#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Map{
public:

    int checkItd(FILE* itd);
    void drawRepere();
    void afficheMap();

    /* Getters */


    /* Setters */

 	GLuint tex;
 	SDL_Surface* ppm;


	 

}