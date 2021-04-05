#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body.h"
#include "Head.h"

using namespace N;
using namespace std;
using namespace B;
using namespace H;

function fh_head;

GLenum type = GL_LINE_LOOP, gltype = GL_POLYGON;
void head::eye() {
	glColor3f(1, 1, 1);
	// right
	glBegin(gltype);
	fh_head.v3f(427.5, 400, 130);
	fh_head.v3f(427.5, 415, 130);
	fh_head.v3f(472.5, 415, 115);
	fh_head.v3f(492.5, 400, 92.5);
	fh_head.v3f(487.5, 387.5, 100);
	glEnd();

	// left
	glBegin(gltype);
	fh_head.v3f(372.5, 400, 130);
	fh_head.v3f(372.5, 415, 130);
	fh_head.v3f(327.5, 415, 115);
	fh_head.v3f(307.5, 400, 92.5);
	fh_head.v3f(312.5, 387.5, 100);
	glEnd();
}

void head::rightTop() {
	// front
	glColor3f(0.5, 0.5, 0.5);
	glBegin(gltype);
	fh_head.v3f(427.5, 287.5, 115);
	fh_head.v3f(447.5, 205, 50);
	fh_head.v3f(502.5, 240, 40);			// b
	fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side
	glColor3f(0.7, 0.7, 0.7);
	glBegin(gltype);
	fh_head.v3f(502.5, 240, 40);
	fh_head.v3f(522.5, 287.5, 55);
	fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2
	glColor3f(0.7, 0, 0.7);
	glBegin(gltype);
	fh_head.v3f(522.5, 287.5, 55);
	fh_head.v3f(509.5, 375, 72.5);	// d?
	//fh_head.v3f(504, 387.5, 60);		// aa
	//fh_head.v3f(502.5, 392, 92);		// ee
	fh_head.v3f(492.5, 387.5, 105);	// dd
	fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2.5
	glColor3f(0.7, 0, 0.7);
	glBegin(gltype);
	//fh_head.v3f(522.5, 287.5, 55);
	fh_head.v3f(509.5, 375, 72.5);	// d?
	fh_head.v3f(504, 387.5, 60);		// aa
	//fh_head.v3f(502.5, 392, 92);		// ee
	fh_head.v3f(492.5, 387.5, 105);	// dd
	//fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side3
	glColor3f(0.7, 0.7, 0);
	glBegin(gltype);
	fh_head.v3f(504, 387.5, 60);		// aa
	fh_head.v3f(502.5, 392, 92);		// ee
	fh_head.v3f(492.5, 387.5, 105);	// dd
	glEnd();

	// front2
	glColor3f(0, 0.7, 0.7);
	glBegin(gltype);
	fh_head.v3f(427.5, 287.5, 115);
	fh_head.v3f(522.5, 287.5, 72.5);
	fh_head.v3f(492.5, 387.5, 105);	// dd
	fh_head.v3f(427, 400, 130);
	glEnd();

	// front3
	glColor3f(0, 0.7, 0);
	glBegin(gltype);
	fh_head.v3f(400, 287.5, 115);
	fh_head.v3f(400, 400, 137.5);
	fh_head.v3f(427, 400, 130);
	fh_head.v3f(427.5, 287.5, 115);
	glEnd();
}

void head::eyeMid() {

	glColor3f(0.9, 0.3, 0.5);
	glBegin(gltype);
	fh_head.v3f(372.5, 400, 130);
	fh_head.v3f(372.5, 415, 130);
	fh_head.v3f(400, 415, 137);
	fh_head.v3f(400, 400, 137);
	glEnd();

	glColor3f(0.9, 0.3, 0.5);
	glBegin(gltype);
	fh_head.v3f(427.5, 415, 130);
	fh_head.v3f(427.5, 400, 130);
	fh_head.v3f(400, 400, 137);
	fh_head.v3f(400, 415, 137);
	glEnd();
}

