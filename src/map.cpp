#include "../include/map.h"

void drawMap(map map){
	
	glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m->tex);
	float texX = MAP_WIDTH/(m->ppm->w*1.0f);//*m->camPos.z));
	float deltaX = 0.f;

	float texY = MAP_HEIGHT/(m->ppm->h*1.0f);//*m->camPos.z));
	float deltaY = 0.f;

	
	glBegin(GL_QUADS);
		glTexCoord2f(deltaX, deltaY);
		glVertex2f(0.f, 50.f);

		glTexCoord2f(deltaX,texY+deltaY);
		glVertex2f(0.f, MAP_HEIGHT+50.f);

		glTexCoord2f(texX+deltaX,texY+deltaY); 
		glVertex2f(MAP_WIDTH, MAP_HEIGHT+50.f);

		glTexCoord2f(texX+deltaX,deltaY); 
		glVertex2f(MAP_WIDTH, 50.f);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

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