#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include <string>
#include "Function.h"

using namespace N;
// using namespace std;

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
int qNo = 3;
std::string str = " ";
float C[SIZE];
float zoom = 1.0;
//============== Danny ==============
float AR = 0, AR1 = 0, AR2 = 0, AR3 = 0, AR4 = 0, AR0 = 0, AR01 = 0, AR5 = 0;
float rotate = 0;
float xR = 0, yR = 0, zR = 0, xT = 0, yT = 0, zT = 0;
//===================================

//============== LIANA ==============
float armRotate = 0, armRSpeed = 0, armx = 0, army = 0, armz = 0, armDirection = 0, armAngle = 0;
float armx2 = 0, army2 = 0, armz2 = 0;
boolean armTurn = false, armUp = false, armDown  = false;
float fingerRotate = 0, fingerRSpeed = 0, fx = 0, fy = 0, fz = 0 /*, fingerDirection = 0, fingerAngle = 0*/;
float fx2 = 0, fy2 = 0, fz2 = 0;
int fCount = 0, llCount = 0, lrCount = 0;
boolean fingerBend = false;
boolean sideView = true;
boolean raiseLeftLeg = false, raiseRightLeg = false;
GLenum nonGLUtype = GL_POLYGON;
GLenum GLUtype = GLU_FILL;
char view = 'p';
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
			if(qNo == 1)
				str = "up";
			if(qNo == 4)
				armx = 1.0, army = 0, armz = 0, armRSpeed = 0.5, armUp = true, armDown = false;
		}
		else if (wParam == VK_DOWN) {
			if(qNo == 1)
				str = "down";
			if(qNo == 4)
				armx = 1.0, army = 0, armz = 0, armUp = false, armDown = true;
		}
		else if (wParam == VK_LEFT) {
			if(qNo == 4)
				armx2 = 1.0, army2 = 0, armz2 = 0, armDirection = +1.0, armRSpeed = 0.5, armTurn = true;
		}
		else if (wParam == VK_RIGHT) {
			if(qNo == 4)
				armx2 = 1.0, army2 = 0, armz2 = 0, armDirection = -1.0, armRSpeed = 0.5, armTurn = true;
		}
		else if (wParam == VK_SPACE) {
			str = "space";
			glLoadIdentity();
			if (qNo == 4) {
				armx = 1.00, army = 0, armz = 0, armx2 = 0, army2 = 0, armz2 = 0;
				armRSpeed = 0, armAngle = 0, armRotate = 0, armDirection = 0;
				armUp = false, armDown = false, armTurn = false;
				fx = 0, fy = 0, fz = 0, fx2 = 0, fy2 = 0, fz2 = 0;
				fingerRotate = 0, fingerRSpeed = 0, fingerBend = false, fCount = 0;
			}
			if (qNo == 3) {
				sideView = false;
			}
		}
		else if (wParam == 0x46) { // F
			if(fCount % 2 == 0)
				fx = 1, fy = 0, fz = 0, fx2 = 0, fy2 = 1, fz2 = 0, fingerRSpeed = 0.5, fingerBend = true, fCount++;
			else
				fx = 0, fy = 0, fz = 0, fx2 = 0, fy2 = 0, fz2 = 0, fingerRotate = 0, fingerRSpeed = 0, fingerBend = false, fCount++;
		}
		else if (wParam == 0x4C) { // L
			if (llCount % 2 == 0)
				raiseLeftLeg = true, llCount++;
			else
				raiseLeftLeg = false, llCount++;
		}
		else if (wParam == 0x4B) { // K
			if (lrCount % 2 == 0)
				raiseRightLeg = true, lrCount++;
			else
				raiseRightLeg = false, lrCount++;
		}
		else if (wParam == 0x50) {//P
			if (pCount % 2 == 0)
				view = 'o', pCount++;
			else
				view = 'p', pCount++;
		}
		else if (wParam == 0x52) //R - anti
			ry += rSpeedP;
		else if (wParam == 0x51) //Q - clockwise
			ry -= rSpeedP;
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