void head::leftTop() {
	// front
	glColor3f(0.5, 0.5, 0.5);
	glBegin(gltype);
	fh_head.v3f(372.5, 287.5, 115);
	fh_head.v3f(352.5, 205, 50);
	fh_head.v3f(297.5, 240, 40);
	fh_head.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side
	glColor3f(0.7, 0.7, 0.7);
	glBegin(gltype);
	fh_head.v3f(297.5, 240, 40);
	fh_head.v3f(277.5, 287.5, 55);
	fh_head.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2
	glColor3f(0.7, 0, 0.7);
	glBegin(gltype);
	fh_head.v3f(277.5, 287.5, 55);
	fh_head.v3f(290.5, 375, 72.5);
	//fh_head.v3f(295, 387.5, 60);		// aa
	//fh_head.v3f(502.5, 392, 92);		// ee
	fh_head.v3f(307.5, 387.5, 105);	// dd
	fh_head.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2.5
	glColor3f(0.7, 0, 0.7);
	glBegin(gltype);
	//fh_head.v3f(277.5, 287.5, 55);
	fh_head.v3f(290.5, 375, 72.5);
	fh_head.v3f(295, 387.5, 60);		// aa
	//fh_head.v3f(502.5, 392, 92);		// ee
	fh_head.v3f(307.5, 387.5, 105);	// dd
	//fh_head.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side3
	glColor3f(0.7, 0.7, 0);
	glBegin(gltype);
	fh_head.v3f(295, 387.5, 60);		// aa
	fh_head.v3f(297, 392, 92);		// ee
	fh_head.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// front2
	glColor3f(0, 0.7, 0.7);
	glBegin(gltype);
	//fh_head.v3f(400, 287.5, 115);
	fh_head.v3f(372.5, 287.5, 115);
	fh_head.v3f(277.5, 287.5, 72.5);
	fh_head.v3f(307.5, 387.5, 105);	// dd
	fh_head.v3f(372.5, 400, 130);
	glEnd();

	// front3
	glColor3f(0, 0.7, 0);
	glBegin(gltype);
	fh_head.v3f(400, 287.5, 115);
	fh_head.v3f(400, 400, 137.5);
	fh_head.v3f(372.5, 400, 130);
	fh_head.v3f(372.5, 287.5, 115);
	glEnd();
}

