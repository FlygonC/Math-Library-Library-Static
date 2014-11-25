#pragma once
#include "Vector3.h"

Vector3::Vector3(float fx, float fy, float fz) {
	x = fx;
	y = fy;
	z = fz;
}

float Vector3::getMagnitude() {
	return (sqrtf((x*x) + (y*y) + (z*z)));
}
Vector3 Vector3::getUnitVector() {
	Vector3 temp;
	float tempMag = getMagnitude();
	temp.x = x / tempMag;
	temp.y = y / tempMag;
	temp.z = z / tempMag;
	return temp;
}
void Vector3::Normalize() {
	float tempMag = getMagnitude();
	x = x / tempMag;
	y = y / tempMag;
	z = z / tempMag;
}
float Vector3::dotProduct(Vector3 &other) {
	return (x*other.x) + (y*other.y) + (z*other.z);
}
Vector3 Vector3::crossProduct(Vector3 &other) {
	Vector3 temp;
	temp.x = (y*other.z) - (z*other.y);
	temp.y = (z*other.x) - (x*other.z);
	temp.z = (x*other.y) - (y*other.x);
	return temp;
}
Vector3 Vector3::Interpolate(Vector3 &other, float T) {
	Vector3 temp;
	temp.x = x + T * (other.x - x);
	temp.y = y + T * (other.y - y);
	temp.z = z + T * (other.z - z);
	return temp;
}

Vector3 Vector3::operator * (float &scalar) {
	Vector3 temp;
	temp.x = x * scalar;
	temp.y = y * scalar;
	temp.z = z * scalar;
	return temp;
}
void Vector3::operator *= (float &scalar) {
	x = x * scalar;
	y = y * scalar;
	z = z * scalar;
}
Vector3 Vector3::operator / (float &scalar) {
	Vector3 temp;
	temp.x = x / scalar;
	temp.y = y / scalar;
	temp.z = z / scalar;
	return temp;
}
void Vector3::operator /= (float &scalar) {
	x = x / scalar;
	y = y / scalar;
	z = z / scalar;
}
Vector3 Vector3::operator * (Vector3 &other) {
	Vector3 temp;
	temp.x = x * other.x;
	temp.y = y * other.y;
	temp.z = z * other.y;
	return temp;
}
void Vector3::operator *= (Vector3 &other) {
	x = x * other.x;
	y = y * other.y;
	z = z * other.y;
}
Vector3 Vector3::operator / (Vector3 &other) {
	Vector3 temp;
	temp.x = x / other.x;
	temp.y = y / other.y;
	temp.z = z / other.y;
	return temp;
}
void Vector3::operator /= (Vector3 &other) {
	x = x / other.x;
	y = y / other.y;
	z = z / other.y;
}
Vector3 Vector3::operator + (Vector3 &other) {
	Vector3 temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	temp.z = z + other.z;
	return temp;
}
void Vector3::operator += (Vector3 &other) {
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
}
Vector3 Vector3::operator - (Vector3 &other) {
	Vector3 temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	temp.z = z - other.z;
	return temp;
}
void Vector3::operator -= (Vector3 &other) {
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
}
void Vector3::operator = (Vector3 &other) {
	x = other.x;
	y = other.y;
	z = other.z;
}
bool Vector3::operator == (Vector3 &other) {
	if (x != other.x || y != other.y || z != other.z) {
		return false;
	}
	else {
		return true;
	}
}