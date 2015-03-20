#include <iostream>
#include <cmath>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define RAIO_EIXO_X 0.4
#define RAIO_EIXO_Y 0.2
#define ALTURA_BASE 0.1

using namespace std;

double rotate_y = 0; 
double rotate_x = 0;

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
	
	// Cor do fundo
	glClearColor(1.0, 1.0, 1.0, 0.0);
	
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
  		glVertex3f(  0.9, 0.4,  0.01 );      
  		glVertex3f(  0.9, 1.2,  0.01 );    
  		glVertex3f( -0.9, 1.2,  0.01 );      
  	    glVertex3f( -0.9, 0.4,  0.01 );    
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
  	/*glBegin(GL_QUADS);
		glVertex3f( 2.2f, 0.00f, 0.5f); // top right
		glVertex3f( 2.0f, 0.00f, 0.5f); // top left
		glVertex3f( 2.0f, 0.00f, 1.0f); // bot left
		glVertex3f( 2.2f, 0.00f, 1.0f); // bot right
	glEnd();*/
	
  	/* TECLADO */
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
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
		glVertex3f( 0.4f, 0.09f, 0.45f); // top right
		glVertex3f(-0.95f, 0.09f, 0.45f); // top left
		glVertex3f(-0.95f, 0.09f, 0.95f); // bot left
		glVertex3f( 0.4f, 0.09f, 0.95f); // bot right
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

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -w/200.0, w/200.0, -h/200.0, h/200.0, -5, 5);
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	// Create window
	glutCreateWindow("Test version");
	
	// Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);
	
	// Ativa o modo de arames
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
	
	// Callback functions  	
	glutDisplayFunc(drawScene);
	glutSpecialFunc(specialKeys);
	glutReshapeFunc(reshape);
	glutMainLoop();
	
	return 0;
}