void head::rightBtm() {
	// side top
	glColor3f(1, 0.6, 1);
	glBegin(gltype);
	fh_head.v3f(509, 415, 40);		// cc
	fh_head.v3f(504, 387.5, 60);		// aa
	fh_head.v3f(502.5, 392, 92);		// ee
	fh_head.v3f(509, 415, 92);
	glEnd();

	// front top
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh_head.v3f(502.5, 392, 92);		// ee
	fh_head.v3f(472.5, 415, 115);
	fh_head.v3f(509, 415, 92);
	glEnd();

	// side top 2
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(509, 415, 40);		// cc
	fh_head.v3f(509, 415, 92);
	fh_head.v3f(495, 457.5, 92.5);	// a2
	fh_head.v3f(509, 435, 45);		// z
	glEnd();

	// front top 2
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(509, 415, 92);
	fh_head.v3f(495, 457.5, 92.5);	// a2
	fh_head.v3f(472.5, 457.5, 115);
	fh_head.v3f(472.5, 415, 115);
	glEnd();

	// front top 3
	glColor3f(1, 1, 0.3);
	glBegin(gltype);
	fh_head.v3f(472.5, 457.5, 115);
	fh_head.v3f(472.5, 415, 115);
	fh_head.v3f(427.5, 415, 130);
	fh_head.v3f(427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	glColor3f(1, 0.5, 0.5);
	glBegin(gltype);
	fh_head.v3f(427.5, 415, 130);
	fh_head.v3f(427.5, 457.5, 130);
	fh_head.v3f(400, 457.5, 137.5);
	fh_head.v3f(400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	glColor3f(0.5, 1, 0.5);
	glBegin(gltype);
	fh_head.v3f(427.5, 457.5, 130);
	fh_head.v3f(400, 457.5, 137.5);
	fh_head.v3f(400, 522.5, 115);
	fh_head.v3f(435, 522.5, 115);
	glEnd();

	// front btm 2
	glColor3f(0.5, 0.5, 1);
	glBegin(gltype);
	fh_head.v3f(472.5, 457.5, 115);
	fh_head.v3f(427.5, 457.5, 130);
	fh_head.v3f(435, 522.5, 115);
	glEnd();

	// front btm 3
	glColor3f(0.7, 0.5, 0.3);
	glBegin(gltype);
	fh_head.v3f(472.5, 457.5, 115);
	fh_head.v3f(435, 522.5, 115);
	fh_head.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	glColor3f(0.5, 0.3, 0.7);
	glBegin(gltype);
	//fh_head.v3f(509, 415, 40);		// cc
	fh_head.v3f(509, 435, 45);		// z
	fh_head.v3f(495, 457.5, 68);		// a1
	fh_head.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(0.5, 0.7, 0.3);
	glBegin(gltype);
	fh_head.v3f(495, 457.5, 68);		// a1
	fh_head.v3f(470, 505, 77.5);		// bb
	fh_head.v3f(435, 522.5, 115);
	fh_head.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1, 1, 0.7);
	glBegin(gltype);
	fh_head.v3f(470, 505, 77.5);		// bb
	fh_head.v3f(467.5, 517.5, 75);	// y
	fh_head.v3f(447.5, 530, 97.5);	// x
	fh_head.v3f(435, 522.5, 115);
	glEnd();

	//// side
	//glColor3f(0.5, 1, 1);
	//glBegin(type);
	//fh_head.v3f(509, 415, 40);		// cc
	//fh_head.v3f(509, 435, 45);		// z
	//fh_head.v3f(495, 457.5, 68);		// a1
	//fh_head.v3f(470, 505, 77.5);		// bb
	//fh_head.v3f(467.5, 517.5, 75);	// y
	//fh_head.v3f(447.5, 530, 97.5);	// x
	//fh_head.v3f(435, 522.5, 115);
	//fh_head.v3f(495, 457.5, 92.5);	// a2
	//glEnd();
}

void head::leftBtm() {
	// side top
	glColor3f(1, 0.6, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 509, 415, 40);		// cc
	fh_head.v3f(800 - 504, 387.5, 60);		// aa
	fh_head.v3f(800 - 502.5, 392, 92);		// ee
	fh_head.v3f(800 - 509, 415, 92);
	glEnd();

	// front top
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 502.5, 392, 92);		// ee
	fh_head.v3f(800 - 472.5, 415, 115);
	fh_head.v3f(800 - 509, 415, 92);
	glEnd();

	// side top 2
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 509, 415, 40);		// cc
	fh_head.v3f(800 - 509, 415, 92);
	fh_head.v3f(800 - 495, 457.5, 92.5);	// a2
	fh_head.v3f(800 - 509, 435, 45);		// z
	glEnd();

	// front top 2
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 509, 415, 92);
	fh_head.v3f(800 - 495, 457.5, 92.5);	// a2
	fh_head.v3f(800 - 472.5, 457.5, 115);
	fh_head.v3f(800 - 472.5, 415, 115);
	glEnd();

	// front top 3
	glColor3f(1, 1, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 472.5, 457.5, 115);
	fh_head.v3f(800 - 472.5, 415, 115);
	fh_head.v3f(800 - 427.5, 415, 130);
	fh_head.v3f(800 - 427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	glColor3f(1, 0.5, 0.5);
	glBegin(gltype);
	fh_head.v3f(800 - 427.5, 415, 130);
	fh_head.v3f(800 - 427.5, 457.5, 130);
	fh_head.v3f(800 - 400, 457.5, 137.5);
	fh_head.v3f(800 - 400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	glColor3f(0.5, 1, 0.5);
	glBegin(gltype);
	fh_head.v3f(800 - 427.5, 457.5, 130);
	fh_head.v3f(800 - 400, 457.5, 137.5);
	fh_head.v3f(800 - 400, 522.5, 115);
	fh_head.v3f(800 - 435, 522.5, 115);
	glEnd();

	// front btm 2
	glColor3f(0.5, 0.5, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 472.5, 457.5, 115);
	fh_head.v3f(800 - 427.5, 457.5, 130);
	fh_head.v3f(800 - 435, 522.5, 115);
	glEnd();

	// front btm 3
	glColor3f(0.7, 0.5, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 472.5, 457.5, 115);
	fh_head.v3f(800 - 435, 522.5, 115);
	fh_head.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	glColor3f(0.5, 0.3, 0.7);
	glBegin(gltype);
	//fh_head.v3f(509, 415, 40);		// cc
	fh_head.v3f(800 - 509, 435, 45);		// z
	fh_head.v3f(800 - 495, 457.5, 68);		// a1
	fh_head.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(0.5, 0.7, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 495, 457.5, 68);		// a1
	fh_head.v3f(800 - 470, 505, 77.5);		// bb
	fh_head.v3f(800 - 435, 522.5, 115);
	fh_head.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1, 1, 0.7);
	glBegin(gltype);
	fh_head.v3f(800 - 470, 505, 77.5);		// bb
	fh_head.v3f(800 - 467.5, 517.5, 75);	// y
	fh_head.v3f(800 - 447.5, 530, 97.5);	// x
	fh_head.v3f(800 - 435, 522.5, 115);
	glEnd();
}

void head::mask() {
	eye();

	rightTop();
	leftTop();
	eyeMid();

	rightBtm();
	leftBtm();
}

void head::headRightTop1() {
	// 1
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh_head.v3f(447.5, 185, 0);
	fh_head.v3f(502.5, 222.5, 0);
	fh_head.v3f(502.5, 240, 40);
	fh_head.v3f(447.5, 205, 50);
	glEnd();

	// 2
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh_head.v3f(447.5, 185, -57.5);
	fh_head.v3f(502.5, 222.5, -57.5);
	fh_head.v3f(502.5, 222.5, 0);
	fh_head.v3f(447.5, 185, 0);
	glEnd();

	// 3
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh_head.v3f(447.5, 212.5, -115);
	fh_head.v3f(502.5, 240, -115);
	fh_head.v3f(502.5, 222.5, -57.5);
	fh_head.v3f(447.5, 185, -57.5);
	glEnd();

	// 4
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(447.5, 260, -147.5);
	fh_head.v3f(502.5, 270, -127.5);
	fh_head.v3f(502.5, 240, -115);
	fh_head.v3f(447.5, 212.5, -115);
	glEnd();
}

