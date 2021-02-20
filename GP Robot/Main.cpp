
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "IRON-MAN MK47"
#define CW_USEDEFAULT 10
#define VALUE 800.0
#define WIDTH VALUE
#define HEIGHT VALUE
#define DEPTH VALUE
#define M_PI 3.141593

int qNo = 4;

float xC(float x) {
	float xCoor, width = WIDTH / 2;
	if (x < width) {
		xCoor = (x / width) - 1;
	}
	else if (x > width) {
		xCoor = (x - width) / width;
	}
	else if (x == width) {
		xCoor = 0.0;
	}
	return xCoor;
}

float yC(float y) {
	float yCoor, height = HEIGHT / 2;
	if (y < height) {
		yCoor = 1 - (y / height);
	}
	else if (y > height) {
		yCoor = 0 - ((y - height) / height);
	}
	else if (y == height) {
		yCoor = 0.0;
	}
	return yCoor;
}

float zC(float z) {
	return ((- z) / (DEPTH / 2));
}

float xP(float x) {
	return (x / (WIDTH / 2));
}

float yP(float y) {
	return (y / (HEIGHT / 2));
}

float zP(float z) {
	return (z / (DEPTH / 2));
}

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
			// press 1
			qNo = 1;
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
			// press numpad 1
			qNo = 61;
			break;
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

void drawCircle(float x1, float y1, float x, float y, float min, float max) {
	for (float i = min; i < max; i++)
	{
		float x2 = xC(x1) + cos(i * M_PI / 180.f) * xP(x);
		float y2 = yC(y1) + sin(i * M_PI / 180.f) * yP(y);
		glVertex2f(x2, y2);
	}
}

void drawSphere(float xradius, float yradius, float zradius, int xaxis, int yaxis, float zaxis, float xmin, float xmax, float ymin, float ymax) {
	float i, j, lats = 100, longs = 100;
	float x2 = xC(xaxis), y2 = yC(yaxis), z2 = zC(zaxis);
	float xr = xP(xradius), yr = yP(yradius), zr = zP(zradius);

	for (i = xmin; i <= xmax; i++) {
		float lat0 = M_PI * (-0.5 + (i - 1) / lats);
		float z0 = sin(lat0);
		float zr0 = cos(lat0);

		float lat1 = M_PI * (-0.5 + i / lats);
		float z1 = sin(lat1);
		float zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);
		for (j = ymin; j <= ymax; j++) {
			float lng = 2 * M_PI * (j - 1.0) / longs;
			float x = cos(lng);
			float y = sin(lng);

			glColor3f(1, 1, 1);
			//glNormal3f(x2 + x * zr0, y2 + y * zr0, z2 + z0);
			glVertex3f(x2 + xr * x * zr0, y2 + yr * y * zr0, z2 + zr * z0);

			//glColor3f(1, 0, 0);
			//glNormal3f(x2 + x * zr1, y2 + y * zr1, z2 + z1);
			glVertex3f(x2 + xr * x * zr1, y2 + yr * y * zr1, z2 + zr * z1);
		}
		glEnd();
	}
}

void drawSphere2(float xradius, float yradius, float zradius, float xaxis, float yaxis, float zaxis, float xstart, float xdivide, float ydivide)
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float x1 = xC(xaxis), y1 = yC(yaxis), z1 = zC(zaxis);
	float x, y, z;
	float sliceA, stackA;
	float xr = xP(xradius), yr = yP(yradius), zr = zP(zradius);
	int sliceNo = 100, stackNo = 100;

	for (sliceA = xstart; sliceA < (2 * M_PI)/xdivide; sliceA += M_PI / sliceNo)
	{
		glBegin(GL_LINE_STRIP);
		for (stackA = xstart; stackA < (2 * M_PI)/ydivide; stackA += M_PI / stackNo)
		{
			// row
			glColor3f(1, 1, 1);
			x = x1 + xr * cos(stackA) * sin(sliceA);
			y = y1 + yr * sin(stackA) * sin(sliceA);
			z = z1 + zr * cos(sliceA);
			glVertex3f(x, y, z);

			// column
			glColor3f(1, 0, 0);
			x = x1 + xr * cos(stackA) * sin(sliceA + M_PI / stackNo);
			y = y1 + yr * sin(stackA) * sin(sliceA + M_PI / sliceNo);
			z = z1 + zr * cos(sliceA + M_PI / sliceNo);
			glVertex3f(x, y, z);
		}
		glEnd();
	}
}

