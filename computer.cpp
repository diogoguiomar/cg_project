#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "computer.h"

using namespace std;

double rotate_y = 0; 
double rotate_x = 0;
double zoom = 1;

// Globals.
static unsigned int texture[2]; // Array of texture indices.

// Struct of bitmap file.
struct BitMapFile
{
   int sizeX;
   int sizeY;
   unsigned char *data;
};

// Routine to read a bitmap file.
// Works only for uncompressed bmp files of 24-bit color.
BitMapFile *getBMPData(string filename)
{
   BitMapFile *bmp = new BitMapFile;
   unsigned int size, offset, headerSize;
  
   // Read input file name.
   ifstream infile(filename.c_str(), ios::binary);
 
   // Get the starting point of the image data.
   infile.seekg(10);
   infile.read((char *) &offset, 4); 
   
   // Get the header size of the bitmap.
   infile.read((char *) &headerSize,4);

   // Get width and height values in the bitmap header.
   infile.seekg(18);
   infile.read( (char *) &bmp->sizeX, 4);
   infile.read( (char *) &bmp->sizeY, 4);

   // Allocate buffer for the image.
   size = bmp->sizeX * bmp->sizeY * 24;
   bmp->data = new unsigned char[size];

   // Read bitmap data.
   infile.seekg(offset);
   infile.read((char *) bmp->data , size);
   
   // Reverse color from bgr to rgb.
   int temp;
   for (int i = 0; i < size; i += 3)
   { 
      temp = bmp->data[i];
	  bmp->data[i] = bmp->data[i+2];
	  bmp->data[i+2] = temp;
   }

   return bmp;
}

// Load external textures.
void loadExternalTextures()			
{
   // Local storage for bmp image data.
   BitMapFile *image[2];

   // Load the textures.
   image[0] = getBMPData("textures/teclado01.bmp");

   // Bind sky image to texture index[0]
   glBindTexture(GL_TEXTURE_2D, texture[0]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);				
}

