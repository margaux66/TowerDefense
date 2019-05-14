#include "../include/map.h"

#define path "map.itd"

int checkItd (FILE* itd){
	 itd = fopen(path, "r");
	 if(itd){
	 	char compare = fgetc(itd); 
	 	if (campare != "@"){
			printf("Le fichier  n'est pas une carte valide.\n");
			fclose(itd);
			return 0;
		}
		char format[4];
		format[] = "ITD"; 
		for (int i = 0; i<3,i++){
			if(fgetc(itd)!=format[i]){
				printf("Le fichier  n'est pas une carte valide.\n");
				fclose(itd);
				return 0;
			}
		}
		switch(fgetc(itd)){
			case 1 :
				break;
			default :
				printf("Le fichier n'est pas une carte valide, la version demandé n'existe pas.\n");
				fclose(itd);
				return 0;					
		}
		char ligne[100];		


		char *retour = fgets(ligne,80,itd);
		if(strcmp(retour,"#premiere ligne de commentaire") != 0){
			printf("Le fichier  n'est pas une carte valide.\n");
			printf("%s",retour);
			fclose(itd);
			return 0;
		}

		char *retour2 = fgets(ligne,80,itd);	
		if( strcmp(retour2,"carte map.ppm") != 0){
			printf("Le fichier  n'est pas une carte valide : problème à la ligne %s.\n", retour2 );
		 	fclose(itd);
		 	return 0;
		}

		char *retour3 = fgets(ligne,80,itd);	
		if( strcmp(retour3,"chemin 255 255 255") != 0){
			printf("Le fichier  n'est pas une carte valide : problème à la ligne %s.\n", retour3 );
		 	fclose(itd);
		 	return 0;
		}

		char *retour4 = fgets(ligne,80,itd);	
		if( strcmp(retour4,"construct 152 255 128") != 0){
			printf("Le fichier  n'est pas une carte valide : problème à la ligne %s.\n", retour4 );
		 	fclose(itd);
		 	return 0;
		}


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