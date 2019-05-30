#ifndef DEF_checkMap_H
#define DEF_checkMap_H 

#include "include.h"
using namespace std;
//#include "../include/map.h"

class checkMap{
public:
    checkMap();
    ~checkMap();
    int checkItd();
    int checkedMap();
    int getPixel(vector<int> pixels, int x, int y, int composante);
    int loadPPM();

    /* Getters */
    string getImage(){ return image;}
    string getPath(){ return path;}
    vector<int> getChemin(){ return chemin;}
    vector<int> getConstruct(){ return construct;}
    vector<int> getIn(){ return in;}
    vector<int> getOut(){ return out;}
    vector<int> getNodeColor(){return nodeColor;}
    vector<int> getData(){return data;}
    vector<vector<int>> getNode(){ return node; } 
    int getNbNode(){ return nbNode;}   

    /* Setters */
    void setImage(string newImage){ image = newImage; }
    void setPath(string newPath){ path = newPath; }
    void setChemin(vector<int> newChemin){ chemin = newChemin; }
    void setConstruct(vector<int> newConstruct){ construct = newConstruct; }
    void setIn(vector<int> newIn){ in = newIn; }
    void setOut(vector<int> newOut){ out = newOut; }
    void setNodeColor(vector<int> newNodeColor){ nodeColor = newNodeColor; }
    void setData(vector<int> newData){ data = newData; }
    void setNode(vector<vector<int>> newNode){ node = newNode;  }
    void setNbNode(int newNbNode){ nbNode = newNbNode; }

private:
 	string image;
    string path;
    vector<int> chemin;
    vector <int>construct;
    vector<int> in;
    vector<int> out;
    vector<int> nodeColor;
	vector<vector<int>> node;
    vector<int> data; 
    int nbNode;

};
#endif