//void test1() {
//	glClearColor(0.0745, 0.109803, 0.129411, 0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	float x1, y1, x2, y2;
//	float angle;
//
//	// head
//	x1 = 450, y1 = 450;
//	glBegin(GL_POLYGON);
//	glColor3f(0.97647, 0.709804, 0.152941);
//	drawCircle(x1, y1, 180, 180, 0, 371);
//
//	glEnd();
//
//	// smile 1
//	x1 = 450, y1 = 472.5;
//	glLineWidth(2);
//	glBegin(GL_POLYGON);
//	glColor3f(0.45098, 0.28627, 0.054902);
//	drawCircle(x1, y1, 90, 67.5, 200, 330);
//
//	glEnd();
//
//	// smile 1 cover
//	x1 = 450, y1 = 472.5;
//	glLineWidth(2);
//	glBegin(GL_POLYGON);
//	glColor3f(0.97647, 0.709804, 0.152941);
//	drawCircle(x1, y1, 90, 58.5, 200, 330);
//
//	glEnd();
//
//	// eye 1
//	x1 = 387, y1 = 405;
//	glBegin(GL_POLYGON);
//	glColor3f(0.45098, 0.28627, 0.054902);
//	drawCircle(x1, y1, 22.5, 22.5, 0, 371);
//
//	glEnd();
//
//	x1 = 513, y1 = 405;
//	glBegin(GL_POLYGON);
//	glColor3f(0.45098, 0.28627, 0.054902);
//	drawCircle(x1, y1, 22.5, 22.5, 0, 371);
//
//	glEnd();
//
//	// eye 2
//	x1 = 387, y1 = 396;
//	glBegin(GL_POLYGON);
//	glColor3f(1, 1, 1);
//	drawCircle(x1, y1, 9, 9, 0, 371);
//
//	glEnd();
//
//	x1 = 513, y1 = 396;
//	glBegin(GL_POLYGON);
//	glColor3f(1, 1, 1);
//	drawCircle(x1, y1, 9, 9, 0, 371);
//
//	glEnd();
//
//	// tear 1
//	glBegin(GL_POLYGON);
//	glColor3f(1, 1, 1);
//	glVertex2f(0.14, 0.05);
//	glColor3f(0.48627, 0.839215, 0.890196);
//	glVertex2f(0.25, -0.15);
//	glVertex2f(0.03, -0.15);
//
//	glEnd();
//
//	// tear 2
//	x1 = 513, y1 = 517.5;
//	glBegin(GL_POLYGON);
//	glColor3f(0.48627, 0.839215, 0.890196);
//	drawCircle(x1, y1, 49.5, 58.5, 177, 354);
//
//	glEnd();
//}

void test2() {
	//glLoadIdentity();
	glRotatef(1, 1, 1, 0);
	//drawSphere(0.3, 400, 400, 0, 30, 30);
}

