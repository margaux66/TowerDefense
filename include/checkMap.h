#ifndef DEF_CHECKMAP_H
#define DEF_CHECKMAP_H 

//include
#include "include.h"

using namespace std;

//Méthodes
class checkMap{
public:
    checkMap(); //constructeur
    ~checkMap(); //destructeur
    int checkItd(); //verification du fichier ITD
    int checkedMap(); //verification si la carte correspond au fichier ITD
    unsigned int getPixel(int x, int y, int composante); //recuperation des pixels
    int loadPPM(); //chargement du fichier PPM

    // Getters //
    string getImage(){ return image;}
    string getPath(){ return path;}
    vector<int> getChemin(){ return chemin;}
    vector<int> getConstruct(){ return construct;}
    vector<int> getIn(){ return in;}
    vector<int> getOut(){ return out;}
    vector<int> getNodeColor(){return nodeColor;}
    vector<unsigned int> getData(){return data;}
    vector<vector<int> > getNode(){ return node; }
    int getWidth(){ return width;}   
    int getHeight(){ return height;}  

    // Setters //
    void setImage(string newImage){ image = newImage; }
    void setPath(string newPath){ path = newPath; }
    void setChemin(vector<int> newChemin){ chemin = newChemin; }
    void setConstruct(vector<int> newConstruct){ construct = newConstruct; }
    void setIn(vector<int> newIn){ in = newIn; }
    void setOut(vector<int> newOut){ out = newOut; }
    void setNodeColor(vector<int> newNodeColor){ nodeColor = newNodeColor; }
    void setData(vector<unsigned int>& newData){ data = newData; }
    void setNode(vector<vector<int> > newNode){ node = newNode;  }
    void setNbNode(int newNbNode){ nbNode = newNbNode; }
    void setWidth(int newWidth){ width = newWidth; }
    void setHeight(int newHeight){ height = newHeight; }

//Attributs
private: 
    string image;
    string path;
    vector<int> chemin;
    vector <int>construct;
    vector<int> in;
    vector<int> out;
    vector<int> nodeColor;
    vector<vector<int> > node;
    vector<unsigned int> data;
    int nbNode;
    int width;
    int height;
};

#endif /* CHECKMAP_H */
