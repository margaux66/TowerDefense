#include "../include/entity.h"

void update(){
	glColor4f(255, 0, 0, 1);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
        glVertex2f(m_x, m_y);
    glEnd();
    glPointSize(1.0f);
};


