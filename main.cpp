#include "main.h"
#include "textures.h"
#include "keyboard.h"
#include "mouse.h"
#include "tower.h"
#include "screen.h"
#include "shadows.h"
#include "table.h"
#include "menu.h"
#include "wires.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glut.h>
#  include <GL/glext.h>
#endif

#define ESC 27

/* lighting on/off (1 = on, 0 = off) */
int light;

/* white ambient light at half intensity (rgba) */
GLfloat LightAmbient[] = { 2.0f, 2.0f, 2.0f, 1.0f };

/* super bright, full intensity diffuse light. */
GLfloat LightDiffuse[] = { 4.0f, 4.0f, 4.0f, 4.0f };

/* Second light with less light than first one*/
GLfloat LightDiffuse2[] = { 0.0f, 0.0f, 0.0f, 0.0f };

/* position of light (x, y, z, (position of light)) */
GLfloat LightPosition[] = { 0.0f, 1.0f, 10.0, 1.0f };

double move_x = 0;
double move_y = 0;
double rotate_y = 0; 
double rotate_x = 0;
double zoom = 1;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// Rotate and scale
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glScalef(zoom, zoom, zoom);	
	
	// translacao que move o computador de local
	glTranslatef(move_x, move_y, 0.0f);
	if(light)
		displayShadows();
	displayKeyboard();
	// correcao da posicao do rato
	glPushMatrix();
	glTranslatef(-1.0f, 0.0f, 0.0f);
	displayMouse();
	glPopMatrix();
	
	drawTable();
	displayTower();
	displayScreen();
	displayWire();
	glutSwapBuffers();
}

void rotate(int initial_y)
{
	rotate_y += 5;
	glutPostRedisplay();
	if (rotate_y < 360 + initial_y) {
		glutTimerFunc(40, rotate, initial_y);
	}
}

void animation()
{
	// Saves initial y axis position
	double initial_y = rotate_y;
	if (rotate_y > 360) {
		rotate_y -= 360;
		initial_y = rotate_y;
	}	
	rotate(initial_y);
}

/* animacao com rato */ 
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			animation();
	}
}

/* rotação utilizando as setas */
void specialKeyInput(int key, int x, int y) 
{
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	glutPostRedisplay();
}

void keyInput(unsigned char key, int x, int y) 
{
	/* zoom */
	if (key == '+')
		zoom += 0.05;
    else if (key == '-' && zoom > 0)
    	zoom -= 0.05;
    else if (key == ESC)
    	exit(0);
    /* ligar/desligar luzes */
	else if (key == 'l') {
		light = light ? 0 : 1;
		if (light) {
	    	glEnable(GL_LIGHT1);
	    	glDisable(GL_LIGHT2);
		} else {
			glDisable(GL_LIGHT1);
	    	glEnable(GL_LIGHT2);
		}
	} 
	/* movimento horizontal e vertical */
	else if (key == 'w')
		move_y += 0.2;
	else if (key == 's')
		move_y -= 0.2;
	else if (key == 'a')
		move_x -= 0.2;
	else if (key == 'd')
		move_x += 0.2;	
		
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	if (h == 0) h = 1; // previne divisão por 0 caso a janela seja pequena d+
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w/100.0, w/100.0, -h/100.0, h/100.0, -10, 10);
}

void init()
{
	loadExternalTextures();	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	createMenu();
	
	// set up light number 1.
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);  // add lighting. (ambient)
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);  // add lighting. (diffuse).
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition); // set light position.
    glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient);  // add lighting. (ambient)
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse2); // add lighting. (diffuse).
    glLightfv(GL_LIGHT2, GL_POSITION,LightPosition); // set light position.
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);                           // turn light 1 on.
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH); 
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Computer");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	init();
	glutMainLoop();
	return 0;
}