// Drawing routine.
void drawScene(void)
{
	float i;
	
	// Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	// Reset transformations
  	glLoadIdentity();
  	
	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glPushMatrix();
	
	// Scale ajust
	glScalef(zoom, zoom, zoom);	
	
	// Caixa - Tras
  	glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 );    
  		glVertex3f(  0.7, 0.3, -1.0 );      
  		glVertex3f(  0.7, 0.6, -1.0 );    
  		glVertex3f( -0.7, 0.6, -1.0 );      
  	    glVertex3f( -0.7, 0.3, -1.0 );    
  	glEnd();
  	
  	// Caixa - Frente
  	glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 );  
  		glVertex3f(  0.7, 0.3,  0.0 );
  		glVertex3f(  0.7, 0.6,  0.0 );
  		glVertex3f( -0.7, 0.6,  0.0 );
  		glVertex3f( -0.7, 0.3,  0.0 );
  	glEnd();
  	
  	// Caixa - Drive
  	glBegin(GL_POLYGON);
  		glColor3f( 0.0, 0.0, 0.0 );  
  		glVertex3f(  0.0, 0.4,  0.01 );
  		glVertex3f(  0.0, 0.5,  0.01 );
  		glVertex3f( -0.6, 0.5,  0.01 );
  		glVertex3f( -0.6, 0.4,  0.01 );
  	glEnd();
  	  	
  	// Caixa - Lateral direita
  	glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 ); 
  		glVertex3f( 0.7,  0.3, -1.0 );
  		glVertex3f( 0.7,  0.6, -1.0 );
  		glVertex3f( 0.7,  0.6,  0.0 );
  		glVertex3f( 0.7,  0.3,  0.0 );
  	glEnd();
 
  	// Caixa - Lateral Esquerda
  	glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 );
  		glVertex3f( -0.7, 0.3,  0.0 );
  		glVertex3f( -0.7, 0.6,  0.0 );
  		glVertex3f( -0.7, 0.6, -1.0 );
  		glVertex3f( -0.7, 0.3, -1.0 );
  	glEnd();
 
  	// Caixa - Topo
  	glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 ); 
  		glVertex3f(  0.7,  0.6,  0.0 );
  		glVertex3f(  0.7,  0.6, -1.0 );
  		glVertex3f( -0.7,  0.6, -1.0 );
  		glVertex3f( -0.7,  0.6,  0.0 );
  	glEnd();
 
  	// Caixa - Parte debaixo
  	glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 ); 
  		glVertex3f(  0.7,  0.3, -1.0 );
  		glVertex3f(  0.7,  0.3,  0.0 );
  		glVertex3f( -0.7,  0.3,  0.0 );
  		glVertex3f( -0.7,  0.3, -1.0 );
  	glEnd();
	
	// Desenha a led de dados
	glColor3f( 1.0, 0.5, 0.0 );
    glBegin(GL_LINES);
  		for(i = 0; i < 2*M_PI; i+=0.02) {
  			glVertex3f(0.1, 0.45, 0.01);
  			glVertex3f(0.1 + RAIO_LED * cos(i), 0.45 + RAIO_LED * sin(i), 0.01);
  		}
  	glEnd();
  	
	// Desenha a led de power
	glColor3f( 0.0, 1.0, 0.0 );
    glBegin(GL_LINES);
  		for(i = 0; i < 2*M_PI; i+=0.02) {
  			glVertex3f(0.2, 0.45, 0.01);
  			glVertex3f(0.2 + RAIO_LED * cos(i), 0.45 + RAIO_LED * sin(i), 0.01);
  		}
  	glEnd();
  	
  	// Desenha o botao de power
	glColor3f( 0.0, 0.0, 0.0 );
    glBegin(GL_LINES);
  		for(i = 0; i < 2*M_PI; i+=0.02) {
  			glVertex3f(0.4, 0.45, 0.01);
  			glVertex3f(0.4 + RAIO_POWER * cos(i), 0.45 + RAIO_POWER * sin(i), 0.01);
  		}
  	glEnd();
	
	
	// Monitor - Tras
  	glBegin(GL_POLYGON);
  		glColor3f(  0.0,  0.0,  0.0 );     
  		glVertex3f(  1.0, 0.3, -0.2 );      
  		glVertex3f(  1.0, 1.3, -0.2 );    
  		glVertex3f( -1.0, 1.3, -0.2 );      
  	    glVertex3f( -1.0, 0.3, -0.2 );    
  	glEnd();
  	
  	// Monitor - Frente
  	glBegin(GL_POLYGON);
  		glColor3f(  0.0,  0.0,  0.0 );   
  		glVertex3f(  1.0, 0.3,  0.0 );
  		glVertex3f(  1.0, 1.3,  0.0 );
  		glVertex3f( -1.0, 1.3,  0.0 );
  		glVertex3f( -1.0, 0.3,  0.0 );
  	glEnd();
  	
  	// Monitor - Vidro
   	glBegin(GL_POLYGON);
  		glColor3f(  0.0,  1.3,  1.0 );     
  		glVertex3f( -0.9, 0.4,  0.01 );     
  		glVertex3f(  0.9, 0.4,  0.01 );      
  		glVertex3f(  0.9, 1.2,  0.01 );      
  	    glVertex3f( -0.9, 1.2,  0.01 );   
  	glEnd();
  	
  	// Monitor - Lateral direita
  	glBegin(GL_POLYGON);
  		glColor3f( 0.0, 0.0, 0.0 ); 
  		glVertex3f( 1.0,  0.3, -0.2 );
  		glVertex3f( 1.0,  1.3, -0.2 );
  		glVertex3f( 1.0,  1.3,  0.0 );
  		glVertex3f( 1.0,  0.3,  0.0 );
  	glEnd();
 
  	// Monitor - Lateral Esquerda
  	glBegin(GL_POLYGON);
  		glColor3f(  0.0,  0.0, 0.0 ); 
  		glVertex3f( -1.0, 0.3,  0.0 );
  		glVertex3f( -1.0, 1.3,  0.0 );
  		glVertex3f( -1.0, 1.3, -0.2 );
  		glVertex3f( -1.0, 0.3, -0.2 );
  	glEnd();
 
  	// Monitor - Topo
  	glBegin(GL_POLYGON);
  		glColor3f( 0.0, 0.0, 0.0 ); 
  		glVertex3f(  1.0,  1.3,  0.0 );
  		glVertex3f(  1.0,  1.3, -0.2 );
  		glVertex3f( -1.0,  1.3, -0.2 );
  		glVertex3f( -1.0,  1.3,  0.0 );
  	glEnd();
 
  	// Monitor - Parte debaixo
  	glBegin(GL_POLYGON);
  		glColor3f( 0.0, 0.0, 0.0 ); 
  		glVertex3f(  1.0,  0.3, -0.2 );
  		glVertex3f(  1.0,  0.3,  0.0 );
  		glVertex3f( -1.0,  0.3,  0.0 );
  		glVertex3f( -1.0,  0.3, -0.2 );
  	glEnd();
  	
  	// Base - Topo
    glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 ); 
  		glVertex3f(  0.25,  0.5, -0.3 );
  		glVertex3f(  0.25,  0.5, -0.2 );
  		glVertex3f( -0.25,  0.5, -0.2 );
  		glVertex3f( -0.25,  0.5, -0.3 );
  	glEnd();
  	
  	// Base - Frente
    glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 ); 
  		glVertex3f(  0.25,  0.5, -0.2 );
  		glVertex3f(  0.25,  0.1, -0.2 );
  		glVertex3f( -0.25,  0.1, -0.2 );
  		glVertex3f( -0.25,  0.5, -0.2 );
  	glEnd();
  	
  	// Base - Tras
    glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 );  
  		glVertex3f(  0.25,  0.5, -0.3 );
  		glVertex3f(  0.25,  0.1, -0.3 );
  		glVertex3f( -0.25,  0.1, -0.3 );
  		glVertex3f( -0.25,  0.5, -0.3 );
  	glEnd();
  	
    // Base - Direita
    glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 );  
  		glVertex3f(  0.25,  0.5, -0.2 );
  		glVertex3f(  0.25,  0.1, -0.2 );
  		glVertex3f(  0.25,  0.1, -0.3 );
  		glVertex3f(  0.25,  0.5, -0.3 );
  	glEnd();
  	
  	// Base - Esquerda
    glBegin(GL_POLYGON);
  		glColor3f( 0.7, 0.7, 0.7 );  
  		glVertex3f( -0.25,  0.5, -0.2 );
  		glVertex3f( -0.25,  0.1, -0.2 );
  		glVertex3f( -0.25,  0.1, -0.3 );
  		glVertex3f( -0.25,  0.5, -0.3 );
  	glEnd();

  	
  	glColor3f( 0.0, 0.0, 0.0 );
    glBegin(GL_LINES);
    // Desenha a elipse inferior
  		for(i = 0; i < 2*M_PI; i+=0.02) {
  			glVertex3f(-0.2, 0.0, -0.2);
  			glVertex3f(RAIO_EIXO_X * cos(i), 0, -0.2+RAIO_EIXO_Y * sin(i));
  		}
  	// Desenha a elipse superior
  		for(i = 0; i < 2*M_PI; i+=0.02) {
  			glVertex3f(-0.2, ALTURA_BASE, -0.2);
  			glVertex3f(RAIO_EIXO_X * cos(i), ALTURA_BASE, -0.2+RAIO_EIXO_Y * sin(i));
  		}
  	glEnd();
	// Desenha o contorno da base
  	glBegin(GL_TRIANGLE_STRIP);
  		for(i = 0.0; i < 2*M_PI; i+=0.2) {
  			glVertex3f(RAIO_EIXO_X * cos(i), 0.0, -0.2+RAIO_EIXO_Y * sin(i));
  			glVertex3f(RAIO_EIXO_X * cos(i), ALTURA_BASE, -0.2+RAIO_EIXO_Y * sin(i));
  		}
  	glEnd();
  	
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
		glVertex3f( 2.2f, 0.00f, 0.3f); // top right
		glVertex3f( 2.0f, 0.00f, 0.3f); // top left
		glVertex3f( 2.0f, 0.00f, 0.7f); // bot left
		glVertex3f( 2.2f, 0.00f, 0.7f); // bot right
	glEnd();
	
  	/* TECLADO */
	
	/*int k;
	
	glBegin(GL_QUADS);
	glColor3f(0.8f,0.8f,0.8f);
	for (k = 0; k < 24; ++k) {
		glVertex3fv(vertices[k%24]);
	}
	glEnd();*/
	
	
	/* Teclado - base */
	glBegin(GL_QUADS);
		glColor3f(0.8f,0.8f,0.8f);
		// front
		glVertex3f( 0.8f, 0.07f, 1.0f); // top right
		glVertex3f(-1.0f, 0.07f, 1.0f); // top left
		glVertex3f(-1.0f, 0.0f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.0f, 1.0f); // bot right
		// back
		glVertex3f( 0.8f, 0.07f, 0.4f); // top right
		glVertex3f(-1.0f, 0.07f, 0.4f); // top left
		glVertex3f(-1.0f, 0.0f, 0.4f); // bot left
		glVertex3f( 0.8f, 0.0f, 0.4f); // bot right
		// top
		glVertex3f( 0.8f, 0.07f, 0.4f); // top right
		glVertex3f(-1.0f, 0.07f, 0.4f); // top left
		glVertex3f(-1.0f, 0.07f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.07f, 1.0f); // bot right
		// bot
		glVertex3f( 0.8f, 0.0f, 0.4f); // top right
		glVertex3f(-1.0f, 0.0f, 0.4f); // top left
		glVertex3f(-1.0f, 0.0f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.0f, 1.0f); // bot right
		// right
		glVertex3f( 0.8f, 0.07f, 0.4f); // top right
		glVertex3f( 0.8f, 0.07f, 1.0f); // top left
		glVertex3f( 0.8f, 0.0f, 1.0f); // bot left
		glVertex3f( 0.8f, 0.0f, 0.4f); // bot right
		// left
		glVertex3f(-1.0f, 0.07f, 0.4f); // top right
		glVertex3f(-1.0f, 0.07f, 1.0f); // top left
		glVertex3f(-1.0f, 0.0f, 1.0f); // bot left
		glVertex3f(-1.0f, 0.0f, 0.4f); // bot right
	glEnd();

	/* Teclado - teclas01 */
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
		glColor3f(0.0f,0.0f,0.0f);
		// front
		glVertex3f( 0.4f, 0.09f, 0.95f); // top right
		glVertex3f(-0.95f, 0.09f, 0.95f); // top left
		glVertex3f(-0.95f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.95f); // bot right
		// back
		glVertex3f( 0.4f, 0.09f, 0.45f); // top right
		glVertex3f(-0.95f, 0.09f, 0.45f); // top left
		glVertex3f(-0.95f, 0.01f, 0.45f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.45f); // bot right
		// top
		glTexCoord2f(0.0, 0.0); glVertex3f(-0.95f, 0.09f, 0.95f); // bot left
		glTexCoord2f(1.0, 0.0); glVertex3f( 0.4f, 0.09f, 0.95f); // bot right
		glTexCoord2f(1.0, 1.0); glVertex3f( 0.4f, 0.09f, 0.45f); // top right
		glTexCoord2f(0.0, 1.0); glVertex3f(-0.95f, 0.09f, 0.45f); // top left
		// bot
		glVertex3f( 0.4f, 0.01f, 0.45f); // top right
		glVertex3f(-0.95f, 0.01f, 0.45f); // top left
		glVertex3f(-0.95f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.95f); // bot right
		// right
		glVertex3f( 0.4f, 0.09f, 0.45f); // top right
		glVertex3f( 0.4f, 0.09f, 0.95f); // top left
		glVertex3f( 0.4f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.4f, 0.01f, 0.45f); // bot right
		// left
		glVertex3f(-0.95f, 0.09f, 0.45f); // top right
		glVertex3f(-0.95f, 0.09f, 0.95f); // top left
		glVertex3f(-0.95f, 0.01f, 0.95f); // bot left
		glVertex3f(-0.95f, 0.01f, 0.45f); // bot right
	glEnd();

	/* Teclado - teclas02 */
	glBegin(GL_QUADS);
		glColor3f(0.0f,0.0f,0.0f);
		// front
		glVertex3f( 0.75f, 0.09f, 0.95f); // top right
		glVertex3f( 0.45f, 0.09f, 0.95f); // top left
		glVertex3f( 0.45f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.75f, 0.01f, 0.95f); // bot right
		// back
		glVertex3f( 0.75f, 0.09f, 0.45f); // top right
		glVertex3f( 0.45f, 0.09f, 0.45f); // top left
		glVertex3f( 0.45f, 0.01f, 0.45f); // bot left
		glVertex3f( 0.75f, 0.01f, 0.45f); // bot right
		// top
		glVertex3f( 0.75f, 0.09f, 0.45f); // top right
		glVertex3f( 0.45f, 0.09f, 0.45f); // top left
		glVertex3f( 0.45f, 0.09f, 0.95f); // bot left
		glVertex3f( 0.75f, 0.09f, 0.95f); // bot right
		// bot
		glVertex3f( 0.75f, 0.01f, 0.45f); // top right
		glVertex3f( 0.45f, 0.01f, 0.45f); // top left
		glVertex3f( 0.45f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.75f, 0.01f, 0.95f); // bot right
		// right
		glVertex3f( 0.75f, 0.09f, 0.5f); // top right
		glVertex3f( 0.75f, 0.09f, 0.95f); // top left
		glVertex3f( 0.75f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.75f, 0.01f, 0.5f); // bot right
		// left
		glVertex3f( 0.45f, 0.09f, 0.45f); // top right
		glVertex3f( 0.45f, 0.09f, 0.95f); // top left
		glVertex3f( 0.45f, 0.01f, 0.95f); // bot left
		glVertex3f( 0.45f, 0.01f, 0.45f); // bot right
	glEnd();
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

