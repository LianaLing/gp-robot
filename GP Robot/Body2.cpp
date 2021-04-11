#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body2.h"

using namespace N;
using namespace std;
using namespace B2;

function fhb2;

GLenum type4 = GL_LINE_LOOP, gltype4 = GL_POLYGON;
boolean tOn4 = false;
void body2::textureOn(boolean t) {
	tOn4 = t;
}
void body2::upperChest() {
	// front top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(378.75, 265, 25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25, 270, 30);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75, 270, 30);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(421.25, 265, 25);
	glEnd();

	// front btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 270, 30);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(340 + 20, 307.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(460 - 20, 307.5, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75, 270, 30);
	glEnd();

	// left top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(378.75, 265, -37.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25, 270, -42.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(356.25, 270, 30);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(378.75, 265, 25);
	glEnd();

	// left btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 270, -42.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(340, 307.5, -60 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(340, 307.5, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(356.25, 270, 30);
	glEnd();

	// right top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(421.25, 265, 25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(443.75, 270, 30);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75, 270, -42.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(421.25, 265, -37.5);
	glEnd();

	// right btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75, 270, -42.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(460, 307.5, -60 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(460, 307.5, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75, 270, 30);
	glEnd();

	// back top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(378.75, 265, -37.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25, 270, -42.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75, 270, -42.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(421.25, 265, -37.5);
	glEnd();

	// back btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 270, -42.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(340 + 20, 307.5, -60);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(460 - 20, 307.5, -60);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75, 270, -42.5);
	glEnd();

	// front btm left 
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 270, 30);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(340 + 20, 307.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(340 + 5, 307.5, 50 - 5);
	glEnd();

	// front btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75, 270, 30);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(460 - 20, 307.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(460 - 5, 307.5, 50 - 5);
	glEnd();

	// back btm left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 270, -42.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(340 + 20, 307.5, -60);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(340 + 5, 307.5, -60 + 5);
	glEnd();

	// back btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75, 270, -42.5);
	fhb2.v3f(460 - 20, 307.5, -60);
	fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// left btm left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 270, -42.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(340, 307.5, -60 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(340 + 5, 307.5, -60 + 5);
	glEnd();

	// left btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 270, 30);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(340, 307.5, 50 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(340 + 5, 307.5, 50 - 5);
	glEnd();

	// right btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75, 270, -42.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(460, 307.5, -60 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// right btm left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75, 270, 30);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(460, 307.5, 50 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(460 - 5, 307.5, 50 - 5);
	glEnd();
}

