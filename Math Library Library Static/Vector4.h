#pragma once
#include <cmath>

class Vector4 {
public:
	float x, y, z, a;

	Vector4();
	Vector4(float fx, float fy, float fz, float fa);

	float getMagnitude();
	Vector4 getUnitVector();
	void Normalise();
	float dotProduct(Vector4 &other);
};