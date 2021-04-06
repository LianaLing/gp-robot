#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include <string>
#include "Function.h"
#include "Body.h"
#include "Head.h"

using namespace N;
using namespace B;
using namespace H;

//#pragma comment (lib, "OpenGL32.lib")
//dependencies included in project properties - linker - input

#define WINDOW_TITLE "IRON-MAN MK47"
#define CW 10
#define VALUE 800.0
#define WIDTH VALUE
#define HEIGHT VALUE
#define DEPTH VALUE
#define SIZE 15
#define ORTHO_VIEW 1.0
#define FRUSTUM_VIEW 1.0

function fh;
body b;
head h;
int qNo = 1;
std::string str = " ";
float C[SIZE];
float zoom = 1.0, cameraTranslateSpeed = 0.1;
char view = 'o';
//============== Danny ==============
float AR = 0, AR1 = 0, AR2 = 0, AR3 = 0, AR4 = 0, AR0 = 0, AR01 = 0, AR5 = 0;
float rotate = 0;
float xR = 0, yR = 0, zR = 0, xT = 0, yT = 0, zT = 0;
float maskRotate = 0, maskRotateSpeed = 0.5;
float nodRotate = 0, nodRotateSpeed = 0.5;
float bCount = 1, mCount = 1, nCount = 1;
boolean openMask = false, bow = false, nod = false;
//===================================

