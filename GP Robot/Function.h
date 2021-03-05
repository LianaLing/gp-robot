#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H

namespace N {
	class function {
	public:
		float xC(float x);
		float yC(float y);
		float zC(float z);
		float xP(float x);
		float yP(float y);
		float zP(float z);
		float cC(float color);
		void v3(float x, float y, float z);
		void drawSphere(float xradius, float yradius, float zradius, int xaxis, int yaxis, float zaxis, float xmin, float xmax, float ymin, float ymax);
		void drawCircle(float x, float y, float xr, float yr, float min, float max);
		void quad(GLenum gltype, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
		void bezierQuad(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float r, float g, float b);
		void drawBezier(GLenum type, float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4);
	};
}

#endif /* MY_CLASS_H */