// body
void upperChest(GLenum gltype) {
	// front top
	glColor3f(1, 0.7, 0.3);
	glBegin(gltype);
	fh.v3f(378.75, 265, 25);
	fh.v3f(356.25, 270, 30);
	fh.v3f(443.75, 270, 30);
	fh.v3f(421.25, 265, 25);
	glEnd();

	// front btm
	glColor3f(1, 0, 0.5);
	glBegin(gltype);
	fh.v3f(356.25, 270, 30);
	fh.v3f(340, 307.5, 50);
	fh.v3f(460, 307.5, 50);
	fh.v3f(443.75, 270, 30);
	glEnd();

	// left top
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(378.75, 265, -37.5);
	fh.v3f(356.25, 270, -42.5);
	fh.v3f(356.25, 270, 30);
	fh.v3f(378.75, 265, 25);
	glEnd();

	// left btm
	glColor3f(0, 1, 0);
	glBegin(gltype);
	fh.v3f(356.25, 270, -42.5);
	fh.v3f(340, 307.5, -60);
	fh.v3f(340, 307.5, 50);
	fh.v3f(356.25, 270, 30);
	glEnd();

	// right top
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh.v3f(421.25, 265, 25);
	fh.v3f(443.75, 270, 30);
	fh.v3f(443.75, 270, -42.5);
	fh.v3f(421.25, 265, -37.5);
	glEnd();

	// right btm
	glColor3f(0.2, 1, 0.5);
	glBegin(gltype);
	fh.v3f(443.75, 270, -42.5);
	fh.v3f(460, 307.5, -60);
	fh.v3f(460, 307.5, 50);
	fh.v3f(443.75, 270, 30);
	glEnd();

	// back top
	glColor3f(0, 0.7, 0.3);
	glBegin(gltype);
	fh.v3f(378.75, 265, -37.5);
	fh.v3f(356.25, 270, -42.5);
	fh.v3f(443.75, 270, -42.5);
	fh.v3f(421.25, 265, -37.5);
	glEnd();

	// back btm
	glColor3f(0.5, 0.3, 1);
	glBegin(gltype);
	fh.v3f(356.25, 270, -42.5);
	fh.v3f(340, 307.5, -60);
	fh.v3f(460, 307.5, -60);
	fh.v3f(443.75, 270, -42.5);
	glEnd();
}

void lowerChest(GLenum gltype) {
	// front top
	glColor3f(0.7, 0.7, 1);
	glBegin(gltype);
	fh.v3f(340, 307.5, 50);
	fh.v3f(343.75, 327.5, 57.5);
	fh.v3f(456.25, 327.5, 57.5);
	fh.v3f(460, 307.5, 50);
	glEnd();

	// middle light (back)


	// middle light
	glColor3f(1, 1, 1);
	fh.sphere(GL_POLYGON, 13, 13, 13, 400, 321, 45, 0, 100, 0, 100, 1, 1, 1);

	// front btm
	glColor3f(0.7, 0.7, 0.7);
	glBegin(gltype);
	fh.v3f(343.75, 327.5, 57.5);
	fh.v3f(346.25, 352.5, 52.5);
	fh.v3f(453.75, 352.5, 52.5);
	fh.v3f(456.25, 327.5, 57.5);
	glEnd();

	// left top
	glColor3f(0.7, 1, 0.7);
	glBegin(gltype);
	fh.v3f(340, 307.5, -60);
	fh.v3f(343.75, 327.5, -60);
	fh.v3f(343.75, 327.5, 57.5);
	fh.v3f(340, 307.5, 50);
	glEnd();

	// left btm
	glColor3f(1, 0.7, 0.7);
	glBegin(gltype);
	fh.v3f(343.75, 327.5, -60);
	fh.v3f(346.25, 352.5, -47.5);
	fh.v3f(346.25, 352.5, 52.5);
	fh.v3f(343.75, 327.5, 57.5);
	glEnd();

	// right top
	glColor3f(0.3, 0.5, 0.3);
	glBegin(gltype);
	fh.v3f(460, 307.5, 50);
	fh.v3f(456.25, 327.5, 57.5);
	fh.v3f(456.25, 327.5, -60);
	fh.v3f(460, 307.5, -60);
	glEnd();

	// right btm
	glColor3f(1, 0.7, 1);
	glBegin(gltype);
	fh.v3f(456.25, 327.5, -60);
	fh.v3f(453.75, 352.5, -47.5);
	fh.v3f(453.75, 352.5, 52.5);
	fh.v3f(456.25, 327.5, 57.5);
	glEnd();

	// back top
	glColor3f(0.7, 0.5, 0.3);
	glBegin(gltype);
	fh.v3f(340, 307.5, -60);
	fh.v3f(343.75, 327.5, -60);
	fh.v3f(456.25, 327.5, -60);
	fh.v3f(460, 307.5, -60);
	glEnd();

	// back btm
	glColor3f(0.5, 0, 1);
	glBegin(gltype);
	fh.v3f(343.75, 327.5, -60);
	fh.v3f(346.25, 352.5, -47.5);
	fh.v3f(453.75, 352.5, -47.5);
	fh.v3f(456.25, 327.5, -60);
	glEnd();
}

