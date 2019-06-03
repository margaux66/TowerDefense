#include "../include/include.h"
#include "../include/monster.h"
#include "../include/tower.h"
#include "../include/building.h"
#include "../include/timer.h"
#include "../include/wave.h"
#include "../include/checkMap.h"

using namespace std;

static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 600;
static const char WINDOW_TITLE[] = "TOWER DEFENSE";

static float aspectRatio;

static const float GL_VIEW_SIZE = 150.;
static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

void reshape(SDL_Surface** surface, unsigned int width, unsigned int height){
	SDL_Surface* surface_temp = SDL_SetVideoMode(width, height, BIT_PER_PIXEL, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE);
	if(NULL == surface_temp){
		fprintf(stderr, "Erreur lors du redimmensionnement de la fenetre.\n");
		exit(EXIT_FAILURE);
	}
	*surface = surface_temp;
	aspectRatio = width / (float)height;

	glViewport(0, 0, (*surface)->w, (*surface)->h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(aspectRatio > 1){
		gluOrtho2D(-GL_VIEW_SIZE/2. * aspectRatio, GL_VIEW_SIZE/2. * aspectRatio, -GL_VIEW_SIZE/2., GL_VIEW_SIZE/2.);
	}
	else {
		gluOrtho2D(-GL_VIEW_SIZE/2., GL_VIEW_SIZE/2., -GL_VIEW_SIZE/2. /aspectRatio, GL_VIEW_SIZE/2./aspectRatio);
	}
}

int main(int argc, char** argv){
	checkMap verif;
	verif.setPath("./data/map.itd");
	if(verif.checkedMap()==1){
		float tempsDepart = 0;
		Timer time;
		time.start();

		if(-1 == SDL_Init(SDL_INIT_VIDEO)){
			fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme\n");
			return EXIT_FAILURE;
		}
		SDL_Surface* surface;
		Monster monster;
		Wave wave;

		putenv("SDL_VIDEO_WINDOW_POS=0,0");
		reshape(&surface, WINDOW_WIDTH, WINDOW_HEIGHT);
		SDL_WM_SetCaption(WINDOW_TITLE, NULL);

		SDL_Rect position;
		GLuint texture_map = loadTexture(loadImage( IMG_Load("./image/map.ppm")));
		GLuint map = loadTexture(loadImage(IMG_Load("./image/carte.ppm")));

		vector<Tower*> allTower;
		Tower t = Tower(1,position,0);
		GLuint texture_t = loadTexture(loadImage(t.getTTexture()));
		allTower.push_back(&t);

		Tower t2 = Tower(2,position,0);
		GLuint texture_t2 = loadTexture(loadImage(t2.getTTexture()));
		allTower.push_back(&t2);

		Tower t3 = Tower(3,position,0);
		GLuint texture_t3 = loadTexture(loadImage(t3.getTTexture()));
		allTower.push_back(&t3);

		Tower t4 = Tower(4,position,0);
		GLuint texture_t4 = loadTexture(loadImage(t4.getTTexture()));
		allTower.push_back(&t4);

		Building b = Building(1,position);
		GLuint texture_b = loadTexture(loadImage(b.getBTexture()));	

		Building b2 = Building(2,position);
		GLuint texture_b2 = loadTexture(loadImage(b2.getBTexture()));	

		Building b3 = Building(3,position);
		GLuint texture_b3 = loadTexture(loadImage(b3.getBTexture()));	

		int loop = 1;
		int premTour =0, secTour=0, troiTour = 0,quatreTour =0, premBuild=0, secBuild = 0, troiBuild=0;
		while(loop){
			glClear(GL_COLOR_BUFFER_BIT);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture_map);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glPushMatrix();
				glBegin(GL_QUADS);
				glTexCoord2f(0,1);
				glVertex2f(-70., -70.);
				glTexCoord2f(1,1);
				glVertex2f(70., -70.);
				glTexCoord2f(1,0);
				glVertex2f(70., 70.);
				glTexCoord2f(0,0);
				glVertex2f(-70., 70.);
				glEnd();
			glPopMatrix();
			
			glClear(GL_COLOR_BUFFER_BIT);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, map);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glPushMatrix();
				glBegin(GL_QUADS);
				glTexCoord2f(0,1);
				glVertex2f(-70., -70.);
				glTexCoord2f(1,1);
				glVertex2f(70., -70.);
				glTexCoord2f(1,0);
				glVertex2f(70., 70.);
				glTexCoord2f(0,0);
				glVertex2f(-70., 70.);
				glEnd();
			glPopMatrix();

			if(premTour==1){
				position.x = -20;
				position.y = -50;
				t.setPosition(position);
				glPushMatrix();
					glTranslatef(position.x ,position.y,0);
					t.draw_tower(texture_t);
				glPopMatrix();
			}

			if(secTour==1){
				position.x = -45;
				position.y = 35;
				t2.setPosition(position);
				glPushMatrix();
					glTranslatef(position.x ,position.y,0);
					t2.draw_tower(texture_t2);
				glPopMatrix();
			}

			if(troiTour==1){
				position.x = 20;
				position.y = -15;
				t3.setPosition(position);
				glPushMatrix();
					glTranslatef(position.x ,position.y,0);
					t3.draw_tower(texture_t3);
				glPopMatrix();
			}
			if(quatreTour ==1){
				position.x = 50;
				position.y = 15;
				t4.setPosition(position);
				glPushMatrix();
					glTranslatef(position.x ,position.y,0);
					t4.draw_tower(texture_t4);
				glPopMatrix();
			}
			if(premBuild ==1){
				glPushMatrix();
					glTranslatef(0,-60,0);
					b.draw_building(texture_b);
				glPopMatrix();
			}
			if(secBuild ==1){
				glPushMatrix();
					glTranslatef(60,+35,0);
					b.draw_building(texture_b2);
				glPopMatrix();
			}		
			if(troiBuild ==1){
				glPushMatrix();
					glTranslatef(-60,+50,0);
					b.draw_building(texture_b3);
				glPopMatrix();
			}
			SDL_GL_SwapBuffers();

			SDL_Event e;
			while(SDL_PollEvent(&e)){
				if(e.type == SDL_QUIT){
					printf("A bientôt !\n");
					loop = 0;
					break;
				}
				if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)){
					printf("A bientôt !\n");
					loop = 0;
					break;
				}


				switch(e.type){
					case SDL_VIDEORESIZE:
					reshape(&surface, e.resize.w, e.resize.h);
					break;

					case SDL_MOUSEBUTTONUP:
					printf("Clic en (%d, %d)\n", e.button.x, e.button.y);
					break;

					case SDL_KEYDOWN:
						//met la partie en pause si elle n'est pas en pause
						//la remet en route si elle était en pause
						if (e.key.keysym.sym == SDLK_p){
							if(time.isPaused()==true){
								time.unpause();
								cout<< "La partie a repris \n";
							}
							else{
						 		time.pause();
					 			cout << "La partie est en pause \n";
						 	}
						}

						if(e.key.keysym.sym == SDLK_a){
							switch(premTour){
								case 1:
									premTour = 0;
									break;
								case 0 :
									premTour = 1;
									t.informations();
									break;
							}
						}
						if(e.key.keysym.sym == SDLK_z){
						 	switch(secTour){
								case 1:
									secTour = 0;
									break;
								case 0 :
									secTour = 1;
									t2.informations();
									break;
							}	
						}
						if(e.key.keysym.sym == SDLK_e){
						 	switch(troiTour){
								case 1:
									troiTour = 0;
									break;
								case 0 :
									troiTour = 1;
									t3.informations();
									break;
							}

						}
						if(e.key.keysym.sym == SDLK_r){
						 	switch(quatreTour){
								case 1:
									quatreTour = 0;
									break;
								case 0 :
									quatreTour = 1;
									t4.informations();
									break;
							}					 	
						}
						if(e.key.keysym.sym == SDLK_t){
						 	switch(premBuild){
								case 1:
									premBuild = 0;
									break;
								case 0 :
									premBuild = 1;
									break;
							}					 		
						}
						if(e.key.keysym.sym == SDLK_y){
						 	switch(secBuild){
								case 1:
									secBuild = 0;
									break;
								case 0 :
									secBuild = 1;
									break;
							}					 	
						}
						if(e.key.keysym.sym == SDLK_u){
						 	switch(troiBuild){
								case 1:
									troiBuild = 0;
									break;
								case 0 :
									troiBuild = 1;
									break;
							}					 		
						}
						if(e.key.keysym.sym ==SDLK_i){
							cout << "Temps écoulé : " <<(SDL_GetTicks()-tempsDepart)/1000<< " en seconde. \n";
							//printf("Temps écoulé : %.3f en sec ondes\n", time.getTicks()/1000);
							printf("Argent : %d\n", monster.getMoney());
							printf("Vague n°%d\n", wave.getCountWave());
							printf("-----------------------------------------\n");
							break;
						}	
						if(e.key.keysym.sym == SDLK_h){
							printf("--HELP--\n");
							printf("Appuyez sur la barre espace pour lancer le jeu\n");
							printf("Appuyez sur i pour obtenir les informations sur la partie en cours\n");
							printf("Appuyez sur a pour achetez une tour Rocket\nAppuyez sur z pour achetez une tour Laser\nAppuyez sur e pour achetez une tour Jaune\nAppuyer sur r pour achetez une tour Bleue\n");
							printf("Appuyez sur t pour achetez un Radar\nAppuyez sur y pour achetez une Usine\nAppuyez sur u pour achetez un Stock\n");
							printf("Appuyez sur p pour mettre le jeu en pause\n");
							printf("Cliquez sur la croix, appuyer sur echap ou q pour quitter le jeu\n");
							printf("-----------------------------------------\n");
						}
						if(e.key.keysym.sym == SDLK_SPACE){
							wave.create_wave();
							tempsDepart = SDL_GetTicks()/1000;
							printf("Bonne chance\n");
							break;
						}								
					break;

					default:
					break;
				}
			}
		}
		
		if(premTour==0){
			GLuint texture_t = NULL;
		}
		if(secTour==0){
			GLuint texture_t2 = NULL;
		}
		if(troiTour==0){
			GLuint texture_t3 = NULL;
		}
		if(quatreTour==0){
			GLuint texture_t4 = NULL;
		}
		if(premBuild==0){
			GLuint texture_b = NULL;
		}
		if(secBuild==0){
			GLuint texture_b2 = NULL;
		}
		if(troiBuild==0){
			GLuint texture_b3 = NULL;
		}
		//SDL_FreeSurface(tow);
		//SDL_FreeSurface(image);
		SDL_Quit();
		return EXIT_SUCCESS;
	}
	else{
		return EXIT_FAILURE;
	}

}