#include "computer.h"
#include "menu.h"

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
