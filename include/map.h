#ifndef DEF_map_H
#define DEF_map_H 

#include "../include/include.h"

class map{
public:

    void drawRepere();
    void afficheMap();

    /* Getters */
    int getHeight(){ return height;}
    int getWidth(){ return width;}
    string getChemin(){ return chemin;}

    /* Setters */
    void setHeight(int newHeight){ height = newHeight; }
    void setWidth(int newWidth){ width = newWidth; }
    void setChemin(string newChemin){ Chemin = newChemin; }

private:
    int height;
    int width;
    string chemin;
	 

}
#endif