void chest(GLenum gltype) {
	upperChest(gltype);
	lowerChest(gltype);
}

void adomen0(GLenum gltype) {
	//GLenum type = GL_POLYGON;

	// front
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(346.25, 352.5, 52.5);
	fh.v3f(351.25, 400, 50);
	fh.v3f(448.75, 400, 50);
	fh.v3f(453.75, 352.5, 52.5);
	glEnd();

	// back
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(346.25, 352.5, -47.5);
	fh.v3f(351.25, 400, -36.25);
	fh.v3f(448.75, 400, -36.25);
	fh.v3f(453.75, 352.5, -47.5);
	glEnd();

	// left
	glBegin(gltype);
	fh.v3f(346.25, 352.5, -47.5);
	fh.v3f(351.25, 400, -36.25);
	fh.v3f(351.25, 400, 50);
	fh.v3f(346.25, 352.5, 52.5);
	glEnd();

	// right
	glBegin(gltype);
	fh.v3f(453.75, 352.5, -47.5);
	fh.v3f(448.75, 400, -36.25);
	fh.v3f(448.75, 400, 50);
	fh.v3f(453.75, 352.5, 52.5);
	glEnd();
}

void adomen1(GLenum gltype) {
	//GLenum type = GL_POLYGON;

	glColor3f(1, 1, 1);
	// front
	glBegin(gltype);
	fh.v3f(351.25, 387.5, 50);
	fh.v3f(353.75, 400, 50);
	fh.v3f(446.25, 400, 50);
	fh.v3f(448.75, 387.5, 50);
	glEnd();

	// back
	glBegin(gltype);
	fh.v3f(351.25, 387.5, -36.25);
	fh.v3f(353.75, 400, -36.25);
	fh.v3f(446.25, 400, -36.25);
	fh.v3f(448.75, 387.5, -36.25);
	glEnd();

	// left
	glBegin(gltype);
	fh.v3f(351.25, 387.5, -36.25);
	fh.v3f(353.75, 400, -36.25);
	fh.v3f(353.75, 400, 50);
	fh.v3f(351.25, 387.5, 50);
	glEnd();

	// right
	glBegin(gltype);
	fh.v3f(448.75, 387.5, -36.25);
	fh.v3f(446.25, 400, -36.25);
	fh.v3f(446.25, 400, 50);
	fh.v3f(448.75, 387.5, 50);
	glEnd();
}

void adomen2(GLenum gltype) {
	//GLenum type = GL_POLYGON;

	// front
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(353.75, 387.5, 50);
	fh.v3f(356.25, 400, 50);
	fh.v3f(443.75, 400, 50);
	fh.v3f(446.25, 387.5, 50);
	glEnd();

	// back
	glBegin(gltype);
	fh.v3f(353.75, 387.5, -36.25);
	fh.v3f(356.25, 400, -36.25);
	fh.v3f(443.75, 400, -36.25);
	fh.v3f(446.25, 387.5, -36.25);
	glEnd();

	// left
	glBegin(gltype);
	fh.v3f(353.75, 387.5, -36.25);
	fh.v3f(356.25, 400, -36.25);
	fh.v3f(356.25, 400, 50);
	fh.v3f(353.75, 387.5, 50);
	glEnd();

	// right
	glBegin(gltype);
	fh.v3f(446.25, 387.5, -36.25);
	fh.v3f(443.75, 400, -36.25);
	fh.v3f(443.75, 400, 50);
	fh.v3f(446.25, 387.5, 50);
	glEnd();
}

void adomen3(GLenum gltype) {
	//GLenum type = GL_POLYGON;

	// front
	glBegin(gltype);
	fh.v3f(356.25, 387.5, 50);
	fh.v3f(357.5, 400, 50);
	fh.v3f(442.5, 400, 50);
	fh.v3f(443.75, 387.5, 50);
	glEnd();

	// front
	glBegin(gltype);
	fh.v3f(356.25, 387.5, -36.25);
	fh.v3f(357.5, 400, -36.25);
	fh.v3f(442.5, 400, -36.25);
	fh.v3f(443.75, 387.5, -36.25);
	glEnd();

	// left
	glBegin(gltype);
	fh.v3f(356.25, 387.5, -36.25);
	fh.v3f(357.5, 400, -36.25);
	fh.v3f(357.5, 400, 50);
	fh.v3f(356.25, 387.5, 50);
	glEnd();

	// right
	glBegin(gltype);
	fh.v3f(443.75, 387.5, -36.25);
	fh.v3f(442.5, 400, -36.25);
	fh.v3f(442.5, 400, 50);
	fh.v3f(443.75, 387.5, 50);
	glEnd();

}