//============== LIANA ==============
float armRotate = 0, armRSpeed = 0, armx = 0, army = 0, armz = 0, armDirection = 0, armAngle = 0;
float armx2 = 0, army2 = 0, armz2 = 0;
boolean armTurnUp = false, armTurnDown = false, armUp = false, armDown = false;
float fingerRotate = 0, fingerRSpeed = 0, fx = 0, fy = 0, fz = 0 /*, fingerDirection = 0, fingerAngle = 0*/;
float fx2 = 0, fy2 = 0, fz2 = 0;
int fCount = 0, llCount = 0, lrCount = 0;
boolean fingerBend = false;
boolean sideView = true;
boolean raiseLeftLeg = false, raiseRightLeg = false;
float rLeftLeg = 0, rRightLeg = 0, legLSpeed = 0, legRSpeed = 0;
//GLenum nonGLUtype = GL_POLYGON;
GLenum nonGLUtype = GL_LINE_LOOP;
//GLenum GLUtype = GLU_FILL;
GLenum GLUtype = GLU_LINE;
int pCount = 0;
float ry = 0, rSpeedP = 10.0;
//===================================
LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			PostQuitMessage(0);
		}
		else if (wParam == 0x31) {
			// press 1.0
			qNo = 1.0;
			break;
		}
		else if (wParam == 0x32) {
			// press 2
			qNo = 2;
			break;
		}
		else if (wParam == 0x33) {
			// press 3
			qNo = 3;
			break;
		}
		else if (wParam == 0x34) {
			// press 4
			qNo = 4;
			break;
		}
		else if (wParam == 0x35) {
			// press 5
			qNo = 5;
			break;
		}
		else if (wParam == 0x36) {
			// press 6
			qNo = 6;
			break;
		}
		else if (wParam == 0x37) {
			// press 7
			qNo = 7;
			break;
		}
		else if (wParam == 0x38) {
			// press 8
			qNo = 8;
			break;
		}
		else if (wParam == 0x39) {
			// press 9
			qNo = 9;
			break;
		}
		else if (wParam == 0x61) {
			// press numpad 1.0
			qNo = 61;
			break;
		}
		else if (wParam == VK_UP) {
			if (qNo == 4) {
				yT += cameraTranslateSpeed;
			}
			else
				armx = 1.0, army = 0, armz = 0, armRSpeed = 0.5, armUp = true, armDown = false;
		}
		else if (wParam == VK_DOWN) {
			if (qNo == 4) {
				yT -= cameraTranslateSpeed;
			}
			else
				armx = 1.0, army = 0, armz = 0, armUp = false, armDown = true;
		}
		else if (wParam == VK_LEFT) {
			if (qNo == 4) {
				xT -= cameraTranslateSpeed;
			}
			else
				armx2 = 1.0, army2 = 0, armz2 = 0, armDirection = +1.0, armRSpeed = 2, armTurnUp = true, armTurnDown = false;
		}
		else if (wParam == VK_RIGHT) {
			if (qNo == 4) {
				xT += cameraTranslateSpeed;
			}
			else
				armx2 = 1.0, army2 = 0, armz2 = 0, armDirection = -1.0, armRSpeed = 2, armTurnDown = true, armTurnUp = false;
		}
		else if (wParam == VK_SPACE) {
			str = "space";

			glLoadIdentity();
			armx = 1.00, army = 0, armz = 0, armx2 = 0, army2 = 0, armz2 = 0;
			armRSpeed = 0, armAngle = 0, armRotate = 0, armDirection = 0;
			armUp = false, armDown = false, armTurnUp = false, armTurnDown = false;
			fx = 0, fy = 0, fz = 0, fx2 = 0, fy2 = 0, fz2 = 0;
			fingerRotate = 0, fingerRSpeed = 0, fingerBend = false, fCount = 0;
			
			sideView = false;
			llCount = 0, lrCount = 0;
			rLeftLeg = 0, legLSpeed = 0;
			rRightLeg = 0, legRSpeed = 0;
			
		}
		else if (wParam == 0x4D) { // m - open or close mask
			mCount *= -1;
			if (mCount == -1) {
				openMask = true;
			}
			else {
				openMask = false;
			}
		}
		else if (wParam == 0x4E) { // n - nod or lift
			nCount *= -1;
			if (nCount == -1) {
				nod = true;
			}
			else {
				nod = false;
			}
		}
		else if (wParam == 0x46) { // F
			if (fCount % 2 == 0)
				fx = 1, fy = 0, fz = 0, fx2 = 0, fy2 = 1, fz2 = 0, fingerRSpeed = 0.5, fingerBend = true, fCount++;
			else
				fx = 0, fy = 0, fz = 0, fx2 = 0, fy2 = 0, fz2 = 0, fingerRotate = 0, fingerRSpeed = 0, fingerBend = false, fCount++;
		}
		else if (wParam == 0x4C) { // L
			if (llCount % 2 == 0)
				raiseLeftLeg = true, raiseRightLeg = false, llCount++, legLSpeed = 2;
			else
				raiseLeftLeg = false, llCount++, legLSpeed = -2;
		}
		else if (wParam == 0x4B) { // K
			if (lrCount % 2 == 0)
				raiseRightLeg = true, raiseLeftLeg = false, lrCount++, legRSpeed = 2;
			else
				raiseRightLeg = false, lrCount++, legRSpeed = -2;
		}
		else if (wParam == 0x50) {//P
			if (pCount % 2 == 0)
				view = 'o', pCount++;
			else
				view = 'p', pCount++;
		}
		else if (wParam == 0x52) { //R - anti
			ry += rSpeedP;
		}
		else if (wParam == 0x51) { //Q - clockwise
			ry -= rSpeedP;
		}
		else if (wParam == 0x57) { // W
			xR = 1, yR = 0, zR = 0;
			str = "upRotate";
		}
		else if (wParam == 0x53) { // S
			xR = 1, yR = 0, zR = 0;
			str = "downRotate";
			if (qNo == 3)
				sideView = true;
		}
		else if (wParam == 0x41) { // A
			xR = 0, yR = 1, zR = 0;
			str = "leftRotate";
		}
		else if (wParam == 0x42) { // B to bow or straighten body
			bCount *= -1;
			if (bCount == -1) {
				bow = true;
			}
			else {
				bow = false;
			}
		}
		else if (wParam == 0x44) { // D
			xR = 0, yR = 1, zR = 0;
			str = "rightRotate";
		}
		else if (wParam == VK_ADD || wParam == 0xBB) {
			zoom += 0.2;
		}
		else if (wParam == VK_SUBTRACT || wParam == 0xBD) {
			zoom -= 0.2;
		}
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void init() {
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//============================= DANNY =================================

// head
void helmet() {
	glPushMatrix();
	glRotatef(nodRotate, 1, 0, 0);

	glPushMatrix();
	glScalef(1, 1, 1.3);

	h.headTop();

	// right
	h.headRightTop1();
	h.headRightTop2();
	h.headRightMid();
	h.headRightBtm();
	h.headRightBtm2();
	h.headRightBack();

	// left
	h.headLeftTop1();
	h.headLeftTop2();
	h.headLeftMid();
	h.headLeftBtm();
	h.headLeftBtm2();
	h.headLeftBack();

	glPushMatrix();
	glTranslatef(0, 0, -0.65); // back to original place
	glRotatef(-maskRotate, 1, 0, 0);
	glTranslatef(0, 0, 0.65); // go to center point
	h.mask();
	glPopMatrix();

	glPopMatrix();

	h.btmCover();

	// right
	glTranslatef(fh.xP(-115), fh.yP(10), -fh.zP(55));
	h.ear();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	fh.cylinder(GLU_FILL, fh.yP(55), fh.yP(55), fh.yP(230), 50, 50);
	glPopMatrix();

	// right
	glTranslatef(fh.xP(230), fh.yP(0), fh.zP(0));
	h.ear();

	glPopMatrix();
}
//============================= DANNY =================================

//============================= LIANA =================================

void finger(GLenum type, float size, float size2, int lineWidth) {
	glPushMatrix();
	if (fingerBend)
		glRotatef(fingerRotate * 2, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2, size, 0);

	glRotatef(-90, 0, 0, 1);
	fh.color('r');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();

	glPushMatrix();
	if (fingerBend)
		glRotatef(fingerRotate, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0, size, 0);
	
	glRotatef(-90, 0, 0, 1);
	fh.color('g');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0);
	if (fingerBend) {
		glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0 - 0.5);
		glRotatef(-fingerRotate, fx2, fy2, fz2);
		glTranslatef(-(-size / 3.0 * 2.0), -(size - 0.15), -size / 5.0);
	}
	fh.color('y');
	fh.sphere(GLU_LINE, size / 8.0, 10, 10);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void leftPalm(GLenum type, float size, float size2, int lineWidth) {
	//--------------------palm--------------------
	glPushMatrix();
	glTranslatef(0, 0, -0.25);
	glLineWidth(lineWidth);
	//front
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, size2);
	glVertex3f(0, 0, size2);
	glVertex3f(size, 0, size2);
	glVertex3f(size, size, size2);
	glEnd();
	//right
	fh.color('w');
	glBegin(type);
	glVertex3f(size, size, size2);
	glVertex3f(size, 0, size2);
	glVertex3f(size, 0, 0);
	glVertex3f(size, size, 0);
	glEnd();
	//left
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, size2);
	glVertex3f(0, 0, size2);
	glVertex3f(0, 0, 0);
	glVertex3f(0, size, 0);
	glEnd();
	//bottom
	fh.color('w');
	glBegin(type);
	glVertex3f(0, 0, size2);
	glVertex3f(0, 0, 0);
	glVertex3f(size, 0, 0);
	glVertex3f(size, 0, size2);
	glEnd();
	//top
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, size2);
	glVertex3f(0, size, 0);
	glVertex3f(size, size, 0);
	glVertex3f(size, size, size2);
	glEnd();
	//back
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(size, 0, 0);
	glVertex3f(size, size, 0);
	glEnd();
	glPopMatrix();

	//--------------------thumb--------------------
	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, -0.5);
		glRotatef(fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 + 0.1, size, 0);

	glRotatef(90, 0, 0, 1);
	fh.cuboid(type, size / 2.5, 1, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, -0.5);
		glRotatef(fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 - 0.1, size + 0.4, 0.2);

	fh.sphere(GLU_LINE, size / 5.0, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//--------------------1st Finger--------------------
	float fSize = size;
	size2 = 0.8;
	finger(type, fSize, size2, lineWidth);

	//--------------------2nd Finger--------------------
	float fty = 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.25, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------3rd Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.15, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------4th Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(0.8, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();
}

void rightPalm(GLenum type, float size, float size2, int lineWidth) {
	//--------------------palm--------------------
	glPushMatrix();
	glTranslatef(0, 0, -0.25);
	glLineWidth(lineWidth);
	//front
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, size2);
	glVertex3f(0, 0, size2);
	glVertex3f(size, 0, size2);
	glVertex3f(size, size, size2);
	glEnd();
	//right
	fh.color('w');
	glBegin(type);
	glVertex3f(size, size, size2);
	glVertex3f(size, 0, size2);
	glVertex3f(size, 0, 0);
	glVertex3f(size, size, 0);
	glEnd();
	//left
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, size2);
	glVertex3f(0, 0, size2);
	glVertex3f(0, 0, 0);
	glVertex3f(0, size, 0);
	glEnd();
	//bottom
	fh.color('w');
	glBegin(type);
	glVertex3f(0, 0, size2);
	glVertex3f(0, 0, 0);
	glVertex3f(size, 0, 0);
	glVertex3f(size, 0, size2);
	glEnd();
	//top
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, size2);
	glVertex3f(0, size, 0);
	glVertex3f(size, size, 0);
	glVertex3f(size, size, size2);
	glEnd();
	//back
	fh.color('w');
	glBegin(type);
	glVertex3f(0, size, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(size, 0, 0);
	glVertex3f(size, size, 0);
	glEnd();
	glPopMatrix();

	//--------------------thumb--------------------
	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, -0.5);
		glRotatef(fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 + 0.1, size, 0);

	glRotatef(90, 0, 0, 1);
	fh.cuboid(type, size / 2.5, 1, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, -0.5);
		glRotatef(fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 - 0.1, size + 0.4, 0.2);

	fh.sphere(GLU_LINE, size / 5.0, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//--------------------1st Finger--------------------
	float fSize = size;
	size2 = 0.8;
	finger(type, fSize, size2, lineWidth);

	//--------------------2nd Finger--------------------
	float fty = 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.25, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------3rd Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.15, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------4th Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(0.8, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();
}

void shoe(float height, float footSize, float sRadius, float slices, float stacks) {
	glPushMatrix();
	glRotatef(-90, 1.0, 0, 0);
	glPushMatrix();
	fh.color('w');
	glTranslatef(/*-calfTopRadius - 0.02*/ 0.07, /*(-calfTopRadius - 0.01) * 2*/ -height - 0.07 /*- footSize*/, /*height + footSize*/ -footSize * 0.5);
	////glRotatef(90, 1.0, 0, 0);
	glRotatef(90, 0, 0, 1.0);
	glScalef(footSize, footSize, footSize * 1.25); //foot
	fh.cuboid(nonGLUtype, 1.0, 0.5, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height, footSize * 0.5);
	glScalef(footSize * 0.5, footSize * 0.5, footSize * 0.5);
	glRotatef(220, 1.0, 0, 0);
	fh.pyramid(nonGLUtype, 0.5, 2); //ball of foot
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height - 0.035, footSize * 1.25);
	glScalef(footSize, footSize * 0.5, footSize);
	glRotatef(90, 1.0, 0, 0);
	fh.pyramid(nonGLUtype, 0.5, 2); //ball of foot
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height - 0.05, footSize * 1.3);
	glScalef(2.0, 0.75, 2.5);
	fh.sphere(GLUtype, sRadius * 0.4, slices, stacks); //ball of foot
	glPopMatrix();
	glPopMatrix();
}

