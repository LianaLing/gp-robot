#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body.h"
#include "Head2.h"

using namespace N;
using namespace std;
using namespace B;
using namespace H2;

function fh_head2;
boolean tOnh2 = false;
GLenum type5 = GL_LINE_LOOP, gltype5 = GL_POLYGON;

void head2::textureOn(boolean t) {
	tOnh2 = t;
}
void head2::eye() {
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	// right
	glBegin(type5);
	fh_head2.v3f(427.5, 400, 130);
	fh_head2.v3f(427.5, 415, 130);
	fh_head2.v3f(472.5, 415, 115);
	fh_head2.v3f(492.5, 400, 92.5);
	fh_head2.v3f(487.5, 387.5, 100);
	glEnd();

	// left
	glBegin(type5);
	fh_head2.v3f(372.5, 400, 130);
	fh_head2.v3f(372.5, 415, 130);
	fh_head2.v3f(327.5, 415, 115);
	fh_head2.v3f(307.5, 400, 92.5);
	fh_head2.v3f(312.5, 387.5, 100);
	glEnd();
}

void head2::rightTop() {
	// front
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(427.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(447.5, 205, 50);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(502.5, 240, 40);			// b
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); glColor3f(0.0, 0.0, 0.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(502.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(522.5, 287.5, 55);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(522.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 375, 72.5);	// d?
	//fh_head2.v3f(504, 387.5, 60);		// aa
	//fh_head2.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(492.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2.5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(522.5, 287.5, 55);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 375, 72.5);	// d?
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(492.5, 387.5, 105);	// dd
	//fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(492.5, 387.5, 105);	// dd
	glEnd();

	// front2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(427.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(522.5, 287.5, 72.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(492.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(427, 400, 130);
	glEnd();

	// front3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(400, 400, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(427, 400, 130);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(427.5, 287.5, 115);
	glEnd();
}

void head2::eyeMid() {

	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(372.5, 400, 130);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(372.5, 415, 130);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(400, 415, 137);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 400, 137);
	glEnd();

	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(427.5, 415, 130);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(427.5, 400, 130);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(400, 400, 137);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 415, 137);
	glEnd();
}

void head2::leftTop() {
	// front
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(372.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(352.5, 205, 50);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(297.5, 240, 40);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); glColor3f(0.0, 0.0, 0.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(297.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(277.5, 287.5, 55);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(277.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(290.5, 375, 72.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(307.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2.5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(290.5, 375, 72.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(295, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// side3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(295, 387.5, 60);		// aa
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(297, 392, 92);		// ee
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// front2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(400, 287.5, 115);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(372.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(277.5, 287.5, 72.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(307.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(372.5, 400, 130);
	glEnd();

	// front3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(400, 400, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(372.5, 400, 130);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(372.5, 287.5, 115);
	glEnd();
}

void head2::rightBtm() {
	// side top
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509, 415, 92);
	glEnd();

	// front top
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509, 415, 92);
	glEnd();

	// side top 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509, 415, 92);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(495, 457.5, 92.5);	// a2
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509, 435, 45);		// z
	glEnd();

	// front top 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509, 415, 92);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(495, 457.5, 92.5);	// a2
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(472.5, 457.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(472.5, 415, 115);
	glEnd();

	// front top 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(427.5, 415, 130);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(427.5, 415, 130);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(400, 457.5, 137.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(427.5, 457.5, 130);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(400, 457.5, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(400, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(435, 522.5, 115);
	glEnd();

	// front btm 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(435, 522.5, 115);
	glEnd();

	// front btm 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(435, 522.5, 115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(509, 415, 40);		// cc
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(435, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(467.5, 517.5, 75);	// y
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 530, 97.5);	// x
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(435, 522.5, 115);
	glEnd();
}

void head2::leftBtm() {
	// side top
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 502.5, 392, 92);		// ee
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509, 415, 92);
	glEnd();

	// front top
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509, 415, 92);
	glEnd();

	// side top 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509, 415, 92);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 495, 457.5, 92.5);	// a2
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509, 435, 45);		// z
	glEnd();

	// front top 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509, 415, 92);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 495, 457.5, 92.5);	// a2
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 472.5, 457.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 472.5, 415, 115);
	glEnd();

	// front top 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 427.5, 415, 130);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 427.5, 415, 130);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 400, 457.5, 137.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 427.5, 457.5, 130);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 400, 457.5, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 400, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 435, 522.5, 115);
	glEnd();

	// front btm 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 435, 522.5, 115);
	glEnd();

	// front btm 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 435, 522.5, 115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(509, 415, 40);		// cc
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 435, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 467.5, 517.5, 75);	// y
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 447.5, 530, 97.5);	// x
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 435, 522.5, 115);
	glEnd();
}

