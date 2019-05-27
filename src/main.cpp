#include "../include/include.h"
#include "../include/monster.h"
#include "../include/tower.h"
#include "../include/building.h"

using namespace std;

static const unsigned int WINDOW_WIDTH = 600;
static const unsigned int WINDOW_HEIGHT = 600;
static const char WINDOW_TITLE[] = "TOWER DEFENSE";

static float aspectRatio;

static const float GL_VIEW_SIZE = 150.;
static const int CICLE_SUBDIVS = 2<<5;
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
	// if(-1 == SDL_Init(SDL_INIT_VIDEO)){
	// 	fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme\n");
	// 	return EXIT_FAILURE;
	// }

	SDL_Surface *ecran = NULL;
	SDL_Surface *texte = NULL;
	SDL_Rect position;
	TTF_Font *police = NULL;
	SDL_Color couleur = {0, 0, 0};
	//reshape(&surface, WINDOW_WIDTH, WINDOW_HEIGHT);
	//SDL_WM_SetCaption(WINDOW_TITLE, NULL);

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	if (TTF_Init() ==-1){
		fprintf(stderr, "Erreur d'initialisation : %s \n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	
	ecran = SDL_SetVideoMode(200, 200, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

	police = TTF_OpenFont("vogue.ttf", 50);
	texte = TTF_RenderText_Blended(police, "Press enter", couleur);

	int loop = 1;
	while(loop){
		Uint32 timer = SDL_GetTicks();

		SDL_Event e;
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				loop = 0;
				break;
			}
			if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)){
				loop = 0;
				break;
			}

			
		// 	switch(e.type){
		// 		case SDL_VIDEORESIZE:
		// 		reshape(&surface, e.resize.w, e.resize.h);
		// 		break;

		// 		case SDL_MOUSEBUTTONUP:
		// 		printf("Clic en (%d, %d)\n", e.button.x, e.button.y);
		// 		break;

		// 		case SDL_KEYDOWN:
		// 		printf("Touche pressed (code = %d)\n", e.key.keysym.sym);
		// 		break;

		// 		default:
		// 		break;
		// 	}
		// }

		int continuer = 1;
		while(continuer){
			SDL_PollEvent(&e);
			switch(e.type){
				case SDL_QUIT:
				continuer = 0;
				break;
			}
		position.x = 60;
		position.y = 350;
		SDL_BlitSurface(texte, NULL, surface, &position);
		SDL_Flip(surface);
		}
	}


	TTF_CloseFont(police);
	TTF_Quit();
	SDL_FreeSurface(texte);
	SDL_Quit();
	return EXIT_SUCCESS;
}