void test3() {
	//// 1
	//glColor3f(0.5, 0.5, 0.5);
	//glBegin(GL_POLYGON);
	//glVertex3f(xC(200), yC(300), 0);
	//glVertex3f(xC(200), yC(290), 0.1);
	////glColor3f(0.7, 0.7, 0.5);
	//glVertex3f(xC(600), yC(290), 0.1);
	//glVertex3f(xC(600), yC(300), 0);
	//glEnd();

	glRotatef(1, 0, 1, 0);
	glColor3f(0.7, 0.5, 0.5);

	// 1
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(300), zC(0));
	glVertex3f(xC(200), yC(307.43303), zC(-46.93034));
	glVertex3f(xC(600), yC(307.43303), zC(-46.93034));
	glVertex3f(xC(600), yC(300), zC(0));
	glEnd();

	// 2
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(307.43303), zC(-46.93034));
	glVertex3f(xC(200), yC(329.00454), zC(-89.26681));
	glVertex3f(xC(600), yC(329.00454), zC(-89.26681));
	glVertex3f(xC(600), yC(307.43303), zC(-46.93034));
	glEnd();

	// 3
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(329.00454), zC(-89.26681));
	glVertex3f(xC(200), yC(362.60301), zC(-122.86522));
	glVertex3f(xC(600), yC(362.60301), zC(-122.86522));
	glVertex3f(xC(600), yC(329.00454), zC(-89.26681));
	glEnd();

	// 4
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(362.60301), zC(-122.86522));
	glVertex3f(xC(200), yC(404.93948), zC(-144.43673));
	glVertex3f(xC(600), yC(404.93948), zC(-144.43673));
	glVertex3f(xC(600), yC(362.60301), zC(-122.86522));
	glEnd();

	// 5
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(404.93948), zC(-144.43673));
	glVertex3f(xC(200), yC(451.86982), zC(-151.86976));
	glVertex3f(xC(600), yC(451.86982), zC(-151.86976));
	glVertex3f(xC(600), yC(404.93948), zC(-144.43673));
	glEnd();

	// 6
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(451.86982), zC(-151.86976));
	glVertex3f(xC(200), yC(498.80016), zC(-144.43673));
	glVertex3f(xC(600), yC(498.80016), zC(-144.43673));
	glVertex3f(xC(600), yC(451.86982), zC(-151.86976));
	glEnd();

	// 7
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(541.13663), zC(-122.86522));
	glVertex3f(xC(200), yC(498.80016), zC(-144.43673));
	glVertex3f(xC(600), yC(498.80016), zC(-144.43673));
	glVertex3f(xC(600), yC(541.13663), zC(-122.86522));
	glEnd();

	// 8
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(574.73504), zC(-89.26681));
	glVertex3f(xC(200), yC(541.13663), zC(-122.86522));
	glVertex3f(xC(600), yC(541.13663), zC(-122.86522));
	glVertex3f(xC(600), yC(574.73504), zC(-89.26681));
	glEnd();

	// 9
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(596.30655), zC(-46.93034));
	glVertex3f(xC(200), yC(574.73504), zC(-89.26681));
	glVertex3f(xC(600), yC(574.73504), zC(-89.26681));
	glVertex3f(xC(600), yC(596.30655), zC(-46.93034));
	glEnd();

	// 10
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.5, 0.5);
	glVertex3f(xC(200), yC(603.73958), zC(0));
	glVertex3f(xC(200), yC(596.30655), zC(-46.93034));
	glVertex3f(xC(600), yC(596.30655), zC(-46.93034));
	glVertex3f(xC(600), yC(603.73958), zC(0));
	glEnd();

	glColor3f(0.1, 0.5, 0.5);
	// 1
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(300), zC(0));
	glVertex3f(xC(200), yC(307.43303), zC(46.93034));
	glVertex3f(xC(600), yC(307.43303), zC(46.93034));
	glVertex3f(xC(600), yC(300), zC(0));
	glEnd();

	// 2
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(307.43303), zC(46.93034));
	glVertex3f(xC(200), yC(329.00454), zC(89.26681));
	glVertex3f(xC(600), yC(329.00454), zC(89.26681));
	glVertex3f(xC(600), yC(307.43303), zC(46.93034));
	glEnd();

	// 3
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(329.00454), zC(89.26681));
	glVertex3f(xC(200), yC(362.60301), zC(122.86522));
	glVertex3f(xC(600), yC(362.60301), zC(122.86522));
	glVertex3f(xC(600), yC(329.00454), zC(89.26681));
	glEnd();

	// 4
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(362.60301), zC(122.86522));
	glVertex3f(xC(200), yC(404.93948), zC(144.43673));
	glVertex3f(xC(600), yC(404.93948), zC(144.43673));
	glVertex3f(xC(600), yC(362.60301), zC(122.86522));
	glEnd();

	// 5
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(404.93948), zC(144.43673));
	glVertex3f(xC(200), yC(451.86982), zC(151.86976));
	glVertex3f(xC(600), yC(451.86982), zC(151.86976));
	glVertex3f(xC(600), yC(404.93948), zC(144.43673));
	glEnd();

	// 6
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(451.86982), zC(151.86976));
	glVertex3f(xC(200), yC(498.80016), zC(144.43673));
	glVertex3f(xC(600), yC(498.80016), zC(144.43673));
	glVertex3f(xC(600), yC(451.86982), zC(151.86976));
	glEnd();

	// 7
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(541.13663), zC(122.86522));
	glVertex3f(xC(200), yC(498.80016), zC(144.43673));
	glVertex3f(xC(600), yC(498.80016), zC(144.43673));
	glVertex3f(xC(600), yC(541.13663), zC(122.86522));
	glEnd();

	// 8
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(574.73504), zC(89.26681));
	glVertex3f(xC(200), yC(541.13663), zC(122.86522));
	glVertex3f(xC(600), yC(541.13663), zC(122.86522));
	glVertex3f(xC(600), yC(574.73504), zC(89.26681));
	glEnd();

	// 9
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(596.30655), zC(46.93034));
	glVertex3f(xC(200), yC(574.73504), zC(89.26681));
	glVertex3f(xC(600), yC(574.73504), zC(89.26681));
	glVertex3f(xC(600), yC(596.30655), zC(46.93034));
	glEnd();

	// 10
	glBegin(GL_POLYGON);
	glVertex3f(xC(200), yC(603.73958), zC(0));
	glVertex3f(xC(200), yC(596.30655), zC(46.93034));
	glVertex3f(xC(600), yC(596.30655), zC(46.93034));
	glVertex3f(xC(600), yC(603.73958), zC(0));
	glEnd();
}