void head2::mask() {
	eye();

	rightTop();
	leftTop();
	eyeMid();

	rightBtm();
	leftBtm();
}

void head2::headRightTop1() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(447.5, 185, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(502.5, 222.5, 0);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(502.5, 240, 40);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(447.5, 205, 50);
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(447.5, 185, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(502.5, 222.5, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(447.5, 185, 0);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(447.5, 212.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(502.5, 240, -115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(502.5, 222.5, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(447.5, 185, -57.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(502.5, 240, -115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(447.5, 212.5, -115);
	glEnd();
}

void head2::headRightTop2() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(502.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(522.5, 287.5, 55);
	//fh_head2.v3f(504, 387.5, 60);		// aa
	//fh_head2.v3f(509.5, 352, 72.5);	// d?
	//fh_head2.v3f(522.5, 287.5, 55);
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(522.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 375, 72.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(502.5, 222.5, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 287, 0);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 335, 27.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(502.5, 240, 40);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 287, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 287, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(502.5, 222.5, 0);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 287, -115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 287, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(502.5, 222.5, -57.5);
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 287, -115);
	glEnd();

}

void head2::headRightMid() {
	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 335, 27.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 352, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 375, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509.5, 375, 72.5);
	glEnd();

	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 375, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509, 415, 40);		// cc
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509.5, 375, 72.5);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0), glBegin(type5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 287, 0);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 352, -12.5);
	fh_head2.v3f(510, 335, 27.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 287, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 352, -12.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(510, 287, 0);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 287, -57.5);
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 352, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 375, -82.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509.5, 352, -57.5);
	glEnd();

	// 7
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(510, 352, -127.5);
	glEnd();

	// 8
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(502.5, 270, -127.5);
	glEnd();

	// 9 
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 310, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 352, -127.5);
	glEnd();
}

void head2::headRightBtm() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509, 435, 45);		// z
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 415, -12.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(492.5, 550, 27.5);	// rr
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509, 435, 45);		// z
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 352, -127.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 415, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 415, -80);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(510, 375, -82.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 415, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 415, -127.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(510, 352, -127.5);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(472.5, 532.5, 67.5);	// s
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 562.5, 87.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(447.5, 562.5, 87.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(427.5, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(427.5, 550, 115);
	glEnd();

	// 8
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(427.5, 550, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(427.5, 572.5, 117.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(400, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 550, 115);
	glEnd();

}

void head2::headRightBtm2() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 415, -147.5);
	glEnd();

	// 2.1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 450, -135);
	glEnd();

	// 2.2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(509.5, 415, -80);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 415, -80);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(515, 487.5, 0);		// r
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -80);
	fh_head2.v3f(515, 487.5, 0);		// r
	fh_head2.v3f(509.5, 415, -12.5);
	glEnd();
}

void head2::headRightBack() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 180, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(447.5, 185, 0);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 205, 50);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 200, 50);
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 180, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(447.5, 185, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 185, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 180, 0);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 207.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(447.5, 212.5, -115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 185, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 180, -57.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 255, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(447.5, 260, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 212.5, -115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 207.5, -115);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 310, -170);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 260, -147.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 255, -147.5);
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(400, 352, -170);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(400, 310, -170);
	glEnd();

	// 7
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(400, 352, -170);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(400, 415, -170);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509.5, 415, -160);
	glEnd();

	// 8
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(400, 415, -170);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(400, 466, -157.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509.5, 466, -147.5);
	glEnd();

}

void head2::headLeftTop1() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 447.5, 185, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 502.5, 222.5, 0);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 502.5, 240, 40);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 447.5, 205, 50);
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 447.5, 185, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 502.5, 222.5, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 447.5, 185, 0);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 447.5, 212.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 502.5, 240, -115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 502.5, 222.5, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 447.5, 185, -57.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 502.5, 240, -115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 447.5, 212.5, -115);
	glEnd();
}

