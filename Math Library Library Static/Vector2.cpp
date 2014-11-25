#pragma once
#include "Vector2.h"

Vector2::Vector2(float fx, float fy) {
	x = fx;
	y = fy;
}

float Vector2::getMagnitude() {
	return (sqrtf((x*x) + (y*y)));
}
Vector2 Vector2::getUnitVector() {
	Vector2 temp;
	temp.x = x;
	temp.y = y;
	float tempMag = temp.getMagnitude();
	temp.x = x / tempMag;
	temp.y = y / tempMag;
	return temp;
}
void Vector2::Normalize() {
	float tempMag = getMagnitude();
	x = x / tempMag;
	y = y / tempMag;
}
float Vector2::dotProduct(Vector2 &other) {
	return (x*other.x) + (y*other.y);
}
float Vector2::angle(Vector2 &other) {
	return acosf(dotProduct(other));
}
Vector2 Vector2::Interpolate(Vector2 &other, float T) {
	Vector2 temp;
	temp.x = x + T * (other.x - x);
	temp.y = y + T * (other.y - y);
	return temp;
}

Vector2 Vector2::operator * (float &scalar) {
	Vector2 temp;
	temp.x = x * scalar;
	temp.y = y * scalar;
	return temp;
}
void Vector2::operator *= (float &scalar) {
	x = x * scalar;
	y = y * scalar;
}
Vector2 Vector2::operator / (float &scalar) {
	Vector2 temp;
	temp.x = x / scalar;
	temp.y = y / scalar;
	return temp;
}
void Vector2::operator /= (float &scalar) {
	x = x / scalar;
	y = y / scalar;
}
Vector2 Vector2::operator * (Vector2 &other) {
	Vector2 temp;
	temp.x = x * other.x;
	temp.y = y * other.y;
	return temp;
}
void Vector2::operator *= (Vector2 &other) {
	x = x * other.x;
	y = y * other.y;
}
Vector2 Vector2::operator / (Vector2 &other) {
	Vector2 temp;
	temp.x = x / other.x;
	temp.y = y / other.y;
	return temp;
}
void Vector2::operator /= (Vector2 &other) {
	x = x / other.x;
	y = y / other.y;
}
Vector2 Vector2::operator + (Vector2 &other) {
	Vector2 temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	return temp;
}
void Vector2::operator += (Vector2 &other) {
	x = x + other.x;
	y = y + other.y;
}
Vector2 Vector2::operator - (Vector2 &other) {
	Vector2 temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	return temp;
}
void Vector2::operator -= (Vector2 &other) {
	x = x - other.x;
	y = y - other.y;
}
void Vector2::operator = (Vector2 &other) {
	x = other.x;
	y = other.y;
}
bool Vector2::operator == (Vector2 &other) {
	if (x != other.x) {
		return false;
	}
	if (y != other.y) {
		return false;
	}
	return true;
}