void body2::lowerChest() {
	// front top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(340 + 20, 307.5, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(343.75 + 20, 327.5, 57.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(456.25 - 20, 327.5, 57.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(460 - 20, 307.5, 50);
	glEnd();

	// middle light (back)


	// middle light
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	fhb2.sphere(GL_POLYGON, 13, 13, 13, 400, 321, 45, 0, 100, 0, 100, 1, 1, 1);

	// front btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); glColor3f(0.0, 0.0, 0.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(343.75 + 20, 327.5, 57.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(346.25 + 20, 352.5, 52.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(453.75 - 20, 352.5, 52.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(456.25 - 20, 327.5, 57.5);
	glEnd();

	// left top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(340, 307.5, -60 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(343.75, 327.5, -60 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(343.75, 327.5, 57.5 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(340, 307.5, 50 - 20);
	glEnd();

	// left btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(343.75, 327.5, -60 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(346.25, 352.5, -47.5 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(346.25, 352.5, 52.5 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(343.75, 327.5, 57.5 - 20);
	glEnd();

	// right top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(460, 307.5, 50 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(456.25, 327.5, 57.5 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(456.25, 327.5, -60 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(460, 307.5, -60 + 20);
	glEnd();

	// right btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(456.25, 327.5, -60 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(453.75, 352.5, -47.5 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(453.75, 352.5, 52.5 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(456.25, 327.5, 57.5 - 20);
	glEnd();

	// back top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(340 + 20, 307.5, -60);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(343.75 + 20, 327.5, -60);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(456.25 - 20, 327.5, -60);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(460 - 20, 307.5, -60);
	glEnd();

	// back btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(343.75 + 20, 327.5, -60);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(346.25 + 20, 352.5, -47.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(453.75 - 20, 352.5, -47.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(456.25 - 20, 327.5, -60);
	glEnd();

	// front top left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(340 + 5, 307.5, 50 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(343.75 + 20, 327.5, 57.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(340 + 20, 307.5, 50);
	glEnd();

	// front top right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(460 - 20, 307.5, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(456.25 - 20, 327.5, 57.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(460 - 5, 307.5, 50 - 5);
	glEnd();

	// back top left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(340 + 5, 307.5, -60 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(343.75 + 5, 327.5, -60 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(343.75 + 20, 327.5, -60);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(340 + 20, 307.5, -60);
	glEnd();

	// back top right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(460 - 20, 307.5, -60);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(456.25 - 20, 327.5, -60);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// left top left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(340 + 20, 307.5, -60);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(343.75 + 20, 327.5, -60);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(343.75, 327.5, -60 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(340, 307.5, -60 + 20);
	glEnd();

	// left top right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(340, 307.5, 50 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(343.75, 327.5, 57.5 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(340 + 5, 307.5, 50 - 5);
	glEnd();

	// right top left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(460 - 5, 307.5, 50 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(456.25, 327.5, 57.5 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(460, 307.5, 50 - 20);
	glEnd();

	// right top right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(460, 307.5, -60 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(456.25, 327.5, -60 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// front btm left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(346.25 + 20, 352.5, 52.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(343.75 + 20, 327.5, 57.5);
	glEnd();

	// front btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(456.25 - 20, 327.5, 57.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(453.75 - 20, 352.5, 52.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	glEnd();

	// back btm left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(343.75 + 5, 327.5, -60 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(346.25 + 20, 352.5, -47.5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(343.75 + 20, 327.5, -60);
	glEnd();

	// back btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(456.25 - 20, 327.5, -60);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(453.75 - 20, 352.5, -47.5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	glEnd();

	// left btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(343.75, 327.5, 57.5 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(346.25, 352.5, 52.5 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	glEnd();

	// left btm left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(343.75 + 5, 327.5, -60 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(346.25, 352.5, -47.5 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(343.75, 327.5, -60 + 20);
	glEnd();

	// right btm left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(456.25, 327.5, 57.5 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(453.75, 352.5, 52.5 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	glEnd();

	// right btm right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(453.75, 352.5, -47.5 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(456.25, 327.5, -60 + 20);
	glEnd();

}