void head2::headLeftTop2() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 502.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 522.5, 287.5, 55);
	//fh_head2.v3f(800 - 504, 387.5, 60);		// aa
	//fh_head2.v3f(800 - 509.5, 352, 72.5);	// d?
	//fh_head2.v3f(800 - 522.5, 287.5, 55);
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 522.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 375, 72.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 502.5, 222.5, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 287, 0);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 335, 27.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 502.5, 240, 40);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 287, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 287, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 502.5, 222.5, 0);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 287, -115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 287, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 502.5, 222.5, -57.5);
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 287, -115);
	glEnd();

}

void head2::headLeftMid() {
	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 335, 27.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 352, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 375, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509.5, 375, 72.5);
	glEnd();

	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 375, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509, 415, 40);		// cc
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509.5, 375, 72.5);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 287, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 352, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 335, 27.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 287, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 352, -12.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 510, 287, 0);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 287, -57.5);
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 352, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 375, -82.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509.5, 352, -57.5);
	glEnd();

	// 7
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 510, 352, -127.5);
	glEnd();

	// 8
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 502.5, 270, -127.5);
	glEnd();

	// 9 
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 310, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 352, -127.5);
	glEnd();
}

void head2::headLeftBtm() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509, 435, 45);		// z
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -12.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 492.5, 550, 27.5);	// rr
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509, 435, 45);		// z
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 352, -127.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 415, -80);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 510, 375, -82.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 415, -127.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 510, 352, -127.5);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 472.5, 532.5, 67.5);	// s
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 447.5, 562.5, 87.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 447.5, 562.5, 87.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 427.5, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 427.5, 550, 115);
	glEnd();

	// 8
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 427.5, 550, 115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 427.5, 572.5, 117.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 400, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 550, 115);
	glEnd();

}

void head2::headLeftBtm2() {
	// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 415, -147.5);
	glEnd();

	// 2.1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 450, -135);
	glEnd();

	// 2.2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 415, -80);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -80);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 515, 487.5, 0);		// r
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -80);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 509.5, 415, -12.5);
	glEnd();
}

void head2::headLeftBack() {
	// Left
	// 1// 1
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 400, 180, 0);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 185, 0);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 447.5, 205, 50);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 200, 50);
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 400, 180, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 185, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 447.5, 185, 0);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 180, 0);
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 400, 207.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 212.5, -115);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 447.5, 185, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 180, -57.5);
	glEnd();

	// 4
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 400, 255, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 260, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 447.5, 212.5, -115);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 207.5, -115);
	glEnd();

	// 5
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 400, 310, -170);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 447.5, 260, -147.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 255, -147.5);
	glEnd();

	// 6
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 400, 352, -170);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 400, 310, -170);
	glEnd();

	// 7
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 400, 352, -170);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 400, 415, -170);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509.5, 415, -160);
	glEnd();

	// 8
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 400, 415, -170);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(800 - 400, 466, -157.5);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(800 - 509.5, 466, -147.5);
	glEnd();

}

void head2::headTop() {
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(372.5, 287.5, 110);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(352.5, 205, 50);
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 205, 50);
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(427.5, 287.5, 110);
	glEnd();
}

void head2::ear() {
	GLUquadricObj* disk = NULL;
	disk = gluNewQuadric();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 0, 1);
	fh_head2.color('r');
	gluQuadricDrawStyle(disk, GLU_FILL);
	gluDisk(disk, 0, fh_head2.yP(55), 50, 50);
	glPopMatrix();
}

void head2::btmCover() {
	// 1 (btm for left and right)
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 427.5, 572.5, 117.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 587.5, 87.5);			// lowest
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(427.5, 572.5, 117.5);
	glEnd();

	// 2
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 492.5, 550, 27.5);		// rr
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(447.5, 587.5, 87.5);			// lowest
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(492.5, 550, 27.5);			// rr
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 492.5, 550, 27.5);		// rr
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(492.5, 550, 27.5);			// rr
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(515, 487.5, 0);				// r
	glEnd();

	// 3
	if (tOnh2) glColor3f(1.0, 1.0, 1.0); else glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	glTexCoord2f(0.0, 1.0), fh_head2.v3f(800 - 509.5, 415, -127.5);
	glTexCoord2f(1.0, 1.0), fh_head2.v3f(800 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head2.v3f(515, 487.5, 0);		// r
	glTexCoord2f(0.0, 0.0), fh_head2.v3f(509.5, 415, -127.5);
	glEnd();
}