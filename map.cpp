#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "map.h"

#define chemin map.itd

int itd_verifCode(FILE* itd){
	 itd = fopen(chemin, "r");
	 if(itd){
	 	if (strcmp(img, "@ITD") != 0){
			fprintf(stderr, "Le fichier  n'est pas une carte valide.\n", );
			fclose(itd);
			return 0;
		}
		else{
			return 1;
		}
	 }
	 else{
	 	fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
	 	return 0;
	 }
}