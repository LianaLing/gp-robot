#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#ifndef MY_CLASS_W // include guard
#define MY_CLASS_W

namespace W {
	class weapon {
	public:
		void frontGun();
		void weaponRing();
		void weaponRing2();
		void holder();
		void pipe(float i);
		void gun(float gunRotating);
	};
}

#endif /* MY_CLASS_H */