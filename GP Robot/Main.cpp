
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "Practical 1"
#define CW_USEDEFAULT 10
#define WIDTH 800
#define HEIGHT 800
#define M_PI 3.2

int qNo = 1;
int testing3 = 0;
float xConvertion(float x) {
	float xCoor, width = WIDTH / 2;
	if (x < width) {
		xCoor = 0 - (x / width);
	}
	else if (x > width) {
		xCoor = (x - width) / width;
	}
	else if (x == width) {
		xCoor = 0.0;
	}
	return xCoor;
}

float yConvertion(float y) {
	float yCoor, height = HEIGHT / 2;
	if (y < height) {
		yCoor = y / height;
	}
	else if (y > height) {
		yCoor = 0 - ((y - height) / height);
	}
	else if (y == height) {
		yCoor = 0.0;
	}
	return yCoor;
}

float xPixel(float x) {
	return (x / (WIDTH / 2));
}

float yPixel(float y) {
	return (y / (HEIGHT / 2));
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
			// press 6
			qNo = 7;
			break;
		}
		else if (wParam == 0x38) {
			// press 6
			qNo = 8;
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
		float x2 = xConvertion(x1) + cos(i * M_PI / 180.f) * xPixel(x);
		float y2 = yConvertion(y1) + sin(i * M_PI / 180.f) * yPixel(y);
		glVertex2f(x2, y2);
	}
}

void test() {
	glClearColor(0.0745, 0.109803, 0.129411, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	float x1, y1, x2, y2;
	float angle;

	// head
	x1 = 0, y1 = 0;
	glBegin(GL_POLYGON);
	glColor3f(0.97647, 0.709804, 0.152941);
	drawCircle(x1, y1, 0.4, 0.4, 0, 371);

	glEnd();

	// smile 1
	x1 = 0, y1 = -0.05;
	glLineWidth(2);
	glBegin(GL_POLYGON);
	glColor3f(0.45098, 0.28627, 0.054902);
	drawCircle(x1, y1, 0.2, 0.15, 200, 330);

	glEnd();

	// smile 1 cover
	x1 = 0, y1 = -0.05;
	glLineWidth(2);
	glBegin(GL_POLYGON);
	glColor3f(0.97647, 0.709804, 0.152941);
	drawCircle(x1, y1, 0.2, 0.13, 200, 330);

	glEnd();

	// eye 1
	x1 = -0.14, y1 = 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.45098, 0.28627, 0.054902);
	drawCircle(x1, y1, 0.05, 0.05, 0, 371);

	glEnd();

	x1 = 0.14, y1 = 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.45098, 0.28627, 0.054902);
	drawCircle(x1, y1, 0.05, 0.05, 0, 371);

	glEnd();

	// eye 2
	x1 = -0.14, y1 = 0.12;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	drawCircle(x1, y1, 0.02, 0.02, 0, 371);

	glEnd();

	x1 = 0.14, y1 = 0.12;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	drawCircle(x1, y1, 0.02, 0.02, 0, 371);

	glEnd();

	// tear 1
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(0.14, 0.05);
	glColor3f(0.48627, 0.839215, 0.890196);
	glVertex2f(0.25, -0.15);
	glVertex2f(0.03, -0.15);

	glEnd();

	// tear 2
	x1 = 0.14, y1 = -0.15;
	glBegin(GL_POLYGON);
	glColor3f(0.48627, 0.839215, 0.890196);
	drawCircle(x1, y1, 0.11, 0.13, 177, 354);

	glEnd();
}

void pahangFlag() {

	glClearColor(255, 255, 255, 255);
	glClear(GL_COLOR_BUFFER_BIT);

	// flag shape
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);

	/*glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(-0.8, -0.5);*/

	glVertex2f(xConvertion(320), yConvertion(200));
	glVertex2f(xConvertion(720), yConvertion(200));
	glVertex2f(xConvertion(720), yConvertion(600));
	glVertex2f(xConvertion(320), yConvertion(600));
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(-0.8, 0);
	glVertex2f(0.8, 0);
	glVertex2f(0.8, -0.5);
	glVertex2f(-0.8, -0.5);

	glEnd();
}

