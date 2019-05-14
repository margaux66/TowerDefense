#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Map{
public:

    int checkItd(FILE* itd);
    void drawRepere();
    void afficheMap();

    /* Getters */
     char* getImage(){
     	return image;
     } 

    /* Setters */
     void setImage(char* newImage){ image = newImage; }

private:
 	GLuint tex;
 	SDL_Surface* ppm;
 	char* image;


	 

}