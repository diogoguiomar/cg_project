#include "computer.h"
#include "textures.h"
#include "keyboard.h"
#include "mouse.h"
#include "tower.h"
#include "screen.h"
#include "menu.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glut.h>
#  include <GL/glext.h>
#endif

#define ESC 27

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
	
	
	displayKeyboard();
	// correcao da posicao do rato
	glPushMatrix();
	glTranslatef(-1.0f, 0.0f, 0.0f);
	displayMouse();
	glPopMatrix();
	
	displayTower();
	displayScreen();
	
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

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			animation();
	}
}

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
	if (key == '+')
		zoom += 0.05;
    else if (key == '-' && zoom > 0)
    	zoom -= 0.05;
    else if (key == ESC)
    	exit(0);

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
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	createMenu();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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