void leftLeg() {
	float thighBaseRadius = 0.08, thighTopRadius = thighBaseRadius - 0.01, height = 0.52, slices = 30, stacks = 30;
	float calfBaseRadius = thighTopRadius, calfTopRadius = calfBaseRadius - 0.02;
	float sRadius = thighTopRadius;
	float footSize = thighBaseRadius + 0.05;

	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0, 0, -height);
	fh.color('g');
	fh.sphere(GLU_LINE, thighBaseRadius, slices, stacks);
	fh.cylinder(GLUtype, thighBaseRadius, thighTopRadius, height, slices, stacks); //thigh
	glPopMatrix();

	glPushMatrix();
	fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //knee
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (!(rLeftLeg < 0)) {
		if (raiseLeftLeg && rLeftLeg < 90 || !raiseLeftLeg && rLeftLeg > 0)
			rLeftLeg += legLSpeed;
		glTranslatef(height, 0, 0), glRotatef(rLeftLeg, 1.0, 0, 0), glTranslatef(-height, 0, 0);
	}

	fh.color('r');
	fh.cylinder(GLUtype, calfBaseRadius, calfTopRadius, height, slices, stacks); //calf

	shoe(height, footSize, sRadius, slices, stacks);

	glPopMatrix();
	glPopMatrix();
}