void head::headRightTop2() {
	// 1
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(502.5, 240, 40);
	fh_head.v3f(510, 335, 27.5);
	fh_head.v3f(522.5, 287.5, 55);
	//fh_head.v3f(504, 387.5, 60);		// aa
	//fh_head.v3f(509.5, 352, 72.5);	// d?
	//fh_head.v3f(522.5, 287.5, 55);
	glEnd();

	// 2
	glColor3f(1, 0, 0);
	glBegin(gltype);
	fh_head.v3f(522.5, 287.5, 55);
	fh_head.v3f(510, 335, 27.5);
	fh_head.v3f(509.5, 375, 72.5);
	fh_head.v3f(509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	glColor3f(0, 1, 0);
	glBegin(gltype);
	fh_head.v3f(502.5, 222.5, 0);
	fh_head.v3f(510, 287, 0);
	fh_head.v3f(510, 335, 27.5);
	fh_head.v3f(502.5, 240, 40);
	glEnd();

	// 4
	glColor3f(0, 0, 1);
	glBegin(gltype);
	fh_head.v3f(502.5, 222.5, -57.5);
	fh_head.v3f(510, 287, -57.5);
	fh_head.v3f(510, 287, 0);
	fh_head.v3f(502.5, 222.5, 0);
	glEnd();

	// 5
	glColor3f(0.5, 0.5, 0.5);
	glBegin(gltype);
	fh_head.v3f(502.5, 240, -115);
	fh_head.v3f(510, 287, -115);
	fh_head.v3f(510, 287, -57.5);
	fh_head.v3f(502.5, 222.5, -57.5);
	glEnd();

	// 6
	glColor3f(0.3, 0.7, 0.5);
	glBegin(gltype);
	fh_head.v3f(502.5, 240, -115);
	fh_head.v3f(502.5, 270, -127.5);
	fh_head.v3f(510, 287, -115);
	glEnd();

}

void head::headRightMid() {
	// 2
	glColor3f(1, 0.5, 0.6);
	glBegin(gltype);
	fh_head.v3f(510, 335, 27.5);
	fh_head.v3f(509.5, 352, -12.5);
	fh_head.v3f(509.5, 375, 0);
	fh_head.v3f(509.5, 375, 72.5);
	glEnd();

	// 1
	glColor3f(0.4, 0.1, 0.3);
	glBegin(gltype);
	fh_head.v3f(509.5, 375, 0);
	fh_head.v3f(509.5, 415, -12.5);
	fh_head.v3f(509, 415, 40);		// cc
	fh_head.v3f(509.5, 375, 72.5);
	glEnd();

	// 3
	glColor3f(0, 0.5, 0.6);
	glBegin(gltype);
	fh_head.v3f(510, 287, 0);
	fh_head.v3f(509.5, 352, -12.5);
	fh_head.v3f(510, 335, 27.5);
	glEnd();

	// 4
	glColor3f(0.6, 1, 0.3);
	glBegin(gltype);
	fh_head.v3f(510, 287, -57.5);
	fh_head.v3f(509.5, 352, -57.5);
	fh_head.v3f(509.5, 352, -12.5);
	fh_head.v3f(510, 287, 0);
	glEnd();

	// 5
	glColor3f(0, 0.6, 1);
	glBegin(gltype);
	fh_head.v3f(510, 287, -115);
	fh_head.v3f(509.5, 352, -57.5);
	fh_head.v3f(510, 287, -57.5);
	glEnd();

	// 6
	glColor3f(0.3, 0.6, 0.1);
	glBegin(gltype);
	fh_head.v3f(510, 287, -115);
	fh_head.v3f(510, 352, -127.5);
	fh_head.v3f(510, 375, -82.5);
	fh_head.v3f(509.5, 352, -57.5);
	glEnd();

	// 7
	glColor3f(0.3, 0.6, 0.8);
	glBegin(gltype);
	fh_head.v3f(510, 287, -115);
	fh_head.v3f(502.5, 270, -127.5);
	fh_head.v3f(510, 310, -160);
	fh_head.v3f(510, 352, -127.5);
	glEnd();

	// 8
	glColor3f(0.8, 0.1, 0.8);
	glBegin(gltype);
	fh_head.v3f(447.5, 260, -147.5);
	fh_head.v3f(510, 310, -160);
	fh_head.v3f(502.5, 270, -127.5);
	glEnd();

	// 9 
	glColor3f(0.8, 0.7, 0.2);
	glBegin(gltype);
	fh_head.v3f(510, 310, -160);
	fh_head.v3f(510, 352, -160);
	fh_head.v3f(510, 352, -127.5);
	glEnd();
}

void head::headRightBtm() {
	// 1
	glColor3f(0.3, 0.6, 0.9);
	glBegin(gltype);
	fh_head.v3f(509, 415, 40);		// cc
	fh_head.v3f(509.5, 415, -12.5);
	fh_head.v3f(509, 435, 45);		// z
	glEnd();

	// 2
	glColor3f(0.3, 0.9, 0.3);
	glBegin(gltype);
	fh_head.v3f(509.5, 415, -12.5);
	fh_head.v3f(515, 487.5, 0);		// r
	fh_head.v3f(492.5, 550, 27.5);	// rr
	fh_head.v3f(509, 435, 45);		// z
	glEnd();

	// 3
	glColor3f(0.7, 0.3, 0.7);
	glBegin(gltype);
	fh_head.v3f(510, 352, -127.5);
	fh_head.v3f(509.5, 415, -127.5);
	fh_head.v3f(509.5, 415, -80);
	fh_head.v3f(510, 375, -82.5);
	glEnd();

	// 4
	glColor3f(0.7, 0.7, 0.3);
	glBegin(gltype);
	fh_head.v3f(510, 352, -160);
	fh_head.v3f(509.5, 415, -160);
	fh_head.v3f(509.5, 415, -127.5);
	fh_head.v3f(510, 352, -127.5);
	glEnd();

	// 5
	glColor3f(0.3, 0.3, 0.9);
	glBegin(gltype);
	fh_head.v3f(509, 435, 45);		// z
	fh_head.v3f(492.5, 550, 27.5);	// rr
	fh_head.v3f(472.5, 532.5, 67.5);	// s
	fh_head.v3f(467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	glColor3f(0.9, 0.3, 0.1);
	glBegin(gltype);
	fh_head.v3f(492.5, 550, 27.5);	// rr
	fh_head.v3f(447.5, 587.5, 87.5);	// lowest
	fh_head.v3f(447.5, 562.5, 87.5);
	fh_head.v3f(472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	glColor3f(0.3, 0.9, 1);
	glBegin(gltype);
	fh_head.v3f(447.5, 562.5, 87.5);
	fh_head.v3f(447.5, 587.5, 87.5);	// lowest
	fh_head.v3f(427.5, 572.5, 117.5);
	fh_head.v3f(427.5, 550, 115);
	glEnd();

	// 8
	glColor3f(0.7, 0.2, 1);
	glBegin(gltype);
	fh_head.v3f(427.5, 550, 115);
	fh_head.v3f(427.5, 572.5, 117.5);
	fh_head.v3f(400, 572.5, 117.5);
	fh_head.v3f(400, 550, 115);
	glEnd();

}

void head::headRightBtm2() {
	// 1
	glColor3f(1, 0, 0.3);
	glBegin(gltype);
	fh_head.v3f(509.5, 415, -160);
	fh_head.v3f(509.5, 466, -147.5);
	fh_head.v3f(509.5, 415, -147.5);
	glEnd();

	// 2.1
	glColor3f(0, 1, 0.3);
	glBegin(gltype);
	fh_head.v3f(509.5, 415, -147.5);
	fh_head.v3f(509.5, 466, -147.5);
	fh_head.v3f(509.5, 450, -135);
	glEnd();

	// 2.2
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(509.5, 415, -147.5);
	fh_head.v3f(509.5, 450, -135);
	fh_head.v3f(509.5, 415, -80);
	glEnd();

	// 3
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(509.5, 415, -80);
	fh_head.v3f(509.5, 450, -135);
	fh_head.v3f(515, 487.5, 0);		// r
	glEnd();

	// 5
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh_head.v3f(509.5, 415, -80);
	fh_head.v3f(515, 487.5, 0);		// r
	fh_head.v3f(509.5, 415, -12.5);
	glEnd();
}

void head::headRightBack() {
	// 1
	glColor3f(1, 0, 0);
	glBegin(gltype);
	fh_head.v3f(400, 180, 0);
	fh_head.v3f(447.5, 185, 0);
	fh_head.v3f(447.5, 205, 50);
	fh_head.v3f(400, 200, 50);
	glEnd();

	// 2
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(400, 180, -57.5);
	fh_head.v3f(447.5, 185, -57.5);
	fh_head.v3f(447.5, 185, 0);
	fh_head.v3f(400, 180, 0);
	glEnd();

	// 3
	glColor3f(0, 0, 1);
	glBegin(gltype);
	fh_head.v3f(400, 207.5, -115);
	fh_head.v3f(447.5, 212.5, -115);
	fh_head.v3f(447.5, 185, -57.5);
	fh_head.v3f(400, 180, -57.5);
	glEnd();

	// 4
	glColor3f(0, 1, 0);
	glBegin(gltype);
	fh_head.v3f(400, 255, -147.5);
	fh_head.v3f(447.5, 260, -147.5);
	fh_head.v3f(447.5, 212.5, -115);
	fh_head.v3f(400, 207.5, -115);
	glEnd();

	// 5
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(400, 310, -170);
	fh_head.v3f(510, 310, -160);
	fh_head.v3f(447.5, 260, -147.5);
	fh_head.v3f(400, 255, -147.5);
	glEnd();

	// 6
	glColor3f(0.5, 1, 0.7);
	glBegin(gltype);
	fh_head.v3f(400, 352, -170);
	fh_head.v3f(510, 352, -160);
	fh_head.v3f(510, 310, -160);
	fh_head.v3f(400, 310, -170);
	glEnd();

	// 7
	glColor3f(1, 0.7, 0.3);
	glBegin(gltype);
	fh_head.v3f(510, 352, -160);
	fh_head.v3f(400, 352, -170);
	fh_head.v3f(400, 415, -170);
	fh_head.v3f(509.5, 415, -160);
	glEnd();

	// 8
	glColor3f(1, 0.1, 1);
	glBegin(gltype);
	fh_head.v3f(509.5, 415, -160);
	fh_head.v3f(400, 415, -170);
	fh_head.v3f(400, 466, -157.5);
	fh_head.v3f(509.5, 466, -147.5);
	glEnd();

}

void head::headLeftTop1() {
	// 1
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 447.5, 185, 0);
	fh_head.v3f(800 - 502.5, 222.5, 0);
	fh_head.v3f(800 - 502.5, 240, 40);
	fh_head.v3f(800 - 447.5, 205, 50);
	glEnd();

	// 2
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 447.5, 185, -57.5);
	fh_head.v3f(800 - 502.5, 222.5, -57.5);
	fh_head.v3f(800 - 502.5, 222.5, 0);
	fh_head.v3f(800 - 447.5, 185, 0);
	glEnd();

	// 3
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 447.5, 212.5, -115);
	fh_head.v3f(800 - 502.5, 240, -115);
	fh_head.v3f(800 - 502.5, 222.5, -57.5);
	fh_head.v3f(800 - 447.5, 185, -57.5);
	glEnd();

	// 4
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 447.5, 260, -147.5);
	fh_head.v3f(800 - 502.5, 270, -127.5);
	fh_head.v3f(800 - 502.5, 240, -115);
	fh_head.v3f(800 - 447.5, 212.5, -115);
	glEnd();
}