void robotDraft() {
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// head
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(375), yC(130));
	glVertex2f(xC(375), yC(200));
	glVertex2f(xC(425), yC(200));
	glVertex2f(xC(425), yC(130));
	glEnd();

	// body
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(340), yC(200));
	glVertex2f(xC(355), yC(350));
	glVertex2f(xC(445), yC(350));
	glVertex2f(xC(460), yC(200));
	glEnd();

	// loin
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(347), yC(350));
	glVertex2f(xC(347), yC(400));
	glVertex2f(xC(453), yC(400));
	glVertex2f(xC(453), yC(350));
	glEnd();

	// da tui left
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(355), yC(400));
	glVertex2f(xC(355), yC(525));
	glVertex2f(xC(390), yC(525));
	glVertex2f(xC(390), yC(400));
	glEnd();

	// xiao tui left
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(355), yC(525));
	glVertex2f(xC(355), yC(680));
	glVertex2f(xC(390), yC(680));
	glVertex2f(xC(390), yC(525));
	glEnd();

	// jiao ban left
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(355), yC(680));
	glVertex2f(xC(355), yC(710));
	glVertex2f(xC(390), yC(710));
	glVertex2f(xC(390), yC(680));
	glEnd();

	// da tui right right
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(410), yC(400));
	glVertex2f(xC(410), yC(525));
	glVertex2f(xC(445), yC(525));
	glVertex2f(xC(445), yC(400));
	glEnd();

	// da tui right right
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(410), yC(525));
	glVertex2f(xC(410), yC(680));
	glVertex2f(xC(445), yC(680));
	glVertex2f(xC(445), yC(525));
	glEnd();

	// da tui right right
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(410), yC(680));
	glVertex2f(xC(410), yC(710));
	glVertex2f(xC(445), yC(710));
	glVertex2f(xC(445), yC(680));
	glEnd();

	// arm upper left
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(250), yC(210));
	glVertex2f(xC(250), yC(245));
	glVertex2f(xC(355), yC(245));
	glVertex2f(xC(355), yC(210));
	glEnd();

	// arm lower left
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(150), yC(210));
	glVertex2f(xC(150), yC(245));
	glVertex2f(xC(250), yC(245));
	glVertex2f(xC(250), yC(210));
	glEnd();

	// hand left
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(80), yC(210));
	glVertex2f(xC(80), yC(245));
	glVertex2f(xC(150), yC(245));
	glVertex2f(xC(150), yC(210));
	glEnd();

	// arm upper right
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(445), yC(210));
	glVertex2f(xC(445), yC(245));
	glVertex2f(xC(550), yC(245));
	glVertex2f(xC(550), yC(210));
	glEnd();

	// arm lower right
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(550), yC(210));
	glVertex2f(xC(550), yC(245));
	glVertex2f(xC(650), yC(245));
	glVertex2f(xC(650), yC(210));
	glEnd();

	// hand right
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(xC(650), yC(210));
	glVertex2f(xC(650), yC(245));
	glVertex2f(xC(720), yC(245));
	glVertex2f(xC(720), yC(210));
	glEnd();
}

