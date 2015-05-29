#include <cmath>
#include "computer.h"
#include "mouse.h"

void displayMouse()
{
	float i;
	/* RATO */
  	// left
  	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_TRIANGLE_STRIP);
  		for(i = -M_PI/2; i < M_PI/2; i+=0.02) {
  			glTexCoord2f(0.0, 0.0); glVertex3f(2.0, 0.0, 0.5);
  			glTexCoord2f(1.0, 0.0); glVertex3f(2.0, 0.1 * cos(i), 0.5 + 0.2 * -sin(i));
  		}
  	glEnd();
  	// right
  	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_TRIANGLE_STRIP);
  		for(i = -M_PI/2; i < M_PI/2; i+=0.02) {
  			glTexCoord2f(0.0, 0.0); glVertex3f(2.2, 0.0, 0.5);
  			glTexCoord2f(1.0, 0.0); glVertex3f(2.2, 0.1 * cos(i), 0.5 + 0.2 * -sin(i));
  		}
  	glEnd();
  	// top
  	glBindTexture(GL_TEXTURE_2D, texture[2]);
  	glBegin(GL_TRIANGLE_STRIP);
  	float k = 0;
  		for(i = -M_PI/2; i < M_PI/2; i+=0.2, k++) {
  			glTexCoord2f(0.0, PART_OF_MOUSE*k); glVertex3f(2.0, 0.1 * cos(i), 0.5+0.2 * -sin(i));
  			glTexCoord2f(1.0, PART_OF_MOUSE*k); glVertex3f(2.2, 0.1 * cos(i), 0.5+0.2 * -sin(i));
  		}
  	glEnd();
  	// base
  	glBegin(GL_QUADS);
  		glVertex3f( 2.0f, 0.00f, 0.7f); // bot left
  		glVertex3f( 2.2f, 0.00f, 0.7f); // bot right
		glVertex3f( 2.2f, 0.00f, 0.3f); // top right
		glVertex3f( 2.0f, 0.00f, 0.3f); // top left
	glEnd();
	// pad
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glBegin(GL_QUADS);
  		glTexCoord2f(0.0, 0.0); glVertex3f( 1.8f, 0.00f, 0.9f); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f( 2.4f, 0.00f, 0.9f); // bot right
		glTexCoord2f(1.0, 1.0); glVertex3f( 2.4f, 0.00f, 0.1f); // top right
		glTexCoord2f(0.0, 1.0); glVertex3f( 1.8f, 0.00f, 0.1f); // top left
	glEnd();
}
