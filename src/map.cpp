#include "../include/map.h"

void drawMap(GLuint text){
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,text);
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
}

void drawRepere(){
	glBegin(GL_LINES);
		glColor3ub(0, 255 ,0);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glColor3ub(255, 0 ,0);
		glVertex2f(0,0);
		glVertex2f(1,0);
	glEnd();
}
