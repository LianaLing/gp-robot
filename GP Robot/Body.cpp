#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body.h"

using namespace N;
using namespace std;
using namespace B;

function fh2;

void body::upperChest(GLenum gltype) {
	// front top
	glColor3f(1, 0.7, 0.3);
	glBegin(gltype);
	fh2.v3f(378.75, 265, 25);
	fh2.v3f(356.25, 270, 30);
	fh2.v3f(443.75, 270, 30);
	fh2.v3f(421.25, 265, 25);
	glEnd();

	// front btm
	glColor3f(1, 0, 0.5);
	glBegin(gltype);
	fh2.v3f(356.25, 270, 30);
	fh2.v3f(340, 307.5, 50);
	fh2.v3f(460, 307.5, 50);
	fh2.v3f(443.75, 270, 30);
	glEnd();

	// left top
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh2.v3f(378.75, 265, -37.5);
	fh2.v3f(356.25, 270, -42.5);
	fh2.v3f(356.25, 270, 30);
	fh2.v3f(378.75, 265, 25);
	glEnd();

	// left btm
	glColor3f(0, 1, 0);
	glBegin(gltype);
	fh2.v3f(356.25, 270, -42.5);
	fh2.v3f(340, 307.5, -60);
	fh2.v3f(340, 307.5, 50);
	fh2.v3f(356.25, 270, 30);
	glEnd();

	// right top
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh2.v3f(421.25, 265, 25);
	fh2.v3f(443.75, 270, 30);
	fh2.v3f(443.75, 270, -42.5);
	fh2.v3f(421.25, 265, -37.5);
	glEnd();

	// right btm
	glColor3f(0.2, 1, 0.5);
	glBegin(gltype);
	fh2.v3f(443.75, 270, -42.5);
	fh2.v3f(460, 307.5, -60);
	fh2.v3f(460, 307.5, 50);
	fh2.v3f(443.75, 270, 30);
	glEnd();

	// back top
	glColor3f(0, 0.7, 0.3);
	glBegin(gltype);
	fh2.v3f(378.75, 265, -37.5);
	fh2.v3f(356.25, 270, -42.5);
	fh2.v3f(443.75, 270, -42.5);
	fh2.v3f(421.25, 265, -37.5);
	glEnd();

	// back btm
	glColor3f(0.5, 0.3, 1);
	glBegin(gltype);
	fh2.v3f(356.25, 270, -42.5);
	fh2.v3f(340, 307.5, -60);
	fh2.v3f(460, 307.5, -60);
	fh2.v3f(443.75, 270, -42.5);
	glEnd();
}