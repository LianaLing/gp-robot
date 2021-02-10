
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "IRON-MAN MK47"
#define CW_USEDEFAULT 10
#define WIDTH 900.0
#define HEIGHT 900.0
#define DEPTH 800.0

#define M_PI 3.2

int qNo = 3;

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
	float zCoor, depth = DEPTH / 2;
	/*if (z < 0) {
		zCoor = (z / depth);
	}
	else if (z > depth) {
		zCoor = (z - depth) / depth;
	}
	else if (z == depth) {
		zCoor = 0;
	}*/
	return (z / depth);
}

float xP(float x) {
	return (x / (WIDTH / 2));
}

float yP(float y) {
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
		float x2 = xC(x1) + cos(i * M_PI / 180.f) * xP(x);
		float y2 = yC(y1) + sin(i * M_PI / 180.f) * yP(y);
		glVertex2f(x2, y2);
	}
}

void drawSphere(float r, int xaxis, int yaxis, float zaxis, float xShape, float yShape) {
	float i, j, lats = 30, longs = 30;
	float x2 = xC(xaxis), y2 = yC(yaxis), z2 = zC(zaxis);

	for (i = 1; i <= xShape; i++) {
		float lat0 = M_PI * (-0.5 + (i - 1) / lats);
		float z0 = sin(lat0);
		float zr0 = cos(lat0);

		float lat1 = M_PI * (-0.5 + i / lats);
		float z1 = sin(lat1);
		float zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= yShape; j++) {
			float lng = 2 * M_PI * (j - 1.0) / longs;
			float x = cos(lng);
			float y = sin(lng);

			glColor3f(1, 1, 1);
			glNormal3f(x2 + x * zr0, y2 + y * zr0, z2 + z0);

			glVertex3f(x2 + r * x * zr0, y2 + r * y * zr0, z2 + r * z0);
			glColor3f(1, 0, 0);
			glNormal3f(x2 + x * zr1, y2 + y * zr1, z2 + z1);

			glVertex3f(x2 + r * x * zr1, y2 + r * y * zr1, z2 + r * z1);
		}
		glEnd();
	}
}

void test1() {
	glClearColor(0.0745, 0.109803, 0.129411, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	float x1, y1, x2, y2;
	float angle;

	// head
	x1 = 450, y1 = 450;
	glBegin(GL_POLYGON);
	glColor3f(0.97647, 0.709804, 0.152941);
	drawCircle(x1, y1, 180, 180, 0, 371);

	glEnd();

	// smile 1
	x1 = 450, y1 = 472.5;
	glLineWidth(2);
	glBegin(GL_POLYGON);
	glColor3f(0.45098, 0.28627, 0.054902);
	drawCircle(x1, y1, 90, 67.5, 200, 330);

	glEnd();

	// smile 1 cover
	x1 = 450, y1 = 472.5;
	glLineWidth(2);
	glBegin(GL_POLYGON);
	glColor3f(0.97647, 0.709804, 0.152941);
	drawCircle(x1, y1, 90, 58.5, 200, 330);

	glEnd();

	// eye 1
	x1 = 387, y1 = 405;
	glBegin(GL_POLYGON);
	glColor3f(0.45098, 0.28627, 0.054902);
	drawCircle(x1, y1, 22.5, 22.5, 0, 371);

	glEnd();

	x1 = 513, y1 = 405;
	glBegin(GL_POLYGON);
	glColor3f(0.45098, 0.28627, 0.054902);
	drawCircle(x1, y1, 22.5, 22.5, 0, 371);

	glEnd();

	// eye 2
	x1 = 387, y1 = 396;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	drawCircle(x1, y1, 9, 9, 0, 371);

	glEnd();

	x1 = 513, y1 = 396;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	drawCircle(x1, y1, 9, 9, 0, 371);

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
	x1 = 513, y1 = 517.5;
	glBegin(GL_POLYGON);
	glColor3f(0.48627, 0.839215, 0.890196);
	drawCircle(x1, y1, 49.5, 58.5, 177, 354);

	glEnd();
}

void test2() {
	//glLoadIdentity();
	glRotatef(1, 1, 1, 0);
	drawSphere(0.3, 400, 400, 0, 30, 30);
}

void pahangFlag() {

	glClearColor(255, 255, 255, 255);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// flag shape
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);

	glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(-0.8, -0.5);

	// white
	glVertex2f(xC(90), yC(200));
	glVertex2f(xC(810), yC(200));
	glVertex2f(xC(810), yC(600));
	glVertex2f(xC(90), yC(600));
	glEnd();

	// black
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

	x1 = 450.0, y1 = 450.0;
	glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLE_FAN);
	drawCircle(x1, y1, 100, 100, 0, 371);

	glEnd();
}

void display()
{
	glClearColor(0, 0, 0, 0);
	//glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (qNo) {
	case 1:
		pahangFlag();
		break;
	case 2:
		//extra();
		break;
	case 3:
		test1();
		break;
	case 4:
		japanFlag();
		break;
	case 5:
		test2();
		break;
	default:
		pahangFlag();
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