void japanFlag() {

	glClearColor(255, 255, 255, 255);
	glClear(GL_COLOR_BUFFER_BIT);

	// flag shape
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);

	glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(-0.8, -0.5);

	glEnd();

	// circle
	float x1, y1, x2, y2;
	float angle;
	double radius = 0.3;

	x1 = 400.0, y1 = 400.0;
	glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLE_FAN);
	drawCircle(x1, y1, 100, 100, 0, 371);

	glEnd();
}

void extra() {

	float x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3);

	// background
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0.5);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glColor3f(1, 1, 1);
	glVertex2f(1, -1);
	glVertex2f(-1, -1);

	glEnd();

	// head
	float radius = 0.36;
	x1 = 0, y1 = -0.027;

	glBegin(GL_POLYGON);
	glColor3f(0, 0.5921, 0.890196);
	for (GLfloat i = -47; i < 225; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.347; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.36;
		glVertex2f(x2, y2);
	}

	glEnd();

	// head border 
	x1 = 0, y1 = -0.027;
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (GLfloat i = -48; i < 227; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.347; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.36;
		glVertex2f(x2, y2);
	}

	glEnd();

	// head2
	x1 = 0.0, y1 = -0.07;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (GLfloat i = -43.3; i < 221; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.3; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.32;
		glVertex2f(x2, y2);
	}

	glEnd();


	// mouth
	x1 = 0.0, y1 = -0.05;
	glBegin(GL_POLYGON);
	glColor3f(0.890196, 0.196088, 0.047058);
	for (GLfloat i = 175; i < 355; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.24; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.23;
		glVertex2f(x2, y2);
	}

	glEnd();

	// mouth 3 version 2
	x1 = 0.0, y1 = -0.3;
	glBegin(GL_POLYGON);
	glColor3f(0.890196, 0.494117, 0.30196);
	for (GLfloat i = 27; i < 150; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.17; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.15;
		glVertex2f(x2, y2);
	}

	glEnd();

	x1 = 0.0, y1 = -0.15;
	glBegin(GL_POLYGON);
	glColor3f(0.890196, 0.494117, 0.30196);
	for (GLfloat i = 215; i < 320; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.185; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.13;
		glVertex2f(x2, y2);
	}

	glEnd();

	// mouth 3 border
	x1 = 0.0, y1 = -0.3;
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (GLfloat i = 27; i < 150; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.17; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.15;
		glVertex2f(x2, y2);
	}

	glEnd();

	// mouth border
	x1 = 0.0, y1 = -0.05;
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for (GLfloat i = 176; i < 355; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.24; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.23;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eyes 1 
	x1 = -0.05, y1 = 0.24;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.05; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.08;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eyes 2 
	x1 = 0.05, y1 = 0.24;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.05; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.08;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eyes 1 border
	x1 = -0.05, y1 = 0.24;
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	//glVertex2f(x1, y1);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.05; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.08;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eyes 2 border
	x1 = 0.05, y1 = 0.24;
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.05; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.08;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eye dots 1

	x1 = -0.03, y1 = 0.24;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.015; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.03;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eye dots 1.5

	x1 = -0.027, y1 = 0.24;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.005; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.01;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eye dots 2

	x1 = 0.03, y1 = 0.24;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.015; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.03;
		glVertex2f(x2, y2);
	}

	glEnd();

	// eye dots 2.5

	x1 = 0.027, y1 = 0.24;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.005; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.01;
		glVertex2f(x2, y2);
	}

	glEnd();

	// nose 
	radius = 0.04;

	x1 = 0.0, y1 = 0.14;
	glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);

	drawCircle(x1, y1, 0.04, 0.04, 0, 360);
	glEnd();

	// nose border

	x1 = 0, y1 = 0.14;
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.04; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.04;
		glVertex2f(x2, y2);
	}

	glEnd();

	// nose 2
	radius = 0.01;

	x1 = -0.01, y1 = 0.15;
	glColor3f(1, 1, 1);

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);

	drawCircle(x1, y1, radius, radius, 0, 360);

	glEnd();

	// nose line
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(0, 0.1);
	glVertex2f(0, -0.05);

	glEnd();

	// belt
	glBegin(GL_POLYGON);
	glColor3f(0.82745, 0.211766, 0.090196);

	glVertex2f(-0.22, -0.3);
	glVertex2f(0.22, -0.3);
	glVertex2f(0.22, -0.34);
	glVertex2f(-0.22, -0.34);

	glEnd();

	// belt border
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(-0.22, -0.3);
	glVertex2f(0.22, -0.3);
	glVertex2f(0.22, -0.34);
	glVertex2f(-0.22, -0.34);

	glEnd();

	//belt left
	x1 = -0.22, y1 = -0.32;
	glBegin(GL_POLYGON);
	glColor3f(0.82745, 0.211766, 0.090196);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.02; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.02;
		glVertex2f(x2, y2);
	}

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (GLfloat i = 64; i < 300; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.02; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.02;
		glVertex2f(x2, y2);
	}

	glEnd();

	//belt right
	x1 = 0.22, y1 = -0.32;
	glBegin(GL_POLYGON);
	glColor3f(0.82745, 0.211766, 0.090196);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.02; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.02;
		glVertex2f(x2, y2);
	}

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.02; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.02;
		glVertex2f(x2, y2);
	}

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.82745, 0.211766, 0.090196);
	for (GLfloat i = 130; i < 220; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.02; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.02;
		glVertex2f(x2, y2);
	}

	glEnd();

	// bell
	x1 = 0, y1 = -0.36;
	glBegin(GL_POLYGON);
	glColor3f(0.894117, 0.866667, 0.007843);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.04; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.04;
		glVertex2f(x2, y2);
	}

	glEnd();

	// bell border
	x1 = 0, y1 = -0.36;
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.04; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.04;
		glVertex2f(x2, y2);
	}

	glEnd();

	// bell 2
	glBegin(GL_POLYGON);
	glColor3f(0.894117, 0.866667, 0.007843);

	glVertex2f(-0.045, -0.35);
	glVertex2f(0.04, -0.33);
	glVertex2f(0.04, -0.34);
	glVertex2f(-0.04, -0.36);

	glEnd();


	// bell 2 border
	glLineWidth(1.5);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(-0.05, -0.35);
	glVertex2f(0.04, -0.33);
	glVertex2f(0.04, -0.34);
	glVertex2f(-0.05, -0.36);

	glEnd();

	// bell 3
	x1 = 0.0025, y1 = -0.37;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x2 = x1 + cos(i * M_PI / 180.f) * 0.015; // keep the axes radius same
		float y2 = y1 + sin(i * M_PI / 180.f) * 0.015;
		glVertex2f(x2, y2);
	}

	glEnd();

	// bell line
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(0.003, -0.37);
	glVertex2f(0.003, -0.4);

	glEnd();

	// beard left 
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(-0.21, 0.11);
	glVertex2f(-0.05, 0.07);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(-0.22, 0.05);
	glVertex2f(-0.05, 0.05);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(-0.22, -0.01);
	glVertex2f(-0.05, 0.03);

	glEnd();

	// beard right 
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(0.21, 0.11);
	glVertex2f(0.05, 0.07);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(0.22, 0.05);
	glVertex2f(0.05, 0.05);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);

	glVertex2f(0.22, -0.01);
	glVertex2f(0.05, 0.03);

	glEnd();
}

void display()
{
	switch (qNo) {
	case 1:
		pahangFlag();
		break;
	case 2:
		extra();
		break;
	case 3:
		test();
		break;
	case 4:
		japanFlag();
		break;
	default:
		pahangFlag();
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