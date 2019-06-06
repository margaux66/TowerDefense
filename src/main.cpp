#include "../include/include.h"
#include "../include/monster.h"
#include "../include/tower.h"
#include "../include/building.h"
#include "../include/wave.h"
#include "../include/checkMap.h"
#include "../include/map.h"

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
	//vérifie si la map est valide
	checkMap verif;
	verif.setPath("./data/map.itd");
	if(verif.checkedMap()==1){
		//initialisation de variable
		unsigned int tempsDepart = 0, tempsPause = 0;
		bool paused = false;
		int debut =0, accueil = 0, help = 1, help2 =0, loop = 1,premTour =0, secTour=0, troiTour = 0,quatreTour =0, premBuild=0, secBuild = 0, troiBuild=0, avancee_monster=0,count =0, avancee_pause =0;
		SDL_Rect pos;
		
		//initialisation fenêtre
		if(-1 == SDL_Init(SDL_INIT_VIDEO)){
			fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme\n");
			return EXIT_FAILURE;
		}
		SDL_Surface* surface;
		putenv("SDL_VIDEO_WINDOW_POS=0,0");
		reshape(&surface, WINDOW_WIDTH, WINDOW_HEIGHT);
		SDL_WM_SetCaption(WINDOW_TITLE, NULL);

		//création object des différentes classes
		Monster joueur;
		Wave wave;
		wave.create_wave();

		//initialisation textures objets
		SDL_Rect position;
		GLuint texture_map = loadTexture(loadImage( IMG_Load("./image/map.ppm")));
		GLuint map = loadTexture(loadImage(IMG_Load("./image/carte.ppm")));
		GLuint accueilText = loadTexture(loadImage(IMG_Load("./image/accueil.png")));
		GLuint helpText = loadTexture(loadImage(IMG_Load("./image/help.png")));
		GLuint helpText2 = loadTexture(loadImage(IMG_Load("./image/help2.png")));
		GLuint pauseText = loadTexture(loadImage(IMG_Load("./image/pause.png")));

		//toutes les tours sont dans un tableau
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

		//tableaux pour stocker les textures des monstres
		vector<GLuint> monstersText;
		//on récupère les monstres créés par la vague
		vector<Monster>monsters = wave.getMonsters();
		for(int i =0; i<monsters.size(); i++){
			monstersText.push_back(loadTexture(loadImage(monsters[i].getMTexture())));
		} 

		//boucle de jeu
		while(loop){
			//SDL_Delay (500);

			//affichage des élements et application des textures
			drawMap(texture_map);
			drawMap(map);

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
			//affiche la page d'acceuil uniquement si acceuil == 0 donc si la personne n'a pas encore touché un bouton
			if(accueil == 0){
				drawMap(accueilText);
				if(help == 0){
					drawMap(helpText);
				}
			}
			//si l'utilisateur a déclenché la vague en appuyant sur espace la vague est lancé
			//pour l'instant la vague n'est constituée que d'un monstre
			if (debut == 1){
				for (int i =0; i<monstersText.size();i++){
					glPushMatrix();
						glTranslatef(monsters[i].getPosition().x,monsters[i].getPosition().y-i*15,0);
						monsters[i].draw_monster(monstersText[i]);
					glPopMatrix();

				}
				avancee_monster = avancee_monster+1;
				usleep(1000);
				if(paused){
					count++;
					avancee_pause = avancee_monster;
				}
				if(paused != true){
					if(avancee_pause == 0){
						monsters[0].deplacement(avancee_monster);
					}
					else{
						monsters[0].deplacement(avancee_monster-(avancee_pause-count*5));
					}
				}

			}
			//si l'utilisateur appuie sur H l'aide s'affiche
			if(help2 == 1){
				drawMap(helpText2);
			}
			//si il appuie sur p le jeu se met en pause
			if(paused == true){
				drawMap(pauseText);
			}
			SDL_GL_SwapBuffers();

			//gestion des évênements
			SDL_Event e;
			while(SDL_PollEvent(&e)){
				//la touche q, esc et la croix permettent de fermer le jeu
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
					// case SDL_VIDEORESIZE:
					// reshape(&surface, e.resize.w, e.resize.h);
					// break;

					//délimitation des boutons de l'accueil
					//change les valeurs des variables en fonction d'où l'utilisateur appuie
					case SDL_MOUSEBUTTONUP:
						if(e.button.x<544 && e.button.x>248 ){
							if(e.button.y<336 && e.button.y>243){
								accueil = 1;
							}
						}
						
						if(e.button.x<544 && e.button.x>248 ){
							if(e.button.y<480 && e.button.y>384){
								help = 0;
							}	
						}
						if(e.button.x<263 && e.button.x>208 ){
							if(e.button.y<101 && e.button.y>52){
								help = 1;
								accueil =0;
							}	
						}
						
					break;

					case SDL_KEYDOWN:
						//met la partie en pause si elle n'est pas en pause
						//la remet en route si elle était en pause
						if (e.key.keysym.sym == SDLK_p){
							if(paused==true){
								paused = false;
								tempsPause = (SDL_GetTicks()-tempsPause);
								cout<< "La partie a repris (temps de pause = "<< tempsPause/1000<<") \n";
							}
							else{
						 		paused = true;
						 		tempsPause = SDL_GetTicks();
					 			cout << "La partie est en pause \n";
						 	}
						}

						//Gestion de l'affichage avec les touches
						//si les différentes variables sont égales à 1 l'élément s'affiche
						//tour et bâtiments
						if(e.key.keysym.sym == SDLK_a){
							switch(premTour){
								case 1:
									premTour = 0;
									break;
								case 0 :
									premTour = 1;
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
						//donne les info relative à la partie
						if(e.key.keysym.sym ==SDLK_i){
							if(tempsDepart != 0){
								cout << "Temps écoulé : " <<(SDL_GetTicks()-(tempsDepart+tempsPause))/1000<< " en seconde. \n";
							}
							else{
								cout << "Temps écoulé : " <<0<< " en seconde. \n";
							}
							printf("Argent : %d\n", joueur.getMoney());
							printf("Vague n°%d\n", wave.getCountWave());
							printf("-----------------------------------------\n");
							break;
						}	
						//affiche l'aide dans le terminal est également sur la fenêtre
						if(e.key.keysym.sym == SDLK_h){
							printf("--HELP--\n");
							printf("Appuyez sur la barre espace pour lancer le jeu\n");
							printf("Appuyez sur i pour obtenir les informations sur la partie en cours\n");
							printf("Appuyez sur a pour achetez une tour Rocket\nAppuyez sur z pour achetez une tour Laser\nAppuyez sur e pour achetez une tour Jaune\nAppuyer sur r pour achetez une tour Bleue\n");
							printf("Appuyez sur t pour achetez un Radar\nAppuyez sur y pour achetez une Usine\nAppuyez sur u pour achetez un Stock\n");
							printf("Appuyez sur p pour mettre le jeu en pause\n");
							printf("Cliquez sur la croix, appuyer sur echap ou q pour quitter le jeu\n");
							printf("-----------------------------------------\n");
							if(help2 == 1){
								help2 = 0;
							}
							else{
								help2 = 1;
							}
							break;
						}
						//donne les informations sur les tours
						if(e.key.keysym.sym == SDLK_m){
							for (int i =0; i<allTower.size();i++){
								allTower[i]->informations();
							}
							break;
						}			
						//lance le jeu			
						if(e.key.keysym.sym == SDLK_SPACE){
							if (tempsDepart == 0){
								debut = 1;
								tempsDepart = SDL_GetTicks();
								printf("Bonne chance\n");
							}
							break;
						}								
					break;

					default:
					break;
				}
			}

		}
		//cache les éléments si le joueur a réappuyé sur la touche correspondante
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

		// SDL_FreeSurface(&texture_map);
		// SDL_FreeSurface(&map);
		// SDL_FreeSurface(&accueilText);
		// SDL_FreeSurface(&helpText);
		// SDL_FreeSurface(&helpText2);
		// SDL_FreeSurface(&pauseText);
		// SDL_FreeSurface(&t);
		// SDL_FreeSurface(&t2);
		// SDL_FreeSurface(&t3);
		// SDL_FreeSurface(&t4);
		// SDL_FreeSurface(&b);
		// SDL_FreeSurface(&b2);
		// SDL_FreeSurface(&b3);

		SDL_Quit();
		return EXIT_SUCCESS;
	}
	else{
		return EXIT_FAILURE;
	}

}