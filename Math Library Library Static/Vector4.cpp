#pragma once
#include "Vector4.h"

Vector4::Vector4(float fx, float fy, float fz, float fa) {
	x = fx;
	y = fy;
	z = fz;
	a = fa;
}

float Vector4::getMagnitude() {
	return (sqrtf((x*x) + (y*y) + (z*z) + (a*a)));
}
Vector4 Vector4::getUnitVector() {
	Vector4 temp;
	float tempMag = getMagnitude();
	temp.x = x / tempMag;
	temp.y = y / tempMag;
	temp.z = z / tempMag;
	temp.a = a / tempMag;
	return temp;
}
void Vector4::Normalise() {
	float tempMag = getMagnitude();
	x = x / tempMag;
	y = y / tempMag;
	z = z / tempMag;
	a = a / tempMag;
}
float Vector4::dotProduct(Vector4 &other) {
	return (x*other.x) + (y*other.y) + (z*other.z) + (a*other.a);
}