#ifndef MAIN_H
#define MAIN_H

using namespace std;

#include <cstdlib>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glut.h>
#  include <GL/glext.h>
#endif

#define QUIT 3
#define WIRED_MODE 5
#define FILLED_MODE 6
#define TOP_VIEW 7
#define LEFT_SIDE_VIEW 8
#define BEHIND_VIEW 9
#define PRESPECTIVE_VIEW 10

// ASCII da tecla escape
#define ESC 27
#define NUM_TEX 10

extern unsigned int texture[NUM_TEX];
#endif
