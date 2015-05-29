#include "computer.h"
#include "shadows.h"

void displayShadows ()
{
	// draw screen shadow
  	glBegin(GL_QUADS); 
  	glColor4f(0.0, 0.0, 0.0, 1.0);
		glVertex3f( -0.9,  0.0, -0.8 ); // bot left
  		glVertex3f(  0.9,  0.0, -0.8 ); // bot right
  		glVertex3f(  0.9,  0.0, -1.8 ); // top right
  		glVertex3f( -0.9,  0.0, -1.8 ); // top left
	
	// draw mouse shadow
  		glVertex3f( 1.0f, 0.01f, 0.2f); // bot left
  		glVertex3f( 1.2f, 0.01f, 0.2f); // bot right
		glVertex3f( 1.2f, 0.01f, 0.3f); // top right
		glVertex3f( 1.0f, 0.01f, 0.3f); // top left
		
	// draw keyboard shadow
		glVertex3f( -1.0f, 0.0f, 0.4f); // bot left
		glVertex3f( 0.45f, 0.0f, 0.4f); // bot right
		glVertex3f( 0.45f, 0.0f, 0.3f); // bot right
		glVertex3f( -1.0f, 0.0f, 0.3f); // bot right
	glEnd();
}