void head::headLeftTop2() {
	// 1
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 502.5, 240, 40);
	fh_head.v3f(800 - 510, 335, 27.5);
	fh_head.v3f(800 - 522.5, 287.5, 55);
	//fh_head.v3f(800 - 504, 387.5, 60);		// aa
	//fh_head.v3f(800 - 509.5, 352, 72.5);	// d?
	//fh_head.v3f(800 - 522.5, 287.5, 55);
	glEnd();

	// 2
	glColor3f(1, 0, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 522.5, 287.5, 55);
	fh_head.v3f(800 - 510, 335, 27.5);
	fh_head.v3f(800 - 509.5, 375, 72.5);
	fh_head.v3f(800 - 509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	glColor3f(0, 1, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 502.5, 222.5, 0);
	fh_head.v3f(800 - 510, 287, 0);
	fh_head.v3f(800 - 510, 335, 27.5);
	fh_head.v3f(800 - 502.5, 240, 40);
	glEnd();

	// 4
	glColor3f(0, 0, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 502.5, 222.5, -57.5);
	fh_head.v3f(800 - 510, 287, -57.5);
	fh_head.v3f(800 - 510, 287, 0);
	fh_head.v3f(800 - 502.5, 222.5, 0);
	glEnd();

	// 5
	glColor3f(0.5, 0.5, 0.5);
	glBegin(gltype);
	fh_head.v3f(800 - 502.5, 240, -115);
	fh_head.v3f(800 - 510, 287, -115);
	fh_head.v3f(800 - 510, 287, -57.5);
	fh_head.v3f(800 - 502.5, 222.5, -57.5);
	glEnd();

	// 6
	glColor3f(0.3, 0.7, 0.5);
	glBegin(gltype);
	fh_head.v3f(800 - 502.5, 240, -115);
	fh_head.v3f(800 - 502.5, 270, -127.5);
	fh_head.v3f(800 - 510, 287, -115);
	glEnd();

}

