#include "../include/utils.h"

using namespace std;
static const int CIRCLE_SUBDIVS = 2<<5;

void drawCircle(int filled) 
{

    int i = 0;

    if(filled) 
    {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0, 0.0);
    }
    else 
    {
        glBegin(GL_LINE_STRIP);

    }

    for(i = 0; i < CIRCLE_SUBDIVS; i++) 
    {
        glVertex2f( cos(i * (2 * M_PI / (float) CIRCLE_SUBDIVS)), 
                    sin(i * (2 * M_PI / (float) CIRCLE_SUBDIVS)));
    }
    glVertex2f( cos(i * (2 * M_PI / (float) CIRCLE_SUBDIVS)), 
                sin(i * (2 * M_PI / (float) CIRCLE_SUBDIVS)));

    glEnd();
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

SDL_Surface* loadImage(SDL_Surface* image){
    SDL_Surface* tex = image;
    if (tex == NULL){
        fprintf(stderr, "Impossible d'afficher l'image %s.\n", image);
    }
    return tex;
}   
