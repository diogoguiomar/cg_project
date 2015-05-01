#include "computer.h"
#include "textures.h"
#include "keyboard.h"

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
	
	glutSwapBuffers();
}

void mainMenu(int option)
{
	if (option == QUIT) exit(0);
}

void viewMenu(int option)
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

void polygonModeMenu(int option)
{
	// Wired Mode
	if (option == WIRED_MODE) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
	// Filled Mode
	else 
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		
	glutPostRedisplay();
}

void createMenu()
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

void rotate(int initial_y)
{
	cout << rotate_y << endl;
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
    glOrtho(-w/100.0, w/100.0, -h/100.0, h/100.0, -5, 5);
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

