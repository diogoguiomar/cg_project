#include <cmath>
#include "computer.h"

void displayMouse()
{
	float i;
	/* RATO */
  	// left
  	glColor3f( 0.0, 0.0, 0.0 );
    glBegin(GL_TRIANGLE_STRIP);
  		for(i = -M_PI/2; i < M_PI/2; i+=0.02) {
  			glVertex3f(2.0, 0.0, 0.5);
  			glVertex3f(2.0, 0.2 * cos(i), 0.5 + 0.2 * -sin(i));
  		}
  	glEnd();
  	// right
  	glColor3f( 0.0, 0.0, 0.0 );
    glBegin(GL_TRIANGLE_STRIP);
  		for(i = -M_PI/2; i < M_PI/2; i+=0.02) {
  			glVertex3f(2.2, 0.0, 0.5);
  			glVertex3f(2.2, 0.2 * cos(i), 0.5 + 0.2 * -sin(i));
  		}
  	glEnd();
  	// top
  	glBegin(GL_TRIANGLE_STRIP);
  		for(i = -M_PI/2; i < M_PI/2; i+=0.2) {
  			glVertex3f(2.0, 0.2 * cos(i), 0.5+0.2 * -sin(i));
  			glVertex3f(2.2, 0.2 * cos(i), 0.5+0.2 * -sin(i));
  		}
  	glEnd();
  	// base
  	glBegin(GL_QUADS);
  		glVertex3f( 2.0f, 0.00f, 0.7f); // bot left
  		glVertex3f( 2.2f, 0.00f, 0.7f); // bot right
		glVertex3f( 2.2f, 0.00f, 0.3f); // top right
		glVertex3f( 2.0f, 0.00f, 0.3f); // top left
	glEnd();
}