void below(GLenum gltype) {
	// front
	glBegin(gltype);
	fh.v3f(357.5, 400, 50);
	fh.v3f(378.75, 427.5, 50);
	fh.v3f(391.25, 457.5, 50);
	fh.v3f(408.75, 457.5, 50);
	fh.v3f(421.25, 427.5, 50);
	fh.v3f(442.5, 400, 50);
	glEnd();

	// back
	glBegin(gltype);
	fh.v3f(357.5, 400, -36.25);
	fh.v3f(378.75, 427.5, -45);
	fh.v3f(391.25, 457.5, -36.25);
	fh.v3f(408.75, 457.5, -36.25);
	fh.v3f(421.25, 427.5, -45);
	fh.v3f(442.5, 400, -36.25);
	glEnd();

	// left
	glBegin(gltype);
	fh.v3f(357.5, 400, -36.25);
	fh.v3f(378.75, 427.5, -45);
	fh.v3f(391.25, 457.5, -36.25);
	fh.v3f(391.25, 457.5, 50);
	fh.v3f(378.75, 427.5, 50);
	fh.v3f(357.5, 400, 50);
	glEnd();

	// right
	glBegin(gltype);
	fh.v3f(442.5, 400, -36.25);
	fh.v3f(421.25, 427.5, -45);
	fh.v3f(408.75, 457.5, -36.25);
	fh.v3f(408.75, 457.5, 50);
	fh.v3f(421.25, 427.5, 50);
	fh.v3f(442.5, 400, 50);
	glEnd();

	// btm
	glBegin(gltype);
	fh.v3f(391.25, 457.5, -36.25);
	fh.v3f(391.25, 457.5, 50);
	fh.v3f(408.75, 457.5, 50);
	fh.v3f(408.75, 457.5, -36.25);
	glEnd();
}

void body(GLenum gltype) {
	// adomen 0 + chest
	glPushMatrix();
	glRotatef(-AR4, 1, 0, 0);
	glTranslatef(0, fh.yP(85), 0);
	glRotatef(-AR2, 1, 0, 0);
	chest(gltype);
	adomen0(gltype);
	glPopMatrix();

	// adomen 1
	glPushMatrix();
	glRotatef(-AR3, 1, 0, 0);
	glTranslatef(0, fh.yP(72.5), 0);
	glRotatef(-AR, 1, 0, 0);
	adomen1(gltype);
	glPopMatrix();

	// adomen 2
	glPushMatrix();
	glRotatef(-AR0, 1, 0, 0);
	glTranslatef(0, fh.yP(60), 0);
	glRotatef(0, 1, 0, 0);
	adomen2(gltype);
	glPopMatrix();

	// adomen 3
	glPushMatrix();
	glRotatef(-AR1, 1, 0, 0);
	glTranslatef(0, fh.yP(47.5), 0);
	adomen3(gltype);
	glPopMatrix();

	// below
	glPushMatrix();
	glTranslatef(0, fh.yP(47.5), 0);
	below(gltype);
	glPopMatrix();
}

// head
void eye(GLenum gltype) {
	glColor3f(1, 0, 0);
	// right
	glBegin(gltype);
	fh.v3f(427.5, 400, 130);
	fh.v3f(427.5, 415, 130);
	fh.v3f(472.5, 415, 115);
	fh.v3f(492.5, 400, 92.5);
	fh.v3f(487.5, 387.5, 100);
	glEnd();

	// left
	glBegin(gltype);
	fh.v3f(372.5, 400, 130);
	fh.v3f(372.5, 415, 130);
	fh.v3f(327.5, 415, 115);
	fh.v3f(307.5, 400, 92.5);
	fh.v3f(312.5, 387.5, 100);
	glEnd();
}

