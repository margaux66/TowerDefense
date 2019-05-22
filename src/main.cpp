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
	if(-1 == SDL_Init(SDL_INIT_VIDEO)){
		fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme\n");
		return EXIT_FAILURE;
	}

	SDL_Surface* surface, *texte=NULL;
	SDL_Rect position;
	TTF_Font *police = NULL;
	SDL_Color couleur = {0, 0, 0};
	reshape(&surface, WINDOW_WIDTH, WINDOW_HEIGHT);
	SDL_WM_SetCaption(WINDOW_TITLE, NULL);

	TTF_Init();
	police = TTF_OpenFont("vogue.ttf", 50);
	texte = TTF_RenderText_Blended(police, "Press enter", couleur);

	char image_path[] = "image/map.ppm";
	SDL_Surface* image = IMG_Load(image_path);
	if(NULL == image){
		fprintf(stderr, "Echec du chargement de l'image\n", image_path);
		exit (EXIT_FAILURE);
	}

	GLuint texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	GLenum format;

	switch(image->format->BytesPerPixel){
		case 1:
		format = GL_RED;
		break;
		case 3:
		format = GL_RGB;
		break;
		case 4:
		format = GL_RGBA;
		break;
		default:
		fprintf(stderr, "Format des pixels de l'image %s non supporte.\n", image_path);
		return EXIT_FAILURE;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);

	int loop = 1;
	while(loop){
		Uint32 timer = SDL_GetTicks();

		glClear(GL_COLOR_BUFFER_BIT);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id);
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

		SDL_GL_SwapBuffers();

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
		SDL_BlitSurface(texte, NULL, image, &position);
		SDL_Flip(image);
		}
	}


	TTF_CloseFont(police);
	TTF_Quit();

	glDeleteTextures(1, &texture_id);
	SDL_FreeSurface(image);
	SDL_FreeSurface(texte);
	SDL_Quit();
	return EXIT_SUCCESS;
}