#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#ifndef MY_CLASS_B // include guard
#define MY_CLASS_B

namespace B {
	class body {
	public:
		void upperChest(GLenum gltype);
	};
}

#endif /* MY_CLASS_H */