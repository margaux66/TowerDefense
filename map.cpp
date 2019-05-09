#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "map.h"

void verifItd(string chemin){
	ifstream map(chemin);  //Ouverture d'un fichier en lecture

	if(map)
	{
    	//Tout est prêt pour la lecture.
	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
};