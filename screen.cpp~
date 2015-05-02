#include "computer.h"
#include "screen.h"

void displayScreen ()
{
	// screen - front
	glBindTexture(GL_TEXTURE_2D, texture[6]);
  	glBegin(GL_QUADS);
  		glTexCoord2f(0.0, 0.0); glVertex3f( -1.0, 0.6, -0.4 ); // bot left 
  		glTexCoord2f(1.0, 0.0); glVertex3f(  1.0, 0.6, -0.4 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  1.0, 1.6, -0.4 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -1.0, 1.6, -0.4 ); // top left
  	glEnd();
 
  	// screen - back
  	glBindTexture(GL_TEXTURE_2D, texture[5]);
  	glBegin(GL_QUADS); 
  		glTexCoord2f(0.0, 0.0); glVertex3f( -1.0, 0.6, -0.5 ); // bot left  
  		glTexCoord2f(1.0, 0.0); glVertex3f(  1.0, 0.6, -0.5 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  1.0, 1.6, -0.5 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -1.0, 1.6, -0.5 ); // top left
  		
  	// screen - right
  		glTexCoord2f(0.0, 0.0); glVertex3f( 1.0,  0.6, -0.4 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f( 1.0,  0.6, -0.5 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.6, -0.5 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.6, -0.4 ); // top left
  		
	// screen - left
		glTexCoord2f(0.0, 0.0); glVertex3f( -1.0, 0.6, -0.5 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f( -1.0, 0.6, -0.4 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f( -1.0, 1.6, -0.4 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -1.0, 1.6, -0.5 ); // top left
  		
	// screen - top
		glTexCoord2f(0.0, 0.0); glVertex3f( -1.0,  1.6, -0.4 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f(  1.0,  1.6, -0.4 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  1.0,  1.6, -0.5 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -1.0,  1.6, -0.5 ); // top left
 
  	// screen - bottom
  		glTexCoord2f(0.0, 0.0); glVertex3f( -1.0,  0.6, -0.5 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f(  1.0,  0.6, -0.5 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  1.0,  0.6, -0.4 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -1.0,  0.6, -0.4 ); // top left
  		
  	// support - front
  		glTexCoord2f(0.0, 0.0); glVertex3f( -0.25,  0.4, -0.5 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f(  0.25,  0.4, -0.5 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  0.25,  0.9, -0.5 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -0.25,  0.9, -0.5 ); // top left
  
  	// support - top
  		glTexCoord2f(0.0, 0.0); glVertex3f( -0.25,  0.9, -0.5 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f(  0.25,  0.9, -0.5 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  0.25,  0.9, -0.6 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -0.25,  0.9, -0.6 ); // top left
  	
    // support - right  
    	glTexCoord2f(0.0, 0.0); glVertex3f(  0.25,  0.4, -0.5 ); // bot left
    	glTexCoord2f(1.0, 0.0); glVertex3f(  0.25,  0.4, -0.6 ); // bot right
    	glTexCoord2f(1.0, 1.0); glVertex3f(  0.25,  0.9, -0.6 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f(  0.25,  0.9, -0.5 ); // top left		
  	
  	// support - left  
  		glTexCoord2f(0.0, 0.0); glVertex3f( -0.25,  0.4, -0.6 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f( -0.25,  0.4, -0.5 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f( -0.25,  0.9, -0.5 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -0.25,  0.9, -0.6 ); // top left 	
  	
  	// support - back
  		glTexCoord2f(0.0, 0.0); glVertex3f( -0.25,  0.4, -0.6 ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f(  0.25,  0.4, -0.6 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  0.25,  0.9, -0.6 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -0.25,  0.9, -0.6 ); // top left
  	glEnd();
  	
    glBegin(GL_LINES);
    double i;
    // bottom elipse
  		for(i = 0.0; i < 2*M_PI; i+=0.02) {
  			glTexCoord2f(0.0, 0.0); glVertex3f(-0.4, BASE, -0.5);
  			glTexCoord2f(1.0, 0.0); glVertex3f(RAIO_EIXO_X * cos(i), BASE, -0.5 + RAIO_EIXO_Y * sin(i));
  		}
  	// top elipse
  		for(i = 0.0; i < 2*M_PI; i+=0.02) {
  			glTexCoord2f(0.0, 0.0); glVertex3f(-0.4, 0.4, -0.5);
  			glTexCoord2f(1.0, 0.0); glVertex3f(RAIO_EIXO_X * cos(i), ALTURA_BASE, -0.5 + RAIO_EIXO_Y * sin(i));
  		}
  	glEnd();
	// fill
  	glBegin(GL_TRIANGLE_STRIP);
  		for(i = 0.0; i < 2*M_PI; i+=0.2) {
  			glTexCoord2f(0.0, 0.0); glVertex3f(RAIO_EIXO_X * cos(i), BASE, -0.5 + RAIO_EIXO_Y * sin(i));
  			glTexCoord2f(1.0, 0.0); glVertex3f(RAIO_EIXO_X * cos(i), ALTURA_BASE, -0.5 + RAIO_EIXO_Y * sin(i));
  		}
  	glEnd();
}