void rightTop(GLenum gltype) {
	// front
	glColor3f(0.5, 0.5, 0.5);
	glBegin(gltype);
	fh.v3f(427.5, 287.5, 115);
	fh.v3f(447.5, 205, 50);
	fh.v3f(502.5, 240, 40);
	fh.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side
	glColor3f(0.7, 0.7, 0.7);
	glBegin(gltype);
	fh.v3f(502.5, 240, 40);
	fh.v3f(522.5, 287.5, 55);
	fh.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2
	glColor3f(0.7, 0, 0.7);
	glBegin(gltype);
	fh.v3f(522.5, 287.5, 55);
	fh.v3f(509.5, 375, 72.5);
	fh.v3f(504, 387.5, 60);		// aa
	//fh.v3f(502.5, 392, 92);		// ee
	fh.v3f(492.5, 387.5, 105);	// dd
	fh.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side3
	glColor3f(0.7, 0.7, 0);
	glBegin(gltype);
	fh.v3f(504, 387.5, 60);		// aa
	fh.v3f(502.5, 392, 92);		// ee
	fh.v3f(492.5, 387.5, 105);	// dd
	glEnd();

	// front2
	glColor3f(0, 0.7, 0.7);
	glBegin(gltype);
	fh.v3f(427.5, 287.5, 115);
	fh.v3f(522.5, 287.5, 72.5);
	fh.v3f(492.5, 387.5, 105);	// dd
	fh.v3f(427, 400, 130);
	glEnd();

	// front3
	glColor3f(0, 0.7, 0);
	glBegin(gltype);
	fh.v3f(400, 287.5, 115);
	fh.v3f(400, 400, 137.5);
	fh.v3f(427, 400, 130);
	fh.v3f(427.5, 287.5, 115);
	glEnd();
}

void eyeMid(GLenum gltype) {

	glColor3f(0.9, 0.3, 0.5);
	glBegin(gltype);
	fh.v3f(372.5, 400, 130);
	fh.v3f(372.5, 415, 130);
	fh.v3f(400, 415, 137);
	fh.v3f(400, 400, 137);
	glEnd();

	glColor3f(0.9, 0.3, 0.5);
	glBegin(gltype);
	fh.v3f(427.5, 415, 130);
	fh.v3f(427.5, 400, 130);
	fh.v3f(400, 400, 137);
	fh.v3f(400, 415, 137);
	glEnd();
}

void leftTop(GLenum gltype) {
	// front
	glColor3f(0.5, 0.5, 0.5);
	glBegin(gltype);
	fh.v3f(372.5, 287.5, 115);
	fh.v3f(352.5, 205, 50);
	fh.v3f(297.5, 240, 40);
	fh.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side
	glColor3f(0.7, 0.7, 0.7);
	glBegin(gltype);
	fh.v3f(297.5, 240, 40);
	fh.v3f(277.5, 287.5, 55);
	fh.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2
	glColor3f(0.7, 0, 0.7);
	glBegin(gltype);
	fh.v3f(277.5, 287.5, 55);
	fh.v3f(290.5, 375, 72.5);
	fh.v3f(295, 387.5, 60);		// aa
	//fh.v3f(502.5, 392, 92);		// ee
	fh.v3f(307.5, 387.5, 105);	// dd
	fh.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side3
	glColor3f(0.7, 0.7, 0);
	glBegin(gltype);
	fh.v3f(295, 387.5, 60);		// aa
	fh.v3f(297, 392, 92);		// ee
	fh.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// front2
	glColor3f(0, 0.7, 0.7);
	glBegin(gltype);
	//fh.v3f(400, 287.5, 115);
	fh.v3f(372.5, 287.5, 115);
	fh.v3f(277.5, 287.5, 72.5);
	fh.v3f(307.5, 387.5, 105);	// dd
	fh.v3f(372.5, 400, 130);
	glEnd();

	// front3
	glColor3f(0, 0.7, 0);
	glBegin(gltype);
	fh.v3f(400, 287.5, 115);
	fh.v3f(400, 400, 137.5);
	fh.v3f(372.5, 400, 130);
	fh.v3f(372.5, 287.5, 115);
	glEnd();
}

