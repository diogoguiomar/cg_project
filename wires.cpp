#define _USE_MATH_DEFINES
#include <cmath>
#include "main.h"
#include "wires.h"

// Control points.
static float controlPoints[6][3] = 
{
	{ 1.1f, 0.05f, 0.3f}, { 1.0, 0.05f, -1.0}, { 2.0, 0.05f, 2.0},
	{2.0, 0.05f, -3.0}, {1.0, 0.05f, -1.5}, { 0.25f, 0.05f, -1.00f}
};
static float controlPoints2[6][3] = 
{
	{ -0.7f, 0.05f, 0.4f}, { -0.7, 0.05f, -1.2}, { -1.0, 0.05f, 1.2},
	{-1.8, 0.05f, -2.0}, {-1.09, 0.05f, -1.0}, { -0.25f, 0.05f, -1.00f}
};

// Drawing routine.
void displayWire()
{
   int i;
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, controlPoints[0]);
    glEnable(GL_MAP1_VERTEX_3);
    glLineWidth(1.5);
    
   // Draw the Bezier curve by approximating with a line strip.
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 50; i++) glEvalCoord1f( (float)i/50.0 );
   glEnd();

   // Draw the control points as dots.
   glPointSize(0.0);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_POINTS);
   for (i = 0; i < 6; i++) 
      glVertex3fv(controlPoints[i]);
   glEnd();
   
   // linha 2
      glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, controlPoints2[0]);
    glEnable(GL_MAP1_VERTEX_3);
    glLineWidth(1.5);
   
   
   // Draw the Bezier curve by approximating with a line strip.
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 50; i++) glEvalCoord1f( (float)i/50.0 );
   glEnd();

   // Draw the control points as dots.
   glPointSize(0.0);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_POINTS);
   for (i = 0; i < 6; i++) 
      glVertex3fv(controlPoints2[i]);
   glEnd();
}
