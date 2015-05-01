#include "computer.h"

void displayKeyboard()
{
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	/* Teclado - base */
	glBegin(GL_QUADS);
		glColor3f(0.8f,0.8f,0.8f);
		// front
		glVertex3f(-1.0f, 0.0f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.0f, 1.0f); // bot right
		glVertex3f( 0.8f, 0.07f, 1.0f); // top right
		glVertex3f(-1.0f, 0.07f, 1.0f); // top left
		// back
		glVertex3f(-1.0f, 0.0f, 0.4f); // bot left
		glVertex3f( 0.8f, 0.0f, 0.4f); // bot right
		glVertex3f( 0.8f, 0.07f, 0.4f); // top right
		glVertex3f(-1.0f, 0.07f, 0.4f); // top left
		// top
		glVertex3f(-1.0f, 0.07f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.07f, 1.0f); // bot right
		glVertex3f( 0.8f, 0.07f, 0.4f); // top right
		glVertex3f(-1.0f, 0.07f, 0.4f); // top left
		// bot
		glVertex3f(-1.0f, 0.0f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.0f, 1.0f); // bot right
		glVertex3f( 0.8f, 0.0f, 0.4f); // top right
		glVertex3f(-1.0f, 0.0f, 0.4f); // top left	
		// right
		glVertex3f( 0.8f, 0.0f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.0f, 0.4f); // bot right
		glVertex3f( 0.8f, 0.07f, 0.4f); // top right
		glVertex3f( 0.8f, 0.07f, 1.0f); // top left	
		// left
		glVertex3f(-1.0f, 0.0f, 1.0f); // bot left
		glVertex3f(-1.0f, 0.0f, 0.4f); // bot right
		glVertex3f(-1.0f, 0.07f, 0.4f); // top right
		glVertex3f(-1.0f, 0.07f, 1.0f); // top left		
	glEnd();

	/* Teclado - teclas */
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
		glColor3f(0.0f,0.0f,0.0f);
		// front
		glVertex3f(-0.95f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.95f); // bot right
		glVertex3f( 0.4f, 0.09f, 0.95f); // top right
		glVertex3f(-0.95f, 0.09f, 0.95f); // top left
		// back
		glVertex3f(-0.95f, 0.01f, 0.45f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.45f); // bot right
		glVertex3f( 0.4f, 0.09f, 0.45f); // top right
		glVertex3f(-0.95f, 0.09f, 0.45f); // top left
		// top
		glTexCoord2f(0.0, 0.0); glVertex3f(-0.95f, 0.09f, 0.95f); // bot left
		glTexCoord2f(1.0, 0.0); glVertex3f( 0.4f, 0.09f, 0.95f); // bot right
		glTexCoord2f(1.0, 1.0); glVertex3f( 0.4f, 0.09f, 0.45f); // top right
		glTexCoord2f(0.0, 1.0); glVertex3f(-0.95f, 0.09f, 0.45f); // top left
		// bot
		glVertex3f(-0.95f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.95f); // bot right
		glVertex3f( 0.4f, 0.01f, 0.45f); // top right
		glVertex3f(-0.95f, 0.01f, 0.45f); // top left
		// right
		glVertex3f( 0.4f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.45f); // bot right
		glVertex3f( 0.4f, 0.09f, 0.45f); // top right
		glVertex3f( 0.4f, 0.09f, 0.95f); // top left	
		// left
		glVertex3f(-0.95f, 0.01f, 0.95f); // bot left
		glVertex3f(-0.95f, 0.01f, 0.45f); // bot right
		glVertex3f(-0.95f, 0.09f, 0.45f); // top right
		glVertex3f(-0.95f, 0.09f, 0.95f); // top left	
	glEnd();
}
