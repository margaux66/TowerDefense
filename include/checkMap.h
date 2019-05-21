#ifndef DEF_checkMap_H
#define DEF_checkMap_H 

#include "../include/include.h"
#include "../include/map.h"

class checkMap{
public:
    checkMap();
    int checkItd(string path);
    int checkMap(string map);

    /* Getters */
    string getImage(){ return image;}
    string getPath(){ return path;}
    array getChemin(){ return chemin;}
    array getConstruct(){ return construct;}
    array getIn(){ return in;}
    array getOut(){ return out;}
    array getNode(){ return node;} 
    int getNbNode(){ return nbNode;}   

    /* Setters */
    void setImage(string newImage){ image = newImage; }
    void setPath(string newPath){ path = newPath; }
    void setChemin(array newChemin){ chemin = newChemin; }
    void setConstruct(array newConstruct){ construct = newConstruct; }
    void setIn(array newIn){ in = newIn; }
    void setOut(array newOut){ out = newOut; }
    void setOut(array newNode){ node = newNode; }
    void setNbNode(array newNbNode){ nbNode = newNbNode; }

private:
 	string image;
    string path
    array chemin;
    array construct;
    array in;
    array out;
	array node; 
    int nbNode;

}
#endif