// Callback routine key entry.
void specialKeys(int key, int x, int y) 
{
	// Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;
 
	// Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;
 
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;
 
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
 
	// Request display update
	glutPostRedisplay();
}

void rotate (int initial_y)
{
	cout << rotate_y << endl;
	rotate_y += 5;
	glutPostRedisplay();
	if (rotate_y < 360 + initial_y) {
		glutTimerFunc(40, rotate, initial_y);
	}
}

void animation ()
{
	// Saves initial y axis position
	double initial_y = rotate_y;
	if (rotate_y > 360) {
		rotate_y -= 360;
		initial_y = rotate_y;
	}	
	rotate(initial_y);
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			animation();
	}
}

void normalKeys (unsigned char key, int x, int y) 
{
	// Zoom in
	if (key == '+')
		zoom += 0.05;
	// Zoom Out
    else if (key == '-' && zoom > 0)
    	zoom -= 0.05;
    // Close program
    else if (key == ESC)
		exit(0);
	// Request display update	
	glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -w/200.0, w/200.0, -h/200.0, h/200.0, -5, 5);
}

void viewMenu (int option)
{
	switch (option) {
		case TOP_VIEW: 
			rotate_y = 0, rotate_x = 90;
			break;		
		case LEFT_SIDE_VIEW:
			rotate_x = 0, rotate_y = 90;
			break;			
		case BEHIND_VIEW:
			rotate_x = 0, rotate_y = 180;
			break;
		case PRESPECTIVE_VIEW:
			rotate_x = 45, rotate_y = 45;
			break;		
	}	
	glutPostRedisplay();
}

