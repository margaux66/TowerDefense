#include "../include/include.h"
#include "../include/monster.h"
#include "../include/tower.h"
#include "../include/building.h"

using namespace std;

static const unsigned int WINDOW_WIDTH = 800;
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

// void drawsquare(int filled){
// 	if(filled){
// 		glBegin(GL_TRIANGLE_FAN);
// 		glVertex2f(0.0, 0.0);
// 	}
// 	else{
// 		glBegin(GL_LINE_STRIP);
// 	}
// 	glVertex2f(100, -100);
// 	glVertex2f(100, 100);
// 	glVertex2f(-100, 100);
// 	glVertex2f(-100, -100);
// 	glVertex2f(100, -100);
// 	glEnd();
// }

// void draw(){
// 	drawsquare(1);
// }

int main(int argc, char** argv){
	if(-1 == SDL_Init(SDL_INIT_VIDEO)){
		fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme\n");
		return EXIT_FAILURE;
	}

	SDL_Surface* surface;
	reshape(&surface, WINDOW_WIDTH, WINDOW_HEIGHT);
	SDL_WM_SetCaption(WINDOW_TITLE, NULL);

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

			switch(e.type){
				case SDL_VIDEORESIZE:
				reshape(&surface, e.resize.w, e.resize.h);
				break;

				case SDL_MOUSEBUTTONUP:
				printf("Clic en (%d, %d)\n", e.button.x, e.button.y);
				break;

				case SDL_KEYDOWN:
				printf("Touche pressed (code = %d)\n", e.key.keysym.sym);
				break;

				default:
				break;
			}
		}
	}
	SDL_Quit();
	return EXIT_SUCCESS;
}