void body() {
	/*glClearColor(0.5, 0.5, 0.5, 0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/
	//glRotatef(1, 0, 1, 0);
	// front
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(xC(340), yC(200), zC(55));
	glVertex3f(xC(355), yC(350), zC(44));
	glVertex3f(xC(445), yC(350), zC(44));
	glVertex3f(xC(460), yC(200), zC(55));
	glEnd();

	// top
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(xC(340), yC(200), zC(-55));
	glVertex3f(xC(340), yC(200), zC(55));
	glVertex3f(xC(460), yC(200), zC(55));
	glVertex3f(xC(460), yC(200), zC(-55));
	glEnd();

	// back
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(xC(340), yC(200), zC(-55));
	glVertex3f(xC(355), yC(350), zC(-44));
	glVertex3f(xC(445), yC(350), zC(-44));
	glVertex3f(xC(460), yC(200), zC(-55));
	glEnd();

	// left
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(xC(340), yC(200), zC(-55));
	glVertex3f(xC(355), yC(350), zC(-44));
	glVertex3f(xC(355), yC(350), zC(44));
	glVertex3f(xC(340), yC(200), zC(55));
	glEnd();

	// right
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex3f(xC(460), yC(200), zC(55));
	glVertex3f(xC(445), yC(350), zC(44));
	glVertex3f(xC(445), yC(350), zC(-44));
	glVertex3f(xC(460), yC(200), zC(-55));
	glEnd();

	// btm
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(xC(355), yC(350), zC(-44));
	glVertex3f(xC(355), yC(350), zC(44));
	glVertex3f(xC(445), yC(350), zC(44));
	glVertex3f(xC(445), yC(350), zC(-44));
	glEnd();

}

void upperChest() {
	// upper chest
	//glPushMatrix();
	//glTranslatef(0, yP(225.142857), 0);
	//glRotatef(90, 1, 0, 0);
	//drawSphere(55, 60, 55, 400, 225.142857, 0, 25, 50, 0, 50);
	//glPopMatrix();

	//glPushMatrix();
	//glLoadIdentity();
	//glLineWidth(3);
	/*glBegin(GL_LINE_STRIP);
	glVertex3f(xC(400), yC(0), 0);
	glVertex3f(xC(400), yC(800), 0);
	glEnd();*/
	//glRotatef(-1, 0, 1, 0);

	//glLoadIdentity();
	//glTranslatef(xP(170), 0, 0);

	// front
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(xC(385.856426), yC(200), zC(22));
	glVertex3f(xC(364.642857), yC(225.142857), zC(44));
	glVertex3f(xC(435.357143), yC(225.142857), zC(44));
	glVertex3f(xC(414.143574), yC(200), zC(22));
	glEnd();

	// left
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(xC(385.856426), yC(200), zC(-37.714286));
	glVertex3f(xC(364.642857), yC(225.142857), zC(-55));
	glVertex3f(xC(364.642857), yC(225.142857), zC(44));
	glVertex3f(xC(385.856426), yC(200), zC(22));
	glEnd();

	// right
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(xC(414.143574), yC(200), zC(22));
	glVertex3f(xC(435.357143), yC(225.142857), zC(44));
	glVertex3f(xC(435.357143), yC(225.142857), zC(-55));
	glVertex3f(xC(414.143574), yC(200), zC(-37.714286));
	glEnd();

	// back
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(xC(385.856426), yC(200), zC(-37.714286));
	glVertex3f(xC(364.642857), yC(225.142857), zC(-55));
	glVertex3f(xC(435.357143), yC(225.142857), zC(-55));
	glVertex3f(xC(414.143574), yC(200), zC(-37.714286));
	glEnd();

}

