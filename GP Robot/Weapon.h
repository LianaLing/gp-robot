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
		void bullet(float i, boolean weaponFireOn, float bulletShot);
		void pipe(float i);
		void gun(float gunRotating, float gunXRotating, boolean weaponFireOn, float bulletShot, int bulletCount);
	};
}

#endif /* MY_CLASS_H */