void rightLeg() {
	float thighBaseRadius = 0.08, thighTopRadius = thighBaseRadius - 0.01, height = 0.52, slices = 30, stacks = 30;
	float calfBaseRadius = thighTopRadius, calfTopRadius = calfBaseRadius - 0.02;
	float sRadius = thighTopRadius;
	float footSize = thighBaseRadius + 0.05;

	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0, 0, -height);
	fh.color('g');
	fh.sphere(GLU_LINE, thighBaseRadius, slices, stacks);
	fh.cylinder(GLUtype, thighBaseRadius, thighTopRadius, height, slices, stacks); //thigh
	glPopMatrix();

	glPushMatrix();
	fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //knee
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (!(rRightLeg < 0)) {
		if (raiseRightLeg && rRightLeg < 90 || !raiseRightLeg && rRightLeg > 0)
			rRightLeg += legRSpeed;
		glTranslatef(height, 0, 0), glRotatef(rRightLeg, 1.0, 0, 0), glTranslatef(-height, 0, 0);
	}

	fh.color('r');
	fh.cylinder(GLUtype, calfBaseRadius, calfTopRadius, height, slices, stacks); //calf

	shoe(height, footSize, sRadius, slices, stacks);

	glPopMatrix();
	glPopMatrix();
}

void armArmour1(GLenum typeQ, GLenum typeT, GLenum typeP) {

	int direction = 1;

	fh.color('w');

	glBegin(typeQ);
	fh.v3f(400, 3, direction * 0);
	fh.v3f(445, 3, direction * 0);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(400, 33, direction * 94);
	glEnd();

	glBegin(typeT);
	fh.v3f(445, 3, direction * 0);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(540, 33, direction * 94);
	glEnd();

	glBegin(typeQ);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(540, 33, direction * 94);
	fh.v3f(540, 75, direction * 152);
	fh.v3f(445, 75, direction * 152);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(445, 3, direction * 0);
	fh.v3f(540, 33, direction * 94);
	fh.v3f(540, 33, -direction * 94);
	fh.v3f(445, 3, -direction * 0);
	glEnd();

	glBegin(typeQ);
	fh.v3f(445, 3, direction * 0);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(540, 33, direction * 94);
	glEnd();

	glBegin(typeQ);
	fh.v3f(400, 33, direction * 94);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(445, 75, direction * 152);
	fh.v3f(400, 75, direction * 152);
	glEnd();

	glBegin(typeT);
	fh.v3f(540, 33, direction * 94);
	fh.v3f(540, 75, direction * 152);
	fh.v3f(604, 75, direction * 152);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(540, 33, direction * 94);
	fh.v3f(604, 75, direction * 152);
	fh.v3f(604, 75, -direction * 152);
	fh.v3f(540, 33, -direction * 94);
	glEnd();

	glBegin(typeT);
	fh.v3f(400, 75, direction * 152);
	fh.v3f(400, 100, direction * 171);
	fh.v3f(340, 100, direction * 171);
	glEnd();

	glBegin(typeQ);
	fh.v3f(400, 75, direction * 152);
	fh.v3f(604, 75, direction * 152);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(400, 100, direction * 171);
	glEnd();

	glBegin(typeT);
	fh.v3f(604, 75, direction * 152);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(630, 100, direction * 171);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(604, 75, direction * 152);
	fh.v3f(630, 100, direction * 171);
	fh.v3f(630, 100, -direction * 171);
	fh.v3f(604, 75, -direction * 152);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 100, direction * 171);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(604, 170, direction * 202);
	fh.v3f(340, 170, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(630, 100, direction * 171);
	fh.v3f(685, 170, direction * 202);
	fh.v3f(604, 170, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(630, 100, direction * 171);
	fh.v3f(685, 170, direction * 202);
	fh.v3f(685, 170, -direction * 202);
	fh.v3f(630, 100, -direction * 171);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 170, direction * 202);
	fh.v3f(664, 170, direction * 202);
	fh.v3f(664, 253, direction * 202);
	fh.v3f(340, 253, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(664, 170, direction * 202);
	fh.v3f(685, 170, direction * 202);
	fh.v3f(703, 253, direction * 202);
	fh.v3f(664, 253, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(685, 170, direction * 202);
	fh.v3f(703, 253, direction * 202);
	fh.v3f(703, 253, -direction * 202);
	fh.v3f(685, 170, -direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 253, direction * 202);
	fh.v3f(604, 253, direction * 202);
	fh.v3f(604, 292, direction * 202);
	fh.v3f(340, 292, direction * 202);
	glEnd();

	glBegin(typeT);
	fh.v3f(604, 253, direction * 202);
	fh.v3f(703, 253, direction * 202);
	fh.v3f(604, 292, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(703, 253, direction * 202);
	fh.v3f(604, 292, direction * 202);
	fh.v3f(604, 292, -direction * 202);
	fh.v3f(703, 253, -direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 292, direction * 202);
	fh.v3f(540, 292, direction * 202);
	fh.v3f(540, 317, direction * 202);
	fh.v3f(340, 317, direction * 202);
	glEnd();

	glBegin(typeT);
	fh.v3f(540, 292, direction * 202);
	fh.v3f(604, 292, direction * 202);
	fh.v3f(540, 317, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(604, 292, direction * 202);
	fh.v3f(540, 317, direction * 202);
	fh.v3f(540, 317, -direction * 202);
	fh.v3f(604, 292, -direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 317, direction * 202);
	fh.v3f(540, 317, direction * 202);
	fh.v3f(540, 400, direction * 202);
	fh.v3f(340, 400, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(540, 317, direction * 202);
	fh.v3f(540, 400, direction * 202);
	fh.v3f(540, 400, -direction * 202);
	fh.v3f(540, 317, -direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(470, 400, direction * 202);
	fh.v3f(540, 400, direction * 202);
	fh.v3f(540, 434, direction * 202);
	fh.v3f(445, 434, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(540, 400, direction * 202);
	fh.v3f(540, 434, direction * 202);
	fh.v3f(540, 434, -direction * 202);
	fh.v3f(540, 400, -direction * 202);
	glEnd();

	glBegin(typeT);
	fh.v3f(340, 434, direction * 202);
	fh.v3f(540, 434, direction * 202);
	fh.v3f(340, 543, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	fh.v3f(540, 434, direction * 202);
	fh.v3f(340, 543, direction * 202);
	fh.v3f(340, 543, -direction * 202);
	fh.v3f(540, 434, -direction * 202);
	glEnd();

	fh.color('r');
	glBegin(typeP);
	fh.circle(400, 400, direction * 204, 77, 77, 0, 360);
	glEnd();
	fh.color('g');
	glBegin(typeP);
	fh.circle(400, 400, direction * 206, 54, 54, 0, 360);
	glEnd();
}

void armArmour2(GLenum typeQ, GLenum typeT, GLenum typeP) {

	int direction = -1;

	fh.color('w');

	glBegin(typeQ);
	fh.v3f(400, 3, direction * 0);
	fh.v3f(445, 3, direction * 0);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(400, 33, direction * 94);
	glEnd();

	//fh.color('y');
	glBegin(typeT);
	fh.v3f(445, 3, direction * 0);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(540, 33, direction * 94);
	glEnd();

	//fh.color('r');
	glBegin(typeQ);
	fh.v3f(400, 33, direction * 94);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(445, 75, direction * 152);
	fh.v3f(400, 75, direction * 152);
	glEnd();

	glBegin(typeQ);
	fh.v3f(445, 33, direction * 94);
	fh.v3f(540, 33, direction * 94);
	fh.v3f(540, 75, direction * 152);
	fh.v3f(445, 75, direction * 152);
	glEnd();

	glBegin(typeT);
	fh.v3f(540, 33, direction * 94);
	fh.v3f(540, 75, direction * 152);
	fh.v3f(604, 75, direction * 152);
	glEnd();

	glBegin(typeT);
	fh.v3f(400, 75, direction * 152);
	fh.v3f(400, 100, direction * 171);
	fh.v3f(340, 100, direction * 171);
	glEnd();

	glBegin(typeQ);
	fh.v3f(400, 75, direction * 152);
	fh.v3f(604, 75, direction * 152);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(400, 100, direction * 171);
	glEnd();

	glBegin(typeT);
	fh.v3f(604, 75, direction * 152);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(630, 100, direction * 171);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 100, direction * 171);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(604, 170, direction * 202);
	fh.v3f(340, 170, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(604, 100, direction * 171);
	fh.v3f(630, 100, direction * 171);
	fh.v3f(685, 170, direction * 202);
	fh.v3f(604, 170, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 170, direction * 202);
	fh.v3f(664, 170, direction * 202);
	fh.v3f(664, 253, direction * 202);
	fh.v3f(340, 253, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(664, 170, direction * 202);
	fh.v3f(685, 170, direction * 202);
	fh.v3f(703, 253, direction * 202);
	fh.v3f(664, 253, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 253, direction * 202);
	fh.v3f(604, 253, direction * 202);
	fh.v3f(604, 292, direction * 202);
	fh.v3f(340, 292, direction * 202);
	glEnd();

	glBegin(typeT);
	fh.v3f(604, 253, direction * 202);
	fh.v3f(703, 253, direction * 202);
	fh.v3f(604, 292, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 292, direction * 202);
	fh.v3f(540, 292, direction * 202);
	fh.v3f(540, 317, direction * 202);
	fh.v3f(340, 317, direction * 202);
	glEnd();

	glBegin(typeT);
	fh.v3f(540, 292, direction * 202);
	fh.v3f(604, 292, direction * 202);
	fh.v3f(540, 317, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(340, 317, direction * 202);
	fh.v3f(540, 317, direction * 202);
	fh.v3f(540, 400, direction * 202);
	fh.v3f(340, 400, direction * 202);
	glEnd();

	glBegin(typeQ);
	fh.v3f(470, 400, direction * 202);
	fh.v3f(540, 400, direction * 202);
	fh.v3f(540, 434, direction * 202);
	fh.v3f(445, 434, direction * 202);
	glEnd();

	glBegin(typeT);
	fh.v3f(340, 434, direction * 202);
	fh.v3f(540, 434, direction * 202);
	fh.v3f(340, 543, direction * 202);
	glEnd();

	fh.color('r');
	glBegin(typeP);
	fh.circle(400, 400, direction * 204, 77, 77, 0, 360);
	glEnd();
	fh.color('g');
	glBegin(typeP);
	fh.circle(400, 400, direction * 206, 54, 54, 0, 360);
	glEnd();
}

void armArmour() {
	/*GLenum typeQ = GL_LINE_LOOP;
	GLenum typeT = GL_LINE_LOOP;
	GLenum typeP = GL_LINE_LOOP;*/

	GLenum typeQ = GL_QUADS;
	GLenum typeT = GL_TRIANGLES;
	GLenum typeP = GL_POLYGON;

	armArmour1(typeQ, typeT, typeP);
	armArmour2(typeQ, typeT, typeP);
}

void leftArm() {
	float uaBaseRadius = 0.05, uaTopRadius = uaBaseRadius - 0.005, height = 0.3, slices = 30, stacks = 30;
	float laBaseRadius = uaTopRadius, laTopRadius = laBaseRadius - 0.01;
	float sRadius = uaTopRadius;
	float palmSize = uaBaseRadius + 0.05;

	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();
	
	glTranslatef(0, 0, -height);
	fh.color('g');
	fh.sphere(GLUtype, sRadius, slices, stacks);
	fh.cylinder(GLUtype, uaBaseRadius, uaTopRadius, height, slices, stacks); //upperarm
	glPopMatrix();

	glPushMatrix();
	//glRotatef(-90, 1.0, 0, 0);
	//glTranslatef(0, 0, height);

	glPushMatrix();
	fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //elbow
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);
	
	fh.color('r');
	fh.cylinder(GLUtype, laBaseRadius, laTopRadius, height, slices, stacks); //lowerarm
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);
	glTranslatef(0, -laTopRadius - 0.01, height + palmSize);
	//glRotatef(90, 1.0, 0, 0);
	glRotatef(90, 0, 1.0, 0);
	glScalef(palmSize, palmSize, palmSize);
	leftPalm(nonGLUtype, 1.0, 0.5, 2);
	glPopMatrix();
	glPopMatrix();

}

void rightArm() {
	float uaBaseRadius = 0.05, uaTopRadius = uaBaseRadius - 0.005, height = 0.3, slices = 30, stacks = 30;
	float laBaseRadius = uaTopRadius, laTopRadius = laBaseRadius - 0.01;
	float sRadius = uaTopRadius;
	float palmSize = uaBaseRadius + 0.05;

	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();

	glTranslatef(0, 0, -height);
	fh.color('g');
	fh.sphere(GLUtype, sRadius, slices, stacks);
	fh.cylinder(GLUtype, uaBaseRadius, uaTopRadius, height, slices, stacks); //upperarm
	glPopMatrix();

	glPushMatrix();
	//glRotatef(-90, 1.0, 0, 0);
	//glTranslatef(0, 0, height);

	glPushMatrix();
	fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //elbow
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);

	fh.color('r');
	fh.cylinder(GLUtype, laBaseRadius, laTopRadius, height, slices, stacks); //lowerarm
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);
	glTranslatef(0, -laTopRadius - 0.01, height + palmSize);
	//glRotatef(90, 1.0, 0, 0);
	glRotatef(90, 0, 1.0, 0);
	glScalef(palmSize, palmSize, palmSize);
	rightPalm(nonGLUtype, 1.0, 0.5, 2);
	glPopMatrix();
	glPopMatrix();

}

void robotBody() {
	// adomen 0 + chest
	glPushMatrix();
	glRotatef(AR4, 1, 0, 0);
	glTranslatef(0, fh.yP(85), 0);
	glRotatef(AR2, 1, 0, 0);
	b.chest();
	b.adomen0();

	// head
	glPushMatrix();
	glTranslatef(0, fh.yP(185), fh.zP(20));
	glScalef(0.25, 0.25, 0.25);
	helmet();
	glPopMatrix();

	//arm if dun put this, bugs will occur
	glPushMatrix();
	glScalef(0, 0, 0);
	leftArm();
	glPopMatrix();

	//arm right
	glPushMatrix();
	glTranslatef(fh.xP(170), fh.yP(180), fh.zP(0));
	glScalef(0.9, 0.9, 0.9);
	//glRotatef(180, 1.0, 0, 0);
	rightArm();
	glPopMatrix();

	//arm left
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(fh.xP(170), fh.yP(180), fh.zP(0));
	glScalef(0.9, 0.9, 0.9);
	leftArm();
	glPopMatrix();

	glPopMatrix();

	// adomen 1
	glPushMatrix();
	glRotatef(AR3, 1, 0, 0);
	glTranslatef(0, fh.yP(72.5), 0);
	glRotatef(AR, 1, 0, 0);
	b.adomen1();
	glPopMatrix();

	// adomen 2
	glPushMatrix();
	glRotatef(AR0, 1, 0, 0);
	glTranslatef(0, fh.yP(60), 0);
	glRotatef(0, 1, 0, 0);
	b.adomen2();
	glPopMatrix();

	// adomen 3
	glPushMatrix();
	glRotatef(AR1, 1, 0, 0);
	glTranslatef(0, fh.yP(47.5), 0);
	b.adomen3();
	glPopMatrix();

	// below
	glPushMatrix();
	glTranslatef(0, fh.yP(47.5), 0);
	b.below();
	glPopMatrix();

	//left leg
	glPushMatrix();
	glRotatef(-rLeftLeg, 1.0, 0, 0);
	glTranslatef(-fh.xP(35), -fh.yP(140), fh.zP(0));
	glScalef(0.7, 0.7, 0.7);
	leftLeg();
	glPopMatrix();

	//right leg
	glPushMatrix();
	glRotatef(-rRightLeg, 1.0, 0, 0);
	glTranslatef(fh.xP(35), -fh.yP(140), fh.zP(0));
	glScalef(0.7, 0.7, 0.7);
	rightLeg();
	glPopMatrix();
}

//============================= LIANA =================================

void switchView(char view) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(tx, ty, 0.0);
	if (qNo == 2) {
		glRotatef(ry, 1.0, 0.0, 0);
	}
	else {
		glRotatef(ry, 0.0, 1.0, 0);
	}
	switch (view) {
	case 'o':
		glOrtho(-ORTHO_VIEW, ORTHO_VIEW, -ORTHO_VIEW, ORTHO_VIEW, -ORTHO_VIEW, ORTHO_VIEW);
		break;
	case 'p':
		gluPerspective(60.0, 1.0, -1.0, 1.0);
		glFrustum(-FRUSTUM_VIEW, FRUSTUM_VIEW, -FRUSTUM_VIEW, FRUSTUM_VIEW, 1.0, FRUSTUM_VIEW * 2 + 1.0);
		break;
	}
}

void display()
{
	init();
	switchView(view);
	for (int i = 0; i < SIZE; i++) {
		C[i] = 1000000;
	}

	//==================== body =========================
	{
		int angle = 10, angle2 = angle + 1, angle3 = angle2 + 1, angle4 = angle - 5, an = 5;

		// press 'B' to bow or straighten the body 
		if (bow) {
			if (AR1 < angle4) {
				AR1 += 0.1;
			}
			if (AR1 == angle4) {
				AR1 = angle4;
			}

			if (AR0 < angle) {
				AR0 += 0.1;
			}
			if (AR0 == angle) {
				AR0 = angle;
			}

			if (AR3 < angle2) {
				AR3 += 0.1;
				if (AR < an) {
					AR += 0.1;
				}
			}
			if (AR3 == angle2) {
				AR3 = angle2;
			}

			if (AR4 < angle3) {
				AR4 += 0.1;
				if (AR2 < (an + an)) {
					AR2 += 0.1;
				}
			}
			if (AR4 == angle3) {
				AR4 = angle3;
			}
		}

		if (!bow) {
			if (AR1 >= 0) {
				AR1 -= 0.1;
			}
			if (AR1 == 0) {
				AR1 = 0;
			}

			if (AR0 >= 0) {
				AR0 -= 0.1;
			}
			if (AR0 == 0) {
				AR0 = 0;
			}

			if (AR3 >= 0) {
				AR3 -= 0.1;
				if (AR >= 0) {
					AR -= 0.1;
				}
			}
			if (AR3 == 0) {
				AR3 = 0;
			}

			if (AR4 >= 0) {
				AR4 -= 0.1;
				if (AR2 >= 0) {
					AR2 -= 0.1;
				}
			}
			if (AR4 == 0) {
				AR4 = 0;
			}
		}
	}
	//===================================================

	// =================== head =========================
	{

		if (openMask && maskRotate <= 30) {
			maskRotate += maskRotateSpeed;
		}
		else if (!openMask && maskRotate > 0) {
			maskRotate -= maskRotateSpeed;
		}

		if (nod && nodRotate < 20) {
			nodRotate += nodRotateSpeed;
		}
		else if (!nod && nodRotate > 0) {
			nodRotate -= nodRotateSpeed;
		}
	}
	// ==================================================

	// =============== arm rotate =======================
	{
		if (armTurnUp || armTurnDown)
			glRotatef(armRotate, armx2, army2, armz2);

		// for right hand rotate
		if (armTurnUp && !armTurnDown && armRotate > -90) {
			armRotate -= armRSpeed;
		}
		else if (armTurnDown && !armTurnUp && armRotate < 30) {
			armRotate += armRSpeed;
		}

		if (fingerBend && fingerRotate <= 45)
			fingerRotate += fingerRSpeed;
		else if (!fingerBend && fingerRotate > 45) {
			fingerRotate -= fingerRSpeed;
		}
	}
	// =================================================

	// ============== Lower Arm rift ===================
	{
		if (armAngle == 110) {
			armAngle = 110;
		}
		else if (armAngle == 0) {
			armAngle = 0;
			armDown = false;
		}

		if (armUp == true && armAngle <= 110) {
			armAngle += armRSpeed;
		}
		else if (armDown == true) {
			armAngle -= armRSpeed;
		}
	}
	// =================================================

	// ================== Leg ==========================
	{
		if (raiseLeftLeg && rLeftLeg < 45 || !raiseLeftLeg && rLeftLeg > -35)
			rLeftLeg += legRSpeed;
	}
	
	// =================================================
	switch (qNo) {
	case 1:
		glPushMatrix();
		glScalef(zoom, zoom, zoom);
		glTranslatef(xT, yT, zT);
		glPushMatrix();
		robotBody();
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glScalef(zoom, zoom, zoom);
		glTranslatef(xT, yT, zT);
		// body 
		glPushMatrix();
		robotBody();
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();
		glScalef(zoom, zoom, zoom);
		if (raiseLeftLeg && rLeftLeg < 45 || !raiseLeftLeg && rLeftLeg > -35)
			rLeftLeg += legLSpeed;

		glTranslatef(0, 0.52, 0);
		glRotatef(-rLeftLeg, 1.0, 0, 0);
		glTranslatef(0, -0.52, 0);
		leftLeg();
		glPopMatrix();
		break;
	case 6:
		//if ((armUp && armAngle > 110) || (armDown && armAngle > 0)) //raise hand
		//	armAngle -= armRSpeed;
		//else if (armAngle == 110)
		//	armAngle = armAngle;
		//else if (armAngle == 0)
		//{ }
		//	
		//else
		//	armAngle += armRSpeed;

		//---------- lower arm lift -----------
		if (armAngle == 110) {
			armAngle = 110;
		}
		else if (armAngle == 0) {
			armAngle = 0;
			armDown = false;
		}

		if (armUp == true && armAngle <= 110) {
			armAngle += armRSpeed;
		}
		else if (armDown == true) {
			armAngle -= armRSpeed;
		}

		//if (armDirection == 1 && armRotate <= 30) //arm rotate
		//	armRotate += armRSpeed;
		//else
		//	if(armRotate >= -90)
		//		armRotate -= armRSpeed;

		


		//glRotatef(0.3, 0, 1.0, 0);
		glPushMatrix();
		if (armTurnUp || armTurnDown)
			glRotatef(armRotate, armx2, army2, armz2);
		glPushMatrix();
		glScalef(zoom, zoom, zoom);
		leftArm();
		glPopMatrix();
		glPopMatrix();
		break;
	case 5:
		armArmour();
		break;
	case 7:
		break;
	case 61:
		C[0] = 0, C[1] = 0, C[2] = 0;
		C[3] = 0.2, C[4] = 0, C[5] = 0;
		C[6] = 0.2, C[7] = 0.2, C[8] = 0;
		glColor3f(1, 1, 1);
		glLineWidth(3);
		glRotatef(1, 0, 1, 0);
		fh.poly3(GL_LINE_STRIP, C, SIZE);
		C[0] = 0, C[1] = 0, C[2] = 0;
		C[3] = -0.2, C[4] = 0, C[5] = 0;
		C[6] = -0.2, C[7] = 0.2, C[8] = 0;
		glColor3f(1, 0, 0);
		fh.poly3(GL_LINE_STRIP, C, SIZE);
		break;
	default:
		glPushMatrix();
		glScalef(zoom, zoom, zoom);
		glTranslatef(xT, yT, zT);
		glPushMatrix();
		robotBody();
		glPopMatrix();
		break;
	}
}
//--------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW, CW, WIDTH, HEIGHT,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------