void rightBtm(GLenum gltype) {
	// side top
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(509, 415, 40);		// cc
	fh.v3f(504, 387.5, 60);		// aa
	fh.v3f(502.5, 392, 92);		// ee
	fh.v3f(509, 415, 92);
	glEnd();

	// front top
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh.v3f(502.5, 392, 92);		// ee
	fh.v3f(472.5, 415, 115);
	fh.v3f(509, 415, 92);
	glEnd();

	// side top 2
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh.v3f(509, 415, 40);		// cc
	fh.v3f(509, 415, 92);
	fh.v3f(495, 457.5, 92.5);	// a2
	fh.v3f(509, 435, 45);		// z
	glEnd();

	// front top 2
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh.v3f(509, 415, 92);
	fh.v3f(495, 457.5, 92.5);	// a2
	fh.v3f(472.5, 457.5, 115);
	fh.v3f(472.5, 415, 115);
	glEnd();

	// front top 3
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(472.5, 457.5, 115);
	fh.v3f(472.5, 415, 115);
	fh.v3f(427.5, 415, 130);
	fh.v3f(427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	glColor3f(1, 0.5, 0.5);
	glBegin(gltype);
	fh.v3f(427.5, 415, 130);
	fh.v3f(427.5, 457.5, 130);
	fh.v3f(400, 457.5, 137.5);
	fh.v3f(400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	glColor3f(0.5, 1, 0.5);
	glBegin(gltype);
	fh.v3f(427.5, 457.5, 130);
	fh.v3f(400, 457.5, 137.5);
	fh.v3f(400, 522.5, 115);
	fh.v3f(435, 522.5, 115);
	glEnd();

	// front btm 2
	glColor3f(0.5, 0.5, 1);
	glBegin(gltype);
	fh.v3f(472.5, 457.5, 115);
	fh.v3f(427.5, 457.5, 130);
	fh.v3f(435, 522.5, 115);
	glEnd();

	// front btm 3
	glColor3f(0.7, 0.5, 0.3);
	glBegin(gltype);
	fh.v3f(472.5, 457.5, 115);
	fh.v3f(435, 522.5, 115);
	fh.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	glColor3f(0.5, 0.3, 0.7);
	glBegin(gltype);
	//fh.v3f(509, 415, 40);		// cc
	fh.v3f(509, 435, 45);		// z
	fh.v3f(495, 457.5, 68);		// a1
	fh.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(0.5, 0.7, 0.3);
	glBegin(gltype);
	fh.v3f(495, 457.5, 68);		// a1
	fh.v3f(470, 505, 77.5);		// bb
	fh.v3f(435, 522.5, 115);
	fh.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1, 1, 0.7);
	glBegin(gltype);
	fh.v3f(470, 505, 77.5);		// bb
	fh.v3f(467.5, 517.5, 75);	// y
	fh.v3f(447.5, 530, 97.5);	// x
	fh.v3f(435, 522.5, 115);
	glEnd();

	//// side
	//glColor3f(0.5, 1, 1);
	//glBegin(type);
	//fh.v3f(509, 415, 40);		// cc
	//fh.v3f(509, 435, 45);		// z
	//fh.v3f(495, 457.5, 68);		// a1
	//fh.v3f(470, 505, 77.5);		// bb
	//fh.v3f(467.5, 517.5, 75);	// y
	//fh.v3f(447.5, 530, 97.5);	// x
	//fh.v3f(435, 522.5, 115);
	//fh.v3f(495, 457.5, 92.5);	// a2
	//glEnd();
}

void leftBtm(GLenum gltype) {
	// side top
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(800 - 509, 415, 40);		// cc
	fh.v3f(800 - 504, 387.5, 60);		// aa
	fh.v3f(800 - 502.5, 392, 92);		// ee
	fh.v3f(800 - 509, 415, 92);
	glEnd();

	// front top
	glColor3f(1, 0, 1);
	glBegin(gltype);
	fh.v3f(800 - 502.5, 392, 92);		// ee
	fh.v3f(800 - 472.5, 415, 115);
	fh.v3f(800 - 509, 415, 92);
	glEnd();

	// side top 2
	glColor3f(1, 1, 0);
	glBegin(gltype);
	fh.v3f(800 - 509, 415, 40);		// cc
	fh.v3f(800 - 509, 415, 92);
	fh.v3f(800 - 495, 457.5, 92.5);	// a2
	fh.v3f(800 - 509, 435, 45);		// z
	glEnd();

	// front top 2
	glColor3f(0, 1, 1);
	glBegin(gltype);
	fh.v3f(800 - 509, 415, 92);
	fh.v3f(800 - 495, 457.5, 92.5);	// a2
	fh.v3f(800 - 472.5, 457.5, 115);
	fh.v3f(800 - 472.5, 415, 115);
	glEnd();

	// front top 3
	glColor3f(1, 1, 1);
	glBegin(gltype);
	fh.v3f(800 - 472.5, 457.5, 115);
	fh.v3f(800 - 472.5, 415, 115);
	fh.v3f(800 - 427.5, 415, 130);
	fh.v3f(800 - 427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	glColor3f(1, 0.5, 0.5);
	glBegin(gltype);
	fh.v3f(800 - 427.5, 415, 130);
	fh.v3f(800 - 427.5, 457.5, 130);
	fh.v3f(800 - 400, 457.5, 137.5);
	fh.v3f(800 - 400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	glColor3f(0.5, 1, 0.5);
	glBegin(gltype);
	fh.v3f(800 - 427.5, 457.5, 130);
	fh.v3f(800 - 400, 457.5, 137.5);
	fh.v3f(800 - 400, 522.5, 115);
	fh.v3f(800 - 435, 522.5, 115);
	glEnd();

	// front btm 2
	glColor3f(0.5, 0.5, 1);
	glBegin(gltype);
	fh.v3f(800 - 472.5, 457.5, 115);
	fh.v3f(800 - 427.5, 457.5, 130);
	fh.v3f(800 - 435, 522.5, 115);
	glEnd();

	// front btm 3
	glColor3f(0.7, 0.5, 0.3);
	glBegin(gltype);
	fh.v3f(800 - 472.5, 457.5, 115);
	fh.v3f(800 - 435, 522.5, 115);
	fh.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	glColor3f(0.5, 0.3, 0.7);
	glBegin(gltype);
	//fh.v3f(509, 415, 40);		// cc
	fh.v3f(800 - 509, 435, 45);		// z
	fh.v3f(800 - 495, 457.5, 68);		// a1
	fh.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(0.5, 0.7, 0.3);
	glBegin(gltype);
	fh.v3f(800 - 495, 457.5, 68);		// a1
	fh.v3f(800 - 470, 505, 77.5);		// bb
	fh.v3f(800 - 435, 522.5, 115);
	fh.v3f(800 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1, 1, 0.7);
	glBegin(gltype);
	fh.v3f(800 - 470, 505, 77.5);		// bb
	fh.v3f(800 - 467.5, 517.5, 75);	// y
	fh.v3f(800 - 447.5, 530, 97.5);	// x
	fh.v3f(800 - 435, 522.5, 115);
	glEnd();
}

void mask(GLenum gltype) {
	eye(GL_LINE_LOOP);

	rightTop(gltype);
	leftTop(gltype);
	eyeMid(gltype);

	rightBtm(gltype);
	leftBtm(gltype);
}

void head(GLenum gltype) {
	mask(gltype);
}

//============================= DANNY =================================

//============================= LIANA =================================

void finger(GLenum type, float size, float size2, int lineWidth) {
	glPushMatrix();
	if(fingerBend)
		glRotatef(fingerRotate * 2, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2, size, 0);
	/*if (fingerBend) {
		glTranslatef(-size / 3.0 + 0.3, size, 0.8);
		glRotatef(fingerRotate * 2, fx2, fy2, fz2);
		glTranslatef(-(-size / 3.0 * 2), -size, 0);
	}*/
	glRotatef(-90, 0, 0, 1);
	fh.color('r');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();

	glPushMatrix();
	if(fingerBend)
		glRotatef(fingerRotate, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0, size, 0);
	/*if (fingerBend) {
		glTranslatef(-size / 3.0, size, 0.3);
		glRotatef(fingerRotate, fx2, fy2, fz2);
		glTranslatef(-(-size / 3.0), -size, 0);
	}*/
	glRotatef(-90, 0, 0, 1);
	fh.color('g');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	/*if (fingerBend)
		glRotatef(-fingerRotate, fx2, fy2, fz2);*/
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0);
	if (fingerBend) {
		glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0 - 0.5);
		glRotatef(-fingerRotate, fx2, fy2, fz2);
		glTranslatef(-(-size / 3.0 * 2.0), -(size - 0.15), -size / 5.0);
	}
	//glTranslatef(0, 0, 0);
	fh.color('y');
	fh.sphere(GLU_LINE, size / 8.0, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void palm(GLenum type, float size, float size2, int lineWidth) {
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
	/*if (fingerBend) {
		glTranslatef(size * 2 / 3.0 + 0.1, size - 0.5, -0.75);
		glRotatef(fingerRotate, fx, fy, fz);
		glTranslatef(-(size * 2 / 3.0 + 0.1), -size, 0);
	}*/
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
	/*if (fingerBend) {
		glTranslatef(size * 2 / 3.0 - 0.1, (size + 0.4) - 0.5, -1.3 + 0.5);
		glRotatef(-fingerRotate, fx, fy, fz);
		glTranslatef(-(size * 2 / 3.0 - 0.1), -(size + 0.4), -0.2);
	}*/
	//fh.color('r');
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

void leg() {
	float thighBaseRadius = 0.1, thighTopRadius = thighBaseRadius - 0.02, height = 0.52, slices = 30, stacks = 30;
	float calfBaseRadius = thighTopRadius, calfTopRadius = calfBaseRadius - 0.02;
	float sRadius = thighTopRadius;
	float footSize = thighBaseRadius + 0.05;

	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0, 0, -height);
	fh.color('g');
	fh.cylinder(GLUtype, thighBaseRadius, thighTopRadius, height, slices, stacks); //thigh
	glPopMatrix();

	//glPushMatrix();
	//glRotatef(-90, 1.0, 0, 0);
	//glTranslatef(0, 0, height);

	glPushMatrix();
	fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //knee
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	/*if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);*/
	//glRotatef(-90, 1.0, 0.0, 0.0);
	//glRotatef(-armAngle, 1.0, 0.0, 0.0);
	fh.color('r');
	fh.cylinder(GLUtype, calfBaseRadius, calfTopRadius, height, slices, stacks); //calf
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	fh.color('w');
	//if (armUp || armDown)
	//	glRotatef(-armAngle, armx, army, armz);
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
	//glRotatef(90, 1.0, 0, 0);
	fh.sphere(GLUtype, sRadius * 0.4, slices, stacks); //ball of foot
	glPopMatrix();
}

void arm() {
	float uaBaseRadius = 0.05, uaTopRadius = uaBaseRadius - 0.005, height = 0.35, slices = 30, stacks = 30;
	float laBaseRadius = uaTopRadius, laTopRadius = laBaseRadius - 0.01;
	float sRadius = uaTopRadius;
	float palmSize = uaBaseRadius + 0.05;

	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	
	glPushMatrix();
	if (raiseLeftLeg)
		glTranslatef(0, 0, -height), glRotatef(-90, 0, 1.0, 0), glTranslatef(0, 0, height);
	else
		glTranslatef(0, 0, -height);
	fh.color('g');
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
	if(armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);
	//glRotatef(-90, 1.0, 0.0, 0.0);
	//glRotatef(-armAngle, 1.0, 0.0, 0.0);
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
	palm(nonGLUtype, 1.0, 0.5, 2);
	glPopMatrix();
	glPopMatrix();

}

//============================= LIANA =================================

void switchView(char view) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glTranslatef(tx, ty, 0.0);
	glRotatef(ry, 0.0, 1.0, 0);;
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
	//=================== rotate ========================
	// press 'a'/'w'/'d'/'s' to rotate 
	if (str == "leftRotate" || str == "upRotate") {
		rotate++;
	}
	else if (str == "rightRotate" || str == "downRotate") {
		rotate--;
	}
	else if (str == "space") {
		glLoadIdentity();
	}
	//===================================================
	//==================== body =========================
	{
		int angle = 10, angle2 = angle + 1, angle3 = angle2 + 1, angle4 = angle - 5, an = 5;

		// press 'D' to curve the body
		if (str == "down") {
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

		// press 'U' to rift the body
		if (str == "up") {
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

	switch (qNo) {
	case 1:
		// body 
		glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		glScalef(zoom, zoom, zoom);
		body(GL_LINE_LOOP);
		glPopMatrix();
		break;
	case 2:
		// head
		glPushMatrix();
		glTranslatef(xT, yT, zT);
		glRotatef(rotate, xR, yR, zR);
		glScalef(zoom, zoom, zoom);
		head(GL_POLYGON);
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();
		/*if (raiseLeftLeg)
			glRotatef(-90, 0, 0, 1.0);
		else
			glLoadIdentity();*/
		/*if (sideView)
			glRotatef(-90, 0, 1.0, 0);
		else
			glLoadIdentity();*/
		leg();
		glPopMatrix();
		break;
	case 4:
		if ((armUp && armAngle > 110) || (armDown && armAngle >= 0)) //raise hand
			armAngle -= armRSpeed;
		else if (armAngle == 110)
			armAngle = armAngle;
		else
			armAngle += armRSpeed;

		if (armDirection == 1 && armRotate <= 30) //arm rotate
			armRotate += armRSpeed;
		else
			if(armRotate >= -90)
				armRotate -= armRSpeed;

		if (fingerBend && fingerRotate <= 45)
			fingerRotate += fingerRSpeed;
		else
			fingerRotate -= fingerRSpeed;
		
		//glRotatef(0.3, 0, 1.0, 0);
		glPushMatrix();
		if (armTurn)
			glRotatef(armRotate, armx2, army2, armz2);
		glPushMatrix();
		glScalef(zoom, zoom, zoom);
		arm();
		glPopMatrix();
		glPopMatrix();
		break;
	case 5:
		break;
	case 6:
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