void polygonModeMenu (int option)
{
	// Wired Mode
	if (option == WIRED_MODE) { 
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
	}
	// Filled Mode
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glutPostRedisplay();
}

void mainMenu (int option)
{
	if (option == QUIT) exit(0);
}

void createMenu ()
{
	int polygonMenuHandle, viewMenuHandle;
	
	// View Menu
	viewMenuHandle = glutCreateMenu(viewMenu);
	glutAddMenuEntry("Top View", TOP_VIEW);
	glutAddMenuEntry("Left Side View", LEFT_SIDE_VIEW);
	glutAddMenuEntry("Behind View", BEHIND_VIEW);
	glutAddMenuEntry("Prespective View", PRESPECTIVE_VIEW);
	
	// Polygon Mode menu
	polygonMenuHandle = glutCreateMenu(polygonModeMenu);
	glutAddMenuEntry("Wired", WIRED_MODE);
	glutAddMenuEntry("Filled", FILLED_MODE);

	// Main menu
	glutCreateMenu(mainMenu);
	glutAddSubMenu("Polygon Mode", polygonMenuHandle);
	glutAddSubMenu("View", viewMenuHandle);
	glutAddMenuEntry("Quit", QUIT);
	
	// Menu attached on right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init () 
{    
	// Create window with name "CG Project"
	glutCreateWindow("CG Project");
	
		// Background color
	glClearColor(1.0, 1.0, 1.0, 0.0);
	
	// Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);
    
    // Create texture index array.
   glGenTextures(2, texture);

   // Load external textures.
   loadExternalTextures();

   // Turn on OpenGL texturing.
   glEnable(GL_TEXTURE_2D); 

   // Specify how texture values combine with current surface color values.
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
   
	// Create the menu
	createMenu();
	

	
	   // Cull back faces.
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	// Initialization functions
	init();
		
	// Callback functions  	
	glutDisplayFunc(drawScene);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(normalKeys);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
	
	return 0;
}