void head::headLeftMid() {
	// 2
	glColor3f(1, 0.5, 0.6);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 335, 27.5);
	fh_head.v3f(800 - 509.5, 352, -12.5);
	fh_head.v3f(800 - 509.5, 375, 0);
	fh_head.v3f(800 - 509.5, 375, 72.5);
	glEnd();

	// 1
	glColor3f(0.4, 0.1, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 375, 0);
	fh_head.v3f(800 - 509.5, 415, -12.5);
	fh_head.v3f(800 - 509, 415, 40);		// cc
	fh_head.v3f(800 - 509.5, 375, 72.5);
	glEnd();

	// 3
	glColor3f(0, 0.5, 0.6);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 287, 0);
	fh_head.v3f(800 - 509.5, 352, -12.5);
	fh_head.v3f(800 - 510, 335, 27.5);
	glEnd();

	// 4
	glColor3f(0.6, 1, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 287, -57.5);
	fh_head.v3f(800 - 509.5, 352, -57.5);
	fh_head.v3f(800 - 509.5, 352, -12.5);
	fh_head.v3f(800 - 510, 287, 0);
	glEnd();

	// 5
	glColor3f(0, 0.6, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 287, -115);
	fh_head.v3f(800 - 509.5, 352, -57.5);
	fh_head.v3f(800 - 510, 287, -57.5);
	glEnd();

	// 6
	glColor3f(0.3, 0.6, 0.1);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 287, -115);
	fh_head.v3f(800 - 510, 352, -127.5);
	fh_head.v3f(800 - 510, 375, -82.5);
	fh_head.v3f(800 - 509.5, 352, -57.5);
	glEnd();

	// 7
	glColor3f(0.3, 0.6, 0.8);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 287, -115);
	fh_head.v3f(800 - 502.5, 270, -127.5);
	fh_head.v3f(800 - 510, 310, -160);
	fh_head.v3f(800 - 510, 352, -127.5);
	glEnd();

	// 8
	glColor3f(0.8, 0.1, 0.8);
	glBegin(gltype);
	fh_head.v3f(800 - 447.5, 260, -147.5);
	fh_head.v3f(800 - 510, 310, -160);
	fh_head.v3f(800 - 502.5, 270, -127.5);
	glEnd();

	// 9 
	glColor3f(0.8, 0.7, 0.2);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 310, -160);
	fh_head.v3f(800 - 510, 352, -160);
	fh_head.v3f(800 - 510, 352, -127.5);
	glEnd();
}

