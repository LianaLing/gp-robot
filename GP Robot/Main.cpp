#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"

using namespace N;
using namespace std;

//#pragma comment (lib, "OpenGL32.lib")
//dependencies included in project properties - linker - input

#define WINDOW_TITLE "IRON-MAN MK47"
#define CW 10
#define VALUE 800.0
#define WIDTH VALUE
#define HEIGHT VALUE
#define DEPTH VALUE
#define SIZE 15

function fh;
int qNo = 4;
float C[SIZE];
//============== LIANA ==============
float armRotate = 0, armRSpeed = 0, armx = 0, army = 0, armz = 0, armDirection = 0, armAngle = 0;
float armx2 = 0, army2 = 0, armz2 = 0;
boolean armTurn = false, armUp = false, armDown  = false;
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
		else if (wParam == VK_UP && qNo == 4) {
			armx = 1.0, army = 0, armz = 0, armRSpeed = 0.5, armUp = true, armDown = false;
		}
		else if (wParam == VK_DOWN && qNo == 4) {
			armx = 1.0, army = 0, armz = 0, armUp = false, armDown = true;
		}
		else if (wParam == VK_LEFT && qNo == 4) {
			armx2 = 1.0, army2 = 0, armz2 = 0, armDirection = +1.0, armRSpeed = 0.5, armTurn = true;
		}
		else if (wParam == VK_RIGHT && qNo == 4) {
			armx2 = 1.0, army2 = 0, armz2 = 0, armDirection = -1.0, armRSpeed = 0.5, armTurn = true;
		}
		else if (wParam == VK_SPACE) {
			glLoadIdentity();
			armx = 1.00, army = 0, armz = 0, armx2 = 0, army2 = 0, armz2 = 0;
			armRSpeed = 0, armAngle = 0, armRotate = 0, armDirection = 0;
			armUp = false, armDown = false, armTurn = false;
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

void body() {
	/*glClearColor(0.5, 0.5, 0.5, 0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/
	//glRotatef(1, 0, 1, 0);
	// front
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(fh.xC(340), fh.yC(200), fh.zC(55));
	glVertex3f(fh.xC(355), fh.yC(350), fh.zC(44));
	glVertex3f(fh.xC(445), fh.yC(350), fh.zC(44));
	glVertex3f(fh.xC(460), fh.yC(200), fh.zC(55));
	glEnd();

	//// top
	//glBegin(GL_POLYGON);
	//glColor3f(0, 1, 0);
	//glVertex3f(xC(340), yC(200), zC(-55));
	//glVertex3f(xC(340), yC(200), zC(55));
	//glVertex3f(xC(460), yC(200), zC(55));
	//glVertex3f(xC(460), yC(200), zC(-55));
	//glEnd();

	//// back
	//glBegin(GL_POLYGON);
	//glColor3f(0, 0, 1);
	//glVertex3f(xC(340), yC(200), zC(-55));
	//glVertex3f(xC(355), yC(350), zC(-44));
	//glVertex3f(xC(445), yC(350), zC(-44));
	//glVertex3f(xC(460), yC(200), zC(-55));
	//glEnd();

	//// left
	//glBegin(GL_POLYGON);
	//glColor3f(1, 1, 0);
	//glVertex3f(xC(340), yC(200), zC(-55));
	//glVertex3f(xC(355), yC(350), zC(-44));
	//glVertex3f(xC(355), yC(350), zC(44));
	//glVertex3f(xC(340), yC(200), zC(55));
	//glEnd();

	//// right
	//glBegin(GL_POLYGON);
	//glColor3f(1, 0, 1);
	//glVertex3f(xC(460), yC(200), zC(55));
	//glVertex3f(xC(445), yC(350), zC(44));
	//glVertex3f(xC(445), yC(350), zC(-44));
	//glVertex3f(xC(460), yC(200), zC(-55));
	//glEnd();

	//// btm
	//glBegin(GL_POLYGON);
	//glColor3f(0, 1, 1);
	//glVertex3f(xC(355), yC(350), zC(-44));
	//glVertex3f(xC(355), yC(350), zC(44));
	//glVertex3f(xC(445), yC(350), zC(44));
	//glVertex3f(xC(445), yC(350), zC(-44));
	//glEnd();

}

void upperChest() {
	// front top
	glColor3f(1, 0.7, 0.3);
	glBegin(GL_QUADS);
	fh.v3f(378.75, 180, 25);
	fh.v3f(356.25, 185, 30);
	fh.v3f(443.75, 185, 30);
	fh.v3f(421.25, 180, 25);
	glEnd();

	// front btm
	glColor3f(1, 0, 0.5);
	glBegin(GL_POLYGON);
	fh.v3f(356.25, 185, 30);
	fh.v3f(340, 222.5, 50);
	fh.v3f(460, 222.5, 50);
	fh.v3f(443.75, 185, 30);
	glEnd();

	// left top
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	fh.v3f(378.75, 180, -37.5);
	fh.v3f(356.25, 185, -42.5);
	fh.v3f(356.25, 185, 30);
	fh.v3f(378.75, 180, 25);
	glEnd();

	// left btm
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	fh.v3f(356.25, 185, -42.5);
	fh.v3f(340, 222.5, -60);
	fh.v3f(340, 222.5, 50);
	fh.v3f(356.25, 185, 30);
	glEnd();

	// right top
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	fh.v3f(421.25, 180, 25);
	fh.v3f(443.75, 185, 30);
	fh.v3f(443.75, 185, -42.5);
	fh.v3f(421.25, 180, -37.5);
	glEnd();

	// right btm
	glColor3f(0.2, 1, 0.5);
	glBegin(GL_POLYGON);
	fh.v3f(443.75, 185, -42.5);
	fh.v3f(460, 222.5, -60);
	fh.v3f(460, 222.5, 50);
	fh.v3f(443.75, 185, 30);
	glEnd();

	// back top
	glColor3f(0, 0.7, 0.3);
	glBegin(GL_QUADS);
	fh.v3f(378.75, 180, -37.5);
	fh.v3f(356.25, 185, -42.5);
	fh.v3f(443.75, 185, -42.5);
	fh.v3f(421.25, 180, -37.5);
	glEnd();

	// back btm
	glColor3f(0.5, 0.3, 1);
	glBegin(GL_POLYGON);
	fh.v3f(356.25, 185, -42.5);
	fh.v3f(340, 222.5, -60);
	fh.v3f(460, 222.5, -60);
	fh.v3f(443.75, 185, -42.5);
	glEnd();
}

void lowerChest() {
	// front top
	glColor3f(0.7, 0.7, 1);
	glBegin(GL_QUADS);
	fh.v3f(340, 222.5, 50);
	fh.v3f(343.75, 242.5, 57.5);
	fh.v3f(456.25, 242.5, 57.5);
	fh.v3f(460, 222.5, 50);
	glEnd();

	// middle light (back)


	// middle light
	glColor3f(1, 1, 1);
	fh.sphere(GL_POLYGON, 13, 13, 13, 400, 235, 45, 0, 100, 0, 100, 1, 1, 1);

	// front btm
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_QUADS);
	fh.v3f(343.75, 242.5, 57.5);
	fh.v3f(346.25, 267.5, 52.5);
	fh.v3f(453.75, 267.5, 52.5);
	fh.v3f(456.25, 242.5, 57.5);
	glEnd();

	// left top
	glColor3f(0.7, 1, 0.7);
	glBegin(GL_QUADS);
	fh.v3f(340, 222.5, -60);
	fh.v3f(343.75, 242.5, -60);
	fh.v3f(343.75, 242.5, 57.5);
	fh.v3f(340, 222.5, 50);
	glEnd();

	// left btm
	glColor3f(1, 0.7, 0.7);
	glBegin(GL_QUADS);
	fh.v3f(343.75, 242.5, -60);
	fh.v3f(346.25, 267.5, -47.5);
	fh.v3f(346.25, 267.5, 52.5);
	fh.v3f(343.75, 242.5, 57.5);
	glEnd();

	// right top
	glColor3f(0.3, 0.5, 0.3);
	glBegin(GL_QUADS);
	fh.v3f(460, 222.5, 50);
	fh.v3f(456.25, 242.5, 57.5);
	fh.v3f(456.25, 242.5, -60);
	fh.v3f(460, 222.5, -60);
	glEnd();

	// right btm
	glColor3f(1, 0.7, 1);
	glBegin(GL_QUADS);
	fh.v3f(456.25, 242.5, -60);
	fh.v3f(453.75, 267.5, -47.5);
	fh.v3f(453.75, 267.5, 52.5);
	fh.v3f(456.25, 242.5, 57.5);
	glEnd();

	// back top
	glColor3f(0.7, 0.5, 0.3);
	glBegin(GL_QUADS);
	fh.v3f(340, 222.5, -60);
	fh.v3f(343.75, 242.5, -60);
	fh.v3f(456.25, 242.5, -60);
	fh.v3f(460, 222.5, -60);
	glEnd();

	// back btm
	glColor3f(0.5, 0, 1);
	glBegin(GL_QUADS);
	fh.v3f(343.75, 242.5, -60);
	fh.v3f(346.25, 267.5, -47.5);
	fh.v3f(453.75, 267.5, -47.5);
	fh.v3f(456.25, 242.5, -60);
	glEnd();
}

void abdomen() {
//	// front 0
//	glBegin(GL_QUADS);
//	glVertex3f(xC(346.25), yC(267.5), zC(52.5));
//	glVertex3f(xC(302.5), yC(315), zC());
//	glVertex3f(xC(497.5), yC(315), zC());
//	glVertex3f(xC(453.75), yC(267.5), zC());
//	glEnd();
}

void head() {
	////Points
	//	float CT_X = 400, CT_Y = 400, CT_Z = 0;
	//	float ax = 400, ay = 105, az = 0;
	//	float bx = 410, by = 107, bz = 5;
	//	float cx = 422.5, cy = 112.5, cz = 10;
	//	float dx = 428.75, dy = 140, dz = 5;
	//	float ex = 430, ey = 177.5, ez = 32.5;
	//	float fx = 406, fy = 182.5, fz = 25;
	//	float gx = 394, gy = 182.5, gz = 25;
	//	float hx = 370, hy = 177.5, hz = 32.5;
	//	float ix = 371.25, iy = 140, iz = 5;
	//	float jx = 377.5, jy = 112.5, jz = 15;
	//	float kx = 390, ky = 107, kz = 5;
	//	float lx = 412.5, ly = 112.5, lz = 25;
	//	float mx = 422.5, my = 120, mz = 15;
	//	float nx = 422, ny = 140, nz = 20;
	//	float ox = 422.5, oy = 147.5, oz = 12.5;
	//	float px = 420, py = 167, pz = 17;
	//	float qx = 422.5, qy = 170, qz = 18;
	//	float rx = 408.5, ry = 174, rz = 25;
	//	float sx = 407, sy = 172.5, sz = 33.5;
	//	float tx = 393, ty = 172.5, tz = 33.5;
	//	float ux = 391.5, uy = 174, uz = 25;
	//	float vx = 377.5, vy = 170, vz = 18;
	//	float wx = 380, wy = 167, wz = 17;
	//	float xx = 377.5, xy = 147.5, xz = 12.5;
	//	float yx = 378, yy = 140, yz = 20;
	//	float zx = 377.5, zy = 120, zz = 25;
	//	float aax = 390, aay = 112.5, aaz = 25;
	//	float bbx = 387.5, bby = 118.75, bbz = 30;
	//	float ccx = 410, ccy = 118.75, ccz = 30;
	//	float ddx = 428.5, ddy = 157.5, ddz = 0;
	//	float eex = 430, eey = 177.5, eez = 32.5;
	//
	//	//Right face
	//	glColor3f(1.0, 0, 0);
	//	//lkacm
	//	glBegin(GL_POLYGON);
	//		glVertex3f(xC(lx), yC(ly), zC(lz));
	//		glVertex3f(xC(kx), yC(ky), zC(kz));
	//		glVertex3f(xC(ax), yC(ay), zC(az));
	//		glVertex3f(xC(cx), yC(cy), zC(cz));
	//		glVertex3f(xC(mx), yC(my), zC(mz));
	//	glEnd();
	//
	//	//mcn
	//	glBegin(GL_TRIANGLES);
	//		glVertex3f(xC(mx), yC(my), zC(mz));
	//		glVertex3f(xC(cx), yC(cy), zC(cz));
	//		glVertex3f(xC(nx), yC(ny), zC(nz));
	//	glEnd();
	//
	//	//ncdo
	//	glBegin(GL_QUADS);
	//		glVertex3f(xC(nx), yC(ny), zC(nz));
	//		glVertex3f(xC(cx), yC(cy), zC(cz));
	//		glVertex3f(xC(dx), yC(dy), zC(dz));
	//		glVertex3f(xC(ox), yC(oy), zC(oz));
	//	glEnd();
	//
	//	//o(dd)(ee)p
	//	glBegin(GL_QUADS);
	//		glVertex3f(xC(ox), yC(oy), zC(oz));
	//		glVertex3f(xC(ddx), yC(ddy), zC(ddz));
	//		glVertex3f(xC(eex), yC(eey), zC(eez));
	//		glVertex3f(xC(px), yC(py), zC(pz));
	//	glEnd();
	//
	//	//glColor3f(0, 0, 1.0);
	//	//p(ee)q
	//	glBegin(GL_TRIANGLES);
	//		glVertex3f(xC(px), yC(py), zC(pz));
	//		glVertex3f(xC(eex), yC(eey), zC(eez));
	//		glVertex3f(xC(qx), yC(qy), zC(qz));
	//	glEnd();
	//
	//	//glColor3f(0, 1.0, 0);
	//	//q(ee)fr
	//	glBegin(GL_QUADS);
	//		glVertex3f(xC(422.5), yC(170), zC(18));
	//		glVertex3f(xC(428.5), yC(157.5), zC(0));
	//		glVertex3f(xC(406), yC(182.5), zC(25));
	//		glVertex3f(xC(408.5), yC(174), zC(25));
	//	glEnd();
	//
	//	//glColor3f(1.0, 1.0, 0);
	//	//srfe
	//	glBegin(GL_QUADS);
	//		glVertex3f(xC(sx), yC(sy), zC(sz));
	//		glVertex3f(xC(rx), yC(ry), zC(rz));
	//		glVertex3f(xC(fx), yC(fy), zC(fz));
	//		glVertex3f(xC(ex), yC(ey), zC(ez));
	//	glEnd();
	//
	//	//Front face
	//	//abl(cc)(CT_X, ccy)
	//	glColor3f(1.0, 1.0, 1.0);
	//	glBegin(GL_POLYGON);
	//		glVertex3f(xC(ax), yC(ay), zC(az));
	//		glVertex3f(xC(bx), yC(by), zC(bz));
	//		glVertex3f(xC(lx), yC(ly), zC(lz));
	//		glVertex3f(xC(ccx), yC(ccy), zC(ccz));
	//		glVertex3f(xC(CT_X), yC(ccy), zC(ccz));
	//	glEnd();
	//
	//	//lm(cc)
	//	glBegin(GL_TRIANGLES);
	//		glVertex3f(xC(lx), yC(ly), zC(lz));
	//		glVertex3f(xC(mx), yC(my), zC(mz));
	//		glVertex3f(xC(ccx), yC(ccy), zC(ccz));
	//	glEnd();
	//
	//	//m(cc)n
	//	glBegin(GL_TRIANGLES);
	//		glVertex3f(xC(mx), yC(my), zC(mz));
	//		glVertex3f(xC(ccx), yC(ccy), zC(ccz));
	//		glVertex3f(xC(nx), yC(ny), zC(nz));
	//	glEnd();
	//
	//	//(CT_X, ccy)(cc)n(CT_X, ny)
	//	glBegin(GL_QUADS);
	//		glVertex3f(xC(CT_X), yC(ccy), zC(ccz));
	//		glVertex3f(xC(ccx), yC(ccy), zC(ccz));
	//		glVertex3f(xC(nx), yC(ny), zC(nz));
	//		glVertex3f(xC(CT_X), yC(ny), zC(nz));
	//	glEnd();
	//
	//	//(CT_X, ny)nop(CT_X, py)
	//	glBegin(GL_POLYGON);
	//		glVertex3f(xC(CT_X), yC(ny), zC(nz));
	//		glVertex3f(xC(nx), yC(ny), zC(nz));
	//		glVertex3f(xC(ox), yC(oy), zC(oz));
	//		glVertex3f(xC(px), yC(py), zC(pz));
	//		glVertex3f(xC(CT_X), yC(py), zC(pz));
	//	glEnd();
	//
	//	//(CT_X, py)ps(CT_X, sy)
	//	glBegin(GL_QUADS);
	//		glVertex3f(xC(CT_X), yC(py), zC(pz));
	//		glVertex3f(xC(px), yC(py), zC(pz));
	//		glVertex3f(xC(sx), yC(sy), zC(sz));
	//		glVertex3f(xC(CT_X), yC(sy), zC(sz));
	//	glEnd();
	//
	//	//spqr
	//	glBegin(GL_QUADS);
	//		glVertex3f(xC(sx), yC(sy), zC(sz));
	//		glVertex3f(xC(px), yC(py), zC(pz));
	//		glVertex3f(xC(qx), yC(qy), zC(qz));
	//		glVertex3f(xC(rx), yC(ry), zC(rz));
	//	glEnd();
	//
	//	////Right face
	//	////bacl
	//	//glColor3f(1, 0, 0);
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(410), yC(105), zC(0));
	//	//	glVertex3f(xC(410), yC(107.5), zC(12.5));
	//	//	glVertex3f(xC(410), yC(112.5), zC(25));
	//	//	glVertex3f(xC(422.5), yC(112.5), zC(10));
	//	//glEnd();
	//
	//	////lc?m
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(410), yC(112.5), zC(25));
	//	//	glVertex3f(xC(422.5), yC(112.5), zC(10));
	//	//	glVertex3f(xC(425), yC(115), zC(-32.5));
	//	//	glVertex3f(xC(422.5), yC(120), zC(15));
	//	//glEnd();
	//
	//	////m??n
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(422.5), yC(120), zC(15));
	//	//	glVertex3f(xC(425), yC(115), zC(-32.5));
	//	//	glVertex3f(xC(425), yC(127.5), zC(-37.5));
	//	//	glVertex3f(xC(422), yC(140), zC(20));
	//	//glEnd();
	//
	//	////n?o
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(422), yC(140), zC(20));
	//	//	glVertex3f(xC(425), yC(127.5), zC(-37.5));
	//	//	glVertex3f(xC(422.4), yC(147.5), zC(-12.5));
	//	//glEnd();
	//
	//	////o???
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(422.4), yC(147.5), zC(-12.5));
	//	//	glVertex3f(xC(425), yC(127.5), zC(-37.5));
	//	//	glVertex3f(xC(425), yC(147.5), zC(-33.75));
	//	//	glVertex3f(xC(428.75), yC(157.5), zC(0));
	//	//glEnd();
	//
	//	////???
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(425), yC(127.5), zC(-37.5));
	//	//	glVertex3f(xC(425), yC(147.5), zC(-33.75));
	//	//	glVertex3f(xC(425), yC(150), zC(-37.5));
	//	//glEnd();
	//
	//	////o??p
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(422.4), yC(147.5), zC(-12.5));
	//	//	glVertex3f(xC(428.75), yC(157.5), zC(0));
	//	//	glVertex3f(xC(426), yC(172.5), zC(5));
	//	//	glVertex3f(xC(420), yC(167), zC(17));
	//	//glEnd();
	//
	//	////p?q
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(420), yC(167), zC(17));
	//	//	glVertex3f(xC(426), yC(172.5), zC(5));
	//	//	glVertex3f(xC(422.5), yC(170), zC(18));
	//	//glEnd();
	//
	//	////q?fr
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(422.5), yC(170), zC(18));
	//	//	glVertex3f(xC(430), yC(177.5), zC(32));
	//	//	glVertex3f(xC(406), yC(182.5), zC(25));
	//	//	glVertex3f(xC(408.5), yC(174), zC(25));
	//	//glEnd();
	//
	//	////srfe
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(407), yC(172.5), zC(33.5));
	//	//	glVertex3f(xC(408.5), yC(174), zC(25));
	//	//	glVertex3f(xC(406), yC(182.5), zC(25));
	//	//	glVertex3f(xC(407), yC(171.5), zC(32.5));
	//	//glEnd();
	//
	//	////Left face
	//	////z??v
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(377.5), yC(120), zC(25));
	//	//	glVertex3f(xC(425 - 57.5), yC(115), zC(-32.5));
	//	//	glVertex3f(xC(425), yC(127.5), zC(-37.5));
	//	//	glVertex3f(xC(377.5), yC(170), zC(18));
	//	//glEnd();
	//
	//	////v?x
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(377.5), yC(170), zC(18));
	//	//glVertex3f(xC(425 - 57.5), yC(127.5), zC(-37.5));
	//	//glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	//	//glEnd();
	//
	//	////x???
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	//	//glVertex3f(xC(425 - 57.5), yC(127.5), zC(-37.5));
	//	//glVertex3f(xC(425 - 57.5), yC(147.5), zC(-33.75));
	//	//glVertex3f(xC(428.75 - 57.5), yC(157.5), zC(0));
	//	//glEnd();
	//
	//	////???
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(425 - 57.5), yC(127.5), zC(-37.5));
	//	//glVertex3f(xC(425 - 57.5), yC(147.5), zC(-33.75));
	//	//glVertex3f(xC(425 - 57.5), yC(150), zC(-37.5));
	//	//glEnd();
	//
	//	////x??w
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	//	//glVertex3f(xC(428.75 - 57.5), yC(157.5), zC(0));
	//	//glVertex3f(xC(426 - 57.5), yC(172.5), zC(5));
	//	//glVertex3f(xC(380), yC(167), zC(17));
	//	//glEnd();
	//
	//	////w?v
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(380), yC(167), zC(17));
	//	//glVertex3f(xC(426 - 57.5), yC(172.5), zC(5));
	//	//glVertex3f(xC(377.5), yC(170), zC(18));
	//	//glEnd();
	//
	//	////v?hu
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(377.5), yC(170), zC(18));
	//	//glVertex3f(xC(426 - 57.5), yC(172.5), zC(5));
	//	//glVertex3f(xC(370), yC(177.5), zC(32.5));
	//	//glVertex3f(xC(391.5), yC(174), zC(25));
	//	//glEnd();
	//
	//	////vugh
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(377.5), yC(170), zC(18));
	//	//glVertex3f(xC(391.5), yC(174), zC(25));
	//	//glVertex3f(xC(394), yC(182.5), zC(25));
	//	//glVertex3f(xC(370), yC(177.5), zC(32.5));
	//	//glEnd();
	//
	//	////Front face
	//	////kabl(cc)(bb)(aa)
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(390), yC(107), zC(5));
	//	//	glVertex3f(xC(400), yC(105), zC(0));
	//	//	glVertex3f(xC(410), yC(107), zC(5));
	//	//	glVertex3f(xC(410), yC(112.5), zC(25));
	//	//	glVertex3f(xC(412.5), yC(118.75), zC(30));
	//	//	glVertex3f(xC(387.5), yC(118.75), zC(30));
	//	//	glVertex3f(xC(390), yC(112.5), zC(25));
	//	//glEnd();
	//
	//	////k(aa)zj
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(390), yC(107), zC(5));
	//	//	glVertex3f(xC(390), yC(112.5), zC(25));
	//	//	glVertex3f(xC(377.5), yC(120), zC(25));
	//	//	glVertex3f(xC(377.5), yC(112.5), zC(15));
	//	//glEnd();
	//
	//	////jzyi
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(377.5), yC(112.5), zC(15));
	//	//	glVertex3f(xC(377.5), yC(120), zC(25));
	//	//	glVertex3f(xC(378), yC(140), zC(20));
	//	//	glVertex3f(xC(371.25), yC(140), zC(5));
	//	//glEnd();
	//
	//	////iyx?
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(371.25), yC(140), zC(5));
	//	//	glVertex3f(xC(378), yC(140), zC(20));
	//	//	glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	//	//	glVertex3f(xC(374), yC(147.5), zC(5));
	//	//glEnd();
	//
	//	////?xwv
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(374), yC(147.5), zC(5));
	//	//	glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	//	//	glVertex3f(xC(380), yC(167), zC(17));
	//	//	glVertex3f(xC(377.5), yC(170), zC(18));
	//	//glEnd();
	//
	//	////?vh
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(374), yC(147.5), zC(5));
	//	//	glVertex3f(xC(377.5), yC(170), zC(18));
	//	//	glVertex3f(xC(370), yC(177.5), zC(32.5));
	//	//glEnd();
	//
	//	////hvug
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(370), yC(177.5), zC(32.5));
	//	//	glVertex3f(xC(377.5), yC(170), zC(18));
	//	//	glVertex3f(xC(391.5), yC(174), zC(25));
	//	//	glVertex3f(xC(394), yC(182.5), zC(25));
	//	//glEnd();
	//
	//	////gutf
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(394), yC(182.5), zC(25));
	//	//	glVertex3f(xC(391.5), yC(174), zC(25));
	//	//	glVertex3f(xC(393), yC(172.5), zC(33.5));
	//	//	glVertex3f(xC(406), yC(182.5), zC(25));
	//	//glEnd();
	//
	//	////tfrs
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(393), yC(172.5), zC(33.5));
	//	//	glVertex3f(xC(406), yC(182.5), zC(25));
	//	//	glVertex3f(xC(408.5), yC(174), zC(25));
	//	//	glVertex3f(xC(407), yC(172.5), zC(33.5));
	//	//glEnd();
	//
	//	//glColor3f(1,1,1);
	//	////(aa)(bb)zy
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(390), yC(112.5), zC(25));
	//	//	glVertex3f(xC(387.5), yC(118.75), zC(30));
	//	//	glVertex3f(xC(377.5), yC(120), zC(25));
	//	//	glVertex3f(xC(378), yC(140), zC(20));
	//	//glEnd();
	//
	//	////(bb)(cc)ny
	//	//glBegin(GL_POLYGON);
	//	//glVertex3f(xC(387.5), yC(118.75), zC(30));
	//	//	glVertex3f(xC(412.5), yC(118.75), zC(30));
	//	//	glVertex3f(xC(422), yC(140), zC(20));
	//	//	glVertex3f(xC(378), yC(140), zC(20));
	//	//glEnd();
	//
	//	////lmn(cc)
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(410), yC(112.5), zC(25));
	//	//	glVertex3f(xC(422.5), yC(120), zC(15));
	//	//	glVertex3f(xC(422), yC(140), zC(20));
	//	//	glVertex3f(xC(412.5), yC(118.75), zC(30));
	//	//glEnd();
	//
	//	////ynox
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(378), yC(140), zC(20));
	//	//	glVertex3f(xC(378), yC(140), zC(20));
	//	//	glVertex3f(xC(428.75), yC(140), zC(5));
	//	//	glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	//	//glEnd();
	//
	//	////xopw
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	//	//	glVertex3f(xC(428.75), yC(140), zC(5));
	//	//	glVertex3f(xC(420), yC(167), zC(17));
	//	//	glVertex3f(xC(380), yC(167), zC(17));
	//	//glEnd();
	//
	//	////wpst
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(380), yC(167), zC(17));
	//	//	glVertex3f(xC(420), yC(167), zC(17));
	//	//	glVertex3f(xC(407), yC(172.5), zC(33.5));
	//	//	glVertex3f(xC(393), yC(172.5), zC(33.5));
	//	//glEnd();
	//
	//	////wtuv
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(380), yC(167), zC(17));
	//	//	glVertex3f(xC(393), yC(172.5), zC(33.5));
	//	//	glVertex3f(xC(391.5), yC(174), zC(25));
	//	//	glVertex3f(xC(377.5), yC(170), zC(18));
	//	//glEnd();
	//
	//	////spqr
	//	//glBegin(GL_POLYGON);
	//	//	glVertex3f(xC(407), yC(172.5), zC(33.5));
	//	//	glVertex3f(xC(420), yC(167), zC(17));
	//	//	glVertex3f(xC(422.5), yC(170), zC(18));
	//	//	glVertex3f(xC(408.5), yC(174), zC(25));
	//	//glEnd();
}

//============================= LIANA =================================

void finger(GLenum type, float size, float size2, int lineWidth) {
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2, size, 0);
	glRotatef(-90, 0, 0, 1);
	//fh.color('w');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-size / 3.0, size, 0);
	glRotatef(-90, 0, 0, 1);
	//fh.color('w');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0);
	//glTranslatef(0, 0, 0);
	//fh.color('r');
	fh.sphere(GLU_LINE, size / 8.0, 10, 10);
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
	glTranslatef(size * 2 / 3.0 + 0.1, size, 0);
	glRotatef(90, 0, 0, 1);
	fh.cuboid(type, size / 2.5, 1, lineWidth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(size * 2 / 3.0 - 0.1, size + 0.4, 0.2);
	//fh.color('r');
	fh.sphere(GLU_LINE, size / 5.0, 10, 10);
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

void arm() {
	float uaBaseRadius = 0.05, uaTopRadius = uaBaseRadius - 0.005, height = 0.35, slices = 30, stacks = 30;
	float laBaseRadius = uaTopRadius, laTopRadius = laBaseRadius - 0.01;
	float sRadius = uaTopRadius;
	float palmSize = uaBaseRadius + 0.05;

	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	
	glPushMatrix();
	glTranslatef(0, 0, -height);
	fh.color('g');
	fh.cylinder(GLU_LINE, uaBaseRadius, uaTopRadius, height, slices, stacks); //upperarm
	glPopMatrix();
	
	glPushMatrix();
	//glRotatef(-90, 1.0, 0, 0);
	//glTranslatef(0, 0, height);
	
	glPushMatrix();
	fh.color('y');
	fh.sphere(GLU_LINE, sRadius, slices, stacks); //elbow
	glPopMatrix();
	
	height -= 0.01;
	glPushMatrix();
	if(armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);
	//glRotatef(-90, 1.0, 0.0, 0.0);
	//glRotatef(-armAngle, 1.0, 0.0, 0.0);
	fh.color('r');
	fh.cylinder(GLU_LINE, laBaseRadius, laTopRadius, height, slices, stacks); //lowerarm
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);
	glTranslatef(0, -laTopRadius - 0.01, height + palmSize);
	//glRotatef(90, 1.0, 0, 0);
	glRotatef(90, 0, 1.0, 0);
	glScalef(palmSize, palmSize, palmSize);
	palm(GL_LINE_LOOP, 1.0, 0.5, 2);
	glPopMatrix();
	glPopMatrix();

}

//============================= LIANA =================================
void dannyWork() {
	upperChest();
	lowerChest();
	abdomen();
}

void display()
{
	init();
	for (int i = 0; i < SIZE; i++) {
		C[i] = 1000000;
	}
	switch (qNo) {
	case 1:
		//glLoadIdentity();
		//glPushMatrix();
		//glRotatef(90, 0, 1, 0);
		head();
		//glPopMatrix();
		//glPushMatrix();
		body();
		//glPopMatrix();
		break;
	case 2:
		
		glRotatef(1, 0, 1, 0);
		glPushMatrix();
		glScalef(1.5, 1.5, 1.5);
		dannyWork();
		glPopMatrix();
		break;
	case 3:
		//test3();
		//glRotatef(1, 1, 1, 0);
		fh.sphere(GL_LINE_STRIP, 200, 200, 200, 400, 400, 36, 0, 100, 0, 100, 1, 0, 0);
		break;
	case 4:
		head();
		if ((armUp && armAngle > 110) || (armDown && armAngle >= 0)) //raise hand
			armAngle -= armRSpeed;
		else
			armAngle += armRSpeed;

		if (armDirection == 1 && armRotate <= 30) //arm rotate
			armRotate += armRSpeed;
		else
			if(armRotate >= -30)
				armRotate -= armRSpeed;
		
		//glRotatef(0.3, 0, 1.0, 0);
		glPushMatrix();
		if (armTurn)
			glRotatef(armRotate, armx2, army2, armz2);
		arm();
		glPopMatrix();
		break;
	case 5:
		glRotatef(1, 0, 0, 1);
		body();
		break;
	case 6:
		//glLoadIdentity();
		glRotatef(1, 0, 1, 0);
		dannyWork();
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
		head();
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