void body2::neck() {
	// front btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(382, 240, 15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 265, 25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(421.25, 265, 25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(418, 240, 15);
	glEnd();

	// left btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(382, 240, -15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 265, -25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(378.75, 265, 25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(382, 240, 15);
	glEnd();

	// right btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(800 - 382, 240, -15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(800 - 378.75, 265, -25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(800 - 378.75, 265, 25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(800 - 382, 240, 15);
	glEnd();

	// back btm
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(382, 240, -15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 265, -25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(421.25, 265, -25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(418, 240, -15);
	glEnd();

	// front top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(382, 210, 15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(382, 240, 15);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(418, 240, 15);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(418, 210, 15);
	glEnd();

	// left top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(382, 210, -15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(382, 240, -15);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(382, 240, 15);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(382, 210, 15);
	glEnd();

	// right top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(800 - 382, 210, -15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(800 - 382, 240, -15);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(800 - 382, 240, 15);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(800 - 382, 210, 15);
	glEnd();

	// back top
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(382, 210, -15);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(382, 240, -15);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(418, 240, -15);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(418, 210, -15);
	glEnd();
}

void body2::chest() {
	neck();
	upperChest();
	lowerChest();
}

void body2::adomen0() {
	//GLenum type4 = GL_POLYGON;

	// front
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(346.25 + 20, 352.5, 52.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(351.25 + 20, 400, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(448.75 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(453.75 - 20, 352.5, 52.5);
	glEnd();

	// back
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(346.25 + 20, 352.5, -47.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(351.25 + 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(448.75 - 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(453.75 - 20, 352.5, -47.5);
	glEnd();

	// left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(346.25, 352.5, -47.5 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(351.25, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(351.25, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(346.25, 352.5, 52.5 - 20);
	glEnd();

	// right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(453.75, 352.5, -47.5 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(448.75, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(448.75, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(453.75, 352.5, 52.5 - 20);
	glEnd();

	// front left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(351.25 + 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(351.25 + 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(346.25 + 20, 352.5, 52.5);
	glEnd();

	// left right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(346.25, 352.5, 52.5 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(351.25, 400, 50 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(351.25 + 5, 400, 50 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	glEnd();

	// front right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(448.75 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(448.75 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(453.75 - 20, 352.5, 52.5);
	glEnd();

	// right left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(448.75 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(448.75, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(453.75, 352.5, 52.5 - 20);
	glEnd();

	// back left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(351.25 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(351.25 + 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(346.25 + 20, 352.5, -47.5);
	glEnd();

	// left left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(351.25 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(351.25, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(346.25, 352.5, -47.5 + 20);
	glEnd();

	// back right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(453.75 - 20, 352.5, -47.5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(448.75 - 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(448.75 - 5, 400, -36.25 + 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	glEnd();

	// right right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(448.75 - 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(448.75, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(453.75, 352.5, -47.5 + 20);
	glEnd();
}

void body2::adomen1() {
	//GLenum type4 = GL_POLYGON;

	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	// front
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(351.25 + 20, 387.5, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(353.75 + 20, 400, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(446.25 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(448.75 - 20, 387.5, 50);
	glEnd();

	// back
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(351.25 + 20, 387.5, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(353.75 + 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(446.25 - 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(448.75 - 20, 387.5, -36.25);
	glEnd();

	// left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(351.25, 387.5, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(353.75, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(353.75, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(351.25, 387.5, 50 - 20);
	glEnd();

	// right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(448.75, 387.5, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(446.25, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(446.25, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(448.75, 387.5, 50 - 20);
	glEnd();

	// front left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(351.25 + 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(353.75 + 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(353.75 + 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(351.25 + 20, 387.5, 50.0);
	glEnd();

	// left right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(351.25, 387.5, 50.0 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(353.75, 400, 50 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(353.75 + 5, 400, 50 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(351.25 + 5, 387.5, 50.0 - 5);
	glEnd();

	// front right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(448.75 - 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(446.25 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(446.25 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(448.75 - 20, 387.5, 50.0);
	glEnd();

	// right left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(448.75 - 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(446.25 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(446.25, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(448.75, 387.5, 50.0 - 20);
	glEnd();

	// back left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(351.25 + 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(353.75 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(353.75 + 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(351.25 + 20, 387.5, -36.25);
	glEnd();

	// left left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(351.25 + 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(353.75 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(353.75, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(351.25, 387.5, -36.25 + 20);
	glEnd();

	// back right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(448.75 - 20, 387.5, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(446.25 - 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(446.25 - 5, 400, -36.25 + 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(448.75 - 5, 387.5, -36.25 + 5);
	glEnd();

	// right right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(448.75 - 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(446.25 - 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(446.25, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(448.75, 387.5, -36.25 + 20);
	glEnd();
}

void body2::adomen2() {
	//GLenum type4 = GL_POLYGON;

	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	// front
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(353.75 + 20, 387.5, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25 + 20, 400, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(446.25 - 20, 387.5, 50);
	glEnd();

	// back
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(353.75 + 20, 387.5, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25 + 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75 - 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(446.25 - 20, 387.5, -36.25);
	glEnd();

	// left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(353.75, 387.5, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(356.25, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(353.75, 387.5, 50 - 20);
	glEnd();

	// right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(446.25, 387.5, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(443.75, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(446.25, 387.5, 50 - 20);
	glEnd();

	// front left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(353.75 + 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25 + 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(356.25 + 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(353.75 + 20, 387.5, 50.0);
	glEnd();

	// left right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(353.75, 387.5, 50.0 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25, 400, 50 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(356.25 + 5, 400, 50 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(353.75 + 5, 387.5, 50.0 - 5);
	glEnd();

	// front right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(446.25 - 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(443.75 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(446.25 - 20, 387.5, 50.0);
	glEnd();

	// right left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(446.25 - 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(443.75 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(446.25, 387.5, 50.0 - 20);
	glEnd();

	// back left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(353.75 + 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(356.25 + 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(353.75 + 20, 387.5, -36.25);
	glEnd();

	// left left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(353.75 + 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(356.25 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(356.25, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(353.75, 387.5, -36.25 + 20);
	glEnd();

	// back right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(446.25 - 20, 387.5, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(443.75 - 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75 - 5, 400, -36.25 + 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(446.25 - 5, 387.5, -36.25 + 5);
	glEnd();

	// right right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(446.25 - 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(443.75 - 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(443.75, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(446.25, 387.5, -36.25 + 20);
	glEnd();
}

void body2::adomen3() {
	//GLenum type4 = GL_POLYGON;

	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	// front
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25 + 20, 387.5, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(357.5 + 20, 400, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75 - 20, 387.5, 50);
	glEnd();

	// back
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25 + 20, 387.5, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(357.5 + 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5 - 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75 - 20, 387.5, -36.25);
	glEnd();

	// left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 387.5, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(357.5, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(356.25, 387.5, 50 - 20);
	glEnd();

	// right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75, 387.5, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(442.5, 400, -36.25 + 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75, 387.5, 50 - 20);
	glEnd();

	// front left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25 + 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(357.5 + 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5 + 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(356.25 + 20, 387.5, 50.0);
	glEnd();

	// left right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25, 387.5, 50.0 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(357.5, 400, 50 - 20);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5 + 5, 400, 50 - 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(356.25 + 5, 387.5, 50.0 - 5);
	glEnd();

	// front right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75 - 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(442.5 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5 - 20, 400, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75 - 20, 387.5, 50.0);
	glEnd();

	// right left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75 - 5, 387.5, 50.0 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(442.5 - 5, 400, 50 - 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5, 400, 50 - 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75, 387.5, 50.0 - 20);
	glEnd();

	// back left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25 + 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5 + 20, 400, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(356.25 + 20, 387.5, -36.25);
	glEnd();

	// left left
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(356.25 + 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(356.25, 387.5, -36.25 + 20);
	glEnd();

	// back right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75 - 20, 387.5, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(442.5 - 20, 400, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5 - 5, 400, -36.25 + 5);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75 - 5, 387.5, -36.25 + 5);
	glEnd();

	// right right
	if (tOn4) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(443.75 - 5, 387.5, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(442.5 - 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5, 400, -36.25 + 20);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(443.75, 387.5, -36.25 + 20);
	glEnd();

}

void body2::below() {
	// front top
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(357.5 + 20, 400, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(421.25, 427.5, 50);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(442.5 - 20, 400, 50);
	glEnd();

	// front btm
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(378.75, 427.5, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(391.25, 457.5, 50 - 10);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(408.75, 457.5, 50 - 10);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(421.25, 427.5, 50);
	glEnd();

	// back top
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(357.5 + 20, 400, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, -45);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(421.25, 427.5, -45);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(442.5 - 20, 400, -36.25);
	glEnd();

	// back btm
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(378.75, 427.5, -45);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(391.25, 457.5, -36.25);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(408.75, 457.5, -36.25);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(421.25, 427.5, -45);
	glEnd();

	// left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(357.5, 400, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, -45);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(391.25, 457.5, -36.25);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(391.25, 457.5, 50 - 10);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5, 400, 50 - 20);
	glEnd();

	// right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(442.5, 400, -36.25 + 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(421.25, 427.5, -45);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(408.75, 457.5, -36.25);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(408.75, 457.5, 50 - 10);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(421.25, 427.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5, 400, 50 - 20);
	glEnd();

	// btm
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(391.25, 457.5, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(391.25, 457.5, 50 - 10);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(408.75, 457.5, 50 - 10);
	glTexCoord2f(0.0, 0.0), fhb2.v3f(408.75, 457.5, -36.25);
	glEnd();

	// front left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(357.5 + 5, 400, 50 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5 + 20, 400, 50);
	glEnd();

	// left right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(357.5, 400, 50 - 20);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5 + 5, 400, 50 - 5);
	glEnd();

	// front right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(442.5 - 20, 400, 50);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(421.25, 427.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(437.5, 400, 50 - 5);
	glEnd();

	// right left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(437.5, 400, 50 - 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(421.25, 427.5, 50);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5, 400, 50 - 20);
	glEnd();

	// back left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, -45);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5 + 20, 400, -36.25);
	glEnd();

	// front right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(442.5 - 20, 400, -36.25);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(421.25, 427.5, -45);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(437.5, 400, -36.25 + 5);
	glEnd();

	// left left
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(378.75, 427.5, -45);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(357.5, 400, -36.25 + 20);
	glEnd();

	// right right
	if (tOn4) fhb2.color('w'); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	glTexCoord2f(0.0, 1.0), fhb2.v3f(437.5, 400, -36.25 + 5);
	glTexCoord2f(1.0, 1.0), fhb2.v3f(421.25, 427.5, -45);
	glTexCoord2f(1.0, 0.0), fhb2.v3f(442.5, 400, -36.25 + 20);
	glEnd();
}