void head::headLeftBtm() {
	// 1
	glColor3f(0.3, 0.6, 0.9);
	glBegin(gltype);
	fh_head.v3f(800 - 509, 415, 40);		// cc
	fh_head.v3f(800 - 509.5, 415, -12.5);
	fh_head.v3f(800 - 509, 435, 45);		// z
	glEnd();

	// 2
	glColor3f(0.3, 0.9, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -12.5);
	fh_head.v3f(800 - 515, 487.5, 0);		// r
	fh_head.v3f(800 - 492.5, 550, 27.5);	// rr
	fh_head.v3f(800 - 509, 435, 45);		// z
	glEnd();

	// 3
	glColor3f(0.7, 0.3, 0.7);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 352, -127.5);
	fh_head.v3f(800 - 509.5, 415, -127.5);
	fh_head.v3f(800 - 509.5, 415, -80);
	fh_head.v3f(800 - 510, 375, -82.5);
	glEnd();

	// 4
	glColor3f(0.7, 0.7, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 352, -160);
	fh_head.v3f(800 - 509.5, 415, -160);
	fh_head.v3f(800 - 509.5, 415, -127.5);
	fh_head.v3f(800 - 510, 352, -127.5);
	glEnd();

	// 5
	glColor3f(0.3, 0.3, 0.9);
	glBegin(gltype);
	fh_head.v3f(800 - 509, 435, 45);		// z
	fh_head.v3f(800 - 492.5, 550, 27.5);	// rr
	fh_head.v3f(800 - 472.5, 532.5, 67.5);	// s
	fh_head.v3f(800 - 467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	glColor3f(0.9, 0.3, 0.1);
	glBegin(gltype);
	fh_head.v3f(800 - 492.5, 550, 27.5);	// rr
	fh_head.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	fh_head.v3f(800 - 447.5, 562.5, 87.5);
	fh_head.v3f(800 - 472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	glColor3f(0.3, 0.9, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 447.5, 562.5, 87.5);
	fh_head.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	fh_head.v3f(800 - 427.5, 572.5, 117.5);
	fh_head.v3f(800 - 427.5, 550, 115);
	glEnd();

	// 8
	glColor3f(0.7, 0.2, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 427.5, 550, 115);
	fh_head.v3f(800 - 427.5, 572.5, 117.5);
	fh_head.v3f(800 - 400, 572.5, 117.5);
	fh_head.v3f(800 - 400, 550, 115);
	glEnd();

}

void head::headLeftBtm2() {
	// 1
	glColor3f(1, 0, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -160);
	fh_head.v3f(800 - 509.5, 466, -147.5);
	fh_head.v3f(800 - 509.5, 415, -147.5);
	glEnd();

	// 2.1
	glColor3f(0, 1, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -147.5);
	fh_head.v3f(800 - 509.5, 466, -147.5);
	fh_head.v3f(800 - 509.5, 450, -135);
	glEnd();

	// 2.2
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -147.5);
	fh_head.v3f(800 - 509.5, 450, -135);
	fh_head.v3f(800 - 509.5, 415, -80);
	glEnd();

	// 3
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -80);
	fh_head.v3f(800 - 509.5, 450, -135);
	fh_head.v3f(800 - 515, 487.5, 0);		// r
	glEnd();

	// 5
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -80);
	fh_head.v3f(800 - 515, 487.5, 0);		// r
	fh_head.v3f(800 - 509.5, 415, -12.5);
	glEnd();
}

void head::headLeftBack() {
	// Left
	// 1// 1
	glColor3f(1, 0, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 400, 180, 0);
	fh_head.v3f(800 - 447.5, 185, 0);
	fh_head.v3f(800 - 447.5, 205, 50);
	fh_head.v3f(800 - 400, 200, 50);
	glEnd();

	// 2
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 400, 180, -57.5);
	fh_head.v3f(800 - 447.5, 185, -57.5);
	fh_head.v3f(800 - 447.5, 185, 0);
	fh_head.v3f(800 - 400, 180, 0);
	glEnd();

	// 3
	glColor3f(0, 0, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 400, 207.5, -115);
	fh_head.v3f(800 - 447.5, 212.5, -115);
	fh_head.v3f(800 - 447.5, 185, -57.5);
	fh_head.v3f(800 - 400, 180, -57.5);
	glEnd();

	// 4
	glColor3f(0, 1, 0);
	glBegin(gltype);
	fh_head.v3f(800 - 400, 255, -147.5);
	fh_head.v3f(800 - 447.5, 260, -147.5);
	fh_head.v3f(800 - 447.5, 212.5, -115);
	fh_head.v3f(800 - 400, 207.5, -115);
	glEnd();

	// 5
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 400, 310, -170);
	fh_head.v3f(800 - 510, 310, -160);
	fh_head.v3f(800 - 447.5, 260, -147.5);
	fh_head.v3f(800 - 400, 255, -147.5);
	glEnd();

	// 6
	glColor3f(0.5, 1, 0.7);
	glBegin(gltype);
	fh_head.v3f(800 - 400, 352, -170);
	fh_head.v3f(800 - 510, 352, -160);
	fh_head.v3f(800 - 510, 310, -160);
	fh_head.v3f(800 - 400, 310, -170);
	glEnd();

	// 7
	glColor3f(1, 0.7, 0.3);
	glBegin(gltype);
	fh_head.v3f(800 - 510, 352, -160);
	fh_head.v3f(800 - 400, 352, -170);
	fh_head.v3f(800 - 400, 415, -170);
	fh_head.v3f(800 - 509.5, 415, -160);
	glEnd();

	// 8
	glColor3f(1, 0.1, 1);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -160);
	fh_head.v3f(800 - 400, 415, -170);
	fh_head.v3f(800 - 400, 466, -157.5);
	fh_head.v3f(800 - 509.5, 466, -147.5);
	glEnd();

}

void head::headTop() {
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh_head.v3f(372.5, 287.5, 110);
	fh_head.v3f(352.5, 205, 50);
	fh_head.v3f(447.5, 205, 50);
	fh_head.v3f(427.5, 287.5, 110);
	glEnd();
}

void head::ear() {
	GLUquadricObj* disk = NULL;
	disk = gluNewQuadric();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 0, 1);
	fh_head.color('r');
	gluQuadricDrawStyle(disk, GLU_FILL);
	gluDisk(disk, 0, fh_head.yP(55), 50, 50);
	glPopMatrix();
}

void head::btmCover() {
	// 1 (btm for left and right)
	glColor3f(0.7, 0.2, 0.6);
	glBegin(gltype);
	fh_head.v3f(800 - 427.5, 572.5, 117.5);
	fh_head.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	fh_head.v3f(447.5, 587.5, 87.5);			// lowest
	fh_head.v3f(427.5, 572.5, 117.5);
	glEnd();

	// 2
	glColor3f(0.7, 1, 0.6);
	glBegin(gltype);
	fh_head.v3f(800 - 492.5, 550, 27.5);		// rr
	fh_head.v3f(800 - 447.5, 587.5, 87.5);	// lowest
	fh_head.v3f(447.5, 587.5, 87.5);			// lowest
	fh_head.v3f(492.5, 550, 27.5);			// rr
	glEnd();

	// 3
	glColor3f(1, 0.4, 0.6);
	glBegin(gltype);
	fh_head.v3f(800 - 515, 487.5, 0);		// r
	fh_head.v3f(800 - 492.5, 550, 27.5);		// rr
	fh_head.v3f(492.5, 550, 27.5);			// rr
	fh_head.v3f(515, 487.5, 0);				// r
	glEnd();

	// 3
	glColor3f(0.2, 1, 0.7);
	glBegin(gltype);
	fh_head.v3f(800 - 509.5, 415, -127.5);
	fh_head.v3f(800 - 515, 487.5, 0);		// r
	fh_head.v3f(515, 487.5, 0);		// r
	fh_head.v3f(509.5, 415, -127.5);
	glEnd();
}