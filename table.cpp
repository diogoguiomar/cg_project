#include "main.h"
#include "table.h"

void drawTable ()
{
	// top table
	glBindTexture(GL_TEXTURE_2D, texture[7]);
  	glBegin(GL_QUADS); 
  		glTexCoord2f(0.0, 0.0); glVertex3f( -3.0, -0.001,  2.0 ); // bot left  
  		glTexCoord2f(1.0, 0.0); glVertex3f(  3.0, -0.001,  2.0 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  3.0, -0.001, -2.0 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -3.0, -0.001, -2.0 ); // top left*/
  		
  	// bottom table
  		glTexCoord2f(0.0, 0.0); glVertex3f( -3.0, -0.2, -2.0 ); // bot left 
  		glTexCoord2f(1.0, 0.0); glVertex3f(  3.0, -0.2, -2.0 ); // bot right 
  		glTexCoord2f(1.0, 1.0); glVertex3f(  3.0, -0.2,  2.0 ); // top right 
		glTexCoord2f(0.0, 1.0); glVertex3f( -3.0, -0.2,  2.0 ); // top right
  		
	// front table 
  		glTexCoord2f(0.0, 0.0); glVertex3f( -3.0, -0.2,  2.0 ); // bot left  
  		glTexCoord2f(1.0, 0.0); glVertex3f(  3.0, -0.2,  2.0 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  3.0, -0.001, 2.0 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -3.0, -0.001, 2.0 ); // top left
  		
  	// back table	
  		glTexCoord2f(0.0, 0.0); glVertex3f( -3.0, -0.2,  -2.0 ); // bot left  
  		glTexCoord2f(1.0, 0.0); glVertex3f(  3.0, -0.2,  -2.0 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  3.0, -0.001, -2.0 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -3.0, -0.001, -2.0 ); // top left
  		
	// right table 
  		glTexCoord2f(0.0, 0.0); glVertex3f(  3.0, -0.2,  2.0 ); // bot left  
  		glTexCoord2f(1.0, 0.0); glVertex3f(  3.0, -0.2, -2.0 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f(  3.0, -0.001, -2.0 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f(  3.0, -0.001, 2.0 ); // top left
  		
	// left table
  		glTexCoord2f(0.0, 0.0); glVertex3f( -3.0, -0.2, -2.0 ); // bot left  
  		glTexCoord2f(1.0, 0.0); glVertex3f( -3.0, -0.2,  2.0 ); // bot right
  		glTexCoord2f(1.0, 1.0); glVertex3f( -3.0, -0.001, 2.0 ); // top right
  		glTexCoord2f(0.0, 1.0); glVertex3f( -3.0, -0.001, -2.0 ); // top left  		
	glEnd();
}