void lowerChest() {

	// front 
	glColor3f(0.3, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex3f(xC(364.642857), yC(225.142857), zC(44));
	glVertex3f(xC(367), yC(253.430005), zC(55));
	glVertex3f(xC(433), yC(253.430005), zC(55));
	glVertex3f(xC(435.357143), yC(225.142857), zC(44));
	glEnd();

	// left
	glColor3f(0.5, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(xC(364.642857), yC(225.142857), zC(-55));
	glVertex3f(xC(367), yC(253.430005), zC(-47.142858));
	glVertex3f(xC(367), yC(253.430005), zC(55));
	glVertex3f(xC(364.642857), yC(225.142857), zC(44));
	glEnd();

	// right
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(xC(435.357143), yC(225.142857), zC(44));
	glVertex3f(xC(433), yC(253.430005), zC(55));
	glVertex3f(xC(433), yC(253.430005), zC(-47.142858));
	glVertex3f(xC(435.357143), yC(225.142857), zC(-55));
	glEnd();

	// back
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(xC(364.642857), yC(225.142857), zC(-55));
	glVertex3f(xC(367), yC(253.430005), zC(-47.142858));
	glVertex3f(xC(433), yC(253.430005), zC(-47.142858));
	glVertex3f(xC(435.357143), yC(225.142857), zC(-55));
	glEnd();
}

void abdomen() {
	// front
	glColor3f(0.3, 1, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(xC(367), yC(253.430005), zC(55));
	glVertex3f(xC(372.5), yC(350), zC(44));
	glVertex3f(xC(427.5), yC(350), zC(44));
	glVertex3f(xC(433), yC(253.430005), zC(55));
	glEnd();
}

//void pahangFlag() {
//
//	glClearColor(255, 255, 255, 255);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	// flag shape
//	glLineWidth(1);
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0, 0, 0);
//
//	//glVertex2f(-0.8, 0.5);
//	//glVertex2f(0.8, 0.5);
//	//glVertex2f(0.8, -0.5);
//	//glVertex2f(-0.8, -0.5);
//
//	// white
//	glVertex2f(xC(90), yC(200));
//	glVertex2f(xC(810), yC(200));
//	glVertex2f(xC(810), yC(600));
//	glVertex2f(xC(90), yC(600));
//	glEnd();
//
//	// black
//	glBegin(GL_POLYGON);
//	glColor3f(0, 0, 0);
//	glVertex2f(-0.8, 0);
//	glVertex2f(0.8, 0);
//	glVertex2f(0.8, -0.5);
//	glVertex2f(-0.8, -0.5);
//
//	glEnd();
//}
//
//void japanFlag() {
//
//	glClearColor(255, 255, 255, 255);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	// flag shape
//	glLineWidth(1);
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0, 0, 0);
//
//	glVertex2f(-0.8, 0.5);
//	glVertex2f(0.8, 0.5);
//	glVertex2f(0.8, -0.5);
//	glVertex2f(-0.8, -0.5);
//
//	glEnd();
//
//	// circle
//	float x1, y1, x2, y2;
//	float angle;
//	double radius = 0.3;
//
//	x1 = 450.0, y1 = 450.0;
//	glColor3f(1, 0, 0);
//
//	glBegin(GL_TRIANGLE_FAN);
//	drawCircle(x1, y1, 100, 100, 0, 371);
//
//	glEnd();
//}

void head() {
	/*glLoadIdentity();
	glRotatef(90,0,1,0);*/
	glRotatef(0.1, 1, 1, 0);

	//Right face
	//bacl
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		glVertex3f(xC(410), yC(105), zC(0));
		glVertex3f(xC(410), yC(107.5), zC(12.5));
		glVertex3f(xC(410), yC(112.5), zC(25));
		glVertex3f(xC(422.5), yC(112.5), zC(10));
	glEnd();

	//lc?m
	glBegin(GL_POLYGON);
		glVertex3f(xC(410), yC(112.5), zC(25));
		glVertex3f(xC(422.5), yC(112.5), zC(10));
		glVertex3f(xC(425), yC(115), zC(-32.5));
		glVertex3f(xC(422.5), yC(120), zC(15));
	glEnd();

	//m??n
	glBegin(GL_POLYGON);
		glVertex3f(xC(422.5), yC(120), zC(15));
		glVertex3f(xC(425), yC(115), zC(-32.5));
		glVertex3f(xC(425), yC(127.5), zC(-37.5));
		glVertex3f(xC(422), yC(140), zC(20));
	glEnd();

	//n?o
	glBegin(GL_POLYGON);
		glVertex3f(xC(422), yC(140), zC(20));
		glVertex3f(xC(425), yC(127.5), zC(-37.5));
		glVertex3f(xC(422.4), yC(147.5), zC(-12.5));
	glEnd();

	//o???
	glBegin(GL_POLYGON);
		glVertex3f(xC(422.4), yC(147.5), zC(-12.5));
		glVertex3f(xC(425), yC(127.5), zC(-37.5));
		glVertex3f(xC(425), yC(147.5), zC(-33.75));
		glVertex3f(xC(428.75), yC(157.5), zC(0));
	glEnd();

	//???
	glBegin(GL_POLYGON);
		glVertex3f(xC(425), yC(127.5), zC(-37.5));
		glVertex3f(xC(425), yC(147.5), zC(-33.75));
		glVertex3f(xC(425), yC(150), zC(-37.5));
	glEnd();

	//o??p
	glBegin(GL_POLYGON);
		glVertex3f(xC(422.4), yC(147.5), zC(-12.5));
		glVertex3f(xC(428.75), yC(157.5), zC(0));
		glVertex3f(xC(426), yC(172.5), zC(5));
		glVertex3f(xC(420), yC(167), zC(17));
	glEnd();

	//p?q
	glBegin(GL_POLYGON);
		glVertex3f(xC(420), yC(167), zC(17));
		glVertex3f(xC(426), yC(172.5), zC(5));
		glVertex3f(xC(422.5), yC(170), zC(18));
	glEnd();

	//q?fr
	glBegin(GL_POLYGON);
		glVertex3f(xC(422.5), yC(170), zC(18));
		glVertex3f(xC(430), yC(177.5), zC(32));
		glVertex3f(xC(406), yC(182.5), zC(25));
		glVertex3f(xC(408.5), yC(174), zC(25));
	glEnd();

	//srfe
	glBegin(GL_POLYGON);
		glVertex3f(xC(407), yC(172.5), zC(33.5));
		glVertex3f(xC(408.5), yC(174), zC(25));
		glVertex3f(xC(406), yC(182.5), zC(25));
		glVertex3f(xC(407), yC(171.5), zC(32.5));
	glEnd();

	//Left face
	//z??v
	glBegin(GL_POLYGON);
		glVertex3f(xC(377.5), yC(120), zC(25));
		glVertex3f(xC(425 - 57.5), yC(115), zC(-32.5));
		glVertex3f(xC(425), yC(127.5), zC(-37.5));
		glVertex3f(xC(377.5), yC(170), zC(18));
	glEnd();

	//v?x
	glBegin(GL_POLYGON);
	glVertex3f(xC(377.5), yC(170), zC(18));
	glVertex3f(xC(425 - 57.5), yC(127.5), zC(-37.5));
	glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	glEnd();

	//x???
	glBegin(GL_POLYGON);
	glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	glVertex3f(xC(425 - 57.5), yC(127.5), zC(-37.5));
	glVertex3f(xC(425 - 57.5), yC(147.5), zC(-33.75));
	glVertex3f(xC(428.75 - 57.5), yC(157.5), zC(0));
	glEnd();

	//???
	glBegin(GL_POLYGON);
	glVertex3f(xC(425 - 57.5), yC(127.5), zC(-37.5));
	glVertex3f(xC(425 - 57.5), yC(147.5), zC(-33.75));
	glVertex3f(xC(425 - 57.5), yC(150), zC(-37.5));
	glEnd();

	//x??w
	glBegin(GL_POLYGON);
	glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	glVertex3f(xC(428.75 - 57.5), yC(157.5), zC(0));
	glVertex3f(xC(426 - 57.5), yC(172.5), zC(5));
	glVertex3f(xC(380), yC(167), zC(17));
	glEnd();

	//w?v
	glBegin(GL_POLYGON);
	glVertex3f(xC(380), yC(167), zC(17));
	glVertex3f(xC(426 - 57.5), yC(172.5), zC(5));
	glVertex3f(xC(377.5), yC(170), zC(18));
	glEnd();

	//v?hu
	glBegin(GL_POLYGON);
	glVertex3f(xC(377.5), yC(170), zC(18));
	glVertex3f(xC(426 - 57.5), yC(172.5), zC(5));
	glVertex3f(xC(370), yC(177.5), zC(32.5));
	glVertex3f(xC(391.5), yC(174), zC(25));
	glEnd();

	//vugh
	glBegin(GL_POLYGON);
	glVertex3f(xC(377.5), yC(170), zC(18));
	glVertex3f(xC(391.5), yC(174), zC(25));
	glVertex3f(xC(394), yC(182.5), zC(25));
	glVertex3f(xC(370), yC(177.5), zC(32.5));
	glEnd();

	//Front face
	//kabl(cc)(bb)(aa)
	glBegin(GL_POLYGON);
		glVertex3f(xC(390), yC(107), zC(5));
		glVertex3f(xC(400), yC(105), zC(0));
		glVertex3f(xC(410), yC(107), zC(5));
		glVertex3f(xC(410), yC(112.5), zC(25));
		glVertex3f(xC(412.5), yC(118.75), zC(30));
		glVertex3f(xC(387.5), yC(118.75), zC(30));
		glVertex3f(xC(390), yC(112.5), zC(25));
	glEnd();

	//k(aa)zj
	glBegin(GL_POLYGON);
		glVertex3f(xC(390), yC(107), zC(5));
		glVertex3f(xC(390), yC(112.5), zC(25));
		glVertex3f(xC(377.5), yC(120), zC(25));
		glVertex3f(xC(377.5), yC(112.5), zC(15));
	glEnd();

	//jzyi
	glBegin(GL_POLYGON);
		glVertex3f(xC(377.5), yC(112.5), zC(15));
		glVertex3f(xC(377.5), yC(120), zC(25));
		glVertex3f(xC(378), yC(140), zC(20));
		glVertex3f(xC(371.25), yC(140), zC(5));
	glEnd();

	//iyx?
	glBegin(GL_POLYGON);
		glVertex3f(xC(371.25), yC(140), zC(5));
		glVertex3f(xC(378), yC(140), zC(20));
		glVertex3f(xC(377.5), yC(147.5), zC(12.5));
		glVertex3f(xC(374), yC(147.5), zC(5));
	glEnd();

	//?xwv
	glBegin(GL_POLYGON);
		glVertex3f(xC(374), yC(147.5), zC(5));
		glVertex3f(xC(377.5), yC(147.5), zC(12.5));
		glVertex3f(xC(380), yC(167), zC(17));
		glVertex3f(xC(377.5), yC(170), zC(18));
	glEnd();

	//?vh
	glBegin(GL_POLYGON);
		glVertex3f(xC(374), yC(147.5), zC(5));
		glVertex3f(xC(377.5), yC(170), zC(18));
		glVertex3f(xC(370), yC(177.5), zC(32.5));
	glEnd();

	//hvug
	glBegin(GL_POLYGON);
		glVertex3f(xC(370), yC(177.5), zC(32.5));
		glVertex3f(xC(377.5), yC(170), zC(18));
		glVertex3f(xC(391.5), yC(174), zC(25));
		glVertex3f(xC(394), yC(182.5), zC(25));
	glEnd();

	//gutf
	glBegin(GL_POLYGON);
		glVertex3f(xC(394), yC(182.5), zC(25));
		glVertex3f(xC(391.5), yC(174), zC(25));
		glVertex3f(xC(393), yC(172.5), zC(33.5));
		glVertex3f(xC(406), yC(182.5), zC(25));
	glEnd();

	//tfrs
	glBegin(GL_POLYGON);
		glVertex3f(xC(393), yC(172.5), zC(33.5));
		glVertex3f(xC(406), yC(182.5), zC(25));
		glVertex3f(xC(408.5), yC(174), zC(25));
		glVertex3f(xC(407), yC(172.5), zC(33.5));
	glEnd();

	glColor3f(1,1,1);
	//(aa)(bb)zy
	glBegin(GL_POLYGON);
		glVertex3f(xC(390), yC(112.5), zC(25));
		glVertex3f(xC(387.5), yC(118.75), zC(30));
		glVertex3f(xC(377.5), yC(120), zC(25));
		glVertex3f(xC(378), yC(140), zC(20));
	glEnd();

	//(bb)(cc)ny
	glBegin(GL_POLYGON);
	glVertex3f(xC(387.5), yC(118.75), zC(30));
		glVertex3f(xC(412.5), yC(118.75), zC(30));
		glVertex3f(xC(422), yC(140), zC(20));
		glVertex3f(xC(378), yC(140), zC(20));
	glEnd();

	//lmn(cc)
	glBegin(GL_POLYGON);
		glVertex3f(xC(410), yC(112.5), zC(25));
		glVertex3f(xC(422.5), yC(120), zC(15));
		glVertex3f(xC(422), yC(140), zC(20));
		glVertex3f(xC(412.5), yC(118.75), zC(30));
	glEnd();

	//ynox
	glBegin(GL_POLYGON);
		glVertex3f(xC(378), yC(140), zC(20));
		glVertex3f(xC(378), yC(140), zC(20));
		glVertex3f(xC(428.75), yC(140), zC(5));
		glVertex3f(xC(377.5), yC(147.5), zC(12.5));
	glEnd();

	//xopw
	glBegin(GL_POLYGON);
		glVertex3f(xC(377.5), yC(147.5), zC(12.5));
		glVertex3f(xC(428.75), yC(140), zC(5));
		glVertex3f(xC(420), yC(167), zC(17));
		glVertex3f(xC(380), yC(167), zC(17));
	glEnd();

	//wpst
	glBegin(GL_POLYGON);
		glVertex3f(xC(380), yC(167), zC(17));
		glVertex3f(xC(420), yC(167), zC(17));
		glVertex3f(xC(407), yC(172.5), zC(33.5));
		glVertex3f(xC(393), yC(172.5), zC(33.5));
	glEnd();

	//wtuv
	glBegin(GL_POLYGON);
		glVertex3f(xC(380), yC(167), zC(17));
		glVertex3f(xC(393), yC(172.5), zC(33.5));
		glVertex3f(xC(391.5), yC(174), zC(25));
		glVertex3f(xC(377.5), yC(170), zC(18));
	glEnd();

	//spqr
	glBegin(GL_POLYGON);
		glVertex3f(xC(407), yC(172.5), zC(33.5));
		glVertex3f(xC(420), yC(167), zC(17));
		glVertex3f(xC(422.5), yC(170), zC(18));
		glVertex3f(xC(408.5), yC(174), zC(25));
	glEnd();
}

void dannyWork() {
	upperChest();
	lowerChest();
	abdomen();
}

void display()
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (qNo) {
	case 1:
		glLoadIdentity();
		//glPushMatrix();
		glRotatef(90, 0, 1, 0);
		head();
		//glPopMatrix();
		//glPushMatrix();
		body();
		//glPopMatrix();
		break;
	case 2:
		//extra();
		test2();
		glPopMatrix();
		break;
	case 3:
		//test3();
		//glRotatef(1, 1, 1, 0);
		drawSphere(200, 300, 200, 400, 400, 36, 0, 50, 0, 100);
		break;
	case 4:
		head();
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
		glLoadIdentity();
		glRotatef(1, 0, 1, 0);
		drawSphere2(100, 150, 100, 400, 400, 36, 2, 1, 1);
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
		CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT,
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