#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "map.h"

#define path "./data/map.itd"

int checkItd (FILE* itd){
	FILE * itd;
	char img[20];
	int r, g, b;
	int parcours = 0;
	int count = 0;
	Color3ub chemin, noeud, construct, in, out;
	itd = fopen("map.itd", "r");
	 	if(itd){
			char ligne[100];		
			char *retour0 = fgets(ligne,80,itd);

			if(strcmp(retour0,"@ITD 1\n") != 0){
				printf("Le fichier  n'est pas une carte valide.\n");
				fclose(itd);
				return 0;
			}

			char *retour1 = fgets(ligne,80,itd);
			if(strcmp(retour1,"#premiere ligne de commentaire\n") != 0){
				printf("Le fichier n'est pas une carte valide.\n");
				fclose(itd);
				return 0;
			}

			fscanf(itd, "%s", img);
			if( strcmp(img,"carte") == 0){
				printf("yeah girl");
				char* fichierPPM;
				fscanf(itd, "%s", fichierPPM);
				setImage(fichierPPM);
			 	fclose(itd);
			 	return 0;
			}
			else {
				printf("Pb avec la ligne carte\n");
				fclose(itd);
			 	return 0;
			}

			while(parcours == 0){

			}
			fscanf(itd, "%s", img);
			if( strcmp(img,"carte") == 0){
				printf("yeah girl");
				char* fichierPPM;
				fscanf(itd, "%s", fichierPPM);
				setImage(fichierPPM);
			 	fclose(itd);
			 	return 0;
			}
			fclose(itd);
	 }

	 else{
	 	fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
	 	return 0;
	 }
}

void drawRepere(){
	glBegin(GL_LINE);
		glColor3ub(0,255,0);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glColor3ub(255, 0 ,0);
		glVertex2f(0,0);
		glVertex2f(1,0);
	glEnd();
}