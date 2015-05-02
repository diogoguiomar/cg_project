#include "computer.h"
#include "tower.h"

void displayTower()
{
	// front
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f( -0.7f, 0.0f,  0.0f ); // bot left
		glTexCoord2f(1.0, 0.0); glVertex3f(  0.7f, 0.0f,  0.0f ); // bot right
		glTexCoord2f(1.0, 1.0); glVertex3f(  0.7f, 0.3f,  0.0f ); // top right
		glTexCoord2f(0.0, 1.0); glVertex3f( -0.7f, 0.3f,  0.0f ); // top left
  	glEnd();
  	
  	// back 
  	glBindTexture(GL_TEXTURE_2D, texture[4]); 
  	glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0); glVertex3f( -0.7f, 0.0f, -1.0f ); // bot left
		glTexCoord2f(1.0, 0.0); glVertex3f(  0.7f, 0.0f, -1.0f ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  0.7f, 0.3f, -1.0f ); // top right
 		glTexCoord2f(0.0, 1.0); glVertex3f( -0.7f, 0.3f, -1.0f ); // top left
  	glEnd();
  	
  	// top
  	glBindTexture(GL_TEXTURE_2D, texture[5]);
  	glBegin(GL_QUADS);
  		glTexCoord2f(0.0, 0.0); glVertex3f( -0.7f,  0.3f,  0.0f ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f(  0.7f,  0.3f,  0.0f ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  0.7f,  0.3f, -1.0f ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -0.7f,  0.3f, -1.0f ); // top left 
  		
  	// bot
  		glTexCoord2f(0.0, 0.0); glVertex3f( -0.7f,  0.0f,  0.0f ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f(  0.7f,  0.0f,  0.0f ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  0.7f,  0.0f, -1.0f ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -0.7f,  0.0f, -1.0f ); // top left  	
  		
  	// right
  		glTexCoord2f(0.0, 0.0); glVertex3f( 0.7f,  0.0f,  0.0f ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f( 0.7f,  0.0f, -1.0f ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f( 0.7f,  0.3f, -1.0f ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( 0.7f,  0.3f,  0.0f ); // top left  
  			
  	// left
  		glTexCoord2f(0.0, 0.0); glVertex3f( -0.7f, 0.0f, -1.0f ); // bot left
  		glTexCoord2f(1.0, 0.0); glVertex3f( -0.7f, 0.0f,  0.0f ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f( -0.7f, 0.3f,  0.0f ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -0.7f, 0.3f, -1.0f ); // top